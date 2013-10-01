#include <kernel.h>
#include <scheduler.h>


#ifdef USE_BITMAP

#define BITS_PER_BYTE		8
#define BITS_PER_INTEGER	(sizeof(int) * BITS_PER_BYTE)
#define BIT_MASK(prio)		(1 << ((prio) % BITS_PER_INTEGER))
#define BIT_WORD(prio)		((prio) / BITS_PER_INTEGER)


void __set_bit(int prio, unsigned int *bitmap) {
	unsigned int mask = BIT_MASK(prio);
	unsigned int *p = ((unsigned int *)bitmap) + BIT_WORD(prio);
	*p |= mask;
}


void __clear_bit(int prio, unsigned int *bitmap) {
	unsigned int mask = BIT_MASK(prio);
	unsigned int *p = ((unsigned int *)bitmap) + BIT_WORD(prio);
	*p &= ~mask;
}


int __ffs(const unsigned int b) {
	unsigned int x = b;
	int r = 32;

	if (!x)
		return 0;
	if (!(x & 0xffff0000u)) {
		x <<= 16;
		r -= 16;
	}
	if (!(x & 0xff000000u)) {
		x <<= 8;
		r -= 8;
	}
	if (!(x & 0xf0000000u)) {
		x <<= 4;
		r -= 4;
	}
	if (!(x & 0xc0000000u)) {
		x <<= 2;
		r -= 2;
	}
	if (!(x & 0x80000000u)) {
		x <<= 1;
		r -= 1;
	}
	return r - 1;
}


int sched_find_first_bit(const unsigned int *b) {
	if (b[7])
		return __ffs(b[7]) + 224;
	if (b[6])
		return __ffs(b[6]) + 192;
	if (b[5])
		return __ffs(b[5]) + 160;
	if (b[4])
		return __ffs(b[4]) + 128;
	if (b[3])
		return __ffs(b[3]) + 96; 
	if (b[2])
		return __ffs(b[2]) + 64; 
	if (b[1])
		return __ffs(b[1]) + 32; 
	return __ffs(b[0]);
}


unsigned int bitmap[8];
#else // USE_BITMAP
#endif // USE_BITMAP
struct TaskQStruct readyQ[CONFIG_MAX_PRIORITY];
struct TaskStruct *currentTask = &idleTask;


void InitScheduler(void) {
	int i;

	for (i=0; i<CONFIG_MAX_PRIORITY; i++) {
		readyQ[i].next = (struct TaskStruct *)&readyQ[i];
		readyQ[i].prev = (struct TaskStruct *)&readyQ[i];
	}
}


struct TaskStruct *TaskSelect(void) {
	struct TaskStruct *task = &idleTask;

#ifdef USE_BITMAP
	int prio = sched_find_first_bit(bitmap);
	printf("sched_find_first_bit( 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x, 0x%08x ) returns %d\n",
			bitmap[7], bitmap[6], bitmap[5], bitmap[4],
			bitmap[3], bitmap[2], bitmap[1], bitmap[0], prio);
	task = readyQ[prio].next;
#else // USE_BITMAP
	int i;
	for (i=CONFIG_MAX_PRIORITY-1; i>=0; i--) {
		if (readyQ[i].next != (struct TaskStruct *)&readyQ[i]) {
			task = readyQ[i].next;
			break;
		}
	}
#endif // USE_BITMAP

	return task;
}


int TaskEnqueue(struct TaskStruct *task) {
	task->next = (struct TaskStruct *)(&readyQ[task->prio]);
	task->prev = (struct TaskStruct *)(&readyQ[task->prio])->prev;
	readyQ[task->prio].prev->next = task;
	readyQ[task->prio].prev = task;
	__set_bit(task->prio, bitmap);

	return 0;
}


int TaskDequeue(struct TaskStruct *task) {
	task->prev->next = task->next;
	task->next->prev = task->prev;
	__clear_bit(task->prio, bitmap);

	return 0;
}


int TaskWait(struct TaskQStruct *waitQ, struct TaskStruct *task) {
	TaskDequeue(task);

	task->next = (struct TaskStruct *)(&waitQ[task->prio]);
	task->prev = (struct TaskStruct *)(&waitQ[task->prio])->prev;
	waitQ[task->prio].prev->next = task;
	waitQ[task->prio].prev = task;

	task->state = TASK_STATE_WAITING;
	DoScheduling();

	return 0;
}


int TaskWakeup(struct TaskStruct *task) {
	task->prev->next = task->next;
	task->next->prev = task->prev;

	TaskEnqueue(task);
	task->state = TASK_STATE_READY;

	DoScheduling();

	return 0;
}


int TaskWakeupAll(struct TaskQStruct *waitQ) {
	struct TaskStruct *task;
	struct TaskStruc *curTask;
	unsigned int flag;

	for (task=waitQ->next; task != (struct TaskStruct *)waitQ; task=curTask) {
		curTask = task->next;

		TaskEnqueue(task);
		task->state = TASK_STATE_READY;
	}

	waitQ->next = (struct TaskStruct *)&waitQ;
	waitQ->prev = (struct TaskStruct *)&waitQ;

	DoScheduling();

	return 0;
}


void ContextSwitch(struct TaskStruct *currentTask, struct TaskStruct *nextTask) {
	struct ContextFrame *ctx = (struct ContextFrame *)nextTask->stackPoint;

	__asm__ __volatile__(
			"str r10, [sp, #-0x4]!\n\t"
			"str r11, [sp, #-0x4]!\n\t"

			"mrs r10, cpsr\n\t"
			"adr r11, switch_end\n\t"

			"str r11, [sp, #-0x4]!\n\t"
			"str r10, [sp, #-0x4]!\n\t"

			"str lr,  [sp, #-0x4]!\n\t"
			"str r12, [sp, #-0x4]!\n\t"
			"str r11, [sp, #-0x4]!\n\t"
			"str r10, [sp, #-0x4]!\n\t"
			"str r9,  [sp, #-0x4]!\n\t"
			"str r8,  [sp, #-0x4]!\n\t"
			"str r7,  [sp, #-0x4]!\n\t"
			"str r6,  [sp, #-0x4]!\n\t"
			"str r5,  [sp, #-0x4]!\n\t"
			"str r4,  [sp, #-0x4]!\n\t"
			"str r3,  [sp, #-0x4]!\n\t"
			"str r2,  [sp, #-0x4]!\n\t"
			"str r1,  [sp, #-0x4]!\n\t"
			"str r0,  [sp, #-0x4]!\n\t"

			"str sp,  %0\n\t"
			"ldr sp,  %1\n\t"
			"ldr r10, %2\n\t"
			"msr cpsr,r10\n\t"

			"ldr r0,  [sp], #0x4\n\t"
			"ldr r1,  [sp], #0x4\n\t"
			"ldr r2,  [sp], #0x4\n\t"
			"ldr r3,  [sp], #0x4\n\t"
			"ldr r4,  [sp], #0x4\n\t"
			"ldr r5,  [sp], #0x4\n\t"
			"ldr r6,  [sp], #0x4\n\t"
			"ldr r7,  [sp], #0x4\n\t"
			"ldr r8,  [sp], #0x4\n\t"
			"ldr r9,  [sp], #0x4\n\t"
			"ldr r10, [sp], #0x4\n\t"
			"ldr r11, [sp], #0x4\n\t"
			"ldr r12, [sp], #0x4\n\t"
			"ldr lr,  [sp], #0x4\n\t"

			"add sp,  sp,   #0x4\n\t"
			"ldr pc,  [sp], #0x4\n\t"

			"switch_end:\n\t"
			"ldr r11, [sp], #0x4\n\t"
			"ldr r10, [sp], #0x4\n\t"
			:
			: "m"(currentTask->stackPoint), "m"(nextTask->stackPoint), "m"(ctx->cpsr)
	);
}


void DoScheduling(void) {
	struct TaskStruct *current;

	printf("[DoScheduling] ..................................\n");
	current = currentTask;
	/*
	if (current->count == 0) {
		TaskDequeue(current);
		current->count = current->timeQuantum;
		TaskEnqueue(current);
	}
	*/
	currentTask = TaskSelect();

	unsigned int loop;
	for (loop=0x0fffffffu; loop>0; loop--);

	if (currentTask == current) {
		return;
	}

	ContextSwitch(current, currentTask);
}


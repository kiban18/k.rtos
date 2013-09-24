#include <kernel.h>
#include <scheduler.h>


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
	struct TaskStruct *task;
	struct TaskStruc *curTask;
	unsigned int flag;
	int i;

	for (i=0; i<CONFIG_MAX_PRIORITY; i++) {
		for (task=readyQ[i].next; task!=(struct TaskStruct *)readyQ; task=curTask) {
			curTask = task->next;

			return task;
		}
	}

	return 0;
}


int TaskEnqueue(struct TaskStruct *task) {
	task->next = (struct TaskStruct *)(&readyQ[task->prio]);
	task->prev = (struct TaskStruct *)(&readyQ[task->prio])->prev;
	readyQ[task->prio].prev->next = task;
	readyQ[task->prio].prev = task;

	return 0;
}


int TaskDequeue(struct TaskStruct *task) {
	task->prev->next = task->next;
	task->next->prev = task->prev;

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

	current = currentTask;
	currentTask = TaskSelect();

	if (currentTask = current) {
		return;
	}

	ContextSwitch(current, currentTask);
}


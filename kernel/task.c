#include <kernel.h>
#include <task.h>
#include <interrupt.h>


struct TaskStruct idleTask;
struct TaskStruct initTask;
unsigned char idleStack[CONFIG_TASK_STACK_SIZE];
unsigned char initStack[CONFIG_TASK_STACK_SIZE];


int InitTask(void) {
	struct TaskStruct *task = &idleTask;
	int flag;

	task->prio = 0;
	task->state = TASK_STATE_READY;

	task->stackAddr = idleStack;
	task->stackPoint = 0;
	task->stackSize = CONFIG_TASK_STACK_SIZE;

	task->StartFunction = 0;
	task->args = 0;

	task->id = (unsigned int)task;
	TaskEnqueue(task);

	return 0;
}


int TaskInit(struct TaskStruct *task, int (*StartFunction)(void *), void *args, unsigned int prio,
                unsigned char *stackAddr, unsigned int stackSize) {
	int flag;

	task->prio = prio;
	task->state = TASK_STATE_READY;

	task->stackAddr = stackAddr;
	task->stackPoint = task->stackAddr + stackSize - sizeof(struct ContextFrame);
	task->stackSize = stackSize;

	task->StartFunction = StartFunction;
	task->args = args;

	task->id = (unsigned int)task;

	TaskInitContext(task);

	TaskEnqueue(task);
	DoScheduling();

	return 0;
}


void TaskInitContext(struct TaskStruct *task) {
	struct ContextFrame *ctx = (struct ContextFrame *)task->stackPoint;

	ctx->pc = (unsigned int)task->StartFunction;
	ctx->r0 = task->args;
	ctx->r1 = 0;
	ctx->r2 = 0;
	ctx->r3 = 0;
	ctx->r4 = 0;
	ctx->r5 = 0;
	ctx->r6 = 0;
	ctx->r7 = 0;
	ctx->r8 = 0;
	ctx->r9 = 0;
	ctx->r10 = 0;
	ctx->r11 = 0;
	ctx->r12 = 0;
	ctx->lr = (unsigned int)TaskExit;
	ctx->cpsr = 0x13; //SVC mode
}


int TaskExit(void) {
	unsigned int flag;

	TaskDequeue(currentTask);
	currentTask->id = 0;
	DoScheduling();

	return 0;
}


struct TaskStruct *TaskGetID(void) {
	return currentTask;
}


int TaskYield(void) {
	int flag;

	TaskDequeue(currentTask);
	TaskEnqueue(currentTask);
	DoScheduling();

	return 0;
}


int TaskGetPriority(struct TaskStruct *task) {
	return task->prio;
}


int TaskSetPriority(struct TaskStruct *task, unsigned int prio) {
	int flag;

	if (task->state & TASK_STATE_READY) {
		TaskDequeue(task);
		task->prio = prio;
		TaskEnqueue(task);
	} else {
		task->prio = prio;
	}

	DoScheduling();

	return 0;
}


#ifndef __TASK_H__
#define __TASK_H__

#include <scheduler.h>


#define TASK_STATE_READY            (1 << 0)
#define TASK_STATE_RUNNING          (1 << 1)
#define TASK_STATE_WAITING          (1 << 2)
#define TASK_STATE_ZOMBI            (1 << 3)


struct TaskStruct {
	struct TaskStruct *next;
	struct TaskStruct *prev;

	unsigned int id;
	unsigned int prio;
	unsigned int state;

	unsigned char *stackAddr;
	unsigned char *stackPoint;
	unsigned int stackSize;

	int (*StartFunction)(void *);
	void *args;

	unsigned int timeQuantum;
	unsigned int count;
};


extern struct TaskStruct *currentTask;
extern struct TaskStruct idleTask;
extern struct TaskStruct initTask;
extern unsigned char initStack[CONFIG_TASK_STACK_SIZE];


int InitTask(void);
int TaskInit(struct TaskStruct *task, int (*StartFunction)(void *), void *args, unsigned int prio, unsigned int timeQuamtum,
        unsigned char *stackAddr, unsigned int stackSize);
void TaskInitContext(struct TaskStruct *task);
int TaskExit(void);
struct TaskStruct *TaskGetID(void);
int TaskYield(void);
int InitTaskMain(void *args);

#endif /* __TASK_H__ end. */


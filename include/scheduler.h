
#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <kernel.h>
#include <task.h>
#define SCHED_TIME_QUANTUM   CONFIG_SCHED_TIME_QUANTUM


struct ContextFrame {
        unsigned int r0;
        unsigned int r1;
        unsigned int r2;
        unsigned int r3;
        unsigned int r4;
        unsigned int r5;
        unsigned int r6;
        unsigned int r7;
        unsigned int r8;
        unsigned int r9;
        unsigned int r10;
        unsigned int r11;
        unsigned int r12;
        unsigned int lr;
        unsigned int cpsr;
        unsigned int pc;
};


struct TaskQStruct {
    struct TaskStruct *next;
    struct TaskStruct *prev;
};


extern struct TaskStruct *currentTask;


void InitScheduler(void);
void DoScheduling(void);
void ContextSwitch(struct TaskStruct *currentTask, struct TaskStruct *nextTask);
struct TaskStruct *TaskSelect(void);
int TaskEnqueue(struct TaskStruct *task);
int TaskDequeue(struct TaskStruct *task);
int TaskWait(struct TaskQStruct *waitQ, struct TaskStruct *task);
int TaskWakeupAll(struct TaskQStruct *waitQ);


#endif /* __SCHEDULER_H__ end. */



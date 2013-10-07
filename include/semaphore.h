#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#include <kernel.h>
#include <task.h>
#include <scheduler.h>


struct SemaStruct {
    unsigned int count;
    struct TaskQStruct waitQ;
};


int SemaInit(struct SemaStruct *sema, unsigned int count);
int SemaTake(struct SemaStruct *sema);
int SemaGive(struct SemaStruct *sema);

#endif /* __SEMAPHORE_H__ end. */


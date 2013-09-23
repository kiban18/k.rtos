#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <kernel.h>
#include <task.h>
#include <scheduler.h>


struct MutexStruct {
    int lock;
    unsigned int cPrio;
    unsigned int oPrio;
    struct TaskStruct *owner;
    struct TaskQStruct waitQ;
};


int MutexInit(struct MutexStruct *mutex, unsigned int cPrio);
int MutexLock(struct MutexStruct *mutex);
int MutexUnlock(struct MutexStruct *mutex);

#endif /* __MUTEX_H__ end. */



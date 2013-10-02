#include <config.h>
#include <mutex.h>
#include <interrupt.h>


int MutexInit(struct MutexStruct *mutex, unsigned int cPrio) {

    mutex->owner = 0;
    mutex->lock = 0;

    mutex->waitQ.next = (struct TaskStruct *)(&mutex->waitQ);
    mutex->waitQ.prev = (struct TaskStruct *)(&mutex->waitQ);

#if defined (_DEBUG_SHOW_SEMAPHORE_USING_MUTEX_)
    printf("**************************************** [MutexInit] mutex(0x%08x) is initialized\n", mutex);
#endif // DEBUG

    return 0;
}


int MutexLock(struct MutexStruct *mutex) {
    unsigned int flag;

    flag = IntSaveDisableIRQ();

    while (mutex->lock) {
#if defined (_DEBUG_SHOW_SEMAPHORE_USING_MUTEX_)
        printf("**************************************** [MutexLock] mutex(0x%08x) is already locked by owner(%d), this task(%d) is Waiting\n",
                mutex, mutex->owner->timeQuantum, currentTask->timeQuantum);
        printWaitQ(mutex->waitQ);
        printAllReadyQ();
#endif // DEBUG
        TaskWait(&mutex->waitQ, currentTask);
        IntRestoreIRQ(flag);
        flag = IntSaveDisableIRQ();
    }

    mutex->owner = currentTask;
    mutex->lock = 1;

    IntRestoreIRQ(flag);

#if defined (_DEBUG_SHOW_SEMAPHORE_USING_MUTEX_)
    printf("**************************************** [MutexLock] this task(%d) is locking mutex(0x%08x)\n", currentTask->timeQuantum, mutex);
#endif // DEBUG

    return 0;
}


int MutexUnlock(struct MutexStruct *mutex) {
    unsigned int flag;

#if defined (_DEBUG_SHOW_SEMAPHORE_USING_MUTEX_)
    printf("**************************************** [MutexUnlock] mutex(0x%08x) is about to unlock from this task(%d)\n", mutex, currentTask->timeQuantum);
    printWaitQ(mutex->waitQ);
    printAllReadyQ();
#endif // DEBUG

    flag = IntSaveDisableIRQ();

    mutex->lock = 0;
    mutex->owner = 0;

    TaskWakeupAll(&mutex->waitQ);

    IntRestoreIRQ(flag);

#if defined (_DEBUG_SHOW_SEMAPHORE_USING_MUTEX_)
    printf("**************************************** [MutexUnlock] mutex(0x%08x) is unlocked\n", mutex);
    printWaitQ(mutex->waitQ);
    printAllReadyQ();
#endif // DEBUG

    return 0;
}


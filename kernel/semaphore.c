#include <config.h>
#include <semaphore.h>
#include <interrupt.h>


int SemaInit(struct SemaStruct *sema, unsigned int count) {

    sema->count = count;

    sema->waitQ.next = (struct TaskStruct *)(&sema->waitQ);
    sema->waitQ.prev = (struct TaskStruct *)(&sema->waitQ);

#if defined (_DEBUG_SHOW_SEMAPHORE_)
    printf("**************************************** [SemaInit] sema(0x%08x,%d) is initialized\n", sema, sema->count);
#endif // DEBUG

    return 0;
}


int SemaTake(struct SemaStruct *sema) {
    unsigned int flag;

    flag = IntSaveDisableIRQ();

    while (sema->count == 0) {
#if defined (_DEBUG_SHOW_SEMAPHORE_)
        printf("**************************************** [SemaTake] count(%d) of sema(0x%08x) is already 0, this task(%d) is Waiting\n",
                sema->count, sema, currentTask->timeQuantum);
#endif // DEBUG
        TaskWait(&sema->waitQ, currentTask);
        IntRestoreIRQ(flag);
        flag = IntSaveDisableIRQ();
    }

    sema->count--;

    IntRestoreIRQ(flag);

#if defined (_DEBUG_SHOW_SEMAPHORE_)
    printf("**************************************** [SemaTake] this task(%d) now took sema(0x%08x,%d)\n",
            currentTask->timeQuantum, sema, sema->count);
#endif // DEBUG

    return 0;
}


int SemaGive(struct SemaStruct *sema) {
    unsigned int flag;

#if defined (_DEBUG_SHOW_SEMAPHORE_)
    printf("**************************************** [SemaGive] this task(%d) is about to give sema(0x%08x,%d)\n",
            currentTask->timeQuantum, sema, sema->count);
#endif // DEBUG

    flag = IntSaveDisableIRQ();

    sema->count++;

    TaskWakeupAll(&sema->waitQ);

    IntRestoreIRQ(flag);

#if defined (_DEBUG_SHOW_SEMAPHORE_)
    printf("**************************************** [SemaGive] this task(%d) now gave sema(0x%08x,%d)\n",
            currentTask->timeQuantum, sema, sema->count);
#endif // DEBUG

    return 0;
}


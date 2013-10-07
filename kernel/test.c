#include <config.h>
#include <kernel.h>
#include <scheduler.h>
#include <task.h>
#include <event.h>
#include <timer.h>
#include <mutex.h>
#include <semaphore.h>


#define LONG_DELAY_LOOP_COUNT   0x8fffffffu
#define SHORT_DELAY_LOOP_COUNT  0x08ffffffu

#define TIMER_INTERVAL_0    55
#define TIMER_INTERVAL_1    13
#define TIMER_INTERVAL_2    36
#define TIMER_INTERVAL_3    25
#define TIMER_INTERVAL_4    10

#define TASK_QUANTUM_0      5
#define TASK_QUANTUM_1      7
#define TASK_QUANTUM_2      3
#define TASK_QUANTUM_3      2
#define TASK_QUANTUM_4      4
#define TASK_QUANTUM_5      2
#define TASK_QUANTUM_6      4
#define TASK_QUANTUM_7      5


int Task0Main(void *args);
int Task1Main(void *args);
int Task2Main(void *args);
int Task3Main(void *args);
int Task4Main(void *args);
int Task5Main(void *args);
int Task6Main(void *args);
int Task7Main(void *args);


struct TaskStruct task0, task1, task2, task3, task4, task5, task6, task7;
unsigned char taskStack0[4096], taskStack1[4096], taskStack2[4096], taskStack3[4096], taskStack4[4096];
unsigned char taskStack5[4096], taskStack6[4096], taskStack7[4096];
//struct EventStruct event;
struct TimerStruct timer0, timer1, timer2, timer3, timer4;


int Task0Main(void *args) {
    while (1) {
#if defined(_SHOW_TASK_SCHED_BY_YIELD_)
        unsigned int loop;
        for (loop=SHORT_DELAY_LOOP_COUNT; loop>0; loop--);
#endif

        printf("\n[Task0Main] running\n");
#if defined(_SHOW_TASK_SCHED_BY_YIELD_)
        TaskYield();
#endif
    }

    return 0;
}


int Task1Main(void *args) {
    while (1) {
#if defined(_SHOW_TASK_SCHED_BY_YIELD_)
        unsigned int loop;
        for (loop=SHORT_DELAY_LOOP_COUNT; loop>0; loop--);
#endif

        printf("\n[TaskMain] running\n");
#if defined(_SHOW_TASK_SCHED_BY_YIELD_)
        TaskYield();
#endif
    }

    return 0;
}


int Task2Main(void *args) {
    while (1) {
#if defined(_SHOW_TASK_SCHED_BY_YIELD_)
        unsigned int loop;
        for (loop=SHORT_DELAY_LOOP_COUNT; loop>0; loop--);
#endif

        printf("\n[Task2Main] running\n");
#if defined(_SHOW_TASK_SCHED_BY_YIELD_)
        TaskYield();
#endif
    }

    return 0;
}


int globalData4TestMutex = 0;
struct MutexStruct m1;

int Task3Main(void *args) {
    unsigned int loop;
    printf("[Task3Main] task(%d) started\n", task3.timeQuantum);
    while (1) {
#if defined(_DEBUG_SHOW_MUTEX_)
        printf("########################################\n");
        printf("## [Task3Main] To MutexLock!!!\n");
        printf("########################################\n");
#endif // DEBUG
        MutexLock(&m1);
#if defined(_DEBUG_SHOW_MUTEX_)
        printf("########################################\n");
        printf("## [Task3Main] MutexLocked!!!\n");
        printf("########################################\n");
#endif // DEBUG

#if defined(_DEBUG_SHOW_MUTEX_)
        printf("########################################\n");
        printf("## [Task3Main] ************************* globalData4TestMutex:%d\n", globalData4TestMutex);
        printf("########################################\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

#if defined(_DEBUG_SHOW_MUTEX_)
        printf("########################################\n");
        printf("## [Task3Main] To MutexUnlock!!!\n");
        printf("########################################\n");
#endif // DEBUG
        MutexUnlock(&m1);
#if defined(_DEBUG_SHOW_MUTEX_)
        printf("########################################\n");
        printf("## [Task3Main] MutexUnlocked!!!\n");
        printf("########################################\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

        if (globalData4TestMutex >= 5)
            break;
    }

    return 0;
}


int Task4Main(void *args) {
    unsigned int loop;
    printf("[Task4Main] task(%d) started\n", task4.timeQuantum);
    while (1) {
#if defined(_DEBUG_SHOW_MUTEX_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task4Main] To MutexLock!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        MutexLock(&m1);
#if defined(_DEBUG_SHOW_MUTEX_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task4Main] MutexLocked!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        globalData4TestMutex++;
#if defined(_DEBUG_SHOW_MUTEX_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task4Main] ************************* globalData4TestMutex increased to %d\n",
                globalData4TestMutex);
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

#if defined(_DEBUG_SHOW_MUTEX_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task4Main] To MutexUnlock!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        MutexUnlock(&m1);
#if defined(_DEBUG_SHOW_MUTEX_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task4Main] MutexUnlocked!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

        if (globalData4TestMutex >= 5)
            break;
    }

    return 0;
}


struct SemaStruct gSema;
int globalData4TestSemaphore = 0;

int Task5Main(void *args) {
    unsigned int loop;
    printf("[Task5Main] task(%d) started\n", task5.timeQuantum);
    while (1) {
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task5Main] To SemaTake!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        SemaTake(&gSema);
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task5Main] SemaTook!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        globalData4TestSemaphore++;
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task5Main] ************************* globalData4TestSemaphore increased to %d\n",
                globalData4TestSemaphore);
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task5Main] To SemaGive!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        SemaGive(&gSema);
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task5Main] SemaGave!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

        if (globalData4TestSemaphore >= 15)
            break;
    }

    return 0;
}


int Task6Main(void *args) {
    unsigned int loop;
    printf("[Task6Main] task(%d) started\n", task6.timeQuantum);
    while (1) {
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task6Main] To SemaTake!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        SemaTake(&gSema);
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task6Main] SemaTook!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        globalData4TestSemaphore++;
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task6Main] ************************* globalData4TestSemaphore increased to %d\n",
                globalData4TestSemaphore);
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task6Main] To SemaGive!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        SemaGive(&gSema);
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task6Main] SemaGave!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

        if (globalData4TestSemaphore >= 15)
            break;
    }

    return 0;
}


int Task7Main(void *args) {
    unsigned int loop;
    printf("[Task7Main] task(%d) started\n", task7.timeQuantum);
    while (1) {
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task7Main] To SemaTake!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        SemaTake(&gSema);
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task7Main] SemaTook!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        globalData4TestSemaphore++;
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task7Main] ************************* globalData4TestSemaphore increased to %d\n",
                globalData4TestSemaphore);
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task7Main] To SemaGive!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG
        SemaGive(&gSema);
#if defined(_DEBUG_SHOW_SEMAPHORE_)
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@ [Task7Main] SemaGave!!!\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif // DEBUG

        for (loop=LONG_DELAY_LOOP_COUNT; loop>0; loop--);

        if (globalData4TestSemaphore >= 15)
            break;
    }

    return 0;
}


void TimerHandler0(void) {
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("[TimerHandler0] tick(%d)\n", systemTick);
#endif // DEBUG
    TimerInit(&timer0, systemTick+TIMER_INTERVAL_0, TimerHandler0);
}


void TimerHandler1(void) {
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("[TimerHandler1] tick(%d)\n", systemTick);
#endif // DEBUG
    TimerInit(&timer1, systemTick+TIMER_INTERVAL_1, TimerHandler1);
}


void TimerHandler2(void) {
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("[TimerHandler2] tick(%d)\n", systemTick);
#endif // DEBUG
    TimerInit(&timer2, systemTick+TIMER_INTERVAL_2, TimerHandler2);
}


void TimerHandler3(void) {
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("[TimerHandler3] tick(%d)\n", systemTick);
#endif // DEBUG
    TimerInit(&timer3, systemTick+TIMER_INTERVAL_3, TimerHandler3);
}


void TimerHandler4(void) {
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("[TimerHandler4] tick(%d)\n", systemTick);
#endif // DEBUG
    TimerInit(&timer4, systemTick+TIMER_INTERVAL_4, TimerHandler4);
}


int InitTaskMain(void *args) {
    printf("[InitTaskMain] init task start..........\n");

#if !defined(_SHOW_MUTEX_) && !defined(_SHOW_SEMAPHORE_)
    TaskInit(&task0, Task0Main, 0, 10, TASK_QUANTUM_0, taskStack0, sizeof(taskStack0));
    TaskInit(&task1, Task1Main, 0, 10, TASK_QUANTUM_1, taskStack1, sizeof(taskStack1));
    TaskInit(&task2, Task2Main, 0, 10, TASK_QUANTUM_2, taskStack2, sizeof(taskStack2));
#endif
#if defined(_SHOW_MUTEX_)
    MutexInit(&m1, 0);
    TaskInit(&task3, Task3Main, 0, 11, TASK_QUANTUM_3, taskStack3, sizeof(taskStack3));
    TaskInit(&task4, Task4Main, 0, 11, TASK_QUANTUM_4, taskStack4, sizeof(taskStack4));
#endif // _SHOW_MUTEX_
#if defined(_SHOW_SEMAPHORE_)
    SemaInit(&gSema, 2);
    TaskInit(&task5, Task5Main, 0, 11, TASK_QUANTUM_5, taskStack5, sizeof(taskStack5));
    TaskInit(&task6, Task6Main, 0, 11, TASK_QUANTUM_6, taskStack6, sizeof(taskStack6));
    TaskInit(&task7, Task7Main, 0, 11, TASK_QUANTUM_7, taskStack7, sizeof(taskStack7));
#endif // _SHOW_SEMAPHORE_

#if defined(_SHOW_TIMER_SORTED_LIST_)
    TimerInit(&timer0, systemTick+TIMER_INTERVAL_0, TimerHandler0);
    TimerInit(&timer1, systemTick+TIMER_INTERVAL_1, TimerHandler1);
    TimerInit(&timer2, systemTick+TIMER_INTERVAL_2, TimerHandler2);
    TimerInit(&timer3, systemTick+TIMER_INTERVAL_3, TimerHandler3);
    TimerInit(&timer4, systemTick+TIMER_INTERVAL_4, TimerHandler4);
#endif // _SHOW_TIMER_SORTED_LIST_

    printAllReadyQ();
    return 0;
}



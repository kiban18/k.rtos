#include <config.h>
#include <kernel.h>
#include <timer.h>

#define ONE_MILLISECOND 70
#define ONE_SECOND ONE_MILLISECOND*1000


volatile unsigned int systemTick;
struct TimerListStruct timerList;


void InitTimer(void) {
    timerList.next = (struct TimerStruct *)&timerList;
    timerList.prev = (struct TimerStruct *)&timerList;
}


int TimerInit(struct TimerStruct *timer, unsigned int timeOut, void (*Handler)(void)) {
    unsigned int flag;

    timer->timeOut = timeOut;
    timer->Handler = Handler;

    flag = IntSaveDisableIRQ();

#if defined(_USE_SORTED_LIST_)
    struct TimerStruct *cur = timerList.next;
    while(1) {
        if (cur == (struct TimerStruct *)&timerList) {
            // TODO append timer to the end of the timerList
            timer->next = cur;
            timer->prev = cur->prev;
            cur->prev->next = timer;
            cur->prev = timer;
            break;
        }
        if (timer->timeOut <= cur->timeOut) {
            // TODO insert timer here
            timer->next = cur;
            timer->prev = cur->prev;
            cur->prev->next = timer;
            cur->prev = timer;
            break;
        }
        cur = cur->next;
    }
#else // _USE_NORMAL_LIST_
    timer->next = (struct TimerStruct *)&timerList;
    timer->prev = timerList.prev;
    timerList.prev->next = timer;
    timerList.prev = timer;
    IntRestoreIRQ(flag);
#endif // _USE_NORMAL_LIST_

    return 0;
}


void TimerTickHandler(void) {
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("[TimerTickHandler] systemTick(%d) ==>", systemTick);
#endif // DEBUG
    struct TimerStruct *timer = timerList.next;

#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf(" timerList->");
#endif // DEBUG
    while(1) {
        if (timer == (struct TimerStruct *)&timerList) {
            break;
        }
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
        printf("(%3d)->", timer->timeOut);
#endif // DEBUG

        if (timer->timeOut <= systemTick) {
            timer->prev->next = timer->next;
            timer->next->prev = timer->prev;
            timer->Handler();
        }

        timer = timer->next;
    }
#if defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("(NULL)\n");
#endif // DEBUG
}


void TickHandler(unsigned int irq) {
    TIMER0_INTCLR = 1;

    systemTick++;
#if defined(_SHOW_TIMER_SORTED_LIST_)
    TimerTickHandler();
#endif

#if defined(_SHOW_TASK_SCHED_ROUND_ROBIN_)
#if defined(_DEBUG_SHOW_TASK_SCHED_ROUND_ROBIN_) && !defined(_DEBUG_SHOW_TIMER_SORTED_LIST_)
    printf("[TickHandler] currentTask(%d)->count(%3d)\n", currentTask->timeQuantum, currentTask->count);
#endif // DEBUG
    if (!currentTask->count--) {
        currentTask->count = currentTask->timeQuantum;
        TaskDequeue(currentTask);
        TaskEnqueue(currentTask);
        DoScheduling();
    }
#endif
}


void InitTick(void) {
    VIC_INTENABLE = (VIC_INTENABLE | (1<<4));
    UART0_IMSC = 1<<4;
    TIMER0_LOAD = ONE_SECOND;
    TIMER0_CTRL = (TIMER_CTRL_ENABLE|TIMER_CTRL_IE|TIMER_CTRL_16BIT|TIMER_CTRL_FREERUN|TIMER_CTRL_DIV16);
}


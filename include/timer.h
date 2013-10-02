#ifndef __TIMER_H__
#define __TIMER_H__

#include <kernel.h>
#include <hw_timer.h>
#include <task.h>
#include <scheduler.h>
#include <interrupt.h>


struct TimerStruct {
	struct TimerStruct *next;
	struct TimerStruct *prev;

	unsigned int timeOut;
	void (*Handler)(void);
};


struct TimerListStruct {
	struct TimerStruct *next;
	struct TimerStruct *prev;
};


extern struct TimerListStruct timerList;
extern volatile unsigned int systemTick;


void InitTimer(void);
void InitTick(void);
int TimerInit(struct TimerStruct *timer, unsigned int timeOut, void (*Handler)(void));
void TimerTickHandler(void);
void TickHandler(unsigned int);


#endif /* __TIMER_H__ end. */


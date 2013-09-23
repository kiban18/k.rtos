
#ifndef __EVENT_H__
#define __EVENT_H__

#include <kernel.h>
#include <task.h>
#include <scheduler.h>


struct EventStruct {
    struct TaskStruct *waitQ[32];
};


int EventInit(struct EventStruct *event);
int EventSend(struct EventStruct *event, unsigned int num);
int EventWait(struct EventStruct *event, unsigned int num);


#endif /* __EVENT_H__ end. */




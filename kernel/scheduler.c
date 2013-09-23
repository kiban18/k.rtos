#include <kernel.h>
#include <scheduler.h>



struct TaskQStruct readyQ[CONFIG_MAX_PRIORITY];
struct TaskStruct *currentTask = &idleTask;


void InitScheduler(void) {

}



struct TaskStruct *TaskSelect(void) {

}



int TaskEnqueue(struct TaskStruct *task) {

}



int TaskDequeue(struct TaskStruct *task) {

}



int TaskWait(struct TaskQStruct *waitQ, struct TaskStruct *task) {

}



int TaskWakeupAll(struct TaskQStruct *waitQ) {

}



void ContextSwitch(struct TaskStruct *currentTask, struct TaskStruct *nextTask) {

}




void DoScheduling(void) {

}




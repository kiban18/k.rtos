#include <kernel.h>
#include <task.h>
#include <interrupt.h>


struct TaskStruct idleTask;
struct TaskStruct initTask;
unsigned char idle_stack[CONFIG_TASK_STACK_SIZE];
unsigned char initStack[CONFIG_TASK_STACK_SIZE];



int InitTask(void) {

}



int TaskInit(struct TaskStruct *task, int (*StartFunction)(void *), void *args, unsigned int prio,
                unsigned char *stackAddr, unsigned int stackSize) {

}



void TaskInitContext(struct TaskStruct *task) {

}



int TaskExit(void) {

}



struct TaskStruct *TaskGetID(void) {

}


int TaskYield(void) {

}






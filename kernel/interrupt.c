#include <kernel.h>
#include <task.h>
#include <interrupt.h>
#include <timer.h>
#include <util.h>


unsigned char exceptStack_fiq[CONFIG_EXCEPT_STACK_SIZE];
unsigned char exceptStack_irq[CONFIG_EXCEPT_STACK_SIZE];
unsigned char exceptStack_abort[CONFIG_EXCEPT_STACK_SIZE];
unsigned char exceptStack_system[CONFIG_EXCEPT_STACK_SIZE];
unsigned char exceptStack_undefine[CONFIG_EXCEPT_STACK_SIZE];

void (*isrTable[96])(void);



void InitInterrupt(void) {
    //TODO: init  interrupt controller register
       VIC_INTENABLE = 1<<4 | 1<<12;
   
		UART0_IMSC = 1<<4;

        TIMER0_LOAD = 0XFFFF;
        TIMER0_CTRL = (TIMER_CTRL_ENABLE|TIMER_CTRL_IE|TIMER_CTRL_16BIT|TIMER_CTRL_FREERUN|TIMER_CTRL_DIV16); // enable
 
}



void IntCommonHandler(void) {
	currentTask->count--;
	printf("[IntCommonHandler] currentTask->timeQuantum:%d, count:%d\n", currentTask->timeQuantum, currentTask->count);
	if (currentTask->count <= 0) {
		TaskDequeue(currentTask);
		currentTask->count = currentTask->timeQuantum;
		TaskEnqueue(currentTask);
		DoScheduling();
	}
}



void IntUnknownHandler(void) {
}



unsigned int IntSaveDisableIRQ(void) {
	return 0;
}



void IntRestoreIRQ(unsigned int flag) {
}



void IntEnable(void) {
}



void IntDisable(void) {
}




void IntSetHandler(int intNum, void (*handler)(void)) {
}



void IntSetHandlerAndUnmask(int intNum, void (*handler)(void)) {
	IntSetHandler(intNum, handler);
	IntUnmask(intNum);
}



void IntUnmask(int intNum) {
}



void IntMask(int intNum) {
}



void IntClearPend(int intNum) {
}



void IntGetPends(unsigned int *pend0, unsigned int *pend1, unsigned int *pend2) {
}





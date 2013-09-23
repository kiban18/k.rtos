#include <kernel.h>
#include <task.h>
#include <interrupt.h>
#include <timer.h>
#include <util.h>


unsigned char exception_stack[CONFIG_EXCEPT_STACK_SIZE];

void (*isrTable[96])(void);



void InitInterrupt(void) {
}



void IntCommonHandler(void) {
}



void IntUnknownHandler(void) {
}



unsigned int IntSaveDisableIRQ(void) {
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





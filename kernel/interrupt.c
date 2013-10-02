#include <config.h>
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


void (*isrTable[32])(unsigned int) = {
    IntUnknownHandler,  // 0
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    TickHandler,        // 4
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,  // 10
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,  // 20
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,
    IntUnknownHandler,  // 30
    IntUnknownHandler
};


void InitInterrupt(void) {
#if 0
    // TODO: This is moved to InitTick() in timer.c
    VIC_INTENABLE = 1<<4 | 1<<12;

    UART0_IMSC = 1<<4;

    TIMER0_LOAD = 0XFFFF;
    TIMER0_CTRL = (TIMER_CTRL_ENABLE|TIMER_CTRL_IE|TIMER_CTRL_16BIT|TIMER_CTRL_FREERUN|TIMER_CTRL_DIV16);
#endif
}


void IntCommonHandler(void) {
    unsigned int irqPend;
    int i;

    irqPend = VIC_INTSTATUS;

    for (i=0; i<32; i++) {
        if (irqPend & (1<<i)) {
            isrTable[i](i);
        }
    }
}


void IntUnknownHandler(unsigned int irq) {
    printf("Unknown INTERRUPT!:0x08%X", irq);
}


unsigned int IntSaveDisableIRQ(void) {
    unsigned int ret;

    __asm__ __volatile__ (
            "mrs    %0, cpsr\n"
            "mov    r1, %0\n"
            "orr    r1, r1, #0xC0\n"
            "msr    cpsr, r1\n"
            : "=r" (ret)
            );

    return ret;
}


void IntRestoreIRQ(unsigned int flag) {
    __asm__ __volatile__ (
            "msr    cpsr, r0\n"
            );
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


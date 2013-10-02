#include <config.h>
#include <kernel.h>
#include <scheduler.h>
#include <task.h>
#include <interrupt.h>
#include <timer.h>


volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;


int KernelMain(void) {
    printf("\n\n\nStart NOOS RTOS kernel...............\n");

#ifdef _SHOW_EXCEPTION_HANDLER_
    __asm__ __volatile__ (
            "SWI 0x121212\n"
            );
    return 0;
#endif // _SHOW_EXCEPTION_HANDLER_

    InitScheduler();
    InitTask();
    InitInterrupt();
    InitTick();
    InitTimer();

    TaskInit(&initTask, InitTaskMain, 0, CONFIG_MAX_PRIORITY - 1, 20, initStack, sizeof(initStack));

    while (1) {
        /* task idle */
        continue;
    }

    return 0;
}


void print_uart0(const char *s) {
     while(*s != '\0') { /* Loop until end of string */
        *UART0DR = (unsigned int)(*s); /* Transmit char */
        s++; /* Next char */
    }
}


int undefine_instruction(void) {
    printf("undefine_instruction\n");
}


int software_interrupt(void) {
    printf("software_interrupt\n");
}


int prefetch_abort(void) {
    printf("prefetch_abort\n");
}


int data_abort(void) {
    printf("data_abort\n");
}


int interrupt_request(void) {
    if(VIC_INTSTATUS & 0x10)
    {
        //printf("timer interrupt ocurred\n");
        // MOVED to the TickHandler in timer.c
#if 0
        TIMER0_INTCLR = 1;
#endif
        IntCommonHandler();
    }
    else if(VIC_INTSTATUS & 0X1000)
    {
        printf("UART interrupt ocurred\n");
        UART0_ICR = (1<<4) ;
    }
}


int fast_interrupt_request(void) {
    printf("fast_interrupt_request\n");
}


#include <kernel.h>
#include <scheduler.h>
#include <task.h>
#include <interrupt.h>
#include <timer.h>


unsigned int idle_count;
volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;
volatile unsigned int * const TEST = (unsigned int *)0xffffffff;

int KernelMain(void) {
    printf("\n\n\nStart NOOS RTOS kernel...............\n");

    InitScheduler();
    InitTask();
    //InitInterrupt();
    //InitTick();
    //InitTimer();

    TaskInit(&initTask, InitTaskMain, 0, CONFIG_MAX_PRIORITY - 1, initStack, sizeof(initStack));


    while (1) {
        /* task idle */
        continue;
    }

    return 0;
}

int kernel_main(void) {
	print_uart0("Hello world!\n");
    //print_uart0("\n\n\nStart NOOS RTOS kernel...............\n");
	//__asm__ __volatile__("MCR     p15,0,r0,c12,c0,0\n");
	//__asm__ __volatile__("mov pc,   #0x00000004\n");
	__asm__ __volatile__("SWI 0x121212\n");
/*
	while (1) {
        print_uart0("idle \n");
        //idle_count++;
    }
	*/
	
    return 0;
}

void print_test(const char *s) {
	 print_uart0("TEST!\n");
	 while(*s != '\0') { /* Loop until end of string */
		  *TEST = (unsigned int)(*s); /* Transmit char */
		   s++; /* Next char */
		    }
}

void print_uart0(const char *s) {
	 while(*s != '\0') { /* Loop until end of string */
		  *UART0DR = (unsigned int)(*s); /* Transmit char */
		   s++; /* Next char */
		    }
}
 
int undefine_instruction(void) {
	print_uart0("undefine_instruction\n");
}

int software_interrupt(void) {
	print_uart0("software_interrupt\n");
}

int prefetch_abort(void) {
	print_uart0("prefetch_abort\n");

}

int data_abort(void) {
	print_uart0("data_abort\n");

}

int interrupt_request(void) {
	print_uart0("interrupt_request\n");

}

int fast_interrupt_request(void) {
	print_uart0("fast_interrupt_request\n");

}


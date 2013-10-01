#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <kernel.h>
#include <util.h>
#include <arm_timer.h>

#define VIC_BASE_ADDR 0x10140000
#define VIC_INTENABLE (*((volatile unsigned int *)(VIC_BASE_ADDR + 0x010)))
#define VIC_INTSTATUS (*((volatile unsigned int *)(VIC_BASE_ADDR + 0x000)))

#define VERSATILE_TIMER0_1_BASE        0x101E2000   /* Timer 0 and 1 */
#define VERSATILE_TIMER2_3_BASE        0x101E3000   /* Timer 2 and 3 */

#define TIMER0_CTRL (*((volatile unsigned int *)(VERSATILE_TIMER0_1_BASE+TIMER_CTRL)))
#define TIMER0_INTCLR (*((volatile unsigned int *)(VERSATILE_TIMER0_1_BASE+TIMER_INTCLR)))
#define TIMER0_LOAD (*((volatile unsigned int *)(VERSATILE_TIMER0_1_BASE+TIMER_LOAD)))
#define TIMER0_VALUE (*((volatile unsigned int *)(VERSATILE_TIMER0_1_BASE+TIMER_VALUE)))



#define UART0_BASE_ADDR 0x101f1000
#define UART0_DR (*((volatile unsigned int *)(UART0_BASE_ADDR + 0x000)))
#define UART0_IMSC (*((volatile unsigned int *)(UART0_BASE_ADDR + 0x038)))
#define UART0_ICR (*((volatile unsigned int *)(UART0_BASE_ADDR + 0x044)))

extern unsigned char exceptStack[CONFIG_EXCEPT_STACK_SIZE];
extern void (*isrTable[96])(void);
extern volatile unsigned int systemTick;


void InitInterrupt(void);
unsigned int IntSaveDisableIRQ(void);
void IntRestoreIRQ(unsigned int flag);
void IntEnable(void);
void IntUnknownHandler(void);
void IntSetHandler(int intNum, void (*handler)(void));
void IntSetHandlerAndUnmask(int intNum, void (*handler)(void));
void IntUnmask(int intNum);
void IntMask(int intNum);
void IntClearPend(int intNum);
void IntGetPends(unsigned int *pend0, unsigned int *pend1, unsigned int *pend2);
void IntCommonHandler(void);


#endif /* __INTERRUPT_H__ end. */




#define __ASSEMBLY__


#include <kernel.h>


.text
.extern __text_start
.extern __bss_start
.extern __bss_end
.extern exception_stack
.extern idle_stack
.extern uart_putc
.extern kernel_main
.extern Clock_Controller_ASM_Init
.extern DDR2_SDRAM_ASM_Init
.extern UART0_ASM_Init
.extern CoSetExceptonVectoerBase

.global except_vec_start
.global except_vec_end




.align 4
except_vec_start:     
    ldr     pc, resetHandlerAddr
    ldr     pc, undefInsHandlerAddr
    ldr     pc, softIntHandlerAddr
    ldr     pc, preAbtHandlerAddr
    ldr     pc, dataAbtHandlerAddr
    b       .   @ reserved vector
    ldr     pc, irqHandlerAddr
    ldr     pc, fiqHandlerAddr

resetHandlerAddr:    .word resetHandler
undefInsHandlerAddr: .word undefInsHandler
softIntHandlerAddr:  .word softIntHandler
preAbtHandlerAddr:  .word preAbtHandler
dataAbtHandlerAddr:  .word dataAbtHandler
irqHandlerAddr:  .word irqHandler
fiqHandlerAddr:  .word fiqHandler

except_vec_end:

undefInsHandler:
    mov     lr, pc
    ldr     pc, =undefine_instruction
    b       .

softIntHandler:
    mov     lr, pc
    ldr     pc, =software_interrupt
    b       .

preAbtHandler:
    mov     lr, pc
    ldr     pc, =prefetch_abort
    b       .

dataAbtHandler:
	MCR     p15,0,r0,c12,c0,0
    mov     lr, pc
    ldr     pc, =data_abort
    b       .

irqHandler:
	MCR     p15,0,r0,c12,c0,0
    mov     lr, pc
    ldr     pc, =interrupt_request
    b       .

fiqHandler:
	MCR     p15,0,r0,c12,c0,0
    mov     lr, pc
    ldr     pc, =fast_interrupt_request
    b       .


resetHandler:
@    bl      init_cpu
@    bl      init_wdt
@    bl      init_memory
@    bl      init_gpio
@    bl		init_clock
@	 bl		init_uart
    bl      init_stack
    bl      init_execption_vector
    bl      init_bss

    /* start kernel main */
    mov     lr, pc
    ldr     pc, =kernel_main
    b       .
	



init_cpu:
    /* change SVC mode */
    mrs     r0, cpsr
    bic     r0, r0, #0x1f
    orr     r0, r0, #0xd3
    msr     cpsr, r0

    /* enable I-Cache */
	mrc	    p15, 0, r0, c1, c0, 0
	orr     r0, r0, #(1 << 12)
	mcr     p15, 0, r0, c1, c0, 0

    
    /* enable coprocessors */
	ldr     r0, =0xffffffff
	mcr     p15, 0, r0, c1, c0, 2

    /* globally enable NEON & VFP */
	mov     r0, #0x40000000
	@@fmxR    FPEXC, r0

    /* enable branch prediction */
	mrc     p15, 0, r0, c1, c0, 0
	orr     r0, r0, #(1 << 11)
	mcr     p15, 0, r0, c1, c0, 0

    mov     pc, lr




init_wdt:
	/* disable WDT(Watch Dog Timer) */
	ldr		r0, =WTCON
	mov		r1, #0x0
	str		r1, [r0]

    mov     pc, lr




init_memory:
	/* DDR2 drive strength setting */
	ldr		r5, =0xE03003CC	
	ldr		r1, =0x55A5
	str		r1, [r5]
	ldr		r5, =0xE03003EC
	ldr		r1, =0x5555
	str		r1, [r5]
	ldr		r5, =0xE030040C	
	str		r1, [r5]
	ldr		r5, =0xE030042C	
	str		r1, [r5]
	ldr		r5, =0xE030044C	
	str		r1, [r5]
	ldr		r5, =0xE030046C	
	str		r1, [r5]
	ldr		r5, =0xE030048C	
	str		r1, [r5]
	ldr		r5, =0xE03004AC	
	ldr		r1, =0xA955
	str		r1, [r5]
	ldr		r5, =0xE03004CC	
	ldr		r1, =0x2AAA
	str		r1, [r5]

	ldr		r5, =GPH0CON
	ldr		r1, =(1<<0)
	str		r1, [r5]
	ldr		r1, =1
	str		r1, [r5, #4] 

    mov     pc, lr




init_gpio:
	/* GPIO initialization */
	ldr		r0, =GPK1CON
	ldr		r1, =0x00002222
	str		r1, [r0]
	
	ldr		r0, =GPK3CON
	ldr		r1, =0x11111100
	str		r1, [r0]
	
	ldr		r0, =GPK3DAT
	mov		r1, #0x00000000
	str		r1, [r0]

	/* IO retention release */
	ldr		r0, =(ELFIN_CLOCK_POWER_BASE + OTHERS)
	ldr		r1, [r0]
	ldr		r2, =(1<<31)
	orr		r1, r1, r2
	str		r1, [r0]

    mov     pc, lr




init_clock:
    push    {lr}
    bl      Clock_Controller_ASM_Init
    pop     {lr}

    mov     pc, lr





init_uart:
    push    {lr}
    bl      UART0_ASM_Init
    pop     {lr}

    mov     pc, lr


init_execption_vector:
    push    {lr}
	/* exception vector address setting */
	ldr		r0, =except_vec_start
  	bl		CoSetExceptonVectoerBase
    pop     {lr}

    mov     pc, lr




init_stack:
    /* setup fiq mode stack */
    ldr     r0, =exception_stack
    ldr     r2, =CONFIG_EXCEPT_STACK_SIZE
    add     r0, r0, r2
    sub     r0, r0, #4

    mov     r1, #0xC0 | 0x11
    msr     cpsr, r1
    mov     sp, r0

    /* setup irq mode stack */
    mov     r1, #0xC0 | 0x12
    msr     cpsr, r1
    mov     sp, r0

    /* setup about mode stack */
    mov     r1, #0xC0 | 0x17
    msr     cpsr, r1
    mov     sp, r0

    /* setup undefine instrucation mode stack */
    mov     r1, #0xC0 | 0x1B
    msr     cpsr, r1
    mov     sp, r0

    /* setup system mode stack */
    mov     r1, #0xC0 | 0x1F
    msr     cpsr, r1
    mov     sp, r0

    /* setup idle task stack */
    mov     r1, #0xC0 | 0x13
    msr     cpsr,r1
    ldr     r0, =idle_stack
    ldr     r1, =CONFIG_TASK_STACK_SIZE
    add     r0, r0, r1
    sub     r0, r0, #4
    mov     sp, r0

    mov     pc, lr




init_bss:
    /* clear kernel bss */
    ldr     r0, =__bss_start
    ldr     r1, =__bss_end
    mov     r2, #0x0
2:
    cmp     r0, r1
    strle   r2, [r0], #4
    ble     2b

    mov     pc, lr




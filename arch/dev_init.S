//==============================================================================
// System Hardware Initialization Routines
//
// Date : 2009/11/28
//==============================================================================
#define __ASSEMBLY__

#include <hal.h>

    .text
	.global		DDR2_SDRAM_ASM_Init
	.global		Clock_Controller_ASM_Init
	.global		UART0_ASM_Init
//	.global		mem_ctrl_asm_init
	
.align 4
	
//------------------------------------------------------------------------------
// DDR2 SDRAM Initialization Function
//------------------------------------------------------------------------------
DDR2_SDRAM_ASM_Init:

	ldr	r0, =APB_DMC_BASE			//APB_DMC_BASE 0xE6000000
	
        ldr     r1, =0x6E101000                         //Phycontrol0 DLL parameter setting
        str     r1, [r0, #DMC_PHYCONTROL0]

        ldr     r1, =0x000000F4                         //Phycontrol1 DLL parameter setting
//        ldr     r1, =0x000000F6                        //Phycontrol1 DLL parameter setting

        str     r1, [r0, #DMC_PHYCONTROL1]

        ldr     r1, =0x00000000                         //Phycontrol2 DLL parameter setting
        str     r1, [r0, #DMC_PHYCONTROL2]

        ldr     r1, =0x6E101002                         //Dll on
        str     r1, [r0, #DMC_PHYCONTROL0]

        ldr     r1, =0x6E101003                         //dll start
        str     r1, [r0, #DMC_PHYCONTROL0]

wait_for_dll_locking:
	ldr		r2, [r0, #DMC_PHYSTATUS0]
	bic		r2, #0xfffffffb		
	mov		r2, r2, lsr #2
	cmp		r2, #0x1
	bne		wait_for_dll_locking

	ldr		r2, [r0, #DMC_PHYSTATUS0]
	bic		r2, #0xffffc03f		
	mov		r2, r2, lsr #6
	mov		r2,r2,lsl #24
	ldr		r1, =0x00101003
	orr		r1,r1,r2

	ldr		r4, =0xF4010000
	str		r1, [r4, #4]

		
//        ldr     r1, =0x54101003                         //Force Value locking
        str     r1, [r0, #DMC_PHYCONTROL0]

	ldr		r1, =0x00101001
	orr		r1,r1,r2
//        ldr     r1, =0x54101001                         //Dll off
        str     r1, [r0, #DMC_PHYCONTROL0]

        ldr     r1, =0x00FF2010                         //auto refresh off
        str     r1, [r0, #DMC_CONCONTROL]

        ldr     r1, =0x00212400                         // BL=4 , 2 chip , DDR2
        str     r1, [r0, #DMC_MEMCONTROL]

//#if 1	// add charles 512MB enable
        ldr     r1, =0x20E01323							// 512MB config , 8banks , linear, Row=14bit,COL=10bit
        str     r1, [r0, #DMC_MEMCONFIG0]

        ldr     r1, =0x40E00323
        str     r1, [r0, #DMC_MEMCONFIG1]
//#else	// 256MB enable
//        ldr     r1, =0x20F80313							// 128MB config , 8banks , linear, Row=13bit,COL=10bit
//        str     r1, [r0, #DMC_MEMCONFIG0]

//        ldr     r1, =0x40F80313
//        str     r1, [r0, #DMC_MEMCONFIG1]

//#endif
        ldr     r1, =0x20000000
        str     r1, [r0, #DMC_PRECHCONFIG]


//#ifdef	CONFIG_HCLKD0_222
//	ldr 	r1, =0x000006c3 						//7.8us*222MHz=0x6c3, 7.8us*166MHz=1294(0x50E)
//       str     r1, [r0, #DMC_TIMINGAREF]
////	/* T-rfc   127.5nS/5ns  64 */
//       ldr     r1, =0x202332C8                         		//TimingRow      @222MHz
//       str     r1, [r0, #DMC_TIMINGROW]
//
//       ldr     r1, =0x24450304							//CL=5
//       str     r1, [r0, #DMC_TIMINGDATA]
//
 //#else
//
	ldr	 r1, =0x0000050E						 //7.8us*200MHz=0x618, 7.8us*166MHz=1294(0x50E)
	str	 r1, [r0, #DMC_TIMINGAREF]

	ldr	 r1, =0x16233288						 //TimingRow 	 @166MHz
	str	 r1, [r0, #DMC_TIMINGROW]

	ldr	 r1, =0x24250304						 //CL=5
	str	 r1, [r0, #DMC_TIMINGDATA]
 //#endif

        ldr     r1, =0x07c80232                         //Timing Power
        str     r1, [r0, #DMC_TIMINGPOWER]

        ldr     r1, =0x07000000                         //chip0 Deselect
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x01000000                         //chip0 PALL
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x00020000                         //chip0 EMRS2
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x00030000                         //chip0 EMRS3
        str     r1, [r0, #DMC_DIRECTCMD]

	ldr     r1, =0x00010400                         //chip0 EMRS1 (MEM DLL on = DQS# disable)
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x00000552                         //chip0 MRS (MEM DLL reset) CL=5, Burst Length=4
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x01000000                         //chip0 PALL
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x05000000                         //chip0 REFA
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x05000000                         //chip0 REFA
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x00000452                         //chip0 MRS (MEM DLL unreset) , BL=4 , CL=5
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x00010780                         //chip0 EMRS1 (OCD default)
        str     r1, [r0, #DMC_DIRECTCMD]


// 	    ldr     r1, =0x00010400                         //chip0 EMRS1 (OCD exit)
	    ldr     r1, =0x00010402                         //chip0 EMRS1 (OCD exit)  Reduced Strength
//      ldr     r1, =0x00010000                         //chip0 EMRS1 (OCD exit)  ODT Disabled
//      ldr     r1, =0x00010440                         //chip0 EMRS1 (OCD exit)
        str     r1, [r0, #DMC_DIRECTCMD]

        ldr     r1, =0x00FF20B0                         //ConControl PHY driving , auto refresh on , out of order scheduling
        str     r1, [r0, #DMC_CONCONTROL]

        ldr     r1, =0x00100002                         //PwrdnConfig
        str     r1, [r0, #DMC_PWRDNCONFIG]

        ldr     r1, =0xFF212400                         //MemControl
        str     r1, [r0, #DMC_MEMCONTROL]

        mov pc, lr
//------------------------------------------------------------------------------
	
//------------------------------------------------------------------------------
// System Clock Initialization Function
//------------------------------------------------------------------------------
Clock_Controller_ASM_Init:

	ldr	r0, =ELFIN_CLOCK_POWER_BASE

	mov	r1, #0xe00
	orr	r1, r1, #0x10
	str	r1, [r0, #APLL_MASK]
	str	r1, [r0, #MPLL_MASK]
	str	r1, [r0, #EPLL_MASK]
	str	r1, [r0, #HPLL_MASK]

	ldr	r1, =CLK_DIV0_VAL
	str	r1, [r0, #CLK_DIV0]

	ldr	r1, =APLL_VAL
	str	r1, [r0, #APLL_CON]

	ldr	r1, =CLK_DIV1_VAL
	str	r1, [r0, #CLK_DIV1]

	ldr	r1, =MPLL_VAL
	str	r1, [r0, #MPLL_CON]
	
	ldr	r1, =EPLL_VAL
	str	r1, [r0, #EPLL_CON]
	
	ldr	r1, =HPLL_VAL
	str	r1, [r0, #HPLL_CON]

	ldr	r1, [r0, #CLK_SRC0]
	ldr	r2, =0x1111
	orr	r1, r1, r2
	str	r1, [r0, #CLK_SRC0]

	mov	r1, #0x10000
1:	sub	r1, r1, #1
    cmp r1, #0
	bne	1b

	mov	pc, lr
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// UART Channel[0] Initialization Function
//------------------------------------------------------------------------------
UART0_ASM_Init:

	// GPIO Setting for UART0
	ldr	r0, =ELFIN_GPIO_BASE
	ldr	r1, [r0]
	ldr 	r2, =(0xF<<12|0xF<<8|0xF<<4|0xF)
	bic	r1, r1, r2
	ldr	r2, =(2<<12|2<<8|2<<4|2)
	orr	r1, r1, r2 
	str   	r1, [r0, #GPA0CON]

	ldr	r0, =ELFIN_UART_BASE
	mov	r1, #0x0
	str	r1, [r0, #UFCON0]
	str	r1, [r0, #UMCON0]

	mov	r1, #0x3
	str	r1, [r0, #ULCON0]

	ldr	r1, =0x245
	str	r1, [r0, #UCON0]

	ldr	r1, =0x23
	str	r1, [r0, #UBRDIV0]

	ldr	r1, =0x3
	str	r1, [r0, #UDIVSLOT0]

1:	ldr	r1, [r0, #UTRSTAT0]
	bic	r1, r1, #0xfffffffd
	mov r1, r1, lsr #1
	cmp r1, #1
	bne 1b
//	ldr	r1, =0x4d4d4d4d
//	str	r1, [r0, #UTXH0]

	mov	pc, lr
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// void uart_putc(int data)//
//------------------------------------------------------------------------------
	.global uart_putc
uart_putc:
	ldr	r3, =ELFIN_UART_BASE
1:	ldr	r1, [r3, #UTRSTAT0]
	bic	r1, r1, #0xfffffffd
	mov r1, r1, lsr #1
	cmp r1, #1
	bne 1b
	str	r0, [r3, #UTXH0]
	mov pc, lr
//------------------------------------------------------------------------------

//int get_pc(void)
	.global get_pc
get_pc:
	mov r0, pc
	mov pc, lr
	

//==============================================================================
// S5PC100 SFR Address Definition
//
// Date : 2009/11/28
//==============================================================================

//--------------------------------------------------
// DRAM Control Registers
//--------------------------------------------------
#define APB_DMC_BASE				0xE6000000
#define DMC_CONCONTROL			0x00
#define DMC_MEMCONTROL			0x04
#define DMC_MEMCONFIG0			0x08
#define DMC_MEMCONFIG1			0x0C
#define DMC_DIRECTCMD			0x10
#define DMC_PRECHCONFIG			0x14
#define DMC_PHYCONTROL0			0x18
#define DMC_PHYCONTROL1			0x1C
#define DMC_PHYCONTROL2			0x20
#define DMC_PWRDNCONFIG 			0x28
#define DMC_TIMINGAREF  			0x30
#define DMC_TIMINGROW   			0x34
#define DMC_TIMINGDATA  			0x38
#define DMC_TIMINGPOWER 			0x3C
#define DMC_PHYSTATUS0  			0x40
#define DMC_PHYSTATUS1  			0x44
#define DMC_CHIP0STATUS  			0x48
#define DMC_CHIP1STATUS  			0x4C
#define DMC_AREFSTATUS  			0x50
#define DMC_MRSTATUS  			0x54
#define DMC_PHYTEST0  			0x58
#define DMC_PHYTEST1  			0x5C
//--------------------------------------------------

//--------------------------------------------------
// Clock Control Registers
//--------------------------------------------------
#define ELFIN_CLOCK_POWER_BASE		0xE0100000
#define APLL_MASK				0x0000
#define MPLL_MASK				0x0004
#define EPLL_MASK				0x0008
#define HPLL_MASK				0x000C

#define APLL_CON				0x0100
#define MPLL_CON				0x0104
#define EPLL_CON				0x0108
#define HPLL_CON				0x010C

#define CLK_SRC0				0x0200
#define CLK_SRC1				0x0204
#define CLK_SRC2				0x0208
#define CLK_SRC3				0x020C

#define CLK_DIV0				0x0300
#define CLK_DIV1				0x0304
#define CLK_DIV2				0x0308
#define CLK_DIV3				0x030C
#define CLK_DIV4				0x0310

#define CLK_OUT				0x0400

#define CLK_GATE_D0_0				0x0500
#define CLK_GATE_D0_1				0x0504
#define CLK_GATE_D0_2				0x0508

#define CLK_GATE_D1_0				0x0520
#define CLK_GATE_D1_1				0x0524
#define CLK_GATE_D1_2				0x0528
#define CLK_GATE_D1_3				0x052C
#define CLK_GATE_D1_4				0x0530
#define CLK_GATE_D1_5				0x0534

#define CLK_GATE_D2_0				0x0540

#define CLK_GATE_SCLK_0			0x0560
#define CLK_GATE_SCLK_1			0x0564

// Power Management Control Registers
#define OTHERS				0x8200
//--------------------------------------------------

//---------------------------------------------------
// UART Channel[0] Control Registers
//---------------------------------------------------
#define ELFIN_UART_BASE			0XEC000000
#define ULCON0					0x0000
#define UCON0					0x0004
#define UFCON0					0x0008
#define UMCON0				0x000C
#define UTRSTAT0				0x0010
#define UERSTAT0				0x0014
#define UFSTAT0				0x0018
#define UMSTAT0				0x001C
#define UTXH0					0x0020
#define URXH0					0x0024
#define UBRDIV0				0x0028
#define UDIVSLOT0				0x002C
#define UINTP0					0x0030
#define UINTSP0				0x0034
#define UINTM0					0x0038
//---------------------------------------------------

//---------------------------------------------------
// Port Group GPA0 Configuration Register
//---------------------------------------------------
#define ELFIN_GPIO_BASE			0xE0300000
#define GPA0CON				0x0000
#define GPA0DAT				0x0004
#define GPA0PULL				0x0008
#define GPA0DRV				0x000C
#define GPA0PDNCON				0x0010
#define GPA0PDNPULL				0x0014
//---------------------------------------------------

//---------------------------------------------------
// Watch Dog Timer Controll Registers
//---------------------------------------------------
#define WTCON					0xEA200000
//---------------------------------------------------

//---------------------------------------------------
// Static Memory Controller(SMC) Control Registers
//---------------------------------------------------
#define ELFIN_SROM_BASE			0xE7000000
#define SROM_BW				0x00
#define SROM_BC0				0x04
#define SROM_BC1				0x08
#define SROM_BC2				0x0C
#define SROM_BC3				0x10
#define SROM_BC4				0x14
#define SROM_BC5				0x18
//---------------------------------------------------

//---------------------------------------------------
// Vectored Interrupt Controller(VIC) Control Registers
//---------------------------------------------------
#define VIC0_ADDRESS				0xE4000F00
//---------------------------------------------------

//---------------------------------------------------
// GPIO Control Registers
//---------------------------------------------------
#define GPK1CON				0xE03002C0
#define GPK3CON				0xE0300300
#define GPK3DAT				0xE0300304
#define GPH0CON				0xE0300C00

//---------------------------------------------------


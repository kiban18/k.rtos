//==============================================================================
// S5PC100 SFR Address Definition
// File Name : C100RegAddr.h
// Date : 2009/11/28
//==============================================================================
#ifndef __C100REGADDR_H__
#define __C100REGADDR_H__


//enum SFR_BASE
//{
#define 	POST_BASE        0

#define	ONDC_BASE        0xb0000000

#define	CHIP_ID_BASE     0xe0000000
#define	SYSCON_BASE      0xe0100000
#define	ALIVE_BASE       0xe0200000
#define	GPIO_BASE        0xe0300000
#define	IEM_APC_BASE     0xe1000000
#define	IEM_IEC_BASE     0xe1100000

#define	INTC_BASE        0xe4000000		
//	INTC_A_BASE      0xe4000000
//	INTC_B_BASE      0xe4100000
//	INTC_C_BASE      0xe4200000

#define	EBI_BASE         0x0
#define	NFCSTON_BASE     0x0
#define	LPCON_BASE       0xe6000000
#define	PL340x32_BASE    0xe6100000
#define	PL340x64_BASE    0xe6200000
#define	SMC_BASE         0xe7000000
#define	ONC_BASE         0xe7100000
#define	NFCON_BASE       0xe7200000
#define	CFCON_BASE       0xe7800000
	
#define	MDMA_BASE        0xe8100000
#define	DMA_A_BASE       0xe9000000
#define	DMA_B_BASE       0xe9200000
#define	DMA_D_BASE       0x0

#define	TIMER_BASE       0xea000000,
#define	SYSTIMER_BASE    0xea100000,
#define	WDT_BASE         0xea200000,
#define	RTC_BASE         0xea300000,

#define	UART_A_BASE      0xec000000
#define	UART_B_BASE      0xec000400
#define	UART_C_BASE      0xec000800
#define	UART_D_BASE      0xec000c00
#define	I2C_BASE         0xec100000
#define	I2C_A_BASE       0xec100000
#define	I2C_B_BASE       0xec200000 // For HDMI
#define	SPI_A_BASE       0xec300000
#define	SPI_B_BASE       0xec400000
#define	SPI_C_BASE       0xec500000
#define	IRDA_BASE        0xec600000
#define	HSI_TX_BASE      0xec900000
#define	HSI_RX_BASE      0xeca00000
#define	DSIM_BASE        0xecb00000
#define	CSI_S_BASE       0xecc00000
#define	USBOTG_BASE      0xed200000
#define	USBDEV_BASE      0xed200000
#define	USBPHYC_BASE     0xed300000
#define	MODEMIF_BASE     0xed500000
#define	SDHC_A_BASE      0xed800000
#define	SDHC_B_BASE      0xed900000
#define	SDHC_C_BASE      0xeda00000

#define	LCDC_BASE        0xee000000
#define	ROT_BASE         0xee100000
#define	CAMIF_BASE       0xee200000
#define	CAMIF_A_BASE     0xee200000
#define	CAMIF_B_BASE     0xee300000
#define	CAMIF_C_BASE     0xee400000
#define	JPEG_BASE        0xee500000
#define	G2D_BASE         0xee800000
#define	G3D_BASE         0xef000000
#define	SDOUT_BASE       0xf0000000
#define	VP_BASE          0xf0100000
#define	MIXER_BASE       0xf0200000
#define	HDMISS_BASE      0xf0300000
#define	MFC_BASE         0xf1000000	

#define	I2S_A_BASE       0xf2000000
#define	I2S_B_BASE       0xf2100000
#define	I2S_C_BASE       0xf2200000
#define	AC97_BASE        0xf2300000
#define	PCM_A_BASE       0xf2400000
#define	PCM_B_BASE       0xf2500000
#define	SPDIF_BASE       0xf2600000
#define	TSADC_BASE       0xf3000000
#define	KEYPADIF_BASE    0xf3100000
#define	GPS_BASE         0xf3800000 // Cellguide

#define	SEC_BASE		 0xf4000000 

#define	APB_ST           0x0
#define	APB_LMT          0x0
//};

// GPIO Control Registers
#define rGPA0CON	(*((volatile unsigned int *)0xE0300000))
#define rGPA0DAT		(*((volatile unsigned int *)0xE0300004))
#define rGPA0PULL	(*((volatile unsigned int *)0xE0300008))
#define rGPA0DRV		(*((volatile unsigned int *)0xE030000C))

#define rGPA1CON	(*((volatile unsigned int *)0xE0300020))
#define rGPA1DAT		(*((volatile unsigned int *)0xE0300024))
#define rGPA1PULL	(*((volatile unsigned int *)0xE0300028))
#define rGPA1DRV		(*((volatile unsigned int *)0xE030002C))

#define rGPBCON			__REG(0xE0300040)	// Port Group GPB Configuration Register 0x00000000
#define rGPBDAT			__REG(0xE0300044)	// Port Group GPB Data Register -
#define rGPBPULL		__REG(0xE0300048)	// Port Group GPB Pull-up/down Register 0x5555
#define rGPBDRV			__REG(0xE030004C)	// Port Group GPB Drive strength control Register 0x0000
#define rGPBPDNCON		__REG(0xE0300050)	// Port Group GPB power down mode configuration register 0x00
#define rGPBPDNPULL	__REG(0xE0300054)	// Port Group GPB power down mode pull-up/down register 0x00

#define rGPCCON			__REG(0xE0300060)	//  R/W GPC Configuration 0x00000000
#define rGPCDAT			__REG(0xE0300064)	//  R/W GPC Data -
#define rGPCPULL		__REG(0xE0300068)	//  R/W GPC Pull-up/down 0x0155
#define rGPCDRV			__REG(0xE030006C)	//  R/W GPC Drive strength control 0x0000
#define rGPCPDNCON		__REG(0xE0300070)	//  R/W GPC Configuration at power down modes 0x00
#define rGPCPDNPULL	__REG(0xE0300074)	//  R/W GPC Pulling control at power down modes 0x00

#define rGPDCON		(*((volatile unsigned int *)0xE0300080))
#define rGPDDAT		(*((volatile unsigned int *)0xE0300084))
#define rGPDPULL	(*((volatile unsigned int *)0xE0300088))
#define rGPDDRV		(*((volatile unsigned int *)0xE030008C))

#define rGPE0CON		__REG(0xE03000A0)	// R/W Port Group GPE0 Configuration Register 0x00000000
#define rGPE0DAT			__REG(0xE03000A4)	// R/W Port Group GPE0 Data Register -
#define rGPE0PULL		__REG(0xE03000A8)	// R/W Port Group GPE0 Pull-up/down Register 0x5555
#define rGPE0DRV		__REG(0xE03000AC)	// R/W Port Group GPE0 Drive strength control Register 0x0000
#define rGPE0PDNCON	__REG(0xE03000B0)	// R/W Port Group GPE0 Power down mode Configuration Register 0x00
#define rGPE0PDNPULL	__REG(0xE03000B4)	// R/W Port Group GPE0 Power down mode Pullup/down Register 0x00
#define rGPE1CON		__REG(0xE03000C0)	// R/W Port Group GPE1 Configuration Register 0x00000000
#define rGPE1DAT			__REG(0xE03000C4)	// R/W Port Group GPE1 Data Register -
#define rGPE1PULL		__REG(0xE03000C8)	// R/W Port Group GPE1 Pull-up/down Register 0x0555
#define rGPE1DRV		__REG(0xE03000CC)	// R/W Port Group GPE1 Drive strength control Register 0x0000
#define rGPE1PDNCON	__REG(0xE03000D0)	// R/W Port Group GPE1 Power down mode Configuration Register 0x00
#define rGPE1PDNPULL	__REG(0xE03000D4)	// R/W Port Group GPE1 Power down mode Pullup/down Register 0x00

#define rGPF0CON		__REG(0xE03000E0)	// Port Group GPF0 Configuration Register 0x00000000
#define rGPF0DAT			__REG(0xE03000E4)	// Port Group GPF0 Data Register Don’t care
#define rGPF0PULL		__REG(0xE03000E8)	// Port Group GPF0 Pull-up/down Register 0x5555
#define rGPF0DRV			__REG(0xE03000EC)	// Port Group GPF0 Drive strength control Register 0x0000
#define rGPF0PDNCON	__REG(0xE03000F0)	// Port Group GPF0 Power down mode Configuration Register 0x00
#define rGPF0PDNPULL	__REG(0xE03000F4)	// Port Group GPF0 Power down mode Pullup/down Register 0x00
#define rGPF1CON		__REG(0xE0300100)	// Port Group GPF1 Configuration Register 0x00000000
#define rGPF1DAT			__REG(0xE0300104)	// Port Group GPF1 Data Register -
#define rGPF1PULL		__REG(0xE0300108)	// Port Group GPF1 Pull-up/down Register 0x5555
#define rGPF1DRV			__REG(0xE030010C)	// Port Group GPF1 Drive strength control Register 0x0000
#define rGPF1PDNCON	__REG(0xE0300110)	// Port Group GPF1 Power down mode Configuration Register 0x00
#define rGPF1PDNPULL	__REG(0xE0300114)	// Port Group GPF1 Power down mode Pullup/down Register 0x00
#define rGPF2CON		__REG(0xE0300120)	// Port Group GPF2 Configuration Register 0x00000000
#define rGPF2DAT			__REG(0xE0300124)	// Port Group GPF2 Data Register -
#define rGPF2PULL		__REG(0xE0300128)	// Port Group GPF2 Pull-up/down Register 0x5555
#define rGPF2DRV			__REG(0xE030012C)	// Port Group GPF2 Drive strength control Register 0x0000
#define rGPF2PDNCON	__REG(0xE0300130)	// Port Group GPF2 Power down mode Configuration Register 0x00
#define rGPF2PDNPULL	__REG(0xE0300134)	// Port Group GPF2 Power down mode Pullup/down Register 0x00
#define rGPF3CON		__REG(0xE0300140)	// Port Group GPF3 Configuration Register 0x00000000
#define rGPF3DAT			__REG(0xE0300144)	// Port Group GPF3 Data Register -
#define rGPF3PUD		__REG(0xE0300148)	// Port Group GPF3 Pull-up/down Register 0x0055
#define rGPF3DRV			__REG(0xE030014C)	// Port Group GPF3 Drive strength control Register 0x0000
#define rGPF3PDNCON	__REG(0xE0300150)	// Port Group GPF3 Power down mode Configuration Register 0x00
#define rGPF3PDNPULL	__REG(0xE0300154)	// Port Group GPF3 Power down mode Pullup/down Register 0x00

#define rGPH0CON	(*((volatile unsigned int *)0xE0300C00))
#define rGPH0DAT	(*((volatile unsigned int *)0xE0300C04))
#define rGPH0PULL	(*((volatile unsigned int *)0xE0300C08))
#define rGPH0DRV	(*((volatile unsigned int *)0xE0300C0C))

#define rGPH1CON	(*((volatile unsigned int *)0xE0300C20))
#define rGPH1DAT	(*((volatile unsigned int *)0xE0300C24))
#define rGPH1PULL	(*((volatile unsigned int *)0xE0300C28))
#define rGPH1DRV	(*((volatile unsigned int *)0xE0300C2C))

#define rGPH3CON	(*((volatile unsigned int *)0xE0300C60))
#define rGPH3DAT	(*((volatile unsigned int *)0xE0300C64))
#define rGPH3PULL	(*((volatile unsigned int *)0xE0300C68))
#define rGPH3DRV	(*((volatile unsigned int *)0xE0300C6C))

// for SD on SLOT
#define rGPJ1CON	(*((volatile unsigned int *)0xE0300220))
#define rGPJ1DAT	(*((volatile unsigned int *)0xE0300224))
#define rGPJ1PULL	(*((volatile unsigned int *)0xE0300228))
#define rGPJ1DRV	(*((volatile unsigned int *)0xE030022C))

// for KEYPAD 3*5
#define rGPJ2CON	(*((volatile unsigned int *)0xE0300240))
#define rGPJ2DAT	(*((volatile unsigned int *)0xE0300244))
#define rGPJ2PULL	(*((volatile unsigned int *)0xE0300248))
#define rGPJ2DRV	(*((volatile unsigned int *)0xE030024C))

// for SENSOR SLOT
#define rGPJ3CON	(*((volatile unsigned int *)0xE0300260))
#define rGPJ3DAT	(*((volatile unsigned int *)0xE0300264))
#define rGPJ3PULL	(*((volatile unsigned int *)0xE0300268))
#define rGPJ3DRV	(*((volatile unsigned int *)0xE030026C))

#define rGPJ4CON		__REG(0xE0300280)	//   R/W GPJ4 Configuration 0x00000000
#define rGPJ4DAT			__REG(0xE0300284)	//   R/W GPJ4 Data -
#define rGPJ4PULL		__REG(0xE0300288)	//   R/W GPJ4 Pull-up/down 0x0055
#define rGPJ4DRV			__REG(0xE030028C)	//   R/W GPJ4 Drive strength control 0x0000
#define rGPJ4PDNCON	__REG(0xE0300290)	//   R/W GPJ4 Configuration at power down modes 0x00
#define rGPJ4PDNPULL	__REG(0xE0300294)	//   R/W GPJ4 Pulling control at power down modes 0x00

#define rGPK0CON		__REG(0xE03002A0)	//  R/W GPK0 Configuration 0x22443322
#define rGPK0DAT		__REG(0xE03002A4)	//  R/W GPK0 Data -
#define rGPK0PULL		__REG(0xE03002A8)	//  R/W GPK0 Pull-up/down 0x0000
#define rGPK0DRV		__REG(0xE03002AC)	//  R/W GPK0 Drive strength control 0xAAAA
#define rGPK0PDNCON	__REG(0xE03002B0)	//  R/W GPK0 Configuration at power down modes 0x00
#define rGPK0PDNPULL	__REG(0xE03002B4)	//  R/W GPK0 Pulling control at power down modes 0x00
#define rGPK1CON		__REG(0xE03002C0)	//  R/W GPK1 Configuration 0x222222
#define rGPK1DAT		__REG(0xE03002C4)	//  R/W GPK1 Data -
#define rGPK1PULL		__REG(0xE03002C8)	//  R/W GPK1 Pull-up/down 0x0020
#define rGPK1DRV		__REG(0xE03002CC)	//  R/W GPK1 Drive strength control 0x0AAA
#define rGPK1PDNCON	__REG(0xE03002D0)	//  R/W GPK1 Configuration at power down modes 0x00
#define rGPK1PDNPULL	__REG(0xE03002D4)	//  R/W GPK1 Pulling control at power down modes 0x00
#define rGPK2CON		__REG(0xE03002E0)	//  R/W GPK2 Configuration 0x22223333
#define rGPK2DAT		__REG(0xE03002E4)	//  R/W GPK2 Data -
#define rGPK2PULL		__REG(0xE03002E8)	//  R/W GPK2 Pull-up/down 0xA500
#define rGPK2DRV		__REG(0xE03002EC)	//  R/W GPK2 Drive strength control 0xAAAA
#define rGPK2PDNCON	__REG(0xE03002F0)	//  R/W GPK2 Configuration at power down modes 0x00
#define rGPK2PDNPULL	__REG(0xE03002F4)	//  R/W GPK2 Pulling control at power down modes 0x00
#define rGPK3CON		__REG(0xE0300300)	//  R/W GPK3 Configuration 0x22222222
#define rGPK3DAT		__REG(0xE0300304)	//  R/W GPK3 Data -
#define rGPK3PUD		__REG(0xE0300308)	//  R/W GPK3 Pull-up/down 0x0885
#define rGPK3DRV		__REG(0xE030030C)	//  R/W GPK3 Drive strength control 0xAAAA
#define rGPK3PDNCON	__REG(0xE0300310)	//  R/W GPK3 Configuration at power down modes 0x00
#define rGPK3PDNPULL	__REG(0xE0300314)	//  R/W GPK3 Pulling control at power down modes 0x00

// Wake Up Interrupt Registers
#define rWKUP_INT0_7_CON		(*((volatile unsigned int *)0xE0300E00))
#define rWKUP_INT8_15_CON		(*((volatile unsigned int *)0xE0300E04))
#define rWKUP_INT16_23_CON		(*((volatile unsigned int *)0xE0300E08))
#define rWKUP_INT24_31_CON		(*((volatile unsigned int *)0xE0300E0C))

#define rWKUP_INT0_7_MASK		(*((volatile unsigned int *)0xE0300F00))
#define rWKUP_INT8_15_MASK		(*((volatile unsigned int *)0xE0300F04))
#define rWKUP_INT16_23_MASK		(*((volatile unsigned int *)0xE0300F08))
#define rWKUP_INT24_31_MASK		(*((volatile unsigned int *)0xE0300F0C))

#define rWKUP_INT0_7_PEND		(*((volatile unsigned int *)0xE0300F40))
#define rWKUP_INT8_15_PEND		(*((volatile unsigned int *)0xE0300F44))
#define rWKUP_INT16_23_PEND		(*((volatile unsigned int *)0xE0300F48))
#define rWKUP_INT24_31_PEND		(*((volatile unsigned int *)0xE0300F4C))

// I2C Control Registers
#define rI2CCON0		(*((volatile unsigned int *)0xEC100000))
#define rI2CSTAT0		(*((volatile unsigned int *)0xEC100004))
#define rI2CADD0		(*((volatile unsigned int *)0xEC100008))
#define rI2CDS0		(*((volatile unsigned int *)0xEC10000C))
#define rI2CLC0		(*((volatile unsigned int *)0xEC100010))

// UART Control Registers
#define rULCON0				(*((volatile unsigned int *)0xEC000000))	//UART Channel 0 Line Control Register 0x00
#define rUCON0				(*((volatile unsigned int *)0xEC000004))	//UART Channel 0 Control Register 0x00
#define rUFCON0				(*((volatile unsigned int *)0xEC000008))	//UART Channel 0 FIFO Control Register 0x0
#define rUMCON0				(*((volatile unsigned int *)0xEC00000C))	//UART Channel 0 Modem Control Register 0x0
#define rUTRSTAT0			(*((volatile unsigned int *)0xEC000010))	//UART Channel 0 Tx/Rx Status Register 0x6
#define rUERSTAT0			(*((volatile unsigned int *)0xEC000014))	//UART Channel 0 Rx Error Status Register 0x0
#define rUFSTAT0			(*((volatile unsigned int *)0xEC000018))	//UART Channel 0 FIFO Status Register 0x00
#define rUMSTAT0			(*((volatile unsigned int *)0xEC00001C))	//UART Channel 0 Modem Status Register 0x0
#define rUTXH0				(*((volatile unsigned char *)0xEC000020))	//UART Channel 0 Transmit Buffer Register -
#define rURXH0				(*((volatile unsigned char *)0xEC000024))	//UART Channel 0 Receive Buffer Register 0x00
#define rUBRDIV0			(*((volatile unsigned int *)0xEC000028))	//UART Channel 0 Baud Rate Divisior Register 0x0000
#define rUDIVSLOT0			(*((volatile unsigned int *)0xEC00002C))	//UART Channel 0 Dividing Slot Register 0x0000
#define rUINTP0				(*((volatile unsigned int *)0xEC000030))	//UART Channel 0 Interrupt Pending Register 0x0
#define rUINTSP0			(*((volatile unsigned int *)0xEC000034))	//UART Channel 0 Interrupt Source Pending Register 0x0
#define rUINTM0				(*((volatile unsigned int *)0xEC000038))	//UART Channel 0 Interrupt Mask Register 0x0

//--------------------------------------------------
// Clock Control Registers
//--------------------------------------------------
#define rAPLL_MASK			(*((volatile unsigned int *)0xE0100000))
#define rMPLL_MASK			(*((volatile unsigned int *)0xE0100004))
#define rEPLL_MASK			(*((volatile unsigned int *)0xE0100008))
#define rHPLL_MASK			(*((volatile unsigned int *)0xE010000C))

#define rAPLL_CON			(*((volatile unsigned int *)0xE0100100))
#define rMPLL_CON			(*((volatile unsigned int *)0xE0100104))
#define rEPLL_CON			(*((volatile unsigned int *)0xE0100108))
#define rHPLL_CON			(*((volatile unsigned int *)0xE010010C))

#define rCLK_SRC0			(*((volatile unsigned int *)0xE0100200))
#define rCLK_SRC1			(*((volatile unsigned int *)0xE0100204))
#define rCLK_SRC2			(*((volatile unsigned int *)0xE0100208))
#define rCLK_SRC3			(*((volatile unsigned int *)0xE010020C))

#define rCLK_DIV0			(*((volatile unsigned int *)0xE0100300))
#define rCLK_DIV1			(*((volatile unsigned int *)0xE0100304))
#define rCLK_DIV2			(*((volatile unsigned int *)0xE0100308))
#define rCLK_DIV3			(*((volatile unsigned int *)0xE010030C))
#define rCLK_DIV4			(*((volatile unsigned int *)0xE0100310))

#define rCLK_OUT			(*((volatile unsigned int *)0xE0100400))

#define rCLK_GATE_D0_0		(*((volatile unsigned int *)0xE0100500))
#define rCLK_GATE_D0_1		(*((volatile unsigned int *)0xE0100504))
#define rCLK_GATE_D0_2		(*((volatile unsigned int *)0xE0100508))

#define rCLK_GATE_D1_0		(*((volatile unsigned int *)0xE0100520))
#define rCLK_GATE_D1_1		(*((volatile unsigned int *)0xE0100524))
#define rCLK_GATE_D1_2		(*((volatile unsigned int *)0xE0100528))
#define rCLK_GATE_D1_3		(*((volatile unsigned int *)0xE010052C))
#define rCLK_GATE_D1_4		(*((volatile unsigned int *)0xE0100530))
#define rCLK_GATE_D1_5		(*((volatile unsigned int *)0xE0100534))

#define rCLK_GATE_D2_0		(*((volatile unsigned int *)0xE0100540))

#define rCLK_GATE_SCLK_0	(*((volatile unsigned int *)0xE0100560))
#define rCLK_GATE_SCLK_1	(*((volatile unsigned int *)0xE0100564))

#define rSWRESET			(*((volatile unsigned int *)0xE0200000))

#define rONENAND_SWRESET	(*((volatile unsigned int *)0xE0200008))

#define rGENERAL_CTRL		(*((volatile unsigned int *)0xE0200100))
#define rGENERAL_STATUS	(*((volatile unsigned int *)0xE0200104))

#define rCAM_MUX_SEL		(*((volatile unsigned int *)0xE0200300))
#define rMIXER_OUT_SEL		(*((volatile unsigned int *)0xE0200304))
#define rLPMP3_MODE_SEL	(*((volatile unsigned int *)0xE0200308))

#define rMIPI_PHY_CON0		(*((volatile unsigned int *)0xE0200400))

#define rMIPI_PHY_CON1		(*((volatile unsigned int *)0xE0200414))

#define rHDMI_PHY_CON0		(*((volatile unsigned int *)0xE0200420))
//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
|  VIC Control Registers
------------------------------------------------------------------------------*/
//	VIC[0]
#define rVIC0IRQSTATUS			(*((volatile unsigned int *)0xE4000000))	//Status Register 0x00000000
#define rVIC0FIQSTATUS			(*((volatile unsigned int *)0xE4000004))	//FIQ Status Register 0x00000000
#define rVIC0RAWINTR				(*((volatile unsigned int *)0xE4000008))	//Raw Interrupt Status Register -
#define rVIC0INTSELECT			(*((volatile unsigned int *)0xE400000C))	//Interrupt Select Register 0x00000000
#define rVIC0INTENABLE			(*((volatile unsigned int *)0xE4000010))	//Interrupt Enable Register 0x00000000
#define rVIC0INTENCLEAR			(*((volatile unsigned int *)0xE4000014))	//Interrupt Enable Clear Register -
#define rVIC0SOFTINT				(*((volatile unsigned int *)0xE4000018))	//Software Interrupt Register 0x00000000
#define rVIC0SOFTINTCLEAR		(*((volatile unsigned int *)0xE400001C))	//Software Interrupt Clear Register -
#define rVIC0PROTECTION			(*((volatile unsigned int *)0xE4000020))	//Protection Enable Register 0x0
#define rVIC0SWPRIORITYMASK	(*((volatile unsigned int *)0xE4000024))	//Software Priority Mask Register 0xFFFF
#define rVIC0PRIORITYDAISY		(*((volatile unsigned int *)0xE4000028))	//Vector Priority Register for Daisy Chain 0xF
// Start of Vector Address Register[0-31]
#define rVIC0VECTADDR0			(*((volatile unsigned int *)0xE4000100))	//Vector Address 0 Register 0x00000000
// Start of Vector Priority Register[0-31]
#define rVIC0VECPRIORITY0		(*((volatile unsigned int *)0xE4000200))	// Vector Priority 0 Register 0xF
#define rVIC0ADDRESS			(*((volatile unsigned int *)0xE4000F00))	// Vector Address Register 0x00000000

//	VIC[1]
#define rVIC1IRQSTATUS			(*((volatile unsigned int *)0xE4100000))	//Status Register 0x00000000
#define rVIC1FIQSTATUS			(*((volatile unsigned int *)0xE4100004))	//FIQ Status Register 0x00000000
#define rVIC1RAWINTR				(*((volatile unsigned int *)0xE4100008))	//Raw Interrupt Status Register -
#define rVIC1INTSELECT			(*((volatile unsigned int *)0xE410000C))	//Interrupt Select Register 0x00000000
#define rVIC1INTENABLE			(*((volatile unsigned int *)0xE4100010))	//Interrupt Enable Register 0x00000000
#define rVIC1INTENCLEAR			(*((volatile unsigned int *)0xE4100014))	//Interrupt Enable Clear Register -
#define rVIC1SOFTINT				(*((volatile unsigned int *)0xE4100018))	//Software Interrupt Register 0x00000000
#define rVIC1SOFTINTCLEAR		(*((volatile unsigned int *)0xE410001C))	//Software Interrupt Clear Register -
#define rVIC1PROTECTION			(*((volatile unsigned int *)0xE4100020))	//Protection Enable Register 0x0
#define rVIC1SWPRIORITYMASK	(*((volatile unsigned int *)0xE4100024))	//Software Priority Mask Register 0xFFFF
#define rVIC1PRIORITYDAISY		(*((volatile unsigned int *)0xE4100028))	//Vector Priority Register for Daisy Chain 0xF
// Start of Vector Address Register[0-31]
#define rVIC1VECTADDR0			(*((volatile unsigned int *)0xE4100100))	//Vector Address 0 Register 0x00000000
// Start of Vector Priority Register[0-31]
#define rVIC1VECPRIORITY0		(*((volatile unsigned int *)0xE4100200))	// Vector Priority 0 Register 0xF
#define rVIC1ADDRESS			(*((volatile unsigned int *)0xE4100F00))	// Vector Address Register 0x00000000

//	VIC[2]
#define rVIC2IRQSTATUS			(*((volatile unsigned int *)0xE4200000))	//Status Register 0x00000000
#define rVIC2FIQSTATUS			(*((volatile unsigned int *)0xE4200004))	//FIQ Status Register 0x00000000
#define rVIC2RAWINTR				(*((volatile unsigned int *)0xE4200008))	//Raw Interrupt Status Register -
#define rVIC2INTSELECT			(*((volatile unsigned int *)0xE420000C))	//Interrupt Select Register 0x00000000
#define rVIC2INTENABLE			(*((volatile unsigned int *)0xE4200010))	//Interrupt Enable Register 0x00000000
#define rVIC2INTENCLEAR			(*((volatile unsigned int *)0xE4200014))	//Interrupt Enable Clear Register -
#define rVIC2SOFTINT				(*((volatile unsigned int *)0xE4200018))	//Software Interrupt Register 0x00000000
#define rVIC2SOFTINTCLEAR		(*((volatile unsigned int *)0xE420001C))	//Software Interrupt Clear Register -
#define rVIC2PROTECTION			(*((volatile unsigned int *)0xE4200020))	//Protection Enable Register 0x0
#define rVIC2SWPRIORITYMASK	(*((volatile unsigned int *)0xE4200024))	//Software Priority Mask Register 0xFFFF
#define rVIC2PRIORITYDAISY		(*((volatile unsigned int *)0xE4200028))	//Vector Priority Register for Daisy Chain 0xF
// Start of Vector Address Register[0-31]
#define rVIC2VECTADDR0			(*((volatile unsigned int *)0xE4200100))	//Vector Address 0 Register 0x00000000
// Start of Vector Priority Register[0-31]
#define rVIC2VECPRIORITY0		(*((volatile unsigned int *)0xE4200200))	// Vector Priority 0 Register 0xF
#define rVIC2ADDRESS			(*((volatile unsigned int *)0xE4200F00))	// Vector Address Register 0x00000000
//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
|  PWM Timer Control Registers
------------------------------------------------------------------------------*/
#define rTCFG0			__REG(0xEA000000)
#define rTCFG1			__REG(0xEA000004)
#define rTCON			__REG(0xEA000008)
#define rTCNTB0			__REG(0xEA00000C)
#define rTCMPB0			__REG(0xEA000010)
#define rTCNTO0			__REG(0xEA000014)
#define rTCNTB1			__REG(0xEA000018)
#define rTCMPB1			__REG(0xEA00001C)
#define rTCNTO1			__REG(0xEA000020)
#define rTCNTB2			__REG(0xEA000024)
#define rTCMPB2			__REG(0xEA000028)
#define rTCNTO2			__REG(0xEA00002C)
#define rTCNTB3			__REG(0xEA000030)
#define rTCNTO3			__REG(0xEA000038)
#define rTCNTB4			__REG(0xEA00003C)
#define rTCNTO4			__REG(0xEA000040)
#define rTINT_CSTAT		__REG(0xEA000044)	//Timer Interrupt Control and Status Register 0x0000_0000
//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
|  LCD Control Registers
------------------------------------------------------------------------------*/
#define rVIDCON0				__REG(0xEE000000)	// Video control 0 register 0x0000_0000
#define rVIDCON1				__REG(0xEE000004)	// Video control 1 register 0x0000_0000
#define rVIDCON2				__REG(0xEE000008)	// Video control 2 register 0x0000_0000
#define rPRTCON				__REG(0xEE00000C)	// Protect Control register 0x0000_0000
#define rVIDTCON0			__REG(0xEE000010)	// Video time control 0 register 0x0000_0000
#define rVIDTCON1			__REG(0xEE000014)	// Video time control 1 register 0x0000_0000
#define rVIDTCON2			__REG(0xEE000018)	// Video time control 2 register 0x0000_0000
#define rWINCON0				__REG(0xEE000020)	// Window control 0 register 0x0000_0000
#define rWINCON1				__REG(0xEE000024)	// Window control 1 register 0x0000_0000
#define rWINCON2				__REG(0xEE000028)	// Window control 2 register 0x0000_0000
#define rWINCON3				__REG(0xEE00002C)	// Window control 3 register 0x0000_0000
#define rWINCON4				__REG(0xEE000030)	// Window control 4 register 0x0000_0000
#define rVIDOSD0A			__REG(0xEE000040)	// Video Window 0’s position control register 0x0000_0000
#define rVIDOSD0B			__REG(0xEE000044)	// Video Window 0’s position control register 0x0000_0000
#define rVIDOSD0C			__REG(0xEE000048)	// Video Window 0’s size control register 0x0000_0000
#define rVIDOSD1A			__REG(0xEE000050)	// Video Window 1’s position control register 0x0000_0000
#define rVIDOSD1B			__REG(0xEE000054)	// Video Window 1’s position control register 0x0000_0000
#define rVIDOSD1C			__REG(0xEE000058)	// Video Window 1’s alpha control register 0x0000_0000
#define rVIDOSD1D			__REG(0xEE00005C)	// Video Window 1’s size control register 0x0000_0000
#define rVIDOSD2A			__REG(0xEE000060)	// Video Window 2’s position control register 0x0000_0000
#define rVIDOSD2B			__REG(0xEE000064)	// Video Window 2’s position control register 0x0000_0000
#define rVIDOSD2C			__REG(0xEE000068)	// Video Window 2’s alpha control register 0x0000_0000
#define rVIDOSD2D			__REG(0xEE00006c)	// Video Window 2’s size control register 0x0000_0000
#define rVIDOSD3A			__REG(0xEE000070)	// Video Window 3’s position control register 0x0000_0000
#define rVIDOSD3B			__REG(0xEE000074)	// Video Window 3’s position control register 0x0000_0000
#define rVIDOSD3C			__REG(0xEE000078)	// Video Window 3’s alpha control register 0x0000_0000
#define rVIDOSD4A			__REG(0xEE000080)	// Video Window 4’s position control register 0x0000_0000
#define rVIDOSD4B			__REG(0xEE000084)	// Video Window 4’s position control register 0x0000_0000
#define rVIDOSD4C			__REG(0xEE000088)	// Video Window 4’s alpha control register 0x0000_0000
#define rVIDW00ADD0B0		__REG(0xEE0000A0)	// Window 0’s buffer start address register, buffer0 0x0000_0000
#define rVIDW00ADD0B1		__REG(0xEE0000A4)	// Window 0’s buffer start address register, buffer1 0x0000_0000
#define rVIDW01ADD0B0		__REG(0xEE0000A8)	// Window 1’s buffer start address register, buffer0 0x0000_0000
#define rVIDW01ADD0B1		__REG(0xEE0000AC)	// Window 1’s buffer start address register, buffer1 0x0000_0000
#define rVIDW02ADD0			__REG(0xEE0000B0)	// Window 2’s buffer start address register 0x0000_0000
#define rVIDW03ADD0			__REG(0xEE0000B8)	// Window 3’s buffer start address register 0x0000_0000
#define rVIDW04ADD0			__REG(0xEE0000C0)	// Window 4’s buffer start address register 0x0000_0000
#define rVIDW00ADD1B0		__REG(0xEE0000D0)	// Window 0’s buffer end address register, buffer 0 0x0000_0000
#define rVIDW00ADD1B1		__REG(0xEE0000D4)	// Window 0’s buffer end address register, buffer 1 0x0000_0000
#define rVIDW01ADD1B0		__REG(0xEE0000D8)	// Window 1’s buffer end address register, buffer 0 0x0000_0000
#define rVIDW01ADD1B1		__REG(0xEE0000DC)	// Window 1’s buffer end address register, buffer 1 0x0000_0000
#define rVIDW02ADD1			__REG(0xEE0000E0)	// Window 2’s buffer end address register 0x0000_0000
#define rVIDW03ADD1			__REG(0xEE0000E8)	// Window 3’s buffer end address register 0x0000_0000
#define rVIDW04ADD1			__REG(0xEE0000F0)	// Window 4’s buffer end address register 0x0000_0000
#define rVIDW00ADD2			__REG(0xEE000100)	// Window 0’s buffer size register 0x0000_0000
#define rVIDW01ADD2			__REG(0xEE000104)	// Window 1’s buffer size register 0x0000_0000
#define rVIDW02ADD2			__REG(0xEE000108)	// Window 2’s buffer size register 0x0000_0000
#define rVIDW03ADD2			__REG(0xEE00010C)	// Window 3’s buffer size register 0x0000_0000
#define rVIDW04ADD2			__REG(0xEE000110)	// Window 4’s buffer size register 0x0000_0000
#define rVP1TCON0			__REG(0xEE000118)	// VP 1 interface timing control 0 register 0x0000_0000
#define rVP1TCON1			__REG(0xEE00011c)	// VP 1 interface timing control 1 register 0x0000_0000
#define rVIDINTCON0			__REG(0xEE000130)	// Indicate the Video interrupt control register 0x0000_0000
#define rVIDINTCON1			__REG(0xEE000134)	// Video Interrupt Pending register 0x0000_0000
#define rW1KEYCON0			__REG(0xEE000140)	// Color key control register 0x0000_0000
#define rW1KEYCON1			__REG(0xEE000144)	// Color key value ( transparent value) register 0x0000_0000
#define rW2KEYCON0			__REG(0xEE000148)	// Color key control register 0x0000_0000
#define rW2KEYCON1			__REG(0xEE00014C)	// Color key value (transparent value) register 0x0000_0000
#define rW3KEYCON0			__REG(0xEE000150)	// Color key control register 0x0000_0000
#define rW3KEYCON1			__REG(0xEE000154)	// Color key value (transparent value) register 0x0000_0000
#define rW4KEYCON0			__REG(0xEE000158)	// Color key control register 0x0000_0000
#define rW4KEYCON1			__REG(0xEE00015C)	// Color key value (transparent value) register 0x0000_0000
#define rDITHMODE			__REG(0xEE000170)	// Dithering mode register. 0x0000_0000
#define rWIN0MAP				__REG(0xEE000180)	// Window color control 0x0000_0000
#define rWIN1MAP				__REG(0xEE000184)	// Window color control 0x0000_0000
#define rWIN2MAP				__REG(0xEE000188)	// Window color control 0x0000_0000
#define rWIN3MAP				__REG(0xEE00018C)	// Window color control 0x0000_0000
#define rWIN4MAP				__REG(0xEE000190)	// Window color control 0x0000_0000
#define rWPALCON_H			__REG(0xEE00019c)	// Window Palette control register 0x0000_0000
#define rWPALCON_L			__REG(0xEE0001A0)	// Window Palette control register 0x0000_0000

#define rTRIGCON			__REG(0xEE0001A4)	// I80 / RGB Trigger Control Register 0x0000_0000
#define rITUIFCON			__REG(0xEE0001A8)	// ITU-R (BT.601/656) Interface Control Register 0x0000_0000
#define rI80IFCONA0			__REG(0xEE0001B0)	// I80 Interface control 0 for Main LDI 0x0000_0000
#define rI80IFCONA1			__REG(0xEE0001B4)	// I80 Interface control 0 for Sub LDI 0x0000_0000
#define rI80IFCONB0			__REG(0xEE0001B8)	// I80 Interface control 1 for Main LDI 0x0000_0000
#define rI80IFCONB1			__REG(0xEE0001BC)	// I80 Interface control 1 for Sub LDI 0x0000_0000
#define rLDI_CMDCON0		__REG(0xEE0001D0)	// I80 Interface LDI Command Control 0 0x0000_0000
#define rLDI_CMDCON1		__REG(0xEE0001D4)	// I80 Interface LDI Command Control 1 0x0000_0000
#define rSIFCCON0			__REG(0xEE0001E0)	// LCD i80 System Interface Command Control 0 0x0000_0000
#define rSIFCCON1			__REG(0xEE0001E4)	// LCD i80 System Interface Command Control 1 0x0000_0000
#define rSIFCCON2			__REG(0xEE0001E8)	// LCD i80 System Interface Command Control 2 0x0000_0000
#define rVIDW0ALPHA0			__REG(0xEE000200)	// Window 0’s alpha value 0 register 0x0000_0000
#define rVIDW0ALPHA1			__REG(0xEE000204)	// Window 0’s alpha value 1 register 0x0000_0000
#define rVIDW1ALPHA0			__REG(0xEE000208)	// Window 1’s alpha value 0 register 0x0000_0000
#define rVIDW1ALPHA1			__REG(0xEE00020c)	// Window 1’s alpha value 1 register 0x0000_0000
#define rVIDW2ALPHA0			__REG(0xEE000210)	// Window 2’s alpha value 0 register 0x0000_0000
#define rVIDW2ALPHA1			__REG(0xEE000214)	// Window 2’s alpha value 1 register 0x0000_0000
#define rVIDW3ALPHA0			__REG(0xEE000218)	// Window 3’s alpha value 0 register 0x0000_0000
#define rVIDW3ALPHA1			__REG(0xEE00021c)	// Window 3’s alpha value 1 register 0x0000_0000
#define rVIDW4ALPHA0			__REG(0xEE000220)	// Window 4’s alpha value 0 register 0x0000_0000
#define rVIDW4ALPHA1			__REG(0xEE000224)	// Window 4’s alpha value 1 register 0x0000_0000
#define rBLENDEQ1			__REG(0xEE000244)	// Window 1’s blending equation Control register 0x0000_00c2
#define rBLENDEQ2			__REG(0xEE000248)	// Window 2’s blending equation Control register 0x0000_00c2
#define rBLENDEQ3			__REG(0xEE00024c)	// Window 3’s blending equation Control register 0x0000_00c2
#define rBLENDEQ4			__REG(0xEE000250)	// Window 4’s blending equation Control register 0x0000_00c2
#define rBLENDCON			__REG(0xEE000260)	// Blending Control register 0x0000_0000
#define rLDI_CMD0			__REG(0xEE000280)	// I80 Interface LDI Command 0 0x0000_0000
#define rLDI_CMD1			__REG(0xEE000284)	// I80 Interface LDI Command 1 0x0000_0000
#define rLDI_CMD2			__REG(0xEE000288)	// I80 Interface LDI Command 2 0x0000_0000
#define rLDI_CMD3			__REG(0xEE00028C)	// I80 Interface LDI Command 3 0x0000_0000
#define rLDI_CMD4			__REG(0xEE000290)	// I80 Interface LDI Command 4 0x0000_0000
#define rLDI_CMD5			__REG(0xEE000294)	// I80 Interface LDI Command 5 0x0000_0000
#define rLDI_CMD6			__REG(0xEE000298)	// I80 Interface LDI Command 6 0x0000_0000
#define rLDI_CMD7			__REG(0xEE00029C)	// I80 Interface LDI Command 7 0x0000_0000
#define rLDI_CMD8			__REG(0xEE0002A0)	// I80 Interface LDI Command 8 0x0000_0000
#define rLDI_CMD9			__REG(0xEE0002A4)	// I80 Interface LDI Command 9 0x0000_0000
#define rLDI_CMD10			__REG(0xEE0002A8)	// I80 Interface LDI Command 10 0x0000_0000
#define rLDI_CMD11			__REG(0xEE0002AC)	// I80 Interface LDI Command 11 0x0000_0000
//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
|  AC97 Control Registers
------------------------------------------------------------------------------*/
#define rAC_GLBCTRL			__REG(0xF2300000)	//  R/W AC97 Global Control Register 0x00000000
#define rAC_GLBSTAT			__REG(0xF2300004)	//  R AC97 Global Status Register 0x00000001
#define rAC_CODEC_CMD		__REG(0xF2300008)	//  R/W AC97 Codec Command Register 0x00000000
#define rAC_CODEC_STAT		__REG(0xF230000C)	//  R AC97 Codec Status Register 0x00000000
#define rAC_PCMADDR		__REG(0xF2300010)	//  R AC97 PCM Out/In Channel FIFO Address Register 0x00000000
#define rAC_MICADDR			__REG(0xF2300014)	//  R AC97 Mic In Channel FIFO Address Register 0x00000000
#define rAC_PCMDATA			__REG(0xF2300018)	//  R/W AC97 PCM Out/In Channel FIFO Data Register 0x00000000
#define rAC_MICDATA			__REG(0xF230001C)	//  R/W AC97 MIC In Channel FIFO Data Register 0x00000000
//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
|  CAM I/F Control Registers
------------------------------------------------------------------------------*/
#define rCISRCFMT(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x00)		// R/W Input Source Format 0x0000_0000
#define rCIWDOFST(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x04)		// R/W Window offset register 0x0000_0000
#define rCIGCTRL(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x08)		// R/W Global control register 0x2001_0080
#define rCIWDOFST2(x)		__REG(CAMIF_A_BASE+(x*0x100000)+0x14)		// R/W Window offset register 2 0x0000_0000
#define rCIOYSA1(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x18)		// R/W Y 1st frame start address for output DMA 0x0000_0000
#define rCIOYSA2(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x1C)		// R/W Y 2nd frame start address for output DMA 0x0000_0000
#define rCIOYSA3(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x20)		// R/W Y 3rd frame start address for output DMA 0x0000_0000
#define rCIOYSA4(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x24)		// R/W Y 4th frame start address for output DMA 0x0000_0000
#define rCIOCBSA1(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x28)		// R/W Cb 1st frame start address for output DMA 0x0000_0000
#define rCIOCBSA2(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x2c)		// R/W Cb 2nd frame start address for output DMA 0x0000_0000
#define rCIOCBSA3(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x30)		// R/W Cb 3rd frame start address for output DMA 0x0000_0000
#define rCIOCBSA4(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x34)		// R/W Cb 4th frame start address for output DMA 0x0000_0000
#define rCIOCRSA1(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x38)		// R/W Cr 1st frame start address for output DMA 0x0000_0000
#define rCIOCRSA2(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x3c)		// R/W Cr 2nd frame start address for output DMA 0x0000_0000
#define rCIOCRSA3(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x40)		// R/W Cr 3rd frame start address for output DMA 0x0000_0000
#define rCIOCRSA4(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x44)		// R/W Cr 4th frame start address for output DMA 0x0000_0000
#define rCITRGFMT(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x48)		// R/W Target image format 0x0000_0000
#define rCIOCTRL(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x4c)		// R/W Output DMA control related 0x0000_0000
#define rCISCPRERATIO(x)		__REG(CAMIF_A_BASE+(x*0x100000)+0x50)		// R/W Pre-scaler control 1 0x0000_0000
#define rCISCPREDST(x)		__REG(CAMIF_A_BASE+(x*0x100000)+0x54)		// R/W Pre-scaler control 2 0x0000_0000
#define rCISCCTRL(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x58)		// R/W Main-scaler control 0x1800_0000
#define rCITAREA(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x5c)		// R/W Target area 0x0000_0000
#define rCISTATUS(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x64)		// R/W Status register 0x0000_0000
#define rCIIMGCPT(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0xc0)		// R/W Image capture enable command 0x0000_0000
#define rCICPTSEQ(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0xc4)		// R/W Capture sequence related 0xFFFF_FFFF
#define rCIIMGEFF(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0xd0)		// R/W Image Effects related 0x0010_0080
#define rCIIYSA0(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0xd4)		// R/W Y frame start address for Input DMA 0x0000_0000
#define rCIICBSA0(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0xd8)		// R/W Cb frame start address for Input DMA 0x0000_0000
#define rCIICRSA0(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0xdc)		// R/W Cr frame start address for Input DMA 0x0000_0000
#define rCIREAL_ISIZE(x)		__REG(CAMIF_A_BASE+(x*0x100000)+0xf8)		// R/W Real Input DMA image size 0x0000_0000
#define rMSCTRL(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0xfc)		// R/W Input DMA control register 0x0400_0000
#define rCIOYOFF(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x168)	// R/W Output DMA Y offset 0x0000_0000
#define rCIOCBOFF(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x16c)	// R/W Output DMA Cb offset 0x0000_0000
#define rCIOCROFF(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x170)	// R/W Output DMA Cr offset 0x0000_0000
#define rCIIYOFF(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x174)	// R/W Input DMA Y offset 0x0000_0000
#define rCIICBOFF(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x178)	// R/W Input DMA Cb offset 0x0000_0000
#define rCIICROFF(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x17c)	// R/W Input DMA Cr offset 0x0000_0000
#define rORGISIZE(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x180)	// R/W Input DMA original image size 0x0000_0000
#define rORGOSIZE(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x184)	// R/W Output DMA original image size 0x0000_0000
#define rCIEXTEN(x)			__REG(CAMIF_A_BASE+(x*0x100000)+0x188)	// R/W Real Output DMA image size 0x0000_0000
#define rCIDMAPARAM(x)		__REG(CAMIF_A_BASE+(x*0x100000)+0x18c)	// R/W DMA Parameter register 0x0000_0000
#define rCSIIMGFMT(x)		__REG(CAMIF_A_BASE+(x*0x100000)+0x194)	// R/W MIPI CSI image format register 0x0000_001E
//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
|  MFC(Multi-Format Codec) Control Registers
------------------------------------------------------------------------------*/
//DMA/STREAM REGISTER
#define rDMA_START					__REG(0xF1000000)	// R/W DMA Start Register 0x0000_0000
#define rDMA_INTERNAL_ADDR		__REG(0xF1000008)	/* C100 Manual에는 없는 Register, SMDK Source 참고 */
#define rBOOTCODE_SIZE			__REG(0xF100000C)	// R/W Firmware Size Register 0x0000_0000
#define rDMA_EXTADDR				__REG(0xF1000014)	// R/W DMA External Memory Address Register 0x0000_0000
#define rEXT_BUF_START_ADDR		__REG(0xF1000018)	// R/W External Buffer Start Address Register 0x0000_0000
#define rEXT_BUF_END_ADDR		__REG(0xF100001C)	// R/W External Buffer End Address Register 0x0000_0000
#define rDMA_INT_ADDR				__REG(0xF1000020)	// R/W Dma Internal Address Register 0x0000_0000
#define rHOST_PTR_ADDR			__REG(0xF1000024)	// R/W Host Pointer Address Register 0x0000_0000
#define rLAST_DEC					__REG(0xF1000028)	// R/W Last Decoding Control Register 0x0000_0000
#define rDONE_M					__REG(0xF100002C)	// R/W Done F/W transfer Register 0x0000_0000
#define rCODEC_PTR					__REG(0xF1000034)	/* C100 Manual에는 없는 Register, SMDK Source 참고 */
#define rENC_ENDADDR				__REG(0xF1000038)	/* C100 Manual에는 없는 Register, SMDK Source 참고 */
#define rBITS_ENDIAN				__REG(0xF1000044)	// R/W Dma Endian Setting Register 0x0000_0000
#define rEXT_BUF_THRESHOLD		__REG(0xF1000048)	/* C100 Manual에는 없는 Register, SMDK Source 참고 */
#define rDEC_UNIT_SIZE				__REG(0xF1000054)	// R/W Decoding Stream Unit Size Register 0x0000_0000
#define rENC_UNIT_SIZE				__REG(0xF1000058)	// R Encoded Stream Unit Size Register 0x0000_0000
#define rSTART_BYTE_NUM			__REG(0xF100005C)	// R/W Start Byte Number Register 0x0000_0000
#define rENC_HEADER_SIZE			__REG(0xF1000060)	// R Encoded Header Size Register 0x0000_0000

// COMMAND CONTORL
#define rSTD_SEL_REG				__REG(0xF1000100)	// R/W Standard Selection Register 0x0000_0000
#define rCH_ID						__REG(0xF1000104)	// R/W Channel ID Register 0x0000_0000
#define rCPU_RESET					__REG(0xF1000108)	// R/W Cpu Reset Register 0x0000_0000
#define rFW_END						__REG(0xF100010c)	// R/W Firmware End Register 0x0000_0000
#define rBUS_MASTER				__REG(0xF1000110)	// R/W Bus Master SettingRegister 0x0000_0000
#define rFRAME_START				__REG(0xF1000114)	// R/W Frame Start Register 0x0000_0000
#define rIMG_SIZE_X					__REG(0xF1000118)	// R/W Horizontal Image Size Register 0x0000_0000
#define rIMG_SIZE_Y					__REG(0xF100011C)	// R/W Vertical Image Size Register 0x0000_0000
#define rTEST_MODE					__REG(0xF1000120)	/* C100 Manual에는 없는 Register, SMDK Source 참고 */
#define rPOST_ON					__REG(0xF1000124)	// R/W Mpeg4 Post Filter On/Off Register 0x0000_0000
#define rFRAME_RATE				__REG(0xF1000128)	// R/W Frame Rate Setting Register 0x0000_0000
#define rSEQ_START					__REG(0xF100012C)	// R/W Sequence Start Control Register 0x0000_0000
#define rSW_RESET					__REG(0xF1000130)	// R/W Software Reset Register 0x0000_0000
#define rFW_START					__REG(0xF1000134)	// R/W Firmware Start Register 0x0000_0001
#define rARM_ENDIAN				__REG(0xF1000138)	// R/W Arm Endian Register 0x0000_0001
#define rERR_CTRL					__REG(0xF100013C)	// R/W Error Control Setting Register 0x0000_0000

// F/W ADDRESS
#define rFW_STT_ADDR_0			__REG(0xF1000200)	// R/W MPEG-4 encoder F/W Address Register 0x0000_0000
#define rFW_STT_ADDR_1			__REG(0xF1000204)	// R/W MPEG-4 Decoder F/W Address Register 0x0000_0000
#define rFW_STT_ADDR_2			__REG(0xF1000208)	// R/W H264 encoder F/W Address Register 0x0000_0000
#define rFW_STT_ADDR_3			__REG(0xF100020C)	// R/W H264 Decoder F/W Address Register 0x0000_0000
#define rFW_STT_ADDR_4			__REG(0xF1000210)	// R/W VC-1 Decoder F/W Address Register 0x0000_0000
#define rFW_STT_ADDR_5			__REG(0xF1000214)	// R/W MPEG-2 Decoder F/W Address Register 0x0000_0000
#define rFW_STT_ADDR_6			__REG(0xF1000218)	// R/W H263 Decoder F/W Address Register 0x0000_0000
#define rVSP_BUF_ADDR				__REG(0xF1000230)	// R/W VSP Working Buffer Address Register 0x0000_0000
#define rDB_STT_ADDR				__REG(0xF1000234)	// R/W Deblock Line Buffer Setting Address Register 0x0000_0000

// ENCODER CONTROL
#define rPROFILE						__REG(0xF1000300)	// R/W Profile Setting Register 0x0000_0000
#define rIDR_PERIOD					__REG(0xF1000304)	// R/W 0x0000_0000
#define rI_PERIOD					__REG(0xF1000308)	// R/W I-Picture Period Register 0x0000_0000
#define rFRAME_QP_INIT				__REG(0xF100030C)	// R/W Register 0x0000_0000
#define rH264_OPTION				__REG(0xF1000310)	// R/W Entropy Encoding Control Register 0x0000_0000
#define rDB_FILTER_OPTION			__REG(0xF1000314)	// R/W Deblocking Filter Control Register 0x0000_0000
#define rSHORT_HD_ON				__REG(0xF1000318)	// R/W Short Header On/Off Control Register 0x0000_0000
#define rMSLICE_ENA				__REG(0xF100031C)	// R/W Multi-Slice Enable Register 0x0000_0000
#define rMSLICE_SEL					__REG(0xF1000320)	// R/W Multi-Slice Selection Register 0x0000_0000
#define rMSLICE_MB					__REG(0xF1000324)	// R/W Multi-Slice Interval MB Register 0x0000_0000
#define rMSLICE_BYTE				__REG(0xF1000328)	// R/W Multi-Slice Interval Byte Register 0x0000_0000

// DECODER CONTROL
#define rDISPLAY_Y_ADDR			__REG(0xF1000400)	// R/W Display Luminace Address Register 0x0000_0000
#define rDISPLAY_C_ADDR			__REG(0xF1000404)	// R/W Display Chrominace Address Register 0x0000_0000
#define rDISPLAY_STATUS			__REG(0xF1000408)	// R/W Display Status Register 0x0000_0000
#define rHEADER_DONE				__REG(0xF100040C)	// R/W Header_done reading Register 0x0000_0000
#define rFRAME_NUM				__REG(0xF1000410)	// R/W Frame_Number Reading Register 0x0000_0000

// INTERRUPT CONTROL
#define rINT_OFF						__REG(0xF1000500)	// R/W Interrupt Control Register 0x0000_0000
#define rINT_MODE					__REG(0xF1000504)	// R/W Interrupt Level Selection Register 0x0000_0000
#define rINT_DONE_CLEAR			__REG(0xF1000508)	// R/W Interrupt Clear Register 0x0000_0000
#define rOPERATION_DONE			__REG(0xF100050C)	// R/W Operation Status Register 0x0000_0000
#define rFW_DONE					__REG(0xF1000510)	// R/W Firmware Status Register 0x0000_0000
#define rINT_STATUS					__REG(0xF1000514)	// R/W Interrupt Status Register 0x0000_0000
#define rINT_ENABLE					__REG(0xF1000518)	// R/W Interrupt Enable Register 0x0000_0000

// MEMORY CONTROLLER SETTING
#define rMEM_STRUCT_SET			__REG(0xF1000600)	// R/W Memoory Structure Setting Register 0x0000_0000

// ENCODER BUFFER ADDRESS
#define rENC_CUR_Y_ADDR			__REG(0xF1000800)	// R/W Encoder Current Y Buffer Address Register 0x0000_0000
#define rENC_CUR_CBCR_ADDR		__REG(0xF1000804)	// R/W Encoder Current C Buffer Address Register 0x0000_0000
#define rENC_DPB_ADDR				__REG(0xF100080C)	// R/W Encoder Dpb start Address Register 0x0000_0000
#define rCIR_MB_NUM				__REG(0xF1000810)	// R/W Intra Refresh Macroblock Number Register 0x0000_0000

// DECODER BUFFER ADDRESS
#define rDEC_DPB_ADDR				__REG(0xF1000900)	// R/W Decoder Decoded Picture Buffer Address Register 0x0000_0000
#define rDPB_COMV_ADDR			__REG(0xF1000904)	// R/W Colocated Motion Vector Buffer Address Register 0x0000_0000
#define rPOST_ADDR					__REG(0xF1000908)	// R/W Post Filter Output Address Setting Register 0x0000_0000
#define rDPB_SIZE					__REG(0xF100090C)	// R Decoded Picture Buffer Size Register 0x0000_0000

// MFCV4.0 VERSION
#define rRC_CONFIG					__REG(0xF1000a00)	// R/W Rate Control ConfigurationRegister 0x0000_0000
#define rRC_FRAME_RATE			__REG(0xF1000a04)	// R/W Rate Control Framerate Register 0x0000_0000
#define rRC_BIT_RATE				__REG(0xF1000a08)	// R/W Rate Control BitrateRegister 0x0000_0000
#define rRC_QBOUND				__REG(0xF1000a0C)	// R/W Quantizer Parameter Boundary Register 0x0000_0000
#define rRC_RPARA					__REG(0xF1000a10)	// R/W Reaction Coefficient Register 0x0000_0000
#define rRC_MB_CTRL				__REG(0xF1000a14)	// R/W MacroBlock Level Rate Control Register 0x0000_0000
#define rRC_QOUT					__REG(0xF1000a18)	// R/W Internal Reference Quantization Scale Register 0x0000_0000

// MFCV4.0 VERSION
#define rMFC4_VERSION				__REG(0xF1000b00)	// R/W MFC4 Version Register 0x0000_0040

// CROPPING INFORMATION
#define rCROP1						__REG(0xF1000C00)	// R/W Cropping Information 1 Register 0x0000_0000
#define rCROP2						__REG(0xF1000C04)	// R/W Cropping Information 2 Register 0x0000_0000
#define rDEC_FRM_SIZE				__REG(0xF1000C08)	// R/W Decoded Frame Size Register 0x0000_0000

// MULTI-CHANNEL COMMAND
#define rCOMMAND_TYPE			__REG(0XF1000D00)	// R/W Command Type Register 0x0000_0000

// MULTI-CHANNEL COMMAND
#define rFRAME_TYPE				__REG(0xF1000C0C)	// R Frame Type Register 0x0000_0000
#define rNUM_EXTRA_DPB			__REG(0xF1000D04)	// W Number Of Extra DPB Register 0x0000_0000
#define rCODEC_COMMAND			__REG(0xF1000D08)	// W Codec Command Register 0x0000_0000
//-----------------------------------------------------------------------------

// NAND
#define rNFSTAT					(*((volatile unsigned int *)0xE7200028))

// for SENSOR SLOT
#define rADCCON					(*((volatile unsigned int *)0xF3000000))
#define rADCTSC					(*((volatile unsigned int *)0xF3000004))
#define rADCDLY					(*((volatile unsigned int *)0xF3000008))
#define rADCDAT0				(*((volatile unsigned int *)0xF300000C))
#define rADCDAT1				(*((volatile unsigned int *)0xF3000010))

#define rADCMUX					(*((volatile unsigned int *)0xF300001C))

#endif

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <kernel.h>
#include <util.h>


#define INT_EINT0    	     0
#define INT_EINT1            1
#define INT_EINT2            2
#define INT_EINT3            3
#define INT_EINT4            4
#define INT_EINT5            5
#define INT_EINT6            6
#define INT_EINT7            7
#define INT_EINT8            8
#define INT_EINT9            9
#define INT_EINT10           10
#define INT_EINT11           11
#define INT_EINT12           12
#define INT_EINT13           13
#define INT_EINT14           14
#define INT_EINT15           15
#define INT_EINT16_31        16
#define INT_BATF             17
#define INT_MDMA             18
#define INT_DMA_A            19
#define INT_DMA_B            20   
#define INT_TIMER0           21
#define INT_TIMER1           22
#define INT_TIMER2           23
#define INT_TIMER3           24
#define INT_TIMER4           25
#define INT_SYS_TIMER        26   
#define INT_WDT              27
#define INT_RTC_ALARM        28
#define INT_RTC_TIC          29
#define INT_GPIO             30
#define INT_CORTEX0          32
#define INT_CORTEX1          33
#define INT_CORTEX2          34
#define INT_CORTEX3          35
#define INT_CORTEX4          36
#define INT_IEM_APC          37
#define INT_IEM_IEC          38   
#define INT_ONDC             39
#define INT_NFC              40
#define INT_CFC              41
#define INT_UART_A           42
#define INT_UART_B           43
#define INT_UART_C           44
#define INT_UART_D           45
#define INT_I2C              46
#define INT_SPI_A            47
#define INT_SPI_B            48
#define INT_SPI_C            49
#define INT_IRDA             50
#define INT_CAN_A            51
#define INT_CAN_B            52
#define INT_HSI_RX           53
#define INT_HSI_TX           54
#define INT_UHOST            55
#define INT_USB              56
#define INT_MSM              57
#define INT_SDHC_A           58
#define INT_SDHC_B           59
#define INT_SDHC_C           60
#define INT_MIPI_CSI_S       61
#define INT_MIPI_DSI_M       62
#define INT_LCD0             64
#define INT_LCD1             65
#define INT_LCD2             66
#define INT_LCD3             67
#define INT_ROTATOR          68
#define INT_CAMIF_A          69
#define INT_CAMIF_B          70
#define INT_CAMIF_C          71
#define INT_JPEG             72
#define INT_2D               73
#define INT_3D               74
#define INT_MIXER            75
#define INT_HDMI             76
#define INT_HDMI_I2C         77
#define INT_MFC              78
#define INT_TVENC            79   
#define INT_I2S_A            80
#define INT_I2S_B            81
#define INT_I2S_C            82
#define INT_AC97             83
#define INT_PCM_A            84
#define INT_PCM_B            85
#define INT_SPDIF            86
#define INT_ADC              87
#define INT_PENDN            88
#define INT_KEYPAD           89
#define INT_GPS              90
#define INT_SEC              91
#define INT_SEC_RX           92
#define INT_SEC_TX           93
#define INT_SDM_IRQ          94
#define INT_SDM_FIQ          95



#define intOutp32(offset, x) Outp32(offset, x)
#define intInp32(offset, x) Inp32(offset, x)


#define	INTC_A_BASE          	 INTC_BASE
#define	INTC_B_BASE          	 INTC_BASE+0x00100000
#define	INTC_C_BASE          	 INTC_BASE+0x00200000
                         	
#define	VIC0_IRQSTATUS       	 INTC_A_BASE+0x00
#define	VIC0_FIQSTATUS       	 INTC_A_BASE+0x04
#define	VIC0_RAWINTR         	 INTC_A_BASE+0x08
#define	VIC0_INTSELECT       	 INTC_A_BASE+0x0c // IRQ or FIQ
#define	VIC0_INTENABLE       	 INTC_A_BASE+0x10
#define	VIC0_INTENCLEAR      	 INTC_A_BASE+0x14
#define	VIC0_SOFTINT         	 INTC_A_BASE+0x18
#define	VIC0_SOFTINTCLEAR    	 INTC_A_BASE+0x1c
#define	VIC0_PROTECTION      	 INTC_A_BASE+0x20
#define	VIC0_SWPRIORITYMASK  	 INTC_A_BASE+0x24
#define	VIC0_PRIORITYDAISY   	 INTC_A_BASE+0x28
#define	VIC0_VECTADDR        	 INTC_A_BASE+0x100
#define	VIC0_VECPRIORITY     	 INTC_A_BASE+0x200
#define	VIC0_ADDR            	 INTC_A_BASE+0xf00
#define	VIC0_PERID0          	 INTC_A_BASE+0xfe0
#define	VIC0_PERID1          	 INTC_A_BASE+0xfe4
#define	VIC0_PERID2          	 INTC_A_BASE+0xfe8
#define	VIC0_PERID3          	 INTC_A_BASE+0xfec
#define	VIC0_PCELLID0        	 INTC_A_BASE+0xff0
#define	VIC0_PCELLID1        	 INTC_A_BASE+0xff4
#define	VIC0_PCELLID2        	 INTC_A_BASE+0xff8
#define	VIC0_PCELLID3        	 INTC_A_BASE+0xffc
                         	
#define	VIC1_IRQSTATUS       	 INTC_B_BASE+0x00
#define	VIC1_FIQSTATUS       	 INTC_B_BASE+0x04
#define	VIC1_RAWINTR         	 INTC_B_BASE+0x08
#define	VIC1_INTSELECT       	 INTC_B_BASE+0x0c
#define	VIC1_INTENABLE       	 INTC_B_BASE+0x10
#define	VIC1_INTENCLEAR      	 INTC_B_BASE+0x14
#define	VIC1_SOFTINT         	 INTC_B_BASE+0x18
#define	VIC1_SOFTINTCLEAR    	 INTC_B_BASE+0x1c
#define	VIC1_PROTECTION      	 INTC_B_BASE+0x20
#define	VIC1_SWPRIORITYMASK  	 INTC_B_BASE+0x24
#define	VIC1_PRIORITYDAISY   	 INTC_B_BASE+0x28
#define	VIC1_VECTADDR        	 INTC_B_BASE+0x100
#define	VIC1_VECPRIORITY     	 INTC_B_BASE+0x200
#define	VIC1_ADDR            	 INTC_B_BASE+0xf00
#define	VIC1_PERID0          	 INTC_B_BASE+0xfe0
#define	VIC1_PERID1          	 INTC_B_BASE+0xfe4
#define	VIC1_PERID2          	 INTC_B_BASE+0xfe8
#define	VIC1_PERID3          	 INTC_B_BASE+0xfec
#define	VIC1_PCELLID0        	 INTC_B_BASE+0xff0
#define	VIC1_PCELLID1        	 INTC_B_BASE+0xff4
#define	VIC1_PCELLID2        	 INTC_B_BASE+0xff8
#define	VIC1_PCELLID3        	 INTC_B_BASE+0xffc
                         	
#define	VIC2_IRQSTATUS       	 INTC_C_BASE+0x00
#define	VIC2_FIQSTATUS       	 INTC_C_BASE+0x04
#define	VIC2_RAWINTR         	 INTC_C_BASE+0x08
#define	VIC2_INTSELECT       	 INTC_C_BASE+0x0c
#define	VIC2_INTENABLE       	 INTC_C_BASE+0x10
#define	VIC2_INTENCLEAR      	 INTC_C_BASE+0x14
#define	VIC2_SOFTINT         	 INTC_C_BASE+0x18
#define	VIC2_SOFTINTCLEAR    	 INTC_C_BASE+0x1c
#define	VIC2_PROTECTION      	 INTC_C_BASE+0x20
#define	VIC2_SWPRIORITYMASK  	 INTC_C_BASE+0x24
#define	VIC2_PRIORITYDAISY   	 INTC_C_BASE+0x28
#define	VIC2_VECTADDR        	 INTC_C_BASE+0x100
#define	VIC2_VECPRIORITY     	 INTC_C_BASE+0x200
#define	VIC2_ADDR            	 INTC_C_BASE+0xf00
#define	VIC2_PERID0          	 INTC_C_BASE+0xfe0
#define	VIC2_PERID1          	 INTC_C_BASE+0xfe4
#define	VIC2_PERID2          	 INTC_C_BASE+0xfe8
#define	VIC2_PERID3          	 INTC_C_BASE+0xfec
#define	VIC2_PCELLID0        	 INTC_C_BASE+0xff0
#define	VIC2_PCELLID1        	 INTC_C_BASE+0xff4
#define	VIC2_PCELLID2        	 INTC_C_BASE+0xff8
#define	VIC2_PCELLID3        	 INTC_C_BASE+0xffc



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




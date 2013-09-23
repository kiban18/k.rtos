#ifndef __SFRBASE_H__
#define __SFRBASE_H__

#define POST_BASE        0

#define ONDC_BASE        0xb0000000

#define CHIP_ID_BASE     0xe0000000
#define SYSCON_BASE      0xe0100000
#define ALIVE_BASE       0xe0200000
#define GPIO_BASE        0xe0300000
#define IEM_APC_BASE     0xe1000000
#define IEM_IEC_BASE     0xe1100000

#define INTC_BASE        0xe4000000		
//	INTC_A_BASE     = 0xe4000000,
//	INTC_B_BASE     = 0xe4100000,
//	INTC_C_BASE     = 0xe4200000,

#define EBI_BASE         0x0
#define NFCSTON_BASE     0x0
#define LPCON_BASE       0xe6000000
#define PL340x32_BASE    0xe6100000
#define PL340x64_BASE    0xe6200000
#define SMC_BASE         0xe7000000
#define ONC_BASE         0xe7100000
#define NFCON_BASE       0xe7200000
#define CFCON_BASE       0xe7800000

#define MDMA_BASE        0xe8100000
#define DMA_A_BASE       0xe9000000
#define DMA_B_BASE       0xe9200000
#define DMA_D_BASE       0x0

#define TIMER_BASE       0xea000000
#define SYSTIMER_BASE    0xea100000
#define WDT_BASE         0xea200000
#define RTC_BASE         0xea300000

#define UART_A_BASE      0xec000000
#define UART_B_BASE      0xec000400
#define UART_C_BASE      0xec000800
#define UART_D_BASE      0xec000c00
#define I2C_BASE         0xec100000
#define I2C_A_BASE       0xec100000
#define I2C_B_BASE       0xec200000 // For HDMI
#define SPI_A_BASE       0xec300000
#define SPI_B_BASE       0xec400000
#define SPI_C_BASE       0xec500000
#define IRDA_BASE        0xec600000
#define HSI_TX_BASE      0xec900000
#define HSI_RX_BASE      0xeca00000
#define DSIM_BASE        0xecb00000
#define CSI_S_BASE       0xecc00000
#define USBOTG_BASE      0xed200000
#define USBDEV_BASE      0xed200000
#define USBPHYC_BASE     0xed300000
#define MODEMIF_BASE     0xed500000
#define SDHC_A_BASE      0xed800000
#define SDHC_B_BASE      0xed900000
#define SDHC_C_BASE      0xeda00000

#define LCDC_BASE        0xee000000
#define ROT_BASE         0xee100000
#define CAMIF_BASE       0xee200000
#define CAMIF_A_BASE     0xee200000
#define CAMIF_B_BASE     0xee300000
#define CAMIF_C_BASE     0xee400000
#define JPEG_BASE        0xee500000
#define G2D_BASE         0xee800000
#define G3D_BASE         0xef000000
#define SDOUT_BASE       0xf0000000
#define VP_BASE          0xf0100000
#define MIXER_BASE       0xf0200000
#define HDMISS_BASE      0xf0300000
#define MFC_BASE         0xf1000000	

#define I2S_A_BASE       0xf2000000
#define I2S_B_BASE       0xf2100000
#define I2S_C_BASE       0xf2200000
#define AC97_BASE        0xf2300000
#define PCM_A_BASE       0xf2400000
#define PCM_B_BASE       0xf2500000
#define SPDIF_BASE       0xf2600000
#define TSADC_BASE       0xf3000000
#define KEYPADIF_BASE    0xf3100000
#define GPS_BASE         0xf3800000 // Cellguide

#define SEC_BASE		 0xf4000000 

#define APB_ST           0x0
#define APB_LMT          0x0

#endif //__SFRBASE_H__


#ifndef __DEF_H__
#define __DEF_H__

#define NULL  0

typedef unsigned int        u32;
typedef unsigned short      u16;
typedef unsigned char       u8;
typedef signed   int        s32;
typedef signed   short      s16;
typedef signed   char       s8;
#ifndef __cplusplus
typedef unsigned int        bool;
#endif

typedef volatile unsigned char		v_u8;
typedef volatile unsigned short int		v_u16;
typedef volatile unsigned int			v_u32;
typedef volatile unsigned long long	v_u64;
	
typedef volatile char				v_s8;
typedef volatile short int				v_s16;
typedef volatile int					v_s32;
typedef volatile long long			v_s64;

#if 0
#define __REGb(x)			(*(v_u8 *)(x))
#define __REGhw(x)		(*(v_u16 *)(x))
#define __REGw(x)		(*(v_u32 *)(x))
#define __REGdw(x)		(*(v_u64 *)(x))
#endif

#define KB(n)		(n<<10)
#define MB(n)		(n<<20)
//

// JJongspi - 100310
typedef unsigned char		unchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;
typedef unsigned char		uchar;
typedef volatile unsigned long	vu_long;
typedef volatile unsigned short vu_short;
typedef volatile unsigned char	vu_char;

#define KB(n)		(n<<10)
#define MB(n)		(n<<20)

//#define __REGw(x)		(*(v_u32 *)(x))
#define __REGw(x)		(*(volatile unsigned int *)(x))

typedef struct FUNC_MENU {
	void (*func)(void);
	const char *desc;
} FUNC_MENU;

//typedef void (*VoidFuncPtr) () VoidFuncPtr;

typedef enum {
	PAL1, PAL2, PAL4, PAL8,
	RGB8, ARGB8, RGB16, ARGB16, RGB24, ARGB24, ARGB32_8888,
	RGB16_I, RGB16_IW, RGB24_I, RGB24_IW,
	BayerRGB8, BayerRGB10, BayerRGB12,
	CRYCBY, CBYCRY, YCRYCB, YCBYCR, // Y/Cb/Cr interleave (1 plane)
	NV12, NV16, NV24, // Y/C non-interleave, Cb/Cr interleave (2 plane)
	NV12_I, NV12_IW, // Y/C non-interleave, Cb/Cr interleave (2 plane)
	TILE_NV12, TILE_NV12_IW, // Y/C non-interleave, Cb/Cr interleave (2 plane), 64 bytes x 32 lines
	YC420, YC422, YC444, // Y/Cb/Cr non-interleave (3 plane)
} IMG_TYPE; 
	// I : Interlaced, IW : Interlaced Weave, None : Progressive

typedef enum {
	RGB_IF, YC444_IF, YC422_IF, YC420_IF
} IMG_IF_TYPE;

typedef enum  {
	C_BLACK = 0, C_RED = 1, C_GREEN = 2, C_BLUE = 3,
	C_WHITE = 4, C_YELLOW = 5, C_CYAN = 6, C_MAGENTA = 7
} COLOR;

typedef enum {
	NTSC, PAL
} TV_STANDARD;

typedef enum   {
	NTSC_M, PAL_M, PAL_BGHID, PAL_N, PAL_NC, PAL_60, NTSC_443, NTSC_J
} TV_VARIANT;

typedef enum   {
	INTERLACED, PROGRESSIVE
} SCAN_MODE;

typedef enum {
	QCIF, CIF, QQVGA, QVGA, VGA, SVGA, SXGA, UXGA, QXGA, WVGA, 
	SD480, SD576, WWSD480, WWSD576, HD720, HD1080, CAM_8M
} IMG_SIZE;
/*	
	CIF(352x288), 
	WVGA(800x480), SVGA(800x600), SXGA(1280x1024), UXGA(1600x1200), QXGA(2048x1536)
	SD480(720x480), SD576(720x576), WWSD480(1440x480), WWSD576(1440x576),
	HD720(1280x720), HD1080(1920x1080), CAM_8M(3264x2448)
*/

typedef enum   {
	FLIP_NO, FLIP_X, FLIP_Y, FLIP_XY
} FLIP_DIR;

typedef enum {
	ROT_0, ROT_90, ROT_180, ROT_270
} ROT_DEG;

typedef enum {
	BYTE, HWORD, WORD, DWORD
} DATA_WIDTH;

typedef enum   {
	RISING, FALLING
} POL;

typedef enum {
	TX, RX, TRX, IN, OUT, UP, DOWN
} DIR;

typedef enum {
	CPU, DMA
} TRANS_MASTER;

typedef enum {
	SINGLE, BURST4, BURST8, BURST16, BURST16X2, BURST32, BURST64, BURST128, BURST256
} BURST_LEN;

typedef enum {
	HCLK, PCLK, ECLK0, ECLK1
} CLK_SRC;

typedef enum {
	IP_AC97,
	IP_CAMIF_CAM_A, IP_CAMIF_CAM_B, IP_CAMIF,
	IP_CAN,
	IP_CFCON,
	IP_GPS,
	IP_EBI,
	IP_EXDMA,
	IP_HSI,
	IP_IEM,
	IP_I2C, IP_I2C_A, IP_I2C_B,
	IP_I2S_A, IP_I2S_B, IP_I2S_C,
	IP_IrDA,
	IP_KEYIF,
	IP_LCDC, IP_LCDC_X, IP_LCDC_Y, IP_LCDC_i80, IP_LCDC_656, 
	IP_MODEMIF,
	IP_NFCON,
	IP_ONDC,
	IP_PCMIF_A, IP_PCMIF_B,
	IP_SDHOST, IP_SDHOST_A, IP_SDHOST_B_4BIT, IP_SDHOST_B_8BIT, IP_SDHOST_C,
	IP_SDPIF, IP_SPDIF_X, IP_SPDIF_Y,
	IP_SPI_A, IP_SPI_B, IP_SPI_C,
	IP_TIMER,
	IP_UART_A, IP_UART_B, IP_UART_C, IP_UART_D,
	IP_USB
} IP;

typedef enum {
	MPEG4=1, H264, DIVX, XVID, H263, MPEG2, VC1, MP4SH,
	PCM, AC3, MP3, WMA
} CODEC_TYPE;

typedef enum {
	LTS350Q1=1, LTS222Q_RGB, LTS222Q_SRGB, LTS222Q_CPU, LTV350QV, 
	LTE480WV, LTS480WS, LTP480WV, UPD161206, TL2796, S6D66A0, D53E4EA7554, SIL9022
} LCD_MODEL;

typedef enum {
	OV7620=1, S5X433, AU70H, S5X3A1, S5K3AAE, S5K4AAF, S5K3C1F, S5K3BAF, S5K4CAGX, ADV7180, M5MO, MC501CB,
	MB0310
//		
} CIS_MODEL;

typedef enum {
	SINGLE_PACKAGE=1, POP1, POP2
} DEV_INFO;

extern u32 g_uHclkFreq, g_uHclk0Freq, g_uHclk1Freq, g_uHclk2Freq;
extern u32 g_uPclkFreq, g_uPclk0Freq, g_uPclk1Freq, g_uPclk2Freq;
extern u32 g_uAclkFreq;
extern u32 g_uEclkFreq, g_uEclk0Freq, g_uEclk1Freq;
extern u32 g_uLcdFrameRate;
extern u32 g_uUartBaudRate;
extern u32 g_uCisMClk;
extern u32 g_eDeviceId;
extern CIS_MODEL g_eCisModel;
extern LCD_MODEL g_eLcdModel;
extern DEV_INFO g_eDevInfo;
	
#endif //__DEF_H__


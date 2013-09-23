#define DRAM_START_ADDR			0x20000000
#define DRAM_END_ADDR			0x40000000

// Memory Region Size
#define SVC_STACK_SIZE			(16*1024)		// 16[KB]
#define IRQ_STACK_SIZE				(16*1024)		// 16[KB]
#define FIQ_STACK_SIZE				(1*1024)			// 1[KB]
#define ABORT_STACK_SIZE			(1*1024)			// 1[KB]
#define UNDEF_STACK_SIZE			(1*1024)			// 1[KB]
#define USER_STACK_SIZE			(1*1024)			// 1[KB]

#define MMU_PAGE_TABLE_SIZE			(16*1024)		// 16[KB] <=> For 1[MB] Section Unit Mapping

	
//APP_IMAGE_SIZE				(32*1024*1024)		// 32[MB]

//CAM_BUF0_SIZE				(3*1024)			// 3[MB]
//CAM_BUF1_SIZE				(3*1024)			// 3[MB]
//CAM_BUF2_SIZE				(3*1024)			// 3[MB]
//CAM_BUF3_SIZE				(3*1024)			// 3[MB]

#define LCD_FB0_SIZE				(16*1024*1024)		// 16[MB]
#define LCD_FB1_SIZE				(16*1024*1024)		// 16[MB]
#define LCD_FB2_SIZE				(16*1024*1024)		// 16[MB]
#define LCD_FB3_SIZE				(16*1024*1024)		// 16[MB]
#define LCD_FB4_SIZE				(16*1024*1024)		// 16[MB]
#define LCD_FB_SIZE_ALIGN			(16*1024*1024)		// 16[MB]

// Memory Region Address
#define SVC_STACK_BASE			(DRAM_END_ADDR - MMU_PAGE_TABLE_SIZE)	// 
#define IRQ_STACK_BASE			(SVC_STACK_BASE -SVC_STACK_SIZE)		// 
#define FIQ_STACK_BASE			(IRQ_STACK_BASE -IRQ_STACK_SIZE)		// 
#define ABORT_STACK_BASE			(FIQ_STACK_BASE -FIQ_STACK_SIZE)		// 
#define UNDEF_STACK_BASE			(ABORT_STACK_BASE -ABORT_STACK_SIZE)	// 
#define SYS_STACK_BASE			(UNDEF_STACK_BASE -UNDEF_STACK_SIZE)	// 

#define STACK_START_ADDR			(SVC_STACK_BASE)
#define STACK_END_ADDR			(SYS_STACK_BASE - SYS_STACK_BASE)

//HEAP_END_ADDR			(STACK_END_ADDR - 4)
//HEAP_START_ADDR			((|Image$$ZI$$Limit|+ 0x7)&0x7)

#define CAM_BUF_BASE_ADDR			(DRAM_END_ADDR - LCD_FB_SIZE_ALIGN)		// 0x3F00_0000
//CAM_BUF0_START_ADDR			(DRAM_END_ADDR - LCD_FB_SIZE_ALIGN)		// 0x3F00_0000
//CAM_BUF1_START_ADDR			(DRAM_END_ADDR + CAM_BUF0_SIZE)		// 
//CAM_BUF2_START_ADDR			(DRAM_END_ADDR + CAM_BUF1_SIZE)		// 
//CAM_BUF3_START_ADDR			(DRAM_END_ADDR + CAM_BUF2_SIZE)		// 

#define LCD_FB0_START_ADDR			(DRAM_END_ADDR - 6*LCD_FB_SIZE_ALIGN)		// 0x3A00_0000
#define LCD_FB1_START_ADDR			(LCD_FB0_START_ADDR + LCD_FB_SIZE_ALIGN)	// 0x3B00_0000
#define LCD_FB2_START_ADDR			(LCD_FB1_START_ADDR + LCD_FB_SIZE_ALIGN)	// 0x3C00_0000
#define LCD_FB3_START_ADDR			(LCD_FB2_START_ADDR + LCD_FB_SIZE_ALIGN)	// 0x3D00_0000
#define LCD_FB4_START_ADDR			(LCD_FB3_START_ADDR + LCD_FB_SIZE_ALIGN)	// 0x3E00_0000

#define BL2_IMAGE_DOWN_ADDR			(CAM_BUF_BASE_ADDR)
#define APP_IMAGE_DOWN_ADDR			(DRAM_START_ADDR)

// Clock Controller Setting Constand
// [833:166:66] 
// 	-. MOUT_APLL=1666
// 	-. DOUT_APLL=MOUT_APLL/2=833 <=> ARMCLK
//	-. HCLKD0 = ARMCLK/5=166.6
//	-. HCLKD0_SECSS = HCLKD0/2 = 83.3
// [667:166:66] 
// 	-. MOUT_APLL=1334
// 	-. DOUT_APLL=MOUT_APLL/2=667 <=> ARMCLK
//	-. HCLKD0 = ARMCLK/4=166.75
//	-. HCLKD0_SECSS = HCLKD0/2 = 83.375

#define CONFIG_CLK_666_166_66	1


#if CONFIG_CLK_666_166_66
#define APLL_MDIV			444
#define APLL_PDIV			4
#define APLL_SDIV			0
#define CLK_DIV0_VAL			(1<<16|1<<12|3<<8|0<<4|1<<0)
#elif CONFIG_CLK_833_166_66
#define APLL_MDIV			417
#define APLL_PDIV			#define 3
#define APLL_SDIV			0
#define CLK_DIV0_VAL			(1<<16|1<<12|4<<8|0<<4|1<<0)
#endif

#define CLK_DIV1_VAL			((1<<16)|(1<<12)|(1<<8)|(1<<4))
#define CLK_DIV2_VAL			(1<<0)

#define MPLL_MDIV			89
#define MPLL_PDIV			2
#define MPLL_SDIV			1
#define EPLL_MDIV			135
#define EPLL_PDIV			3
#define EPLL_SDIV			3
#define HPLL_MDIV			96
#define HPLL_PDIV			6
#define HPLL_SDIV			3

#define APLL_VAL			(1<<31|APLL_MDIV<<16|APLL_PDIV<<8|APLL_SDIV)
#define MPLL_VAL			(1<<31|MPLL_MDIV<<16|MPLL_PDIV<<8|MPLL_SDIV)
#define EPLL_VAL			(1<<31|EPLL_MDIV<<16|EPLL_PDIV<<8|EPLL_SDIV)
#define HPLL_VAL			(1<<31|HPLL_MDIV<<16|HPLL_PDIV<<8|HPLL_SDIV)

// CPSR Bit Field Definition
#define USER_MODE		 	0x10
#define FIQ_MODE		 	0x11
#define IRQ_MODE		 	0x12
#define SVC_MODE		 	0x13
#define MONITOR_MOD			0x16
#define ABORT_MODE		 	0x17
#define UNDEF_MODE		 	0x1B
#define SYS_MODE			0x1F

#define MODE_BITS		 	0x1F
#define IRQ_BIT			 	(1<<7)
#define FIQ_BIT				(1<<6)



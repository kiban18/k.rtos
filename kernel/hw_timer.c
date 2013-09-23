#include <kernel.h>
#include <sfr_base.h>
#include <typedef.h>
#include <util.h>
#include <interrupt.h>

#include <timer.h>
#include <hw_timer.h>

#define tmrOutp32(a, d) Outp32(a, d)
#define tmrInp32(a, d) Inp32(a, d)
#define tmrOutp16(a, d) Outp16(a, d)
#define tmrInp16(a, d) Inp16(a, d)
#define tmrOutp8(a, d) Outp8(a, d)
#define tmrInp8(a, d) Inp8(a, d)

#define uTimerPclkFreq g_uPclk1Freq

#ifndef TIMER_SPEC_VER1
#define MAX_TIMER_CNT 0x7fffffff
#else
#define MAX_TIMER_CNT 0xffff
#endif


unsigned int clkFreq  = (u32)(500*1000000);
unsigned int g_uHclk0Freq = (u32)(166*1000000);
unsigned int g_uPclk0Freq = (u32)((166*1000000)>>1);
unsigned int g_uHclk1Freq = (u32)(133*1000000);
unsigned int g_uPclk1Freq = (u32)((133*1000000)>>1);
unsigned int g_uPclk2Freq = (u32)((133*1000000)>>1);
unsigned int g_uEclk0Freq = (u32)(32*1000000);
unsigned int g_uLcdFrameRate = (u32)(60);


u32 m_uTimerFreq = 100000;
u32 m_uPreScale;
float m_fTimerPeriod;


unsigned int ePort = 0x080;
unsigned int uBit = 0;
unsigned int eDir = 4;

unsigned int port = 0x080;
unsigned int bit = 0;
unsigned int dir = 4;



#define M 1000000.0

u32 volatile uCh0Cnt;
u32 volatile uCh1Cnt;
u32 volatile uCh2Cnt;
u32 volatile uCh3Cnt;
u32 volatile uCh4Cnt;


void InitGpioBit(unsigned int ePort, unsigned int uBit, unsigned int eDir)
{
}



void HwTimerStart(void)
{
}



void HwTimerInitCh0ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal)
{
}



void HwTimerInitCh1ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal)
{
}



void HwTimerInitCh2ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal)
{
}



void HwTimerInitCh3ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal)
{
}



void HwTimerInitCh4ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal)
{
}



void HwTimerReadCount0(u32 *uCnt)
{
}



void HwTimerReadCount(unsigned int eCh, u32 *uCnt)
{
}



void HwTimerReadElapsedTime(float *msec)
{
}



void HwTimerConvertToTime(u32 uCnt, float *msec)
{
}



// Clear interrupt
void HwTimerClearInterrupt(unsigned int eTmr)
{
}



// Set prescaler
void HwTimerSetPrescaler(unsigned int eTmr, u32 uPreScalerVal)
{
}



// Set divider
void HwTimerSetDivider(unsigned int eTmr, unsigned int eDiv)
{
}



// Set count buffer
void HwTimerSetCntBuf(unsigned int eTmr, u32 uCntVal)
{
}



// Set compare buffer
void HwTimerSetCmpBuf(unsigned int eTmr, u32 uCmpVal)
{
}



// Set dead zone
void HwTimerSetDeadZone(unsigned int bEnDz, u32 uDzLen)
{
}



// Set auto-reload
void HwTimerSetAutoReload(unsigned int eTmr, unsigned int bEnAutoReload)
{
}



// Set inverter
void HwTimerSetInverter(unsigned int eTmr, unsigned int bEnInverter)
{
}



// Set interrupt
void HwTimerSetInt(unsigned int eTmr, unsigned int bEnInt)
{
}



// Set manual update
void HwTimerSetManualUpdate(unsigned int eTmr, unsigned int bEnManualUpdate)
{
}



// Get Period and LowWidth and HighWidth
void HwTimerGetPeriodAndLowHighWidth(
	u32 uPreScalerVal, unsigned int eDiv,
	u32 uCntVal, u32 uCmpVal, unsigned int bEnInverter,
	float *fPeriod, float *fLowWidth, float *fHighWidth)
{
}



// Start timer
void HwTimerStartCh(unsigned int eTmr)
{
}



// Stop timer
void HwTimerStopCh(unsigned int eTmr)
{
}



// Initialize timer0 for pwm out
void HwTimerInitCh0ForPwmOut(u32 uPreScalerVal, unsigned int eDiv, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnDz, u32 uDzLen, unsigned int bEnAutoReload, unsigned int bEnInverter)
{
}



// Initialize timer1 for pwm out
void HwTimerInitCh1ForPwmOut(u32 uPreScalerVal, unsigned int eDiv, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnAutoReload, unsigned int bEnInverter)
{
}



// Initialize timer1 for external clock IN pwm OUT
void HwTimerInitCh1ForExtClkInPwmOut(u32 uPreScalerVal, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnAutoReload, unsigned int bEnInverter)
{
}



// Initialize timer1 for interrupt
void HwTimerInitCh1ForInt(u32 uPreScalerVal, unsigned int eDiv, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnAutoReload, unsigned int bEnInverter)
{
}



// Initialize timer2 for pwm out
void HwTimerInitCh2ForPwmOut(u32 uPreScalerVal, unsigned int eDiv, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnAutoReload, unsigned int bEnInverter)
{
}



// Initialize timer2 for external clock IN pwm OUT
void HwTimerInitCh2ForExtClkInPwmOut(u32 uPreScalerVal, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnAutoReload, unsigned int bEnInverter)
{
}



// Initialize timer2 for interrupt
void HwTimerInitCh2ForInt(u32 uPreScalerVal, unsigned int eDiv, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnAutoReload, unsigned int bEnInverter)
{
}



// Initialize timer3 for interrupt
void HwTimerInitCh3ForInt(u32 uPreScalerVal, unsigned int eDiv, u32 uCntVal, u32 uCmpVal,
	unsigned int bEnAutoReload)
{
}



// Initialize timer4 for interrupt
void HwTimerInitCh4ForInt(u32 uPreScalerVal, unsigned int eDiv, u32 uCntVal,
	unsigned int bEnAutoReload)
{
}



// Initialize Ip for interrupt
void HwTimerInitIpForInt(unsigned int eCh, u32 uIntPeriod) // uIntPeriod -> usec
{
}



// Initialize Ip for pwm out
// uIntPeriod -> usec, uOnTimeRatio -> %
void HwTimerInitIpForPwmOut(unsigned int eCh, u32 uIntPeriod, u32 uOnTimeRatio)
{
}


// Initialize base H/W for pwm timer
void HwTimerInitBaseHwForPwmTimer(void)
{
}


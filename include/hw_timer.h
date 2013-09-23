#ifndef __NEW_TIMER_H__
#define __NEW_TIMER_H__

#include <typedef.h>


#define TCFG0            TIMER_BASE + 0x00 // Configuration 0
#define TCFG1            TIMER_BASE + 0x04 // Configuration 1
#define TCON             TIMER_BASE + 0x08 // Control
#define TCNTB0           TIMER_BASE + 0x0c // Count buffer 0
#define TCMPB0           TIMER_BASE + 0x10 // Compare buffer 0
#define TCNTO0           TIMER_BASE + 0x14 // Count observation 0
#define TCNTB1           TIMER_BASE + 0x18 // Count buffer 1
#define TCMPB1           TIMER_BASE + 0x1c // Compare buffer 1
#define TCNTO1           TIMER_BASE + 0x20 // Count observation 1
#define TCNTB2           TIMER_BASE + 0x24 // Count buffer 2
#define TCMPB2           TIMER_BASE + 0x28 // Compare buffer 2
#define TCNTO2           TIMER_BASE + 0x2c // Count observation 2
#define TCNTB3           TIMER_BASE + 0x30 // Count buffer 3
#define TCMPB3           TIMER_BASE + 0x34 // Compare buffer 3
#define TCNTO3           TIMER_BASE + 0x38 // Count observation 3
#define TCNTB4           TIMER_BASE + 0x3c // Count buffer 4
#define TCNTO4           TIMER_BASE + 0x40 // Count observation 4
#define TINT_CSTAT       TIMER_BASE + 0x44 // Interrupt control and status

#define TIMER0  0
#define TIMER1  1
#define TIMER2  2
#define TIMER3  3
#define TIMER4  4

#define DIV1    0
#define DIV2    1
#define DIV4    2
#define DIV8    3
#define DIV16   4



extern unsigned int ePort;
extern unsigned int uBit;
extern unsigned int eDir;

extern unsigned int port;
extern unsigned int bit;
extern unsigned int dir;


void HwTimerStart(void);
void HwTimerReadCount(unsigned int  eCh, u32 *uCnt);
void HwTimerReadCount0(u32 *uCnt);
void HwTimerReadElapsedTime(float *msec);
void HwTimerConvertToTime(u32 uCnt, float *msec);	
//	void SetTimerFreq(u32 uTimerFreq);
//	void GetTimePeriod(float &fPeriod);

void HwTimerGetPeriodAndLowHighWidth(
        u32 uPreScalerVal, unsigned int  eDiv,
        u32 uCntVal, u32 uCmpVal, unsigned int bEnInverter,
        float *fPeriod, float *fLowWidth, float *fHighWidth);

void HwTimerClearInterrupt(unsigned int  eTmr);
void HwTimerStartCh(unsigned int  eTmr);
void HwTimerStopCh(unsigned int  eTmr);

void HwTimerInitCh0ForPwmOut(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnDz, u32 uDzLen, unsigned int bEnAutoReload, unsigned int bEnInverter);
void HwTimerInitCh0ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh0ForInt(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnDz, u32 uDzLen, unsigned int bEnAutoReload, unsigned int bEnInverter);

void HwTimerInitCh1ForPwmOut(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnAutoReload, unsigned int bEnInverter);
void HwTimerInitCh1ForExtClkInPwmOut(u32 uPreScalerVal, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnAutoReload, unsigned int bEnInverter);		
void HwTimerInitCh1ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh1ForInt(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnAutoReload, unsigned int bEnInverter);

void HwTimerInitCh2ForPwmOut(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnAutoReload, unsigned int bEnInverter);
void HwTimerInitCh2ForExtClkInPwmOut(u32 uPreScalerVal, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnAutoReload, unsigned int bEnInverter);	
void HwTimerInitCh2ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh2ForInt(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnAutoReload, unsigned int bEnInverter);

void HwTimerInitCh3ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh3ForInt(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal,
        unsigned int bEnAutoReload);

void HwTimerInitCh4ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal);
void HwTimerInitCh4ForInt(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal,
        unsigned int bEnAutoReload);

void HwTimerInitIpForInt(unsigned int  eCh, u32 uIntPeriod); // uIntPeriod -> usec	
void HwTimerInitIpForPwmOut(unsigned int  eCh, u32 uIntPeriod, u32 uOnTimeRatio); // uIntPeriod -> usec, uOnTimeRatio -> %

void HwTimerSetPrescaler(unsigned int  eTmr, u32 uPreScalerVal);
void HwTimerSetDivider(unsigned int  eTmr, unsigned int  eDiv);
void HwTimerSetCntBuf(unsigned int  eTmr, u32 uCntVal);
void HwTimerSetCmpBuf(unsigned int  eTmr, u32 uCmpVal);
void HwTimerSetDeadZone(unsigned int bEnDz, u32 uDzLen);
void HwTimerSetAutoReload(unsigned int  eTmr, unsigned int bEnAutoReload);
void HwTimerSetInverter(unsigned int  eTmr, unsigned int bEnInverter);
void HwTimerSetInt(unsigned int  eTmr, unsigned int bEnInt);
void HwTimerSetManualUpdate(unsigned int  eTmr, unsigned int bEnManualUpdate);

extern u32 m_uTimerFreq;
extern u32 m_uPreScale;
extern float m_fTimerPeriod;


void HwTimerInitBaseHwForPwmTimer(void);

void HwTimerInitCh0ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh1ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh2ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh3ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal, u32 uCmpVal);
void HwTimerInitCh4ForInt0(u32 uPreScalerVal, unsigned int  eDiv, u32 uCntVal);

void InitGpioBit(unsigned int ePort, unsigned int uBit, unsigned int eDir);


#endif //__NEW_TIMER_H__

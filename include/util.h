#ifndef __UTIL_H__
#define __UTIL_H__

#include <typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define Outp32(addr, data) (*(volatile u32 *)(addr) = (data))
#define Outp16(addr, data) (*(volatile u16 *)(addr) = (data))
#define Outp8(addr, data)  (*(volatile u8 *)(addr) = (data))
#define Inp32(addr, data) (data = (*(volatile u32 *)(addr)))
#define Inp16(addr, data) (data = (*(volatile u16 *)(addr)))
#define Inp8(addr, data)  (data = (*(volatile u8 *)(addr)))

#ifndef BOOT_CODE
#ifdef USE_DBGR_CONSOLE
#include <stdio.h>
#define InitUart(uCh)   0
#define GetChar         getchar
#define PutChar         putchar
#define Disp            printf
#define Dbg             printf
#define DispResult		printf
#define GetString       gets
int GetInt(void);
char GetKey(void);
#else
#if 0
#include "com.h"
#define InitUart(uCh)   comInitCh(uCh)
 #ifdef AUTO_TEST
int GetInt(void);
extern void Disp(const char *fmt,...);
#define DispResult		comPrintf
 #else
#define GetInt          comGetInt
#define Disp	        comPrintf
#define DispResult		comPrintf
 #endif
#define GetChar         comGetChar
#define PutChar         comPutChar
#define GetKey          comGetKey
#define Dbg             comPrintf
#define GetString       comGetString
#endif
#endif
#endif

#ifdef DISP_GPIO_REG
#define gpioOutp32(a, d) {u32 a2, d2; a2=a; d2=d; Dbg("Outp32(0x%08x, 0x%08x);\n", a2, d2); Outp32(a2, d2);}
//#define gpioInp32(a, d) {u32 a2, d2; a2=a; Inp32(a2, d2); d=d2; Disp("Inp32(\'h%08x, d); // d=0x%08x\n", a2, d2);}
#define gpioInp32 Inp32
#else
#define gpioOutp32 Outp32
#define gpioInp32 Inp32
#endif

#define SetBits(uAddr, uBaseBit, uMaskValue, uSetValue) \
{ \
	volatile u32 x; \
	gpioInp32(uAddr, x); \
	x &= ~((unsigned)(uMaskValue)<<(uBaseBit)); \
	x |= ((unsigned)(uSetValue)<<(uBaseBit)); \
	gpioOutp32(uAddr, x); \
}

#define Align(x, alignbyte) \
	(((x)+(alignbyte)-1)/(alignbyte)*(alignbyte))

void TurnOnLED(u32 uWhichLed); // uWhichLed = 1,2,3,4
void TurnOffLED(u32 uWhichLed); // uWhichLed = 1,2,3,4
void DispSysInfo(void);
void StartTimer(void);
float GetElapsedTime(void);
void Delay100us(u32 uNumOfUnits);
void Delay10us(u32 uNumOfUnits);
void Delay1us(u32 uNumOfUnits);
void TuneDelay(void);
#define Delay(x) Delay100us(x)
u32 LoadFile(const char *pFilename, u32 uDstAddr);
void SaveToFile(const char* pFilename, u32 uSrcAddr, u32 fileSize);
int ConvertStrToNum(char *string);
void ConvertRgbToYCbYCr( u32 uHsz, u32 uVsz, u32 uStAddr, u32 uDstAddr );
void ConvertRgbToYCbCr420( u32 uHsz, u32 uVsz, u32 uStAddr, u32 uDstAddr );
void ConvertNv12ToYuv420(u32 uSrcAddrOfY, u32 uSrcAddrOfCbCr, u32 uPicHsz, u32 uPicVsz, u32 uDstAddrOfY);
void ConvertNv16ToCBYCRY(u32 uSrcAddrOfY, u32 uSrcAddrOfCbCr, u32 uPicHsz, u32 uPicVsz, u32 uDstAddrOfY);
void ConvertYuv420ToNv12(u32 uSrcAddrOfY, u32 uPicHsz, u32 uPicVsz, u32 uDstAddrOfY);


void Copy1b(u32 sa, u32 da, u32 bytes);
void Copy1w(u32 sa, u32 da, u32 uCntOfWords);
bool Compare1b(u32 a1, u32 a2, u32 bytes);
bool Compare1w(u32 a1, u32 a2, u32 uCntOfWords);
bool Compare4w(u32 uSrcAddr, u32 DstAddr, u32 uCntOfWords);
void Dump1b(u32 addr, u32 bytes);
void Dump1w(u32 addr, u32 uCntOfWords);
void Copy8w(u32 uSrcAddr, u32 uDstAddr, u32 uCntOf8Words);
void Read8w(u32 uSrcAddr, u32 uDstAddr, u32 uCntOf8Words);
void Write8w(u32 uSrcAddr, u32 uDstAddr, u32 uCntOf8Words);
//#define Compare8 Compare1b

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
//#include "virtual.h"
class FILE_STORAGE;
void DispFileNames(FILE_STORAGE *pFile, const char *pExtList=NULL);
//void DispFileNames(FILE_STORAGE *pFile);
void DispStringArray(char* apString[], u32 uNumOfFiles);

void SetFreeHwMemStAddr(u32 uAddr);
u32 GetFreeHwMemStAddr(u32 uAlign=4);
u32 AllocHwMem(u32 uSizeInBytes, u32 uAlignInBytes=4);

bool CompareFrameBuffers(u32 a0, u32 width, u32 height, u32 a1, u32 dispWidth, u32 dispHeight,
	u32& uMaxAbsDiff, u32& uAvgDiff);
void ConvertImgTypeToString(IMG_TYPE eBpp, const char* &pStr);
void ConvertImgSzToNumber(IMG_SIZE eSize, u32& uHsz, u32& uVsz);
void GetFbSize(IMG_TYPE eImgFmt, u32 uImgHsz, u32 uImgVsz, u32& uFbSize);
void GetFbAddr(IMG_TYPE eImgFmt, u32 uImgHsz, u32 uImgVsz, u32 uFbStAddr, u32 uNumOfFrm,
	u32 uIdx, u32& uFbYAddr, u32& uFbCAddr);
void ConvertCodecTypeToString(CODEC_TYPE eCodec, const char* &pCodecName);
inline u32 Stop(void) { while (1); return 0; }
#ifndef BOOT_CODE
#define Assert(b) (!(b) ? Dbg("\n %s(line %d)\n", __FILE__, __LINE__), Stop() : 0)
#else
#define Assert(b) (!(b) ? Stop() : 0)
#endif
#endif

#endif // __ETC_H__

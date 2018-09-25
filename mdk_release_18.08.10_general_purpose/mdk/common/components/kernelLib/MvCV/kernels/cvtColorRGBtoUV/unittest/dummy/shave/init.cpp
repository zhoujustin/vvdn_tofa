///
/// @file
/// @copyright All code copyright Movidius Ltd 2013, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief    cvtColorRGBtoUV kernel function call for unitary test
///

#include "cvtColorRGBtoUV.h"
#include "svuCommonShave.h"
#include "mv_types.h"

#define TEST_FRAME_WIDTH 1920
#define TEST_FRAME_HEIGHT 1

u8 inputR[TEST_FRAME_HEIGHT][TEST_FRAME_WIDTH];
u8 inputG[TEST_FRAME_HEIGHT][TEST_FRAME_WIDTH];
u8 inputB[TEST_FRAME_HEIGHT][TEST_FRAME_WIDTH];

/*output pre pad marker*/
uint32_t  __attribute__((section(".kept.data"))) outputUV_u32prePad[4] __attribute__ ((aligned (16)));
/*output data marker*/
u8 __attribute__((section(".kept.data"))) outputUV[TEST_FRAME_HEIGHT][TEST_FRAME_WIDTH] __attribute__ ((aligned (16)));
/*output post pad marker*/
uint32_t __attribute__((section(".kept.data"))) outputUV_u32postPad[4] __attribute__ ((aligned (16)));

u32 width;
u32 line;

u8* inLineR[TEST_FRAME_HEIGHT];
u8* inLineG[TEST_FRAME_HEIGHT];
u8* inLineB[TEST_FRAME_HEIGHT];
u8* outLineUV[TEST_FRAME_HEIGHT];

u8** inLinesR;
u8** inLinesG;
u8** inLinesB;
u8** outLinesUV;




int main( void )
{
//	void cvtColorRGBtoUV_asm(u8** inR, u8** inG, u8** inB, u8** uvOut, u32 width, u32 line) 

	inLineR[0] = (u8*)inputR[0];
	inLineG[0] = (u8*)inputG[0];
	inLineB[0] = (u8*)inputB[0];
	outLineUV[0] = (u8*)outputUV[0];
	
	inLinesR = (u8**)inLineR;
	inLinesG = (u8**)inLineG;
	inLinesB = (u8**)inLineB;
	outLinesUV = (u8**)outLineUV;
	
	#ifdef UNIT_TEST_USE_C_VERSION
	mvcvCvtColorRGBtoUV(inLinesR, inLinesG, inLinesB, outLinesUV, width, line);
	#else
	mvcvCvtColorRGBtoUV_asm(inLinesR, inLinesG, inLinesB, outLinesUV, width, line);
	#endif
	
	SHAVE_HALT; 
    return 0;
}
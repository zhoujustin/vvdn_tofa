///
/// @file
/// @copyright All code copyright Movidius Ltd 2014, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     This file contains the source code of the SIPP pipeline
///            generated by the SIPP Graph Designer.
///
///
///  ************************ DO NOT EDIT, THIS IS A GENERATED FILE!!!! ************************
/// 

#ifndef __SIPPTUTC2MODEL_H__
#define __SIPPTUTC2MODEL_H__

#include <sipp.h>
#include <sippTestCommon.h>

#include "sippMat.h"


//The full-frame buffers
extern UInt8 DDR_DATA SippTutC2Model_dmaIn0_buffer[ 512 * 512 * 1 ]ALIGNED(8);
extern UInt8 DDR_DATA SippTutC2Model_dmaOut1_buffer[ 512 * 512 * 1 ]ALIGNED(8);
	
///

typedef struct SippTutC2Model
{
	//Filter references for human readable shape
	SippPipeline *pl;

	//Declare references to all filters in the pipeline
	SippFilter *dmaIn0;
	SippFilter *dmaOut1;
	SippFilter *erode5x52;
	SippFilter *dilate5x53;

} SippTutC2Model;

void readSippTutC2ModelInput(SippTutC2Model *pPl);
void writeSippTutC2ModelOutput(SippTutC2Model *pPl);

void buildSippTutC2Model(SippTutC2Model *pPl);
void configSippTutC2Model(SippTutC2Model *pPl);


#endif
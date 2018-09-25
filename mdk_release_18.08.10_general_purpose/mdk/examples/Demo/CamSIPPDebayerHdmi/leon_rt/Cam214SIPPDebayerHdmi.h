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

#ifndef __CAM214SIPPDEBAYERHDMI_H__
#define __CAM214SIPPDEBAYERHDMI_H__

#include <sipp.h>
#include <sippTestCommon.h>

#include "ISPPipeSettings.h"


//The full-frame buffers
	
///

typedef struct Cam214SIPPDebayerHdmi
{
	//Filter references for human readable shape
	SippPipeline *pl;

	//Declare references to all filters in the pipeline
	SippFilter *dmaIn0;
	SippFilter *sigmaDnsMa2x5x0;
	SippFilter *lscMa2x5x0;
	SippFilter *rawMa2x5x0;
	SippFilter *debayerMa2x5x0;
	SippFilter *dogLtmMa2x5x0;
	SippFilter *ydnsMa2x5x0;
	SippFilter *sharpenMa2x5x0;
	SippFilter *chromaGenMa2x5x0;
	SippFilter *medianMa2x5x0;
	SippFilter *chromadnsMa2x5x0;
	SippFilter *colorcombMa2x5x0;
	SippFilter *lutMa2x5x0;
	SippFilter *polyphasefirMa2x5xY;
	SippFilter *polyphasefirMa2x5xU;
	SippFilter *polyphasefirMa2x5xV;
	SippFilter *dmaOutY;
	SippFilter *dmaOutU;
	SippFilter *dmaOutV;

} Cam214SIPPDebayerHdmi;

void readCam214SIPPDebayerHdmiInput(Cam214SIPPDebayerHdmi *pPl);
void writeCam214SIPPDebayerHdmiOutput(Cam214SIPPDebayerHdmi *pPl);

void buildCam214SIPPDebayerHdmi(Cam214SIPPDebayerHdmi *pPl);
void configCam214SIPPDebayerHdmi(Cam214SIPPDebayerHdmi *pPl);


#endif
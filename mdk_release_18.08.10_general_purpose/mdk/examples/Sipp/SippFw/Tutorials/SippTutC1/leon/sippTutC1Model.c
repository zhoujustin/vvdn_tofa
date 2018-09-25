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

#include "sippTutC1Model.h"

#include <include/sippHwDefs.h>
#include <filters/erode5x5/erode5x5.h>


//The full-frame buffers
UInt8      DDR_DATA SippTutC1Model_dmaIn0_buffer[512      * 512     * 1  ]ALIGNED(8);
UInt8      DDR_DATA SippTutC1Model_dmaOut1_buffer[512      * 512     * 1  ]ALIGNED(8);
	
///
void readSippTutC1ModelInput(SippTutC1Model *pPl)
{
   sippRdFileU8((UInt8*)SippTutC1Model_dmaIn0_buffer,512        * 512     * 1 * sizeof(UInt8),"../../../../../../../resources/lena_512x512_luma.raw");
   //Ensure parameter is used to avoid compiler warning
   (void)(pPl);
	
}

void writeSippTutC1ModelOutput(SippTutC1Model *pPl)
{
   sippWrFileU8((UInt8*)SippTutC1Model_dmaOut1_buffer,512        * 512     * 1 * sizeof(UInt8),"output.raw");
   //Ensure parameter is used to avoid compiler warning
   (void)(pPl);

}
   
void buildSippTutC1Model(SippTutC1Model *pPl)
{
   // create new pipeline
   pPl->pl               = sippCreatePipeline(0, 7, SIPP_MBIN(mbinImgSipp));

   // create filters
   pPl->dmaIn0          =  sippCreateFilter(pPl->pl, 0x00,       512,    512,    N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
   pPl->erode5x52       =  sippCreateFilter(pPl->pl, 0x00,       512,    512,    N_PL(1),  SZ(UInt8), SZ(Erode5x5Param),  SVU_SYM(svuErode5x5),         0);
   pPl->dmaOut1         =  sippCreateFilter(pPl->pl, 0x00,       512,    512,    N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
	
   // link filters
   sippLinkFilter(pPl->erode5x52,     pPl->dmaIn0,        5,5                 );
   sippLinkFilter(pPl->dmaOut1,       pPl->erode5x52,     1,1                 );
	
}

  
void configSippTutC1Model(SippTutC1Model *pPl)
{
   DmaParam            *dmaIn0Cfg          = (DmaParam         *)pPl->dmaIn0->params;
   Erode5x5Param       *erode5x52Cfg       = (Erode5x5Param    *)pPl->erode5x52->params;
   DmaParam            *dmaOut1Cfg         = (DmaParam         *)pPl->dmaOut1->params;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // here go through all the filter instances and assign the value for all parameter
  // fields as defined in the filter property window
   erode5x52Cfg->eMat[0]=   (UInt8*)&dMat[0];
   erode5x52Cfg->eMat[1]=   (UInt8*)&dMat[2];
   erode5x52Cfg->eMat[2]=   (UInt8*)&dMat[4];
   erode5x52Cfg->eMat[3]=   (UInt8*)&dMat[6];
   erode5x52Cfg->eMat[4]=   (UInt8*)&dMat[8];
   dmaIn0Cfg->ddrAddr   = (UInt32)&SippTutC1Model_dmaIn0_buffer;
   dmaOut1Cfg->ddrAddr  = (UInt32)&SippTutC1Model_dmaOut1_buffer;
  
  
}
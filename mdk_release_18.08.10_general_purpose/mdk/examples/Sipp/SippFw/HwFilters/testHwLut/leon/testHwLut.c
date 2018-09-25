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

#include "testHwLut.h"

#include <include/sippHwDefs.h>
#include <arch/ma2x5x/include/sippHwDefs_ma2x5x.h>


//The full-frame buffers
UInt16     DDR_DATA TestHwLut_dmaIn0_buffer  [SIPP_HW_LUT_BUFFER_WIDTH* SIPP_HW_LUT_BUFFER_HEIGHT* SIPP_HW_LUT_BUFFER_NUM_IN_PLANES]ALIGNED(8);
UInt8      DDR_DATA TestHwLut_dmaOut0_buffer [SIPP_HW_LUT_BUFFER_WIDTH* SIPP_HW_LUT_BUFFER_HEIGHT* SIPP_HW_LUT_BUFFER_NUM_IN_PLANES]ALIGNED(8);
	
///
void readTestHwLutInput(TestHwLut *pPl)
{
   sippRdFileU8((UInt8*)TestHwLut_dmaIn0_buffer,SIPP_HW_LUT_BUFFER_WIDTH * SIPP_HW_LUT_BUFFER_HEIGHT * SIPP_HW_LUT_BUFFER_NUM_IN_PLANES* sizeof(UInt16),"../../../../../../../resources/OCT_384x290_I_gamma_16bpp.raw");
   //Ensure parameter is used to avoid compiler warning
   (void)(pPl);
	
}

void writeTestHwLutOutput(TestHwLut *pPl)
{
   sippWrFileU8((UInt8*)TestHwLut_dmaOut0_buffer,SIPP_HW_LUT_BUFFER_WIDTH * SIPP_HW_LUT_BUFFER_HEIGHT * SIPP_HW_LUT_BUFFER_NUM_IN_PLANES* sizeof(UInt8),"lutTestOutput.raw");
   //Ensure parameter is used to avoid compiler warning
   (void)(pPl);

}
   
void buildTestHwLut(TestHwLut *pPl)
{
   // create new pipeline
   pPl->pl               = sippCreatePipeline(0, 0, SIPP_MBIN(mbinImgSipp));

   // create filters
   pPl->dmaIn0          =  sippCreateFilter(pPl->pl, 0x00,       SIPP_HW_LUT_BUFFER_WIDTH, SIPP_HW_LUT_BUFFER_HEIGHT, N_PL(SIPP_HW_LUT_BUFFER_NUM_IN_PLANES), SZ(UInt16), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
   pPl->lutMa2x5x0      =  sippCreateFilter(pPl->pl, 0x0,        SIPP_HW_LUT_BUFFER_WIDTH, SIPP_HW_LUT_BUFFER_HEIGHT, N_PL(SIPP_HW_LUT_BUFFER_NUM_IN_PLANES), SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_LUT_ID,        0);
   pPl->dmaOut0         =  sippCreateFilter(pPl->pl, 0x00,       SIPP_HW_LUT_BUFFER_WIDTH, SIPP_HW_LUT_BUFFER_HEIGHT, N_PL(SIPP_HW_LUT_BUFFER_NUM_IN_PLANES), SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
	
   // link filters
   sippLinkFilter(pPl->lutMa2x5x0,    pPl->dmaIn0,        1,1                 );
   sippLinkFilter(pPl->dmaOut0,       pPl->lutMa2x5x0,    1,1                 );
	
}

  
void configTestHwLut(TestHwLut *pPl)
{
   DmaParam            *dmaIn0Cfg          = (DmaParam         *)pPl->dmaIn0->params;
   LutParam            *lutMa2x5x0Cfg      = (LutParam         *)pPl->lutMa2x5x0->params;
   DmaParam            *dmaOut0Cfg         = (DmaParam         *)pPl->dmaOut0->params;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // here go through all the filter instances and assign the value for all parameter
  // fields as defined in the filter property window
   lutMa2x5x0Cfg->cfg=      INTERP_MODE | CHANNEL_MODE<< 1  | INT_WIDTH<< 3  | (LUTS_NO - 1) << 8  |(CHANNELS_NO - 1) << 12 | LUT_LOAD << 14 | APB_ACCESS<< 15 | CSC_ENABLE<< 16;
   lutMa2x5x0Cfg->sizeA=    LUT_REGION0_SIZE_I | (LUT_REGION1_SIZE_I <<  4) | (LUT_REGION2_SIZE_I <<  8) | (LUT_REGION3_SIZE_I << 12) | (LUT_REGION4_SIZE_I << 16) | (LUT_REGION5_SIZE_I << 20) | (LUT_REGION6_SIZE_I << 24) | (LUT_REGION7_SIZE_I << 28);
   lutMa2x5x0Cfg->sizeB=    LUT_REGION8_SIZE_I | (LUT_REGION9_SIZE_I  <<  4) | (LUT_REGION10_SIZE_I <<  8) | (LUT_REGION11_SIZE_I << 12) | (LUT_REGION12_SIZE_I << 16) | (LUT_REGION13_SIZE_I << 20) | (LUT_REGION14_SIZE_I << 24) | (LUT_REGION15_SIZE_I << 28);
   lutMa2x5x0Cfg->lut=      (void *)appLUT;
   lutMa2x5x0Cfg->lutFormat=LUT_LD_FORMAT;
   lutMa2x5x0Cfg->mat[0]=   LUT_MAT_11;
   lutMa2x5x0Cfg->mat[1]=   LUT_MAT_12;
   lutMa2x5x0Cfg->mat[2]=   LUT_MAT_13;
   lutMa2x5x0Cfg->mat[3]=   LUT_MAT_21;
   lutMa2x5x0Cfg->mat[4]=   LUT_MAT_22;
   lutMa2x5x0Cfg->mat[5]=   LUT_MAT_23;
   lutMa2x5x0Cfg->mat[6]=   LUT_MAT_31;
   lutMa2x5x0Cfg->mat[7]=   LUT_MAT_32;
   lutMa2x5x0Cfg->mat[8]=   LUT_MAT_33;
   lutMa2x5x0Cfg->offset[0]=LUT_OFF_1;
   lutMa2x5x0Cfg->offset[1]=LUT_OFF_2;
   lutMa2x5x0Cfg->offset[2]=LUT_OFF_3;
   dmaIn0Cfg->ddrAddr   = (UInt32)&TestHwLut_dmaIn0_buffer;
   dmaOut0Cfg->ddrAddr  = (UInt32)&TestHwLut_dmaOut0_buffer;
  
  
}
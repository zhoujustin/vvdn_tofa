///
/// @file
/// @copyright All code copyright Movidius Ltd 2014, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     This file contains the declaration of the @ref conv7x1Fp16ToFp16 SIPP filter API.
///

#ifndef __SIPP_CONV7x1FP16TOFP16_H__
#define __SIPP_CONV7x1FP16TOFP16_H__ 

#include <sipp.h>

/// @sf_definition conv7x1Fp16ToFp16 Convolution 7x1 Fp16ToFp16
/// @sf_description This filter performs a convolution on the fp16 input image using the given 7x1 matrix.
/// @sf_group Arithmetic
/// @sf_outdatatype half
/// @sf_inputs
/// 	- datatypes: half; kernels: 7x1
/// @sf_extasm $(MV_COMMON_BASE)/components/kernelLib/MvCV/kernels/convolution7x1Fp16ToFp16/arch/$(MV_SOC_REV_DIR)/shave/src/convolution7x1Fp16ToFp16.asm
/// @{

/// @brief Parameter structure of the @ref conv7x1Fp16ToFp16 filter.
typedef struct
{
    /// @sf_pfdesc 7 element array with fp16 values containing the 7x1 convolution matrix.
	/// @sf_pfdefvalue 
	/// @sf_pfarraysize 7
    UInt16* cMat; //fp16 7x1 matrix
}
Conv7x1Fp16ToFp16Param;

/// @brief Shave function of the @ref conv7x1Fp16ToFp16 filter.
void SVU_SYM(svuConv7x1Fp16ToFp16)(SippFilter *fptr);
SHAVE_SYM_EXPORT(svuConv7x1Fp16ToFp16);

/// @}

#endif // __SIPP_CONV7x1FP16TOFP16_H__ 

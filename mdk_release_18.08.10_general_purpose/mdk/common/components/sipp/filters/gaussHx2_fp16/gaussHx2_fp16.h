///
/// @file
/// @copyright All code copyright Movidius Ltd 2014, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     This file contains the declaration of the @ref gaussHx2_fp16 SIPP filter API.
///

#ifndef __SIPP_GAUSS_Hx2_FP16_H__
#define __SIPP_GAUSS_Hx2_FP16_H__ 

#include <sipp.h>

/// @sf_definition gaussHx2_fp16 GaussHx2_fp16
/// @sf_description This filter applies downscale 2x horizontal gaussian blur. Has to be used in combination with GaussVx2 to obtain correct output.
/// @sf_group Arithmetic
/// @sf_outdatatype half
/// @sf_inputs
/// @sf_preserve numPlanes, dataType
///		- datatypes: half; kernels: 1x5
/// @sf_extasm $(MV_COMMON_BASE)/components/kernelLib/MvCV/kernels/gaussHx2_fp16/arch/$(MV_SOC_REV_DIR)/shave/src/gaussHx2_fp16.asm
/// @{

/// @brief Shave function of the @ref gaussHx2_fp16 filter.
void SVU_SYM(svuGaussHx2_fp16)(SippFilter *fptr);
SHAVE_SYM_EXPORT(svuGaussHx2_fp16);

/// @}

#endif // __SIPP_GAUSS_Hx2_FP16_H__ 
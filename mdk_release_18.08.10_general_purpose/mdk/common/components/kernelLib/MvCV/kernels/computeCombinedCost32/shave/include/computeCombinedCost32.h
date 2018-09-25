#ifndef __COMPUTE_COMBINED_COST_32__
#define __COMPUTE_COMBINED_COST_32__

#include <mv_types.h>
#include <mvcv_macro.h>

//!@{
/// mvcvComputeCombinedCost32 	- computes disparity cost of AD-Census 
/// @param[in] disparityCost	- matching cost
/// @param[in] adCost			- absolute difference cost
/// @param[in] alpha			- weight factor for disparityCost
/// @param[in] beta			    - weight factor for absolute difference cost
/// @param[in] width         	- image width
/// @param[in] normFactor       - normalization factor to fit in u8
/// @return    Nothing

MVCV_FUNC(void, mvcvComputeCombinedCost32, u8* disparityCost, u8* adCost, u32 alpha, u32 beta, u32 width, u32 normFactor)
//!@}
	
#endif //__COMPUTE_COMBINED_COST_32__
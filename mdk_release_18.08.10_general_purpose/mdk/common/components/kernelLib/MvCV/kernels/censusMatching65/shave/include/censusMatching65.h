#ifndef __CENSUS_MATCHING65_H__
#define __CENSUS_MATCHING65_H__

#include <mv_types.h>
#include <mvcv_macro.h>

//!@{
/// mvcvCensusMatching        - performs an XOR operation between pixel one pixel in *in1 and 65 pixels from *in2 and counts up how many values of 1 are in the result
/// @param[in] in1            - pointer to input lines of the left image
/// @param[in] in2            - pointer to input lines of the right image
/// @param[out] out           - array of disparity cost
/// @param[in] width          - width of the input lines
/// @return    Nothing

MVCV_FUNC(void, mvcvCensusMatching65, u32 *in1, u32 *in2, u8 *out, u32 width)
//!@}
	
#endif //__CENSUS_MATCHING65_H__
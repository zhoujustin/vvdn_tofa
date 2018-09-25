#include "integralImageSumM2.h"

void mvcvIntegralimage_sum_u32_M2(u32* out, u8* in, u32 runNr, u32** prevPointer, u32 width)
{
  if (0 == runNr) 
    {
        unsigned int x;
        unsigned int onLineSum = 0;;
        for(x = 0; x < width; x++)
        {
            onLineSum += in[x];
            out[x] = onLineSum;
        }
        *prevPointer = out;
    }
    else
    {
        unsigned int x;
        unsigned int onLineSum = 0;;
        for(x = 0; x < width; x++)
        {
            onLineSum += in[x];
            out[x] = (*prevPointer)[x] + onLineSum;
        }
        *prevPointer = out;
    }
	return;
}
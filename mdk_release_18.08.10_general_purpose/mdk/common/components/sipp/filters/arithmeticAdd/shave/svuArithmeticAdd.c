#include <sipp.h>
#include <sippShaveMacros.h>
#include <filters/arithmeticAdd/arithmeticAdd.h>

/// ArithmeticAdd for two arrays
///@param[in]   src1Addr    - array of pointers to input lines from the first image
///@param[in]   src2Addr    - array of pointers to input lines from the second image
///@param[out]  destAddr    - array of pointers for output line
///@param[in]   width       - width of input line
#ifdef SIPP_USE_MVCV
void mvcvArithmeticAdd_asm      (UInt8** src1, UInt8** src2, UInt8** dst, UInt32 width);
#else
void arithmeticAddImplementation(UInt8** src1, UInt8** src2, UInt8** dst, UInt32 width) {
    int i;
    float add;
    for(i = 0; i < width; i++)
    {
        add = src1[0][i] + src2[0][i];

        if (add >= 255)
            add = 255.0f;
        if (add <= 0)
            add = 0.0f;
        dst[0][i] = (UInt8)(add);
    }
}
#endif

void svuArithmeticAdd(SippFilter *fptr)
{
    UInt8 *input1[1];
    UInt8 *input2[1];
    UInt8 *output;
    UInt32 numLinesThisIter = sippFilterGetLinesThisIter (fptr);
    UInt32 iterNum;

    for (iterNum = 0; iterNum < numLinesThisIter; iterNum++)
    {
        //the 2 input lines
        input1[0] = (UInt8 *)getInPtr(fptr, 0, iterNum, 0, 0);
        input2[0] = (UInt8 *)getInPtr(fptr, 1, iterNum, 0, 0);

        //the output line
        output = (UInt8 *)getOutPtr(fptr, iterNum, 0);

    #ifdef SIPP_USE_MVCV
        mvcvArithmeticAdd_asm(input1, input2, &output, fptr->sliceWidth);
    #else
        arithmeticAddImplementation(input1, input2, &output, fptr->sliceWidth);
    #endif
    }
}
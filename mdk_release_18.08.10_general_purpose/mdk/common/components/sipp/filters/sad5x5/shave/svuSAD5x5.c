#include <sipp.h>
#include <sippShaveMacros.h>
#include <filters/sad5x5/sad5x5.h>

/// SAD (sum of absolute differences) 5x5
///@param[in] in1       - array of pointers to input lines from the first image
///@param[in] in2       - array of pointers to input lines from the second image
///@param[out] out      - array of pointers for output line
///@param[in] width     - width of input line

#ifdef SIPP_USE_MVCV
void mvcvSumOfAbsDiff5x5_asm(UInt8** in1, UInt8** in2, UInt8** out, UInt32 width);
#else
void sumOfAbsDiff5x5        (UInt8** in1, UInt8** in2, UInt8** out, UInt32 width)
{
    int x, y;
    unsigned int i;
    UInt8 *lines1[5], *lines2[5];
    float sum;

    for(i = 0; i < 5; i++)
    {
        lines1[i] = in1[i];
        lines2[i] = in2[i];
    }

    for (i = 0; i < width; i++){
        sum = 0.0;
        for (x = 0; x < 5; x++)
        {
            for (y = 0; y < 5; y++)
            {
                sum += fabs((float)(lines1[x][y - 2] - lines2[x][y - 2]));
            }
            lines1[x]++;
            lines2[x]++;
        }
        if (sum >= 255)
            sum = 255.0;
        out[0][i] = (UInt8)(sum);
    }
}
#endif

void svuSAD5x5(SippFilter *fptr)
{
    UInt8 *input1[5];
    UInt8 *input2[5];
    UInt8 *output;

    UInt32 numLinesThisIter = sippFilterGetLinesThisIter (fptr);
    UInt32 iterNum;

    for (iterNum = 0; iterNum < numLinesThisIter; iterNum++)
    {
        //the (2 * 5) input lines
        for(int i = 0; i < 5; i++)
        {
            input1[i] = (UInt8 *)getInPtr(fptr, 0, iterNum, i, 0);
            input2[i] = (UInt8 *)getInPtr(fptr, 1, iterNum, i, 0);
        }

        //the output line
        output = (UInt8 *)getOutPtr(fptr, iterNum, 0);

    #ifdef SIPP_USE_MVCV
        mvcvSumOfAbsDiff5x5_asm(input1, input2, &output, fptr->sliceWidth);
    #else
        sumOfAbsDiff5x5(input1, input2, &output, fptr->sliceWidth);
    #endif
    }
}
///
/// @file
/// @copyright All code copyright Movidius Ltd 2012, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief    Application configuration Leon file
///

#include <OsDrvShaveL2Cache.h>
#include <OsDrvCpr.h>
#include "app_config.h"

#define L2CACHE_CFG     (SHAVE_L2CACHE_NORMAL_MODE)

// 3: Global Data (Only if absolutely necessary)
// ----------------------------------------------------------------------------
// Sections decoration is required here for downstream tools

// 4: Static Local Data
// ----------------------------------------------------------------------------
// 5: Static Function Prototypes
// ----------------------------------------------------------------------------

// 6: Functions Implementation
// ----------------------------------------------------------------------------

int initClocksAndMemory(void)
{
	s32 sc;

	tyAuxClkDividerCfg auxClkAllOn[] =
	{
			{AUX_CLK_MASK_UART, CLK_SRC_REFCLK0, 96, 625},   // Give the UART an SCLK that allows it to generate an output baud rate of of 115200 Hz (the uart divides by 16)
			{0,0,0,0}, // Null Terminated List
	};

	// Configure the system
	sc = OsDrvCprInit();
	if(sc)
	    return sc;
	sc = OsDrvCprOpen();
	if(sc)
	    return sc;
	sc = OsDrvCprAuxClockArrayConfig(auxClkAllOn);
	if(sc)
	    return sc;

    // Set the shave L2 Cache mode
    sc = OsDrvShaveL2CacheInit(L2CACHE_CFG);
    if(sc)
       return sc;

    //Set Shave L2 cache partitions
    int partition_id;
    OsDrvShaveL2CGetPartition(SHAVEPART256KB, &partition_id);

    //Allocate Shave L2 cache set partitions
    sc = OsDrvShaveL2CacheAllocateSetPartitions();
    if(sc)
        return sc;

    //Assign the one partition defined to all shaves
    for (int i = 0; i < SHAVES_USED; i++)
    {
        OsDrvShaveL2CSetNonWindowedPartition(i, 0, NON_WINDOWED_DATA_PARTITION);
        OsDrvShaveL2CSetNonWindowedPartition(i, 0, NON_WINDOWED_INSTRUCTIONS_PARTITION);
    }

    OsDrvShaveL2CachePartitionInvalidate(0);
    return 0;
}
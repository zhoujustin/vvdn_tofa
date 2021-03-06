///
/// @file
/// @copyright All code copyright Movidius Ltd 2012, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     Application configuration Leon header
///

#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_

#include <mv_types.h>

//L2 cache partition number
#define PARTITION_0    (0)

/// Setup all the clock configurations needed by this application and also the ddr
///
/// @return    0 on success, non-zero otherwise  
int initClocksAndMemory(void);

#endif

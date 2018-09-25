///
/// @file
/// @copyright All code copyright Movidius Ltd 2012, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     RTEMS configuration Leon header
///
#ifndef _RTEMS_CONFIG_H_
#define _RTEMS_CONFIG_H_

// 1: Includes
// ----------------------------------------------------------------------------
#include "app_config.h"
#include "fatalExtension.h"

// 2: Defines
// ----------------------------------------------------------------------------

#if defined(__RTEMS__)

#if !defined (__CONFIG__)
#define __CONFIG__

/* ask the system to generate a configuration table */
#define CONFIGURE_INIT

#define CONFIGURE_MICROSECONDS_PER_TICK 1000 /* 1 millisecond */

#define CONFIGURE_TICKS_PER_TIMESLICE 10 /* 20 milliseconds */

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_POSIX_INIT_THREAD_TABLE

#define CONFIGURE_MINIMUM_TASK_STACK_SIZE            2048

#define CONFIGURE_MAXIMUM_USER_EXTENSIONS            4

#define CONFIGURE_INITIAL_EXTENSIONS { .fatal = Fatal_extension }

#define CONFIGURE_MAXIMUM_POSIX_THREADS              4

#define CONFIGURE_MAXIMUM_SEMAPHORES                 4

// 3:  Exported Global Data (generally better to avoid)
// ----------------------------------------------------------------------------
// 4:  Functions (non-inline)
// ----------------------------------------------------------------------------

void *POSIX_Init (void *args);

#include <rtems/confdefs.h>

#endif // __CONFIG__

#endif // __RTEMS__

// Program the booting clocks
// Clock configuration on start-up
BSP_SET_CLOCK(DEFAULT_OSC_CLOCK_KHZ, DEFAULT_APP_CLOCK_KHZ, 1, 1, DEFAULT_RTEMS_CSS_LOS_CLOCKS, DEFAULT_RTEMS_MSS_LRT_CLOCKS,APP_UPA_CLOCKS,0,0);
// Program L2 cache behaviour (Disabled)
BSP_SET_L2C_CONFIG(0, DEFAULT_RTEMS_L2C_REPLACEMENT_POLICY, DEFAULT_RTEMS_L2C_LOCKED_WAYS,DEFAULT_RTEMS_L2C_MODE, 0, 0);
#endif // _RTEMS_CONFIG_H_
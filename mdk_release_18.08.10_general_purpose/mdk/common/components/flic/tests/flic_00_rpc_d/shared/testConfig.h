///
/// @file
/// @copyright All code copyright Movidius Ltd 2017, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     Test specifics
///

#ifndef __TEST_CONFIG_H__
#define __TEST_CONFIG_H__

#if 0
  #define SZ_ETC   "2s"
  #define N         2 //number of crosses
  #define N_MSG    (16)
  #define PRINT     0
  #define LOG       1
#elif 1
  #define SZ_ETC   "1m:30s"
  #define N         8 //number of crosses
  #define N_MSG    (200*1000)
  #define PRINT     0
  #define LOG       0
#elif 0
  #define SZ_ETC   "15m"
  #define N         8 //number of crosses
  #define N_MSG    (2*1000*1000)
  #define PRINT     0
  #define LOG       0
#endif

struct MyMsg{
  uint32_t data;
};

inline bool operator==(const MyMsg& lhs, const MyMsg& rhs)
{
   if(lhs.data == rhs.data) return true;
   else                     return false;
}

#endif
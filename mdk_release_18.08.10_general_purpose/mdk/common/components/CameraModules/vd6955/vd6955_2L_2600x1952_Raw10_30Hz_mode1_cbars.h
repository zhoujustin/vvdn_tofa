//
// 30fps full live images at 2600x1952 pixels, sent on 2 MIPI lanes

//HEADER_FORMAT = V2.1

#ifndef _VD6955_2L_2600x1952_RAW10_30HZ_MODE1_CB_H_
#define _VD6955_2L_2600x1952_RAW10_30HZ_MODE1_CB_H_

#include "CameraDefines.h"
#include "mv_types.h"

#define VD6955_2L_2600x1952_RAW10_30HZ_MODE1_CB_I2C_CONFIG_STEPS (4)
//there must be at least 3 standard steps present in the file:
//0)          configure registers set0
//(1), (2)... optionally configure other registers set
//N-1)        set the streaming register (individual step)
//N)          set the standby register (individual step)


const u16 vd6955_2L_2600x1952_RAW10_30Hz_mode1_cbars_I2Cregs[][2] =
{
//configuration step 0
   {0x3002, 0x32},
   {0x3016, 0x46},
   {0x3017, 0x29},
   {0x3003, 0x03},
   {0x3045, 0x03},
   {0xFBD7, 0x00},
   {0xFBD8, 0x00},
   {0xFBD9, 0x00},
   {0xFBDA, 0x00},
   {0xFBDB, 0x00},
   {0xFBDC, 0x00},
   {0xFBDD, 0x00},
   {0xFBDE, 0x00},
   {0xFBDF, 0x00},
   {0xFBE0, 0x00},
   {0xFBE1, 0x00},
   {0xFBE2, 0x00},
   {0xFBE3, 0x00},
   {0xFBE4, 0x00},
   {0xFBE5, 0x00},
   {0xFBE6, 0x00},
   {0xFBE7, 0x00},
   {0xFBE8, 0x00},
   {0xFBE9, 0x00},
   {0xFBEA, 0x00},
   {0xFBEB, 0x00},
   {0xFBEC, 0x00},
   {0xFBED, 0x00},
   {0xFBEE, 0x00},
   {0xFBEF, 0x00},
   {0xFBF0, 0x00},
   {0xFBF1, 0x00},
   {0xFBF2, 0x00},
   {0xFBF3, 0x00},
   {0xFBF4, 0x00},
   {0xFBF5, 0x00},
   {0xFBF6, 0x00},
   {0xFBF7, 0x00},
   {0xFBF8, 0x00},
   {0xFBF9, 0x00},
   {0xFBFA, 0x00},
   {0xFBFB, 0x00},
   {0xFBFC, 0x00},
   {0xFBFD, 0x00},
   {0xFBFE, 0x00},
   {0xFB00, 0x51},
   {0xF800, 0xc0},
   {0xF801, 0x24},
   {0xF802, 0x7c},
   {0xF803, 0xfb},
   {0xF804, 0x7d},
   {0xF805, 0xc7},
   {0xF806, 0x7b},
   {0xF807, 0x10},
   {0xF808, 0x7f},
   {0xF809, 0x72},
   {0xF80A, 0x7e},
   {0xF80B, 0x30},
   {0xF80C, 0x12},
   {0xF80D, 0x09},
   {0xF80E, 0x47},
   {0xF80F, 0xd0},
   {0xF810, 0x24},
   {0xF811, 0x90},
   {0xF812, 0x02},
   {0xF813, 0x05},
   {0xF814, 0xe0},
   {0xF815, 0xf5},
   {0xF816, 0x77},
   {0xF817, 0xe5},
   {0xF818, 0x77},
   {0xF819, 0xc3},
   {0xF81A, 0x94},
   {0xF81B, 0x80},
   {0xF81C, 0x50},
   {0xF81D, 0x08},
   {0xF81E, 0x75},
   {0xF81F, 0x7a},
   {0xF820, 0xfb},
   {0xF821, 0x75},
   {0xF822, 0x7b},
   {0xF823, 0xd7},
   {0xF824, 0x80},
   {0xF825, 0x33},
   {0xF826, 0xe5},
   {0xF827, 0x77},
   {0xF828, 0xc3},
   {0xF829, 0x94},
   {0xF82A, 0xc0},
   {0xF82B, 0x50},
   {0xF82C, 0x08},
   {0xF82D, 0x75},
   {0xF82E, 0x7a},
   {0xF82F, 0xfb},
   {0xF830, 0x75},
   {0xF831, 0x7b},
   {0xF832, 0xdb},
   {0xF833, 0x80},
   {0xF834, 0x24},
   {0xF835, 0xe5},
   {0xF836, 0x77},
   {0xF837, 0xc3},
   {0xF838, 0x94},
   {0xF839, 0xe0},
   {0xF83A, 0x50},
   {0xF83B, 0x08},
   {0xF83C, 0x75},
   {0xF83D, 0x7a},
   {0xF83E, 0xfb},
   {0xF83F, 0x75},
   {0xF840, 0x7b},
   {0xF841, 0xdf},
   {0xF842, 0x80},
   {0xF843, 0x15},
   {0xF844, 0xe5},
   {0xF845, 0x77},
   {0xF846, 0xc3},
   {0xF847, 0x94},
   {0xF848, 0xf0},
   {0xF849, 0x50},
   {0xF84A, 0x08},
   {0xF84B, 0x75},
   {0xF84C, 0x7a},
   {0xF84D, 0xfb},
   {0xF84E, 0x75},
   {0xF84F, 0x7b},
   {0xF850, 0xe3},
   {0xF851, 0x80},
   {0xF852, 0x06},
   {0xF853, 0x75},
   {0xF854, 0x7a},
   {0xF855, 0xfb},
   {0xF856, 0x75},
   {0xF857, 0x7b},
   {0xF858, 0xe7},
   {0xF859, 0xe5},
   {0xF85A, 0x55},
   {0xF85B, 0x7f},
   {0xF85C, 0x00},
   {0xF85D, 0xb4},
   {0xF85E, 0x22},
   {0xF85F, 0x02},
   {0xF860, 0x7f},
   {0xF861, 0x01},
   {0xF862, 0xe5},
   {0xF863, 0x53},
   {0xF864, 0x5f},
   {0xF865, 0x60},
   {0xF866, 0x05},
   {0xF867, 0x74},
   {0xF868, 0x14},
   {0xF869, 0x12},
   {0xF86A, 0xfa},
   {0xF86B, 0x4c},
   {0xF86C, 0x75},
   {0xF86D, 0x7c},
   {0xF86E, 0xfb},
   {0xF86F, 0x75},
   {0xF870, 0x7d},
   {0xF871, 0xc7},
   {0xF872, 0x75},
   {0xF873, 0x7e},
   {0xF874, 0x30},
   {0xF875, 0x75},
   {0xF876, 0x7f},
   {0xF877, 0x62},
   {0xF878, 0xe4},
   {0xF879, 0xf5},
   {0xF87A, 0x77},
   {0xF87B, 0xe5},
   {0xF87C, 0x77},
   {0xF87D, 0xc3},
   {0xF87E, 0x94},
   {0xF87F, 0x08},
   {0xF880, 0x40},
   {0xF881, 0x03},
   {0xF882, 0x02},
   {0xF883, 0xf9},
   {0xF884, 0x0e},
   {0xF885, 0x85},
   {0xF886, 0x7d},
   {0xF887, 0x82},
   {0xF888, 0x85},
   {0xF889, 0x7c},
   {0xF88A, 0x83},
   {0xF88B, 0xe0},
   {0xF88C, 0xfe},
   {0xF88D, 0xa3},
   {0xF88E, 0xe0},
   {0xF88F, 0xff},
   {0xF890, 0x12},
   {0xF891, 0x21},
   {0xF892, 0x22},
   {0xF893, 0x8e},
   {0xF894, 0x78},
   {0xF895, 0x8f},
   {0xF896, 0x79},
   {0xF897, 0x12},
   {0xF898, 0xfa},
   {0xF899, 0x40},
   {0xF89A, 0x12},
   {0xF89B, 0x22},
   {0xF89C, 0x93},
   {0xF89D, 0x50},
   {0xF89E, 0x07},
   {0xF89F, 0xe4},
   {0xF8A0, 0xf5},
   {0xF8A1, 0x78},
   {0xF8A2, 0xf5},
   {0xF8A3, 0x79},
   {0xF8A4, 0x80},
   {0xF8A5, 0x33},
   {0xF8A6, 0x12},
   {0xF8A7, 0xfa},
   {0xF8A8, 0x40},
   {0xF8A9, 0x7b},
   {0xF8AA, 0x01},
   {0xF8AB, 0xaf},
   {0xF8AC, 0x79},
   {0xF8AD, 0xae},
   {0xF8AE, 0x78},
   {0xF8AF, 0x12},
   {0xF8B0, 0x22},
   {0xF8B1, 0x4f},
   {0xF8B2, 0x74},
   {0xF8B3, 0x02},
   {0xF8B4, 0x12},
   {0xF8B5, 0xfa},
   {0xF8B6, 0x4c},
   {0xF8B7, 0x85},
   {0xF8B8, 0x7b},
   {0xF8B9, 0x82},
   {0xF8BA, 0xf5},
   {0xF8BB, 0x83},
   {0xF8BC, 0xe0},
   {0xF8BD, 0xfe},
   {0xF8BE, 0xa3},
   {0xF8BF, 0xe0},
   {0xF8C0, 0xff},
   {0xF8C1, 0x7d},
   {0xF8C2, 0x03},
   {0xF8C3, 0x12},
   {0xF8C4, 0x17},
   {0xF8C5, 0xd8},
   {0xF8C6, 0x12},
   {0xF8C7, 0x1b},
   {0xF8C8, 0x9b},
   {0xF8C9, 0x8e},
   {0xF8CA, 0x78},
   {0xF8CB, 0x8f},
   {0xF8CC, 0x79},
   {0xF8CD, 0x74},
   {0xF8CE, 0xfe},
   {0xF8CF, 0x25},
   {0xF8D0, 0x7b},
   {0xF8D1, 0xf5},
   {0xF8D2, 0x7b},
   {0xF8D3, 0x74},
   {0xF8D4, 0xff},
   {0xF8D5, 0x35},
   {0xF8D6, 0x7a},
   {0xF8D7, 0xf5},
   {0xF8D8, 0x7a},
   {0xF8D9, 0x78},
   {0xF8DA, 0x24},
   {0xF8DB, 0xe6},
   {0xF8DC, 0xff},
   {0xF8DD, 0xc3},
   {0xF8DE, 0x74},
   {0xF8DF, 0x20},
   {0xF8E0, 0x9f},
   {0xF8E1, 0x7e},
   {0xF8E2, 0x00},
   {0xF8E3, 0x25},
   {0xF8E4, 0x79},
   {0xF8E5, 0xff},
   {0xF8E6, 0xee},
   {0xF8E7, 0x35},
   {0xF8E8, 0x78},
   {0xF8E9, 0x85},
   {0xF8EA, 0x7f},
   {0xF8EB, 0x82},
   {0xF8EC, 0x85},
   {0xF8ED, 0x7e},
   {0xF8EE, 0x83},
   {0xF8EF, 0xf0},
   {0xF8F0, 0xa3},
   {0xF8F1, 0xef},
   {0xF8F2, 0xf0},
   {0xF8F3, 0x05},
   {0xF8F4, 0x77},
   {0xF8F5, 0x74},
   {0xF8F6, 0x02},
   {0xF8F7, 0x25},
   {0xF8F8, 0x7d},
   {0xF8F9, 0xf5},
   {0xF8FA, 0x7d},
   {0xF8FB, 0xe4},
   {0xF8FC, 0x35},
   {0xF8FD, 0x7c},
   {0xF8FE, 0xf5},
   {0xF8FF, 0x7c},
   {0xF900, 0x74},
   {0xF901, 0x02},
   {0xF902, 0x25},
   {0xF903, 0x7f},
   {0xF904, 0xf5},
   {0xF905, 0x7f},
   {0xF906, 0xe4},
   {0xF907, 0x35},
   {0xF908, 0x7e},
   {0xF909, 0xf5},
   {0xF90A, 0x7e},
   {0xF90B, 0x02},
   {0xF90C, 0xf8},
   {0xF90D, 0x7b},
   {0xF90E, 0x22},
   {0xF90F, 0x90},
   {0xF910, 0x30},
   {0xF911, 0x47},
   {0xF912, 0x74},
   {0xF913, 0x98},
   {0xF914, 0xf0},
   {0xF915, 0x90},
   {0xF916, 0x30},
   {0xF917, 0x36},
   {0xF918, 0x74},
   {0xF919, 0x1e},
   {0xF91A, 0xf0},
   {0xF91B, 0x90},
   {0xF91C, 0x30},
   {0xF91D, 0x42},
   {0xF91E, 0x74},
   {0xF91F, 0x24},
   {0xF920, 0xf0},
   {0xF921, 0xe5},
   {0xF922, 0x53},
   {0xF923, 0x60},
   {0xF924, 0x42},
   {0xF925, 0x78},
   {0xF926, 0x2b},
   {0xF927, 0x76},
   {0xF928, 0x01},
   {0xF929, 0xe5},
   {0xF92A, 0x55},
   {0xF92B, 0xb4},
   {0xF92C, 0x22},
   {0xF92D, 0x17},
   {0xF92E, 0x90},
   {0xF92F, 0x30},
   {0xF930, 0x36},
   {0xF931, 0x74},
   {0xF932, 0x46},
   {0xF933, 0xf0},
   {0xF934, 0x78},
   {0xF935, 0x28},
   {0xF936, 0x76},
   {0xF937, 0x31},
   {0xF938, 0x90},
   {0xF939, 0x30},
   {0xF93A, 0x0e},
   {0xF93B, 0xe0},
   {0xF93C, 0xc3},
   {0xF93D, 0x13},
   {0xF93E, 0x30},
   {0xF93F, 0xe0},
   {0xF940, 0x04},
   {0xF941, 0x78},
   {0xF942, 0x26},
   {0xF943, 0x76},
   {0xF944, 0x40},
   {0xF945, 0xe5},
   {0xF946, 0x55},
   {0xF947, 0xb4},
   {0xF948, 0x44},
   {0xF949, 0x21},
   {0xF94A, 0x90},
   {0xF94B, 0x30},
   {0xF94C, 0x47},
   {0xF94D, 0x74},
   {0xF94E, 0x9a},
   {0xF94F, 0xf0},
   {0xF950, 0x90},
   {0xF951, 0x30},
   {0xF952, 0x42},
   {0xF953, 0x74},
   {0xF954, 0x64},
   {0xF955, 0xf0},
   {0xF956, 0x90},
   {0xF957, 0x30},
   {0xF958, 0x0e},
   {0xF959, 0xe0},
   {0xF95A, 0x13},
   {0xF95B, 0x13},
   {0xF95C, 0x54},
   {0xF95D, 0x3f},
   {0xF95E, 0x30},
   {0xF95F, 0xe0},
   {0xF960, 0x0a},
   {0xF961, 0x78},
   {0xF962, 0x24},
   {0xF963, 0xe4},
   {0xF964, 0xf6},
   {0xF965, 0x80},
   {0xF966, 0x04},
   {0xF967, 0x78},
   {0xF968, 0x2b},
   {0xF969, 0xe4},
   {0xF96A, 0xf6},
   {0xF96B, 0x90},
   {0xF96C, 0x30},
   {0xF96D, 0x88},
   {0xF96E, 0x02},
   {0xF96F, 0x1d},
   {0xF970, 0x4f},
   {0xF971, 0x22},
   {0xF972, 0x90},
   {0xF973, 0x0c},
   {0xF974, 0x1a},
   {0xF975, 0xe0},
   {0xF976, 0x30},
   {0xF977, 0xe2},
   {0xF978, 0x18},
   {0xF979, 0x90},
   {0xF97A, 0x33},
   {0xF97B, 0x68},
   {0xF97C, 0xe0},
   {0xF97D, 0x64},
   {0xF97E, 0x05},
   {0xF97F, 0x70},
   {0xF980, 0x2f},
   {0xF981, 0x90},
   {0xF982, 0x30},
   {0xF983, 0x38},
   {0xF984, 0xe0},
   {0xF985, 0x70},
   {0xF986, 0x02},
   {0xF987, 0xa3},
   {0xF988, 0xe0},
   {0xF989, 0xc3},
   {0xF98A, 0x70},
   {0xF98B, 0x01},
   {0xF98C, 0xd3},
   {0xF98D, 0x40},
   {0xF98E, 0x21},
   {0xF98F, 0x80},
   {0xF990, 0x1b},
   {0xF991, 0x90},
   {0xF992, 0x33},
   {0xF993, 0x68},
   {0xF994, 0xe0},
   {0xF995, 0xb4},
   {0xF996, 0x05},
   {0xF997, 0x18},
   {0xF998, 0xc3},
   {0xF999, 0x90},
   {0xF99A, 0x30},
   {0xF99B, 0x3b},
   {0xF99C, 0xe0},
   {0xF99D, 0x94},
   {0xF99E, 0x0d},
   {0xF99F, 0x90},
   {0xF9A0, 0x30},
   {0xF9A1, 0x3a},
   {0xF9A2, 0xe0},
   {0xF9A3, 0x94},
   {0xF9A4, 0x00},
   {0xF9A5, 0x50},
   {0xF9A6, 0x02},
   {0xF9A7, 0x80},
   {0xF9A8, 0x01},
   {0xF9A9, 0xc3},
   {0xF9AA, 0x40},
   {0xF9AB, 0x04},
   {0xF9AC, 0x75},
   {0xF9AD, 0x10},
   {0xF9AE, 0x01},
   {0xF9AF, 0x22},
   {0xF9B0, 0x02},
   {0xF9B1, 0x16},
   {0xF9B2, 0xe1},
   {0xF9B3, 0x22},
   {0xF9B4, 0x90},
   {0xF9B5, 0xff},
   {0xF9B6, 0x33},
   {0xF9B7, 0xe0},
   {0xF9B8, 0x90},
   {0xF9B9, 0xff},
   {0xF9BA, 0x34},
   {0xF9BB, 0xe0},
   {0xF9BC, 0x60},
   {0xF9BD, 0x0d},
   {0xF9BE, 0x7c},
   {0xF9BF, 0xfb},
   {0xF9C0, 0x7d},
   {0xF9C1, 0xd7},
   {0xF9C2, 0x7b},
   {0xF9C3, 0x28},
   {0xF9C4, 0x7f},
   {0xF9C5, 0x34},
   {0xF9C6, 0x7e},
   {0xF9C7, 0xff},
   {0xF9C8, 0x12},
   {0xF9C9, 0x09},
   {0xF9CA, 0x47},
   {0xF9CB, 0x7f},
   {0xF9CC, 0x20},
   {0xF9CD, 0x7e},
   {0xF9CE, 0x01},
   {0xF9CF, 0x7d},
   {0xF9D0, 0x00},
   {0xF9D1, 0x7c},
   {0xF9D2, 0x00},
   {0xF9D3, 0x12},
   {0xF9D4, 0x12},
   {0xF9D5, 0xa4},
   {0xF9D6, 0xe4},
   {0xF9D7, 0x90},
   {0xF9D8, 0x3e},
   {0xF9D9, 0x44},
   {0xF9DA, 0xf0},
   {0xF9DB, 0x02},
   {0xF9DC, 0x16},
   {0xF9DD, 0x7e},
   {0xF9DE, 0x22},
   {0xF9DF, 0xe5},
   {0xF9E0, 0x44},
   {0xF9E1, 0x60},
   {0xF9E2, 0x10},
   {0xF9E3, 0x90},
   {0xF9E4, 0xf6},
   {0xF9E5, 0x2c},
   {0xF9E6, 0x74},
   {0xF9E7, 0x04},
   {0xF9E8, 0xf0},
   {0xF9E9, 0x90},
   {0xF9EA, 0xf6},
   {0xF9EB, 0x34},
   {0xF9EC, 0xf0},
   {0xF9ED, 0x90},
   {0xF9EE, 0xf6},
   {0xF9EF, 0x3c},
   {0xF9F0, 0xf0},
   {0xF9F1, 0x80},
   {0xF9F2, 0x0e},
   {0xF9F3, 0x90},
   {0xF9F4, 0xf5},
   {0xF9F5, 0xc0},
   {0xF9F6, 0x74},
   {0xF9F7, 0x04},
   {0xF9F8, 0xf0},
   {0xF9F9, 0x90},
   {0xF9FA, 0xf5},
   {0xF9FB, 0xc8},
   {0xF9FC, 0xf0},
   {0xF9FD, 0x90},
   {0xF9FE, 0xf5},
   {0xF9FF, 0xd0},
   {0xFA00, 0xf0},
   {0xFA01, 0x90},
   {0xFA02, 0xfb},
   {0xFA03, 0x7f},
   {0xFA04, 0x02},
   {0xFA05, 0x19},
   {0xFA06, 0x0b},
   {0xFA07, 0x22},
   {0xFA08, 0x90},
   {0xFA09, 0x0c},
   {0xFA0A, 0x1a},
   {0xFA0B, 0xe0},
   {0xFA0C, 0x20},
   {0xFA0D, 0xe2},
   {0xFA0E, 0x15},
   {0xFA0F, 0xe4},
   {0xFA10, 0x90},
   {0xFA11, 0x30},
   {0xFA12, 0xf8},
   {0xFA13, 0xf0},
   {0xFA14, 0xa3},
   {0xFA15, 0xf0},
   {0xFA16, 0x90},
   {0xFA17, 0x30},
   {0xFA18, 0xf1},
   {0xFA19, 0xe0},
   {0xFA1A, 0x44},
   {0xFA1B, 0x08},
   {0xFA1C, 0xf0},
   {0xFA1D, 0x90},
   {0xFA1E, 0x30},
   {0xFA1F, 0xf0},
   {0xFA20, 0xe0},
   {0xFA21, 0x44},
   {0xFA22, 0x08},
   {0xFA23, 0xf0},
   {0xFA24, 0x02},
   {0xFA25, 0x03},
   {0xFA26, 0xde},
   {0xFA27, 0x22},
   {0xFA28, 0x90},
   {0xFA29, 0x0c},
   {0xFA2A, 0x1a},
   {0xFA2B, 0xe0},
   {0xFA2C, 0x30},
   {0xFA2D, 0xe2},
   {0xFA2E, 0x0d},
   {0xFA2F, 0xe0},
   {0xFA30, 0x20},
   {0xFA31, 0xe0},
   {0xFA32, 0x06},
   {0xFA33, 0x90},
   {0xFA34, 0xfb},
   {0xFA35, 0x85},
   {0xFA36, 0x74},
   {0xFA37, 0x00},
   {0xFA38, 0xa5},
   {0xFA39, 0x12},
   {0xFA3A, 0x16},
   {0xFA3B, 0xa0},
   {0xFA3C, 0x02},
   {0xFA3D, 0x18},
   {0xFA3E, 0xac},
   {0xFA3F, 0x22},
   {0xFA40, 0x85},
   {0xFA41, 0x7b},
   {0xFA42, 0x82},
   {0xFA43, 0x85},
   {0xFA44, 0x7a},
   {0xFA45, 0x83},
   {0xFA46, 0xe0},
   {0xFA47, 0xfc},
   {0xFA48, 0xa3},
   {0xFA49, 0xe0},
   {0xFA4A, 0xfd},
   {0xFA4B, 0x22},
   {0xFA4C, 0x25},
   {0xFA4D, 0x7b},
   {0xFA4E, 0xf5},
   {0xFA4F, 0x7b},
   {0xFA50, 0xe4},
   {0xFA51, 0x35},
   {0xFA52, 0x7a},
   {0xFA53, 0xf5},
   {0xFA54, 0x7a},
   {0xFA55, 0x22},
   {0xFA56, 0xc0},
   {0xFA57, 0xd0},
   {0xFA58, 0x90},
   {0xFA59, 0x35},
   {0xFA5A, 0xb5},
   {0xFA5B, 0xe0},
   {0xFA5C, 0x54},
   {0xFA5D, 0xfc},
   {0xFA5E, 0x44},
   {0xFA5F, 0x01},
   {0xFA60, 0xf0},
   {0xFA61, 0x12},
   {0xFA62, 0x1f},
   {0xFA63, 0x5f},
   {0xFA64, 0xd0},
   {0xFA65, 0xd0},
   {0xFA66, 0x02},
   {0xFA67, 0x0a},
   {0xFA68, 0x16},
   {0xFA69, 0x22},
   {0xFA6A, 0x90},
   {0xFA6B, 0x0c},
   {0xFA6C, 0x1a},
   {0xFA6D, 0xe0},
   {0xFA6E, 0x20},
   {0xFA6F, 0xe0},
   {0xFA70, 0x06},
   {0xFA71, 0x90},
   {0xFA72, 0xfb},
   {0xFA73, 0x85},
   {0xFA74, 0x74},
   {0xFA75, 0x00},
   {0xFA76, 0xa5},
   {0xFA77, 0xe5},
   {0xFA78, 0x10},
   {0xFA79, 0x02},
   {0xFA7A, 0x1e},
   {0xFA7B, 0x8f},
   {0xFA7C, 0x22},
   {0xFA7D, 0x90},
   {0xFA7E, 0xfb},
   {0xFA7F, 0x85},
   {0xFA80, 0x74},
   {0xFA81, 0x00},
   {0xFA82, 0xa5},
   {0xFA83, 0xe5},
   {0xFA84, 0x1a},
   {0xFA85, 0x60},
   {0xFA86, 0x03},
   {0xFA87, 0x02},
   {0xFA88, 0x17},
   {0xFA89, 0x47},
   {0xFA8A, 0x22},
   {0xFA8B, 0x90},
   {0xFA8C, 0xfb},
   {0xFA8D, 0x84},
   {0xFA8E, 0x02},
   {0xFA8F, 0x18},
   {0xFA90, 0xd9},
   {0xFA91, 0x22},
   {0xFA92, 0x02},
   {0xFA93, 0x1f},
   {0xFA94, 0xb1},
   {0xFA95, 0x22},
   {0x35D8, 0x01},
   {0x35D9, 0x0F},
   {0x35DA, 0x01},
   {0x35DB, 0x72},
   {0x35DC, 0x01},
   {0x35DD, 0xB4},
   {0x35DE, 0x01},
   {0x35DF, 0xDF},
   {0x35E0, 0x02},
   {0x35E1, 0x08},
   {0x35E2, 0x02},
   {0x35E3, 0x28},
   {0x35E4, 0x02},
   {0x35E5, 0x56},
   {0x35E6, 0x02},
   {0x35E7, 0x6A},
   {0x35E8, 0x02},
   {0x35E9, 0x7D},
   {0x35EA, 0x02},
   {0x35EB, 0x8B},
   {0x35EC, 0x02},
   {0x35ED, 0x92},
   {0x35EF, 0x22},
   {0x35F1, 0x23},
   {0x35F3, 0x22},
   {0x35F6, 0x19},
   {0x35F7, 0x55},
   {0x35F8, 0x1D},
   {0x35F9, 0x4C},
   {0x35FA, 0x16},
   {0x35FB, 0xC7},
   {0x35FC, 0x1A},
   {0x35FD, 0xA0},
   {0x35FE, 0x18},
   {0x35FF, 0xD6},
   {0x3600, 0x03},
   {0x3601, 0xD4},
   {0x3602, 0x18},
   {0x3603, 0x8A},
   {0x3604, 0x0A},
   {0x3605, 0x0D},
   {0x3606, 0x1E},
   {0x3607, 0x8D},
   {0x3608, 0x17},
   {0x3609, 0x43},
   {0x360A, 0x19},
   {0x360B, 0x16},
   {0x360C, 0x1F},
   {0x360D, 0xAD},
   {0x360E, 0x19},
   {0x360F, 0x08},
   {0x3610, 0x14},
   {0x3611, 0x26},
   {0x3612, 0x1A},
   {0x3613, 0xB3},
   {0x35D2, 0x7F},
   {0x35D3, 0xFF},
   {0x35D4, 0x70},
   {0x35D0, 0x01},
   {0x3E44, 0x01},
   {0x3570, 0x01},
//Wait{100}

//configuration step 1
   {0x0111, 0x02}, // CSI2 Mode
   {0x0112, 0x0a}, // 10-bit
   {0x0113, 0x0a}, // 10-bit
   {0x0114, 0x01}, // Dual Lane
   {0x6006, 0x00}, // no NOT swap data lanes
   {0x6007, 0x00}, //
   {0x6008, 0x00}, //
   {0x0900, 0x00}, // Disable binning
   {0x2136, 0x10},
   {0x2137, 0x00}, // EXTCLK = 16 MHz
   {0x0300, 0x00},
   {0x0301, 0x0a}, // VT Pix Clk Div 10
   {0x0302, 0x00},
   {0x0303, 0x01}, // VT Sys Clk Div 1
   {0x0304, 0x00},
   {0x0305, 0x02}, // Pre PLL Clk Div 2
   {0x0306, 0x00},
   {0x0307, 0xFB}, // PLL Multiplier 0x00FB = 204
   {0x0308, 0x00},
   {0x0309, 0x0a}, // Op Pix Clk Div 10
   {0x030a, 0x00},
   {0x030b, 0x01}, // Op Sys Clk Div 1
   {0x0340, 0x07},
   {0x0341, 0xba}, // Frame length 0x07BA = 1977
   {0x034c, 0x0a},
   {0x034d, 0x28}, // X Output size 2600
   {0x034e, 0x07},
   {0x034f, 0xa0}, // Y Output size 1952
   {0x040c, 0x0a},
   {0x040d, 0x28}, // Digital Crop Image Width 2600
   {0x040e, 0x07},
   {0x040f, 0xa0}, // Digital Crop Image Height 1952
   {0x0202, 0x0f},
   {0x0203, 0x0f}, // Coarse Integration Time 1965
   {0x0204, 0x00},
   {0x0205, 0x00}, // Analogue Gain 1
   {0x0600, 0x00},
   {0x0601, 0x02},  //Test mode on (color bars)
//Wait{100}

//configuration step 2 (independent step)
   {0x0100, 0x01},  // Mode Select - start streaming
//Wait{100}

//configuration step 3 (independent step)
   {0x0100, 0x00}  // Mode Select - stop streaming
//Wait{100}
};

I2CConfigDescriptor vd6955_2L_2600x1952_RAW10_30Hz_mode1_cbars_I2CConfigSteps[VD6955_2L_2600x1952_RAW10_30HZ_MODE1_CB_I2C_CONFIG_STEPS] =
{
      { .numberOfRegs = 769,
        .delayMs = 100
      },
      { .numberOfRegs = 38,
        .delayMs = 100
      },
      { .numberOfRegs = 1, //the streaming configuration step
        .delayMs = 0
      },
      { .numberOfRegs = 1, //the standby configuration step
        .delayMs = 0
      }
};

const mipiSpec vd6955_2L_2600x1952_RAW10_30Hz_mode1_cbars_mipiCfg =
{
      .dataMode     = MIPI_D_MODE_0,
      .dataRateMbps = 1000,
      .nbOflanes    = 2,
      .pixelFormat  = CSI_RAW_10
};


GenericCamSpec vd6955_2L_2600x1952_RAW10_30Hz_mode1_cbars_camCfg =
{
      .frameWidth            = 2600,
      .frameHeight           = 1952,
      .hBackPorch            = 0,
      .hFrontPorch           = 0,
      .vBackPorch            = 0,
      .vFrontPorch           = 0,
      .bytesPerPixel         = 2,
      .internalPixelFormat   = RAW16,
      .mipiCfg               = &vd6955_2L_2600x1952_RAW10_30Hz_mode1_cbars_mipiCfg,
      .idealRefFreq          = 16,
      .sensorI2CAddress1     = (0x36>>1),
      .sensorI2CAddress2     = (0x36>>1),
      .nbOfI2CConfigSteps    = VD6955_2L_2600x1952_RAW10_30HZ_MODE1_CB_I2C_CONFIG_STEPS,
      .i2cConfigSteps        = vd6955_2L_2600x1952_RAW10_30Hz_mode1_cbars_I2CConfigSteps,
      .regSize               = 1, //data register size (register address size always on 2 bytes)
      .regValues             = vd6955_2L_2600x1952_RAW10_30Hz_mode1_cbars_I2Cregs,
};


#endif //_VD6955_2L_2600x1952_RAW10_30HZ_MODE1_CB_H_
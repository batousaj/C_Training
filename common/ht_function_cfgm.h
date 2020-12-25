/**
 * @file ht_constant.h
 * @author Thien Vu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef HT_FUNCTION_CFGM_H
#define HT_FUNCTION_CFGM_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Define data type ussigned -- 1 byte -- 2 byte -- 3 byte -- 4 byte
typedef uint8_t     uint8 ;
typedef uint16_t    uint16 ;
typedef uint32_t    uint32 ;
typedef uint64_t    uint64 ;

// Define data type -- 1 byte -- 2 byte -- 3 byte -- 4 byte
typedef int8_t      int8 ;
typedef int16_t     int16 ;
typedef int32_t     int32 ;
typedef int64_t     int64 ;

typedef enum {
    FALSE,
    TRUE
} bool_t;

#ifdef __cplusplus
}
#endif
#endif
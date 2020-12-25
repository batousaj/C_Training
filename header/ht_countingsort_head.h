/**
 * @file ht_countingsort_head.h
 * @author Thien Vu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef ht_countingsort_head_H
#define ht_countingsort_head_H

#include <stdint.h>
#include "ht_constant.h"

// enum  ht_list_day_tmp_2{
//     Monday,
//     Tuesday,
//     Wednesday,
//     Thursday,
//     Friday,
//     Saturday,
//     Sunday,
//     No_day
    
// } ;

typedef enum  {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
    No_day
    
} ht_list_day_tmp_2;

typedef struct {
    uint32_t ht_list_u32;
    uint8_t ht_test_u8;
    uint8_t *ht_day_u8;

} ht_maxswing_tmp;

#endif // * define !ht_countingsort_head_H //

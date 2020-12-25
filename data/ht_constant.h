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

#ifndef HT_CONSTANT_H
#define HT_CONSTANT_H

#include <stdint.h>
#include "ht_function_cfgm.h"

#define  ht_testcase_h          1u
#define  ht_constantvalue_flash 0x02


#define ht_zero     0u
#define ht_one      1u
#define ht_two      2u
#define ht_three    3u
#define ht_four     4u
#define ht_five     5u
#define ht_six      0x06
#define ht_seven    0x07
#define ht_eight    0x08
#define ht_night    0x09
#define ht_ten      0x0A

extern uint8 ht_counter_u8;
extern uint8 ht_index_u8  ; 
extern uint8 ht_state_u8  ;
extern uint8 ht_flow_u8   ;


bool_t ht_switch_bo     ; 
bool_t ht_statement_bo  ;

#endif
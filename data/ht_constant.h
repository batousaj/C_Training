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
#include "ht_function_flp.h"

#define  ht_testcase_h          1u
#define  ht_constantvalue_flash 0x02


extern uint8 ht_counter_u8;
extern uint8 ht_index_u8  ; 
extern uint8 ht_state_u8  ;
extern uint8 ht_flow_u8   ;


extern bool_t ht_switch_bo     ; 
extern bool_t ht_statement_bo  ;


#endif
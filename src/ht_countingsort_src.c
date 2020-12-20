/**
 * @file ht_countingsort_src.c
 * @author Thien Vu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "ht_countingsort_head.h"
#include "ht_main_head.h"
#include <stdio.h>

int stack_counter = 0;

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


#ifdef ht_testcase_h
    uint16_t ht_tmp_count_u16 =  (uint16_t)ht_testcase_h;
#endif

uint8_t ht_i,value=7;
uint8_t ht_count_for;

#define ht_zero 0u
#define ht_seven 0x07

void ht_countingsort(void) 
{
    // enum ht_list_day_tmp_2 day;
    
    ht_list_day_tmp_2 day;
    day = No_day;

    printf("%d",(uint8_t)(day));

    for ( ht_count_for = ht_zero; ht_count_for < (uint8_t)ht_seven ; ht_count_for++ )
    {
        ht_maxswing_tmp ht_inforday_num = 
        {
            day, ht_count_for, (uint8_t*)&value
        };
        printf(" \n %d - %d - %d ",ht_inforday_num.ht_list_u32,ht_inforday_num.ht_test_u8,ht_inforday_num.ht_day_u8);
    }

    
    printf("\nI'm thien\n");
    printf("%d \n",stack_counter);
    
}


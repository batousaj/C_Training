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

#include "ht_main_head.h"
#include "ht_countingsort_head.h"

#include <stdio.h>

uint8 ht_counter_u8 = 0;
uint8 ht_index_u8 = 0;

#ifdef ht_testcase_h
    uint16_t ht_tmp_count_u16 =  (uint16_t)ht_testcase_h;
#endif

uint8 value=7;


static void ht_countingsort (void) 
{
    // enum ht_list_day_tmp_2 day;
    
    ht_list_day_tmp_2 day;
    day = No_day;

    printf("%d",(uint8_t)(day));

    for ( ht_index_u8 = ht_zero; ht_index_u8 < (uint8_t)ht_seven ; ht_index_u8++ )
    {
        ht_maxswing_tmp ht_inforday_num = 
        {
            day, ht_index_u8, (uint8_t*)&value
        };
        printf(" \n %d - %d - %d ",ht_inforday_num.ht_list_u32,ht_inforday_num.ht_test_u8,ht_inforday_num.ht_day_u8);
    }
}

void ht_main(void)
{
    ht_countingsort();
}

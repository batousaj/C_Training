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
    uint16 ht_tmp_count_u16 =  (uint16)ht_testcase_h;
#endif

uint8 value=7;


static void ht_countingsort (void) 
{
    // enum ht_list_day_tmp_2 day;
    
    ht_Date_cmt day;
    day = No_day;

    printf(" - %d",(uint8) day);

    ht_maxswing_tmp* ht_inforday_num; 

    ht_inforday_num->ht_test_u8 = 2;

    printf(" \n - %d ",ht_inforday_num->ht_test_u8);

    for ( ht_index_u8 = ht_zero; ht_index_u8 < (uint8)ht_seven ; ht_index_u8++ )
    {
        // ht_maxswing_tmp *ht_inforday_num = 
        // {
        //     day, ht_index_u8, (uint8*)&value
        // };
    }
}

static int8 abc (void) 
{
    return 0,1;
}

void ht_main(void)
{
    ht_countingsort();
    uint16 y,c = abc();
    printf("a %d %d",y,c);
}

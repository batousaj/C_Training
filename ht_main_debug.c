/**
 * @file ht_main_debug.c
 * @author Thien Vu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "ht_main_head.h"
#include "ht_countingsort_head.h"

#include <stdio.h>


uint8 a,tmp ;
uint8 count = 8;

/**
 * @brief 
 * 
 */

#ifdef ht_constantvalue_flash 
    uint8 *c = &count;
#endif

int main(void) 
{

    ht_main ();
    
    printf("\n %d ",ht_counter_u8 + 1);

    tmp = (uint8)((ht_constantvalue_flash << 1u ) | 0x01 ) + 2;
    a = *c + 2 + tmp;

    printf ("%d",a);
    return 0;
}

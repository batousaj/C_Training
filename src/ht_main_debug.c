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


#include <stdio.h>
#include "ht_countingsort_head.h"


uint8_t a,tmp ;
uint8_t count = 8;

/**
 * @brief 
 * 
 */
#ifdef ht_constantvalue_flash 
    uint8_t *c = &count;
#endif

int main(void) {

    ht_countingsort();

    printf ("hello world\n");
    printf ("%d \n",c);

    tmp = (uint8_t)((ht_constantvalue_flash << 1u ) | 0x01 ) + 2;
    a = *c + 2 + tmp;

    printf ("%d",a);
    return 0;
}

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


#define ht_constantvalue_flash 2
uint8_t a;

int main() {

    printf ("hello world\n");
    a = ht_constantvalue_flash + 2 ;
    printf(a);
    return 0;
}

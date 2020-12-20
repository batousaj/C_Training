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
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define ht_constantvalue_flash 0x02


extern int stack_counter;

extern void ht_countingsort(void);

typedef struct {
    uint32_t ht_list_u32;
    uint8_t *ht_number_u8;

} ht_maxswing_tmp;

enum {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
    No_day
    
} ht_list_day_tmp;



#ifdef __cplusplus
}
#endif // * extern the libary between C and C++
#endif // * define ht_countingsort_head_H //

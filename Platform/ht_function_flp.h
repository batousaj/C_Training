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

#ifndef HT_FUNCTION_FLP_H
#define HT_FUNCTION_FLP_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


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


// Define data type ussigned -- 1 byte -- 2 byte -- 3 byte -- 4 byte
typedef uint8_t     uint8 ;
typedef uint16_t    uint16 ;
typedef uint32_t    uint32 ;
typedef uint64_t    uint64 ;

// Define data type -- 1 byte -- 2 byte -- 3 byte -- 4 byte
typedef int8_t      int8 ;
typedef int16_t     int16 ;
typedef int32_t     int32 ;
typedef int64_t     int64 ;

typedef enum {
    FALSE,
    TRUE
} bool_t;


// DATA CODE DID 
/****************************************************************
// 4 Byte
// {
//     1 Byte - Time ( 2 bit Hours - 2 bit Minutes - 2 bit Sencond - 2 bit date)
//     2 Byte - Data
//     1 Byte - NRC 
// }
*/

/**
 * @ht_time_cmt 
 * 16 bit - 4 byte  ht_time_cmt = 0x00 | 0x00 | 0x00 | 0x00
 * Hours----------------------------|      |      |      |
 * Minutes---------------------------------|      |      |
 * Second-----------------------------------------|      |
 * Date--------------------------------------------------|
 */
typedef uint16 ht_time_cmt;

typedef enum  {
    Monday = 2,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
    No_day

} ht_Date_cmt ;

typedef enum {
    ht_Outofday_nrc         = 0x11,
    ht_Lessday_nrc          = 0x12,
    ht_Datatooshort_nrc     = 0x13,
    ht_Datatoolong_nrc      = 0x14

} ht_reportstatus_cmt ;


// uint8 ht_diddatatype_ocs [(uint8)ht_four] = 
// {
    // 0x81, // enable to read
    // 0x82, // disbale to read
    // 0x71, // enable to write
    // 0x72
// };
//**************************************************************

typedef struct {
    uint8 DID ;
    ht_time_cmt ht_Time_dta;
    ht_reportstatus_cmt ht_status_nrc;

} ht_inforreport_time_cmt ;

// uint16 ht_expendtime_fnc(ht_time_cmt *ht_time, );
// //Diagnostic Data
// const ht_inforreport_time_cmt ht_inforreport_time_ocs [(uint8) (ht_four - 1 )] = 
// {
//     {ht_diddatatype_ocs[], ht_expendtime_fnc(),        ht_Outofday_nrc},
//     {ht_diddatatype_ocs[], ht_expendtime_fnc(),        ht_Lessday_nrc},
//     {ht_diddatatype_ocs[], ht_expendtime_fnc(),        ht_Datatooshort_nrc},
//     {ht_diddatatype_ocs[], ht_expendtime_fnc(),        ht_Datatoolong_nrc}
// };

#ifdef __cplusplus
}
#endif
#endif
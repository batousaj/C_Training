/**
 * @file test.cpp
 * @author Thien Vu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TEST_CPP
#define TEST_CPP
#ifdef __cplusplus
    extern "C" {
#endif

#include <stdint.h>
#include <string.h>

using namespace std;

#define ZERO 0
/**
 * Enum "ReturnType_t"
 * E_NOT_OK = FLASE, E_OK = TRUE
 * Return Value_type
 */
typedef enum {
    E_NOT_OK,
    E_OK
} ReturnType_t;


/**
 * API : SimpleArraySum - "test.cpp"
 * Input Parameter : uint32_t Data_u8[], ReturnType_t Data_return
 * Return ReturnType_t
 */
ReturnType_t SimpleArraySum(string string_array,uint32_t *Data_u32);

/**
 * API : strc_split - "test.cpp"
 * Input Parameter : uint32_t Data_u8[], ReturnType_t Data_return
 * Return ReturnType_t
 */
ReturnType_t strc_split(string String_array,char limo);


#ifdef __cplusplus
}
#endif 
#endif 

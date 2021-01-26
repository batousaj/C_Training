#include <stdio.h>
#include <test_header.h>

ReturnType_t SimpleArraySum(string string_array[],uint32_t *Data_u32)
{
    uint32_t count_u32;
    ReturnType_t Data_return;
    uint32_t Array_u32[];

    if (sizeof(Array_u32) > 0)
    {
        for ( count_u32 = ZERO ; count_u32 < sizeof(Array_u32) ; i++ )
        {   
            Data_u32 = Data_u32 + Array_u32[count_u32 + 1];
        }
        Data_return = E_OK;

    } else {
        Data_return = E_NOT_OK;
    }

    return Data_return;
}
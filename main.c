/**
 * @file main.c
 * @author Thien Vu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
#include <stdio.h>
#include <string.h>
#include <stdint.h>
//#include <stdbool.h>


 * #define index 9u

    void check_number (int32_t number)
    {
        printf("%d",number);
        uint8_t Ngto[] = " So nguyen to ";
        uint8_t KNgto[] = " Khong nguyen to ";
        if (number < 2)
        {
            printf(Ngto);
        } else {
            for (uint32_t i = 2 ; i < (uint32_t)index ; i++ )
                {
                    if (i == number)
                    {
                        continue; //do nothing
                    } else {
                        if ( (number)%i == 0 )
                        {
                            strcpy(Ngto,KNgto);
                            break;
                        } else {
                            continue; //do nothing
                        }
                    }
                    
                }
            printf(Ngto);
        }
    }

    int abcd(){

        return (int)15;
    }

    int main(void)
    {
        uint8_t abc[1] = "2";

        int b;

        int *jj = (void*)(intptr_t)abcd();

        printf("Nhap 1 so : ");
        scanf("%d",&b);

        uint16_t a = (uint16_t)(abc[0]);

        //check_number((uint32_t)number);

        printf("%d \n",jj);
        printf("%d \n",&jj);
        printf("%d \n",sizeof(int));
        printf("%d \n",sizeof(jj));
        printf("%d \n",sizeof(uint32_t));
        //int a = (int)number;

        printf("%d %d",(void*)(intptr_t)abcd(),&jj);
        
    
        return 0;
    }
 * 
 */

/**
#include <stdio.h>
#include <stdint.h>

typedef enum 
{
    FALSE = 0,
    TRUE
} state;

int Check_number(int B)
{
    static int a = 0;
    static state yi = 0;

    yi = TRUE;

    if (B < 2) 
    {
        yi = FALSE;
    }
    else 
    {
        for(int j=2; j < B; j++)
        {
            a = a + 1;
            if(B%j == 0)
            {
                printf("\nt");
                yi = FALSE;
            }
            else
            {
                printf("\ne");
            }    
        }
    }
    return yi;
}


int* IsSumOfPrimeNumbers(int A)
{
    static int32_t results[2];

    static int32_t results_1 ;

    static state deci,aci ;

    for (int32_t i=1 ; i < A; i++)
    {

        deci = Check_number(i);

        if ( deci == TRUE )
        {
            results_1 = A - i;
            aci = Check_number(results_1);

            if ( aci == TRUE )
            {
                results[0] = results_1;
                results[1] = i;
                break;
            }
            else
            {
                continue;
            }
            
        } 
        else 
        {
            results[0] = 0;
            results[1] = 0;
        }
    }
    return results;
}

int main(void)
{
    int32_t input;
    printf("Nhap 1 so : ");
    scanf("%d",&input);

    int32_t *kq;
    kq = IsSumOfPrimeNumbers(input);

    printf("Ket qua : {%d,%d}",kq);
    printf("Ket qua : {%d,%d}",*kq);
    printf("Ket qua : {%d,%d}",kq[0],kq[1]);
    printf("Ket qua : {%d,%d}",*(kq + 0),*(kq + 1));

    return 0;
}
*/


//     int b[1] = {5};
//     int *a = b;
//     printf("%d",&b);
//     printf("-%d",a);
//     printf("-%d",*a);
//     printf("-%d",&a);

//     int *d = *&b; // confirm again 
//     printf("-%d",d);
//     printf("-%d",*d);
//     printf("-%d",&d);

//     int *c;
//     c = a;
//     printf("-%d",c);
//     printf("-%d",*c);
//     printf("-%d",&c);

// //------------------------------------------------------------
//     int b_1 = 2;
//     int *a_1 = &b_1;
//     printf("\n%d",&b_1);
//     printf("-%d",a_1);
//     printf("-%d",*a_1);
//     printf("-%d",&a_1);

//     int *c_1;
//     c_1 = a_1;
//     printf("-%d",c_1);
//     printf("-%d",*c_1);
//     printf("-%d",&c_1);

// //                                                               
// #include <stdio.h>
// #include <string.h>
// #include <stdint.h>

// enum state  {
//     False = 0,
//     True = 1
// };

// void AnalyzeParagraph (char *str)
// {
//     const int number = (int)(strlen(str));
//     printf("%d Character. \n",number);

//     static int index = 1;
//     printf("%c \n",(&(*str))[2]);

//     //printf("%c \n",(&str)[3]);
//     // printf("%c \n",&(*str));
//     // printf("%c \n",*(&str));

//     // printf("%c \n",&(*(str + 1)));
//     // printf("%c \n",(&(*str) + 2));
//     //printf("%s",&((*str)[0]));
//     //int const *tmo = &number;
//     //printf("\n-%d\n",*tmo);

//     static char abc[1]=".";
//     for (int i = 0; i < number ; i++)
//     {
//         printf("a");
//         if((char)((&(*str))[i]) == abc[0])
//         {
//             ++index;
//         }
//         else 
//         {
//             continue;
//         }
//     }
//     printf("%d Sentence. \n",index);

//     char sep_char[] = "a";
//     int sep_number[100];

//     int tmp = 0;

//     sep_char[0] = (&(*str))[0];
//     sep_number[0] = 0;

//     enum state state1;

//     for (int j_3 = 1; j_3 < number; j_3++ )
//     {
//         for (int j_4 = 0; j_4 < j_3; j_4++ )
//         {
//             if (str[j_3] == str[j_4]
//                 /* (&(*str))[j_3] == (&(*str))[j_4] */
//                 )
//             {
//                 state1 = False;
//                 break;
//             }
//             else 
//             {
//                 //printf ("a");
//                 state1 = True;
//             }
//             printf ("a");
//         }

//         printf("\n%d",state1);
//         if (state1 == True)
//         {
//             printf ("a");
//             tmp = tmp + 1;
//             sep_number[tmp] = 0;
//             sep_char[tmp] = str[j_3];//(char)((&(*str))[j_3]);
//             printf("-%c",sep_char[tmp]);
//             printf("-%d\n",tmp);
//         }
//         printf("\n----%d-----%d----\n",j_3,number);
//     }


// }

// int main(void)
// {

//     AnalyzeParagraph("abcdefgh");
//     return 0;
// }

// enum 
// {
//     A_E = 0,
//     b 
// } c = A_E;

//queue

//| | | | |




// stack lifo 
// fifo


// 4 
// 8 

// base on architecture 
// 32 64  


// sizeof(tmp_t); => 12 

// uint8_t getString(char **pStr)
// {
//     static char myStr[] = "hello world"; // stack
//     memcpy(pStr, myStr, strlen(myStr));
//     // pStr = myStr;
// }

// int main (void)
// {
//     char buf[256] = "hello world\0";
//     char *pBuf = buf;

//     char *a = (pBuf + sizeof(*pBuf)); 
    

//     // const uint8_t arr[] = { 1, 2, 3};
//     // uint8_t  * const pArr = arr;
//     // *pArr = 5;


//     printf("%s \n", a);
//     printf("%d \n", sizeof(buf));
//     printf("%d \n", strlen(buf));
//     // getString(&pStr);
//     // printf("%s \r\n", pStr);
//     // const char ch = 'i';
//     // printf("Nhap chuoi :");
//     // scanf("%s",string);

//     // printf("%d",ch);
//     // printf("%s",strchr(string,ch));
//     // char *abc = string;

//     // printf("%s \n",string);
//     // printf("%d \n",&abc);
//     // printf("%c \n",abc[1]);

//     // char a = abc[1];
//     //&(*abc) = "bbc";
//     //printf("%d \n",&(*abc));

//     // AnalyzeParagraph(*abc);

//     // printf("%c \n",(char)((&(*abc))[0]));
//     // printf("%c \n",string[0]);

//     // AnalyzeParagraph(string);
//     return 0;
// }

// #include <conio.h>
// #include <stdio.h>
// #include <string.h>

// char* ConvertToPigLatinh(int **s)
// {
//     static char string[] = "empty";
//     printf("\n - %s",string);
//     strcpy(string,s);

//     printf("\n - %s",string);

//     int number = strlen(s);
//     int *ptr = &number;
//     const int tmp = *ptr;
//     char str[1] = " ";
//     //char *str_2_tmp[1] = "a";
//     char *str_2_tmp = (char *)(string[0]);
//     char abc[2] = "ay";

//     printf("\n ---- %s",str_2_tmp);

//     printf("\n - %s",string);

//     strncpy(string,str,1);
    
//     printf("\n-a");

//     strcat(str_2_tmp,abc);

//     printf("%s",str_2_tmp);
//     strcat(string,str_2_tmp);

//     printf("%s",string);

//     return string;
// }

// int main(void)
// {
//     char *string = "empty"; // constant
//     printf("Please enter 1 string :");
//     scanf("%s",string);

//     printf("%s",string);

//     char *s = string;
//     s = ConvertToPigLatinh(string);

//     printf("%s",s);

//     return 0;
// }




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdint.h>
#include <main.h>

// #define BASE_NUM 0; 
// typedef enum  
// {
//     E_NOT_OK,
//     E_OK
// } state_t;

// uint8_t ProcessDiagram( uint32_t* PtrNum)
// {
//     static state_t Return_state;
//     uint32_t col_, row_;

//     col_ = 2*(*PtrNum) - 1;
//     row_ = 2*(*PtrNum) - 1;

//     uint32_t ArrNum[row_][col_];

//     if ( *PtrNum == (int)*PtrNum )
//     {
//         for (uint8_t i = 0; i < (int)(row_/2) + 1 ; i++ )
//         {
//             for (uint8_t j = 0 ; j < (int)(col_/2) ; j++ )
//             {   
//                 if ( j < i )
//                 {
//                     ArrNum[i][j] = j + 1;
//                     ArrNum[row_ - i - 1][j] = j + 1;

//                     ArrNum[i][col_-j - 1] = j + 1 ;
//                     ArrNum[row_ - i - 1][col_-j - 1] = j + 1 ;

//                     if ( j == ((int)(col_/2) - 1) )
//                     {
//                         ArrNum[i][j+1] = j + 1;
//                         ArrNum[row_ - i - 1][j+1] = j + 1;
//                     }
//                 }
//                 else {
//                     ArrNum[i][j] = i + 1 ;
//                     ArrNum[row_ - i - 1][j] = i + 1 ;

//                     ArrNum[i][col_-j - 1] = i + 1 ;
//                     ArrNum[row_ - i - 1][col_-j - 1] = i + 1 ;

//                     if ( j == ((int)(col_/2) - 1) )
//                     {
//                         ArrNum[i][j+1] = i + 1;
//                         ArrNum[row_ - i - 1][j+1] = i + 1;
//                     }
//                 }

//             }
//             ArrNum[*PtrNum-1][*PtrNum -1] = *PtrNum;
//         }

//         for (uint8_t i = 0; i < row_ ; i++ )
//         {
//             for (uint8_t j = 0; j < row_ ; j++ )
//             {
//                 if(j == row_ - 1)
//                 {
//                     printf(" %3d\n",(char)ArrNum[i][j]);
//                 }
//                 else {
//                     printf(" %3d",ArrNum[i][j]);
//                 }
//             }
//         }

//         Return_state = E_OK;
//     }
//     else 
//     {
//         Return_state = E_NOT_OK;
//     }


//     return Return_state;
// }



class Student 
{

}

int main (void)
{
    // uint32_t Num ;
    // printf("Nhap so :");
    // scanf("%d",&Num);

    // if( E_OK == ProcessDiagram(&Num))
    // {
    //     ;// DO NOTHING
    // } 
    // else {
    //     printf("So nhap vao khong phai so nguyen");
    // }

    // // uint32_t abc[2][1] = {{2},{1}};
    // // printf("%d %d",abc[0][0],abc[1][0]);

    int a[] = {0,1,2,3};
    int *Ptr = a + 1;
    
    printf("%d\n",*Ptr); //1
    printf("%d\n",*Ptr++); //1
    printf("%d\n",++*Ptr); //3
    printf("%d\n",--*Ptr); //2
    printf("%d\n",*++Ptr); //3



    char b[] = "hello";
    char *Ptr1 = b + 1;
    
    printf("%c\n",*Ptr1++); //e
    printf("%c\n",++*Ptr1); //l+1 = f
    printf("%c\n",--*Ptr1); //l
    printf("%c\n",*++Ptr1); //l sau
    printf("%c\n",*Ptr1); //l sau

    for (int i=0; i < 10; i++)
    switch (i)
        {
            default :
                printf("A");
            case 1 :
                printf("B");
            case 2 :
                printf("C");
        }
        printf("--");
    
    int p = 5;
    int *Ptr2 = &p;
    int *Ptr3 = Ptr2;
    
    printf("%d\n",&p); 
    printf("%d\n",*Ptr2); 
    printf("%d\n",Ptr2);

    *Ptr3 = 7;
    printf("%d\n",*Ptr3);
    printf("%d\n",Ptr3);


    Student a;



    return 0;
}

/* 
   Program to convert Binary number to Decimal number.
   Also counts number of 0's and 1's in the binary number.
   Program also supports binary to octal and hexadecimal conversion
   if base variable is changed to 8 or 16 respectively.
*/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define ZERO_ONE_COUNT
    

int main(void)                     
{
    
    
    uint8_t base=2;

    if(base==2)
    {
        printf("Binary to Decimal Conversion\n");
    }
    else if(base == 16)
    {
        printf("Binary to Hexa Decimal Conversion\n");
       
    }
    else if(base == 8)
    {
        printf("Binary to Octal Conversion\n");
    }

   
    long long int binaryNum = 0;
    int dec = 0;

    uint8_t i = 0;
   
    uint32_t zero_cnt=0;
    uint32_t one_cnt=0;

    printf("Enter a binary number: ");
    scanf("%lld", &binaryNum);
    

    while (binaryNum) 
    {
        int rem= binaryNum % 10;
        
        #ifdef ZERO_ONE_COUNT
        if(rem==0)
        {
            zero_cnt++;
        }
        else if(rem==1)
        {
            one_cnt++;
        }
        #endif


        binaryNum = binaryNum / 10;

        // Multiplying the last digit with the base value i.e 2 raised to the power i for e.g. 2^0, 2^1, 2^2, ...
        // and adding the result to decimal equivalent variable
        dec += rem*pow(base,i);
        i+=1;

    }
    printf("Decimal Equivalent: %d\n", dec);
    printf("Number of 0's: %u\n",zero_cnt);
    printf("Number of 1's: %u\n",one_cnt);
   
    
        



    
    
 

    return 0;



}

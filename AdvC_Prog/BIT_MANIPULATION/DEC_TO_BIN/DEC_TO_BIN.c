
/* 
   Program to convert Decimal number to Binary number.
   Program also supports Decimal  to octal and hexadecimal conversion
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
    
    int deciNum = 0;
    int tmp_deciNum = 0;
    long long bin_num = 0;
    int rem = 0;
    int i = 1;

    printf("Enter a Decimal number: ");
    scanf("%d", &deciNum);
    
  
    if(deciNum>0)
    {
        while (deciNum!=0) 
        {
      
        rem= deciNum % base;        
        tmp_deciNum = deciNum / base;
        bin_num += rem*i;
        i=i*10;

        }
    } 
    else if(deciNum<0)
    {
        printf("Please enter a valid positive integer number\n");
        return -1;
    }

    printf("Decimal Number %d Binary Number Equivalent: %lld\n",deciNum, bin_num);
   
   return 0;

}

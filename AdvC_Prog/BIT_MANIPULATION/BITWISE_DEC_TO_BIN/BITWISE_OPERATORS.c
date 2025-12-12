
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
    

long long decimalToBinary(int deciNum, uint8_t base);

long long decimalToBinary(int deciNum, uint8_t base)
{
    long long bin_num = 0;
    int rem = 0;
    int i = 1;

    while (deciNum!=0) 
    {
      
        rem= deciNum % base;        
        deciNum = deciNum / base;
        bin_num += rem*i;
        i=i*10;

    }
    return bin_num;
}


int main(void)                     
{
    
    uint8_t base=2; 
    
    int deciNum1 = 0;
    int deciNum2 = 0;
    int tmp_deciNum = 0;
    long long bin_num1 = 0;
    long long bin_num2 = 0;
    int rem = 0;
    int i = 1;

    printf("Enter Two Numbers: ");
    scanf("%d  %d", &deciNum1,&deciNum2);  

    if(deciNum1<0 && deciNum2<0)
    { 
    printf("Taking 2's complement for negative number conversion\n");       
    tmp_deciNum = deciNum1;
    tmp_deciNum = ~tmp_deciNum+1;
    bin_num1 = decimalToBinary(tmp_deciNum, base);
    
    tmp_deciNum = deciNum2;
    tmp_deciNum = ~tmp_deciNum+1;
    bin_num2 = decimalToBinary(tmp_deciNum, base);
    printf("Decimal Number %d and Decimal Number %d Binary Equivalents Are : %lld  %lld \n",deciNum1,deciNum2, bin_num1,bin_num2);
    printf("Bitwise AND & Operator Applied On Numbers %d & %d = %lld \n",deciNum1,deciNum2,bin_num1 & bin_num2); 
    printf("Bitwise  OR | Operator Applied On Numbers %d & %d = %lld \n",deciNum1,deciNum2,bin_num1 | bin_num2); 
    printf("Bitwise  XOR ^ Operator Applied On Numbers %d & %d = %lld \n",deciNum1,deciNum2,bin_num1 ^ bin_num2);
    printf("Bitwise Left Shift << Operator Applied On Number %d Two Times = %lld \n",deciNum1,deciNum1<<2);
    printf("Bitwise Left Shift << Operator Applied On Number %d Two Times = %lld \n",deciNum2,deciNum2<<2);
    }
    else if(deciNum1>0 && deciNum2>0)
    {
     bin_num1 = decimalToBinary(deciNum1, base);
     bin_num2 = decimalToBinary(deciNum2, base);
     printf("Decimal Number %d and Decimal Number %d Binary Number Equivalent: %lld  Binary Number Equivalent: %lld\n",deciNum1,deciNum2, bin_num1,bin_num2);
     printf("Bitwise AND & Operator Applied On Numbers %d & %d = %lld \n",deciNum1,deciNum2,bin_num1 & bin_num2); 
     printf("Bitwise  OR | Operator Applied On Numbers %d & %d = %lld \n",deciNum1,deciNum2,bin_num1 | bin_num2); 
     printf("Bitwise  XOR ^ Operator Applied On Numbers %d & %d = %lld \n",deciNum1,deciNum2,bin_num1 ^ bin_num2);
     printf("Bitwise Left Shift << Operator Applied On Number %d Two Times = %lld \n",deciNum1,deciNum1<<2);
     printf("Bitwise Left Shift << Operator Applied On Number %d Two Times = %lld \n",deciNum2,deciNum2<<2);
    }
    
   return 0;

}

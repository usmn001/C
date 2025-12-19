#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>


#define BIN_TO_DECIMAL



#define BIT_TOGGLINE
#undef  BIT_TOGGLINE
    

int main(void)                     // Program to Check and Set a Bit at Given Position
{
    
    #ifdef BIN_TO_DECIMAL
    printf("**** BINARY TO DECIMAL CONVERSION PROGRAM ****\n\n");
    long long int binaryNum = 0;
    int dec = 0;

    uint8_t i = 0;
    uint8_t base = 2; // Base value for binary number system

    printf("Enter a binary number: ");
    scanf("%lld", &binaryNum);
    

    while (binaryNum) 
    {
        int rem= binaryNum % 10;
        binaryNum = binaryNum / 10;

        // Multiplying the last digit with the base value
        // and adding it to the decimal value
        dec += rem*pow(base,i);
        i+=1;

    }
    printf("Decimal Equivalent: %d\n", dec);
    #endif
    
        



    
    
    #ifdef BIT_TOGGLINE
        printf("**** BIT CHECK AND SET PROGRAM ****\n\n");
    int32_t a = 0,bitStatus = 0, new_num = 0;
    uint8_t pos = 0;

    printf("Enter a number: ");
    scanf("%i", &a);
    printf("\nEnter Bit Position (0-31) to check and Set: ");
    scanf("%hhu", &pos);
    bitStatus = (a>>pos) & 1; 
    printf("The %d Bit Is Set to %d\n", pos, bitStatus);

    new_num = a | (1<<pos);       // Shifting 1 to the left by 'pos' and then ORing it with 'a' to set the bit at 'pos'
    printf("New Number After Setting the %d Bit is: %d\n", pos, new_num);
    #endif


    return 0;



}

#include <stdio.h>
#include <stdint.h>

int main(void)                     // Program to Check and Set a Bit at Given Position
{

    int32_t a = 0,bitStatus = 0, new_num = 0;
    uint8_t pos = 0;

    printf("Enter a number: ");
    scanf("%i", &a);
    printf("\nEnter Bit Position (0-31) to check and Set: ");
    scanf("%hhu", &pos);
    bitStatus = (a>>pos) & 1; 
    printf("The %d Bit Is Set to %d\n", pos, bitStatus);

    new_num = a | (1<<pos);
    printf("New Number After Setting the %d Bit is: %d\n", pos, new_num);


    return 0;



}

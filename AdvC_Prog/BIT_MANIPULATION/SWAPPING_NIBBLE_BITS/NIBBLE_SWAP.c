#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define SWAP_NIBBLES(data) ((data & 0x0F) << 4 | (data & 0xF0) >> 4)

int main(void)                     
{
    uint8_t a = 0x52;
    uint8_t * b = &a;
    
    //PART 1 : HERE WE ARE SWAPPING HIGHER NIBBLE BITS TO LOWER NIBBLE BITS
    // 1 NIBBLE = 4 BITS
    
    uint8_t HIGH = (a & 0xF0);
    uint8_t LOW  = (a & 0x0F);
    
    printf("BEFORE SWAPPING\nHIGHER NIBBLE BITS : %x,  LOWER NIBBLE BITS : %x \n",HIGH,LOW);
    
    *b = SWAP_NIBBLES(a);
    HIGH = (*b & 0xF0)>>4;
    LOW = *b & 0x0F;
    
    printf("AFTER SWAPPING\nHIGHER NIBBLE BITS : %x, LOWER NIBBLE BITS : %x\n",HIGH,LOW);
    printf("OR OF HIGH AND LOW NIBBLE BITS : %x\n",HIGH | LOW);

    // PART 2 : SWAPPING BITS INSIDE THE NIBBLE
    // Swapping each single bits inside the nibbles.

    printf("\nPERFORMING BIT SWAP IN THE NIBBLE BITS\n\n");
   
    LOW = ((LOW & 0x1)<<3) |
          ((LOW & 0x2)<<1) |
          ((LOW & 0x4)>>1) |
          ((LOW & 0x8)>>3);
            
    HIGH = ((HIGH & 0x1)<<3) |
           ((HIGH & 0x2)<<1) |
           ((HIGH & 0x4)>>1) |
           ((HIGH & 0x8)>>3);

    printf("AFTER SWAPPING BITS IN LOWER AND HIGHER NIBBLE \n");
    printf("HIGH NIBBLE BITS : %x , LOWER NIBBLE BITS : %i\n",HIGH, LOW);
    printf("OR OF HIGH AND LOW NIBBLE BITS : %x\n",(HIGH<<4) | LOW);
       
    return 0;
}


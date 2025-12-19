/*
    Variadic Macros in C Programming
    Program showing use of # and ## Token Pasting Operators in Macros
    Author : M USMAN
    
*/
#include <stdio.h>

typedef enum : __uint8_t 
{
    I2C_READ_ERROR          = 0,
    I2C_READ_SUCCESS        = 1,       
    I2C_WRITE_ERROR         = 0,
    I2C_WRITE_SUCCESS       = 1
} Ret_Type;



#define MSG(x)                    printf(#x " = %d\n", x)        // Macro to print variable name and its value
#define FUNC(x)                   Ret_Type I2C_##x()             // Macro to call Message function with stringified argument

//#define I2C_COMMANDS(x)           {#x, I2C_##x}                  // Macro to create command structure with token pasting

FUNC(READ)
{
    printf("I2C Read Function Called\n");
    return I2C_READ_SUCCESS;
}

FUNC(WRITE)
{
    printf("I2C Write Function Called\n");
    return I2C_WRITE_SUCCESS;
}

 
/*
struct sens_calib
{
    const char *cmd_nam)e;
    Ret_Type (*cmd_func)();
};


struct sens_calib commands[] =
{
    I2C_COMMANDS(CALIB),
    I2C_COMMANDS(RESET),
};*/

int main(void)
{                     
   int a = 10;
   ++a;
   MSG(a); // Using MSG Macro to print value of a
   a++;
   MSG(a); // Using MSG Macro to print value of a  
   I2C_READ();
   I2C_WRITE();

   return 0;
}

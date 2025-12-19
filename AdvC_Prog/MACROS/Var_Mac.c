/*
    Variadic Macros in C Programming
    This program demonstrates the use of variadic macros to handle a variable number of arguments.
    It includes examples of printing messages to standard output and standard error streams,
    as well as using predefined macros like __FILE__ and __LINE__.
    
*/
#include <stdio.h>

#define WARNING1(...)             fprintf(stderr, __VA_ARGS__)
#define WARNING2(format,...)      fprintf(stdout,format, __VA_ARGS__)
#define MSG(x)                    printf(#x " = %d\n", x) // Macro to print variable name and its value


int main(void)
{                     
   fprintf(stderr, "Warning Message\n"); // Printing to Standard Error Stream
   fprintf(stdout, "Hello World from C Programming\n"); // Printing to Standard Output Stream
   fprintf(stdout, "This is a Variadic Macro Example In File %s\n",__FILE__); // Printing File Name using __FILE__ Macro
   
   WARNING1("Using Warning1 Macro %s\n",__FILE__); // Printing File Name using WARNING1 Macro, Macro Arguments are passed to fprintf, replacing format & __VA_ARGS__
   
   WARNING2("Using Warning2 Macro in File %s at Line %d\n",__FILE__,__LINE__);  // Printing File Name & Line Number using WARNING2 Macro, Macro Arguments are passed to fprintf, replacing format & __VA_ARGS__
   
   int a = 10;
   ++a;
   MSG(a); // Using MSG Macro to print value of a
   a++;
   MSG(a); // Using MSG Macro to print value of a
   
   
   return 0;
}

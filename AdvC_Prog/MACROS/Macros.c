
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define SUM(a,b)                ( (a)+(b))
#define IS_UPPER(c)             (isupper(c) ? 1 : 0)
#define IS_LOWER(c)             (islower(c) ? 1 : 0)
#define IS_ALPHANUMERIC(c)      (isalnum(c) ? 1 : 0)

#define MACRO_SUM    
#define MACRO_CHAR1  
#undef  MACRO_CHAR1           
#define MACRO_CHAR2             1

int main(void)                     // Program to Check and Set a Bit at Given Position
{

    
    printf("%d\n",__LINE__);
    printf("%s\n",__FILE__);
    printf("%s\n",__DATE__);
    printf("%s\n",__TIME__);
   

    // Sum of Two Numbers Using Macro
    #ifdef MACRO_SUM
    int a = 0, b = 0;
    printf("Enter Two Numbers: ");
    scanf("%i  %i", &a,&b);
    printf("Sum of %d and %d is: %d\n", a, b, SUM(a,b));
    #endif
    

    // Check Whether Character is Uppercase or Lowercase Using Macro
  
    
    

    // Challenge 4 : Check Whether Character is Upper or Lower Case Using Macro

    // Method : 1 Check Whether Character is Uppercase or Lowercase Using Macro
    #ifdef MACRO_CHAR1

    printf("Enter a Character: ");
    char c = 0;
    scanf(" %c", &c);

    if(IS_UPPER(c))
    {
        printf("The Character '%c' is Uppercase\n", c);
    }
        
    else if(IS_LOWER(c))
    {        
        printf("The Character '%c' is Lowercase\n", c);
    }
    else if(!IS_UPPER(c) && !IS_LOWER(c))
    {
        printf("The Character '%c' is Not an Alphabet\n", c);
    }
    #endif

    // Method : 2 Check Whether Character is Uppercase or Lowercase Using Macro
    #ifdef MACRO_CHAR2
    char ch = '\0';
    printf("Enter a Character: ");
    for(int i = 0; i<=1; i++)
    {   
         ch= getchar();
    }
    

    if(IS_ALPHANUMERIC(ch) && IS_UPPER(ch))
    {
        printf("The Character '%c' is Uppercase\n", ch);
    }
        
    else if(IS_ALPHANUMERIC(ch) && IS_LOWER(ch))
    {        
        printf("The Character '%c' is Lowercase\n", ch);
    }
    else if(!IS_ALPHANUMERIC(ch))
    {
        printf("The Character '%c' is Not an Alphanumeric\n", ch);
    }
    #endif

    






    
   

    return 0;



}

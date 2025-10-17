#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


int main() 
{
    alarm(5);

    while (1)
    {
      printf("hello\n");
    }
    
    
   return 0;
}
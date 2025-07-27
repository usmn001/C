#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


int main() 
{
    
    
    printf("Testing SIGSTOP \n");
    raise(SIGSTOP); // This will stop the process
    printf("Process resumed after SIGSTOP \n");

    return 0;
}
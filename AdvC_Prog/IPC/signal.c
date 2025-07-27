#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void signal_handler(int signum);

int main ()
{

 

void (*signal_handler_fp)(int);     // Function Pointer For Signal Handler

   signal_handler_fp = signal(SIGFPE, signal_handler);  // signal() function returns address of signal handler on success,
                                                        // And SIG_ERR on failure.
   if (signal_handler_fp == SIG_ERR) {
       perror("Error setting up signal handler");
       return 1;
   } 
 
int a = 5;
a = a/0; 

return 0;
}

void signal_handler(int signum) 
{
    if(signum==SIGFPE)
    {
    printf("Received SIGFPE signal. Divide By Zero Exception");
    exit(0);
    }
    else
    {
    printf("Signal %d received. Exiting...\n", signum);
    }
   
}
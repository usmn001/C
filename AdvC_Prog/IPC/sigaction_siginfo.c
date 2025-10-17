#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

static void termination_handler(int signum,siginfo_t *siginfo, void *context) 
{
   printf("Sending PID %ld, User ID : %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main(int argc,char *argv[])
{
    struct sigaction act;
    memset(&act,'\0',sizeof(act));
    
    act.sa_sigaction = &termination_handler; // Use sa_sigaction for siginfo_t
    act.sa_flags = SA_SIGINFO; // Set the flag to use sa_sigaction
     
   if(sigaction(SIGINT, &act, NULL) <0) {
        perror("Error setting up signal handler");
        return 1;
    }

    while(1) {
             sleep(3);
    }
    
    
   
 return 0;
}
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void termination_handler(int signum) 
{
   printf("Received Termination Signal ");

}

int main()
{
    struct sigaction new_action, old_action;

    new_action.sa_handler = termination_handler;
    sigemptyset(&new_action.sa_mask); //Specifying No Signal Should Be Blocked During Exection of Termination_Handler
    new_action.sa_flags = 0;    // specifies a set of flags which modify the behavior of signals.
    
    
    if (sigaction(SIGINT, &new_action, NULL) == -1) {
        perror("Error setting up signal handler");
        return 1;
    }
   

   while(1) {
       printf("Running... Press Ctrl+C to terminate.\n");
       sleep(3);
       //raise(SIGTERM); // Simulate sending SIGTERM signal
   }
 return 0;
}


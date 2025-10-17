#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

static void signal_handler(int signum, siginfo_t *siginfo, void *context) 
{
  if(signum == SIGINT) 
  {
      end_game();
  }
  else if(signum == SIGALRM) 
  {
      printf("\n TIMES UP");
      raise(SIGINT); // Raise SIGINT to end the game
  }
 }



int main() {

   srand (time(0));
   struct sigaction act;
   memset(&act,'\0',sizeof(act));
   act.sa_sigaction = &signal_handler;
   act.sa_flags = SA_SIGINFO; // Set the flag to use sa_sigaction


   if(sigaction(SIGINT, &act, NULL) <0) {
        perror("Error setting up signal handler");
        return 1;
    }
   
    if(sigaction(SIGALRM, &act, NULL) <0) {
        perror("Error setting up signal handler");
        return 1;
    }
    
    
   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];
      printf("\nWhat is %d times %d: ", a, b);
      alarm(5);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else
         printf("\nWrong! Score: %d\n", score);

       }



    

 
    return 0;
} 

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


char buf[1000];



void child_process1()
{
char *str = "First Child Process";
sprintf(buf,"%s PID = %i,Parent PID = %i\n",str,getpid(),getppid());  // sprintf is Putting the output in buffer. 
write(1,buf,strlen(buf));  // This write statement is showing output on screen   
}

void child_process2()
{
char *str = "Second Child Process";
sprintf(buf,"%s PID = %i,Parent PID = %i\n",str,getpid(),getppid());  // sprintf is Putting the output in buffer. 
write(1,buf,strlen(buf));  // This write statement is showing output on screen
}

void child_process3()
{
char *str = "Third Child Process";
sprintf(buf,"%s PID = %i,Parent PID = %i\n",str,getpid(),getppid());  // sprintf is Putting the output in buffer. 
write(1,buf,strlen(buf));  // This write statement is showing output on screen
}



void main(void)
{

pid_t pid1,pid2, pid3;

pid1 = fork();

if(pid1 == 0)
{
    child_process1();
}

if (pid1 > 0 )
{
char *str = "Parent Process";
sprintf(buf,"%s PID = %i,Parent PID = %i\n",str,getpid());  // sprintf is Putting the output in buffer.
write(1,buf,strlen(buf));  // This write statement is showing output on screen
}

pid2 = fork();

if(pid2 == 0)
{
    child_process2();
}

if (pid2 > 0 )
{
char *str = "Parent Process";
sprintf(buf,"%s PID = %i,Parent PID = %i\n",str,getpid());  // sprintf is Putting the output in buffer.
write(1,buf,strlen(buf));  // This write statement is showing output on screen
}


pid3 = fork();

if(pid3 == 0)
{
    child_process3();
}

if (pid3 > 0 )
{
char *str = "Parent Process";
sprintf(buf,"%s PID = %i,Parent PID = %i\n",str,getpid());  // sprintf is Putting the output in buffer.
write(1,buf,strlen(buf));  // This write statement is showing output on screen
}



}
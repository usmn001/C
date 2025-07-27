#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


#define MAX_COUNT 10
#define BUF_SIZE 100


void main(void)
{

pid_t pid;
pid= fork();

char buf[BUF_SIZE];



for(int i=0;i<MAX_COUNT;i++)
{

if(pid == 0)
{
char *str = "Child Process";
sprintf(buf,"%s Process pid = %d,value = %d\n",str,pid,i);  // sprintf is Putting the output in buffer.
}
else if(pid > 0)
{
char *str = "Parent Process";
sprintf(buf,"%s Process pid = %d,value = %d\n",str,pid,i);
}

write(1,buf,strlen(buf));  // This write statement is showing output on screen 
}


}







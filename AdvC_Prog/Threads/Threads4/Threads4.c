#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void *thread_func(void *arg) 
{
pthread_detach(pthread_self());
sleep(1);
printf("Thread Function Running\n");
pthread_exit(NULL);
}


int main(int argc, char *argv[])
{

pthread_t tid;
int ret;
ret = pthread_create(&tid,NULL,thread_func,NULL);



if(ret !=0)
{
perror("Thread Creation Error\n");
exit(1);
}

printf("After Creation Of Main Thread\n");

pthread_exit(NULL);

}

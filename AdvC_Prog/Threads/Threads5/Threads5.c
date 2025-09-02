#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_attr_t  attr;

void *thread_func(void *threadid) 
{
long tid;
size_t stacksize;
tid = (long)threadid;
pthread_attr_getstacksize(&attr,&stacksize);
printf("Thread id %ld,stack size = %li bytes \n",tid,stacksize);
pthread_exit(NULL);
}


int main(int argc, char *argv[])
{

pthread_t myThread;;
size_t stacksize;
pthread_t myID;
long t;

pthread_attr_init(&attr);         // Here we are initializing the thread attribute type variable attr
pthread_attr_getstacksize(&attr,&stacksize);   // Function returning default allocated stack size
printf("Default stack size = %li bytes \n",stacksize);
stacksize = 9000000;
pthread_attr_setstacksize(&attr,stacksize);

printf("Creating thread with stack size = %li bytes \n",stacksize);
myID = pthread_create(&myThread,&attr,thread_func,(void *)t);

if(myID)
{
printf("ERROR,Return Code from pthread_create() %lu\n");
exit(-1);
}
pthread_exit(NULL);
}






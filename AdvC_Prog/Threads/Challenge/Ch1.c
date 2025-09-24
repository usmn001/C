#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func1(void *msg) ;

int cnt_g = 0;      // Shared Resource, Access to this resource is controlled by mutex locks

void *thread_func1(void *msg) 
{
cnt_g++;
printf("%s, Thread ID = %i , Modified Global Counter Value = %i\n",(char *)msg,pthread_self(),cnt_g);
printf("%s, Thread ID = %i , Read Global Counter Value = %i\n",(char *)msg,pthread_self(),cnt_g);
pthread_exit(NULL);
}





int main(int argc, char *argv[])
{
pthread_t thread1,thread2;             // Here we are declaring two thread variables thread1 and thread2 of type pthread_t
char *msg1 = "Hello From Main To Thread 1";


if(pthread_create(&thread1,NULL,thread_func1,(void*)msg1) ) // Here we are creating the thread named thread1 with attributes defined in thr1_attr and executing function thread_func1
{
    printf("Thread 1 Creation has failed\n");
}

char *msg2 = "Hello From Main To Thread 2";
if(pthread_create(&thread2,NULL,thread_func1,(void*)msg2) ) // Here we are creating the thread named thread1 with attributes defined in thr1_attr and executing function thread_func1
{
    printf("Thread 2 Creation has failed\n");
}





pthread_join(thread1, NULL);                        // Here we are waiting for thread1 to complete
pthread_join(thread2, NULL);                        // Here we are waiting for thread1 to complete
printf("All threads are completed\n");

pthread_exit(NULL);
}






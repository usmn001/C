#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 10
pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER; // Creating Mutex lock1  to control access to shared resources

void *thread_func1(void *msg) ;

int cnt_g = 0;      // Shared Resource, Access to this resource is controlled by mutex locks

void *thread_func1(void *msg) 
{

int *x = (int *)msg;

if(pthread_mutex_lock(&mutex_lock)==0)
{
printf("Thread ID = %i Acquired the lock\n",pthread_self());
sleep(1);    
cnt_g++;
printf("Message is %i, Thread ID = %i , Modified Global Counter Value = %i\n",*x,pthread_self(),cnt_g);
printf("Message is %i, Thread ID = %i , Read Global Counter Value = %i\n",*x,pthread_self(),cnt_g);
}
else
{
    printf("Thread ID = %i Failed to Acquire the lock\n",pthread_self());
}


if(pthread_mutex_unlock(&mutex_lock)==0)
{
printf("Thread ID = %i Released the lock\n",pthread_self());
}
else
{
    printf("Thread ID = %i Failed to release the lock\n",pthread_self());
}
pthread_exit(NULL);
}





int main(int argc, char *argv[])
{
pthread_t thread_id[NUM_THREADS];            // Here we are declaring an array of thread variables thread_id of type pthread_t
int values[NUM_THREADS];
for(int i=0;i<NUM_THREADS;i++)
{
values[i] = i+1;
if(pthread_create(&thread_id[i],NULL,thread_func1,&values[i])==0) // Here we are creating the thread named thread1 with default attributes and executing function thread_func1
{
    printf("Thread %i Creation is Successful\n",i+1);
}
else
{
    printf("Thread %i Creation has failed\n",i+1);
}

}




for(int i=0;i<NUM_THREADS;i++)
{
pthread_join(thread_id[i],NULL);                        // Here we are waiting for thread1 to complete
pthread_exit(&thread_id[i]);
}
printf("All threads are completed\n");


}






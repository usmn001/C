#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 10
pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER; // Creating Mutex lock1  to control access to shared resources
pthread_cond_t cond_var1 = PTHREAD_COND_INITIALIZER;;   // Creating Condition variable cond_var1 of type pthread_cond_t

void *thread_func1(void *msg) ;

int cnt_g = 0;      // Shared Resource, Access to this resource is controlled by mutex locks
int num_even_threads = NUM_THREADS/2;
int even_threads_completed = 0;

void *thread_func1(void *msg) 
{

    int *x = (int *)msg;
    if( *x %2==0 )
    {   
        if(pthread_mutex_lock(&mutex_lock)==0  )
        {
            printf("Thread # %i With ID = %lu , Acquired the lock\n",*x,pthread_self());
            sleep(1);    
            cnt_g++;
            printf("Thread # %i With ID = %lu , Modified Global Counter Value = %i\n",*x,pthread_self(),cnt_g);
            printf("Thread # %i With ID = %lu , Read Global Counter Value = %i\n",*x,pthread_self(),cnt_g);
        }
        else
        {
            printf("Thread # %i With ID = %lu , Failed to Acquire the lock\n",*x,pthread_self());
        }


        if( (pthread_mutex_unlock(&mutex_lock)==0) )
        {
            printf("Thread # %i With ID = %lu , Released the lock\n",*x,pthread_self());
            even_threads_completed++;
        }
        else
        {
            printf("Thread # %i With ID = %lu , Failed to release the lock\n",*x,pthread_self());
        }

        if((even_threads_completed==num_even_threads) && (pthread_cond_broadcast(&cond_var1)==0))
        {
                printf("Thread # %i With ID = %lu Broadcasting Condition Variable\n",*x,pthread_self());   
        }
    }

    else if( (*x %2!=0)) 
    {
        if(pthread_mutex_lock(&mutex_lock)==0 && pthread_cond_wait(&cond_var1,&mutex_lock)==0)
        {
            printf("Thread # %i With ID = %lu Acquired the lock\n",*x,pthread_self());
            sleep(1);    
            cnt_g++;
            printf("Thread # %i With ID = %lu , Modified Global Counter Value = %i\n",*x,pthread_self(),cnt_g);
            printf("Thread # %i With ID = %lu , Read Global Counter Value = %i\n",*x,pthread_self(),cnt_g);   
        }
        else
        {
            printf("Thread # %i With ID = %lu , Failed to Acquire the lock\n",*x,pthread_self());
        }

        if(pthread_mutex_unlock(&mutex_lock)==0)
        {
            printf("Thread # %i With ID = %lu , Released the lock\n",*x,pthread_self());   
        }
        else
        {
            printf("Thread # %i With ID = %lu , Failed to release the lock\n",*x,pthread_self());
        }
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
sleep(1);

for(int i=0;i<NUM_THREADS;i++)
{
pthread_join(thread_id[i],NULL);                        // Here we are waiting for thread1 to complete
}

printf("All threads are completed\n");

for(int i=0;i<NUM_THREADS;i++)
{
pthread_exit(&thread_id[i]);
}

}

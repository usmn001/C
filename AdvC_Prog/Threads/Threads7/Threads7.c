#include <stdio.h>
#include <unistd.h>
#include <pthread.h>



void *thread_func1(void *threadid) ;
void *thread_func2(void *threadid) ;

pthread_attr_t  thr1_attr;   // Creating Thread attribute variable thr1_attr of type pthread_attr_t
pthread_attr_t  thr2_attr;   // Creating Thread attribute variable thr2_attr of type pthread_attr_t

pthread_mutex_t mutex_lock1; // Creating Mutex lock1  to control access to shared resources
pthread_mutex_t mutex_lock2; // Creating Mutex lock2 to control access to shared resources

pthread_cond_t cond_var1 = PTHREAD_COND_INITIALIZER;;   // Creating Condition variable cond_var1 of type pthread_cond_t

int num_sh = 0;      // Shared Resource, Access to this resource is controlled by mutex locks

void *thread_func1(void *threadid) 
{
size_t stacksize;
pthread_attr_getstacksize(&thr1_attr,&stacksize);
printf("Thread 1 id = %ld,stack size = %li bytes \n",pthread_self(),stacksize);

if(pthread_mutex_lock(&mutex_lock1) ==0 && pthread_cond_wait(&cond_var1,&mutex_lock1)==0)
{
printf("Thread 1 Accessing Shared Resource\n");   
num_sh--;
printf("Value In Thread 1 Function = %i\n",num_sh);
}
else
{
    printf("Thread 1 Failed to Acquire the lock\n");
}


if(pthread_mutex_unlock(&mutex_lock1) ==0)
{
printf("Thread 1 Freeing Shared Resource\n");
}
else
{
 printf("Thread 1 Failed to release the lock\n");
}
pthread_exit(NULL);
}

void *thread_func2(void *threadid) 
{
size_t stacksize;
int ret_t;
pthread_attr_getstacksize(&thr2_attr,&stacksize);
printf("Thread 2 id = %ld,stack size = %li bytes \n",pthread_self(),stacksize);

while(1)
{
if(pthread_cond_signal(&cond_var1)==0) 
{
    printf("Thread 2 Signaling Condition Variable\n");   // Signaling the condition variable cond_var1 to wake up waiting threads
}
if(pthread_mutex_lock(&mutex_lock1) ==0 )
{
printf("Thread 2 Accessing Shared Resource\n");
num_sh++;
sleep(1);
printf("Value In Thread 2 Function = %i\n",num_sh);
}
else
{
    printf("Thread 2 Failed to Acquire the lock\n");
}
if(pthread_mutex_unlock(&mutex_lock1)==0 )
{
printf("Thread 2 Freeing Shared Resource\n");
}
else
{
    printf("Thread 2 Failed to release the lock\n");
}

pthread_exit(NULL);
}
}



int main(int argc, char *argv[])
{
pthread_t thread1,thread2;             // Here we are declaring two thread variables thread1 and thread2 of type pthread_t
size_t stacksize;

pthread_attr_init(&thr1_attr);         // Here we are initializing the thread attribute type variable attr
pthread_attr_getstacksize(&thr1_attr,&stacksize);   // Function returning default allocated stack size
printf("Default stack size = %li bytes \n",stacksize);
stacksize = 9000000;
pthread_attr_setstacksize(&thr1_attr,stacksize); // Here we are setting the stack size attribute to 9000000 bytes

pthread_attr_init(&thr2_attr);         // Here we are initializing the thread attribute type variable attr
pthread_attr_getstacksize(&thr2_attr,&stacksize);   // Function returning default allocated stack size
printf("Default stack size = %li bytes \n",stacksize);
stacksize = 400000;
pthread_attr_setstacksize(&thr2_attr,stacksize);  // Here we are setting the stack size attribute to 400000 bytes

printf("Creating threads with stack size = %li bytes \n",stacksize);

if(pthread_create(&thread1,&thr1_attr,thread_func1,NULL)) // Here we are creating the thread named thread1 with attributes defined in thr1_attr and executing function thread_func1
{
    printf("Thread 1 Creation has failed\n");
}

if(pthread_create(&thread2,&thr2_attr,thread_func2,NULL))  // Here we are creating the thread named thread2 with attributes defined in thr2_attr and executing function thread_func2
{
    printf("Thread 2 Creation has failed\n");
}

if(pthread_mutex_init(&mutex_lock1, NULL)!=0)       // Here we are initializing and creating mutex lock1 dynamically 
{
    printf("Mutex Lock 1 Creation has failed\n");
}

if(pthread_mutex_init(&mutex_lock2, NULL)!=0)       // Here we are initializing and creating mutex lock2 dynamically
{
    printf("Mutex Lock 2 Creation has failed\n");
}

pthread_join(thread1, NULL);                        // Here we are waiting for thread1 to complete
pthread_join(thread2, NULL);                        // Here we are waiting for thread2 to complete
printf("All threads are completed\n");

pthread_exit(NULL);
}






#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct thread_data {
   int  thread_id;
   char *msg_p;
};


void * thread_fun(void *ptr) 
{
struct  thread_data *st_data_ptr;
st_data_ptr = (struct thread_data *) ptr;    
printf("Thread ID : %d \n", st_data_ptr->thread_id);
printf("Message : %s \n", st_data_ptr->msg_p);
return NULL;
}


int main(int argc, char * argv[])
{
struct  thread_data *st_data_ptr;
st_data_ptr->thread_id = 1;
st_data_ptr->msg_p = "This is thread 1";

pthread_t thread;
pthread_create(&thread,NULL,thread_fun,(void *)st_data_ptr); // Here we are passing the address of structure to the thread function.
pthread_join(thread,NULL);      // Now we are going to wait for our thread function to finish its execution.
pthread_exit(NULL);
return 0;
}

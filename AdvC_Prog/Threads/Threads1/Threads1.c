#include <stdio.h>
#include <pthread.h>

void * hello_fun() 
{
printf("Hello World");
return NULL;
}


int main(int argc, char * argv[])
{
pthread_t thread;
pthread_create(&thread,NULL,hello_fun,NULL);
pthread_join(thread,NULL);      // Now we are going to wait for our thread function to finish its execution.
pthread_exit(NULL);
return 0;
}

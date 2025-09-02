#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * thread_fun(void *ptr) 
{
char *str = strdup("Hello from thread"); // strdup is duplicating the string and allocating memory for it in heap, while returning the address of that memory. 
return (void *)str;   // Here we are returning a string from the thread function.          
}


int main(int argc, char * argv[])
{
char *str;   
pthread_t thread;
pthread_create(&thread,NULL,thread_fun,NULL); // Here we are passing the address of structure to the thread function.
pthread_join(thread,(void**)&str);      // Now we are going to wait for our thread function to finish its execution.
printf("%s",str);
free(str);
return 0;
}

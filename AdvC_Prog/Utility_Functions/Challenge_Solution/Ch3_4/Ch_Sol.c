/* This program is showing current time and printing generated errors */

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main(void)                     // Program to Check and Set a Bit at Given Position
{
    clock_t start, end;
    start = clock();
    double cpu_time_used;
    time_t T1 = time(NULL);
    char *str = ctime(&T1);
    if(*str == '\0')
    {
        fprintf(stderr,"Error in fetching Time\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\nTime Taken By CPU : %f Seconds\n",cpu_time_used);
        exit(EXIT_FAILURE);
    }
    else if (str != NULL)
    {
        fprintf(stderr,"Current Time is : %s",str);
        
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken By CPU : %f Seconds\n",cpu_time_used);
    exit(EXIT_SUCCESS);
}


#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

int main(void)                     // Program to Check and Set a Bit at Given Position
{
    clock_t start, end;
    start = clock();
    size_t sctime;
    double cpu_time_used;
    time_t T1 = time(NULL);
    srand((unsigned) T1);                   // Seed the random number generator
    printf("Current Time : %s", ctime(&T1));
    printf("Generated Random Numbers : ");
    for(int i = 0; i < 10; i++)
    {
        long r = rand();                    // Generate a random number
        printf("%ld ", r);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken By CPU : %f Seconds\n",cpu_time_used);
    return 0;
}

/* This program is generating random numbers , fills array with random numbers and then display that */
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
void fillarray(double arr[],int n);
void showarray(const double arr[],int n);
void sortarray(double arr[],int n);
int comp(const void * a, const void * b);

int main(void)                     // Program to Check and Set a Bit at Given Position
{
    clock_t start, end;
    start = clock();
    double cpu_time_used;
    time_t T1 = time(NULL);
    int n;
    printf("Enter the Size of Array : ");
    scanf("%d",&n);
    double arr[n]; 
    memset(arr,0,n*sizeof(double));
    fillarray(arr,n);
    showarray(arr,n); 
    sortarray(arr,n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken By CPU : %f Seconds\n",cpu_time_used);
    return 0;
}
int comp(const void * a, const void * b)
{
    printf("\nComparing %lf and %lf",*(double*)a,*(double*)b);
    if ( *(double*)a <  *(double*)b ) return -1;
    if ( *(double*)a == *(double*)b ) return 0;
    if ( *(double*)a >  *(double*)b ) return 1;
}
void sortarray(double arr[],int n)
{
    qsort(arr,n,sizeof(double), comp); 
    printf("\nSorted Array is : \n");
    showarray(arr,n);
}


void fillarray(double arr[],int n)
{
    time_t T1 = time(NULL);
    srand(T1);
    for(int i=0;i<n;i++)
    {
        arr[i] = (double)rand()/((double) rand() + 0.1);
    }
}

void showarray(const double arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%lf ",arr[i]);
    }
}

/*
 ============================================================================
 Name        : AU4.1.7.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void behind(int *, int);

int main(void) {
    int array[] = {4,2,3,1,1};
    int N=5, i;

    /*scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }*/
    behind(array,N);
    for (i=0; i<=N-1; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
void behind(int *ptr,int size){
    int g_i=0;
    int cnt_g=0;
    int g_n;
    for(int i=0;i<=size-1;i++){
    cnt_g=0;
        for(int j=0;j<=size-1;j++)
        {
        if(ptr[i]>ptr[j] && cnt_g<size-1){
        	++cnt_g;
        }
        }
        if(cnt_g==size-1){
            g_i = i;
        }
    }
    g_n = ptr[g_i];
    printf("greatest number is : %i\n",g_n);
    for(int i=0;i<=size-1;i++){
    	ptr[i] = g_n-ptr[i];
    }

}

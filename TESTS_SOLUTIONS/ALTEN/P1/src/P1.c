/*
 ============================================================================
 Name        : P1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int A[] = {4, 2, 5, 8, 7, 3, 7};
	int *tp=NULL,*hp=NULL,sum=0;
	int N = sizeof(A)/sizeof(A[0]);
	int cnt=0;
    tp=A+1;
	hp=A;

    while(hp<A+N)
    {
     sum = *hp+*tp;
    	if(sum%2==0){
    	cnt+=1;
    	hp=hp+2;
    	tp=tp+2;
    	}
    	else if(sum%2!=0){
    	tp=tp+1;
    	hp=hp+1;
    	}

    }
    printf("%i",cnt);

    }










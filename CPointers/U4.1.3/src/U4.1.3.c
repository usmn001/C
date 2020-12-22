/*
 ============================================================================
 Name        : U4.1.3.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Pass pointers to functions, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void timesTwo(int *);
int main(void) {
	int n;
	printf("please enter an integer ");
	scanf("%i",&n);
	printf("In main:You entered %d.\n",n);
	timesTwo(&n);
	printf("In main: The value of n is %d.\n",n);
	return 0;
}

void timesTwo(int *numptr){
    printf("In the function : the number is %d.\n",*numptr);
    *numptr = *numptr *2; /* Here value of n pointed by pointer numptr get's changed
                             As we passed it's address from main thread */
    printf("In the function : new number is %d.\n",*numptr);
}

/*
 ============================================================================
 Name        : 4.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Pass variables to functions by reference in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void add(int,int,int*);
int main(void) {
	int a,b,sum;
	printf("Enter two numbers ");
	scanf("%i %i",&a,&b);
	add(a,b,&sum);       /*Here we are passing variable sum by reference i.e.
	                       by passing it's address to a pointer located in
	                       function call'd */

	printf("Sum = %i",sum);
}
void add(int a,int b,int *sum){
*sum = a+b;
}

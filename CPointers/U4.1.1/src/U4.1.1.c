/*
 ============================================================================
 Name        : 1.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Find the address of a variable, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void myFunction(int *,double *,char *);
int main(void) {
	int i=42;
	int *iAdr =&i;
	double a = 3.14;
	double *aAdr = &a;
	char c ='p';
	char * cAdr;
	cAdr = &c;
	printf("i = %d and its address is %p.\n",i,iAdr);
	printf("a = %lf and it's address is %p.\n",a,aAdr);
	printf("c = %c and its address is %p.\n",c,cAdr);
	myFunction(iAdr,aAdr,cAdr);
	return(0);
}

void myFunction(int *iptr, double *aptr, char *cptr){
printf("Function received address %p, %p,%p",iptr,aptr,cptr);
}



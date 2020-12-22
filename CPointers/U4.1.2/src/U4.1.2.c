/*
 ============================================================================
 Name        : U4.1.2.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Dereference a pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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
		*iAdr=50;           /*Assigning new value at memory address of integer variable a
		                      pointed by pointer iAdr as we copied address of variable a in pointer iAdr*/

		printf("i = %d and its address is %p.\n",i,iAdr);
		*aAdr=2.6822;
		printf("a = %lf and it's address is %p.\n",a,aAdr);
		*cAdr='u';
		printf("c = %c and its address is %p.\n",c,cAdr);
		return(0);
}

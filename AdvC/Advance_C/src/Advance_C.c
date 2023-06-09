/*
 ============================================================================
 Name        : Advance_C.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <complex.h>


int num =1;
int n2;
static int a;

static struct{
	int age;
	char name[];
}Person;



void add(){

printf("\n In main thread a = %i",a);
}


int main(void) {
	int cnt=1;
	char *ptr = "Hello Usman";
	char arr[] = "Hello Usman";
	typedef int aa;
	num +=1;

	printf("In main thread Num = %i",num);

	n2 -=1;
	printf("\n In main thread n2 = %i",n2);
	while(cnt<5){
		 a+=1;
		 add();
		 cnt+=1;

	}
for(int i=0;i<6;i++){

	printf("\n Character %c is at address  : %p",*(ptr+i),(ptr+i));
}

printf("size of array = %zu",sizeof(arr));
printf("\n %c",*(arr+1));
printf("\n %zu",strlen(ptr));

/*********Complex Numbers*********/

#ifdef __STDC_NO_COMPLEX__
 printf ("\n Complex numbers are not supported. \n");
#else
 printf("Complex numbers are supported.\n");

 double complex cx = 1.0 + 3.0*I;
 double complex cy = 1.0 - 4.0*I;

 printf("Complex number values are : cx = %.2f%+.2fi  cy = %.2f%+.2fi\n", creal(cx), cimag(cx),creal(cy),cimag(cy));

#endif


 /*******Type Qualifiers********/

const int a = 1;
const int ptr1 = &a;
printf("\n const pointer address = %p",ptr1);




	return EXIT_SUCCESS;
}











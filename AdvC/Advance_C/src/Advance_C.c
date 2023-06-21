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
#include <stdarg.h>
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

//typedef int dty;


/********** Variadic Function****************/

int sum(int v1,...) {
va_list parg;
int val = 0,sum = 0,cnt=0;
va_start(parg,v1);
while(cnt<v1){
	val = va_arg(parg,int);
	sum +=val;
	cnt+=1;
}
va_end(parg);

return sum;
}

/************ Unions***********/

union Person {
	int age;
	char *name;

};


int entries =5;
enum symbolType{i,f,c};

struct table{

  char *name;
  enum symbolType type;
 union {
   int i;
   float f;
   char c;
} data;

};

/*double average(double v1,double v2,...) {
va_list parg;
double sum = v1 + v2;
double value = 0.0;
int cnt = v1;
va_start(parg,v2);

while((value = va_arg(parg,double)) != 0.0) {
  sum += value;
  ++cnt;
}
va_end(parg);

return sum/cnt;
}*/

int main(void) {

	/*int cnt=1;
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

//*********Complex Numbers*********

#ifdef __STDC_NO_COMPLEX__
 printf ("\n Complex numbers are not supported. \n");
#else
 printf("Complex numbers are supported.\n");

 double complex cx = 1.0 + 3.0*I;
 double complex cy = 1.0 - 4.0*I;

 printf("Complex number values are : cx = %.2f%+.2fi  cy = %.2f%+.2fi\n", creal(cx), cimag(cx),creal(cy),cimag(cy));

#endif


 //*******Type Qualifiers********

const int a = 1;
const int ptr1 = &a;
printf("\n const pointer address = %p \n ",ptr1);

volatile int b;

//*** Advanced Control Flow *********

int i=(5,10);
label : printf("\n Hello");

goto label;
	return EXIT_SUCCESS;*/

/*putchar('C');

double v1= 10.5, v2 = 2.5;
int num1 = 6, num2 = 5;
long num3 = 12L, num4 = 20L;*/

//printf("Average = %.2lf\n@",average(v1,3.5,v2,4.5,0.0));


printf("\n Using variadic function Sum = %i \n ",sum(2,2,4));


//----------------Union-----------------------

union Person p1;
p1.age=15;
printf("Person Age = %i\n",p1.age);
p1.name = "USMAN";
printf("Person Name = %s\n",p1.name);

//printf("\n Average = %.2lf",average(v1,3.5,v2,4.5,0.0));
entries =1;
struct table t[entries];

t[0].name = "USMAN";





}








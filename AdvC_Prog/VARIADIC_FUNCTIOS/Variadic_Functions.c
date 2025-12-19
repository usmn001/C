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



/********** Variadic Function****************/

int sum(int v1,...) 
{
va_list parg;
int val = 0,sum = 0,cnt=0;
va_start(parg,v1);

for(cnt = 0;cnt<=v1+1;cnt++)
{
	val = va_arg(parg,int);
	sum +=val;
	cnt+=1;
}
va_end(parg);

return sum;
}


int main(void) 
{
printf("Output Of Sum = %i",sum(5,1,2,3,4));  // 1st element is showing the count of elements passed.





}








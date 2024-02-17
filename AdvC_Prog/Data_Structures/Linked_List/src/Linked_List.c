/*
 ============================================================================
 Name        : Linked_List.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct X{
	double d_;
	short s_;
	int i_;
	bool b_;
};

struct Y{
	bool b_;
	short s_;
	int i_;
	int* ptr_;
};

int main(){
	uint8_t c = 0;
	uint8_t n= 0;
	n=4;
	while(n){
		if(n&1) ++c;
		n>>=1;
	}
printf("%i",n);
}

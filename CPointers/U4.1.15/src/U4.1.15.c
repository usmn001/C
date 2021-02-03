/*
 ============================================================================
 Name        : U4.1.15.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Allocate memory for arrays using malloc in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *array;
	printf("Size of int is : %i\n",sizeof(int));
	array = (int*)malloc(4*sizeof(int));  /*Here we've reserved 4 memory spaces having unique memory address on heap each single one of the size of int data type which is 4 bytes i.e. 32 bits  */
	printf("Returned malloc pointer is : %p\n",array);
	printf("Before heap address, reserved memory space is : %x \n",(array-1));
	array[0] = 11;
	*(array+1) = 222;
	array[2] = 333;
	array[3] = 4444;
	*(array+4) = 555;
	array[5] = 666;
	printf("Heap Memory address %p contains %i\n",array,array[0]);
	printf("Heap Memory address %p contains %i\n",(array+1),array[1]);
	printf("Heap Memory address %p contains %i\n",array+2,array[2]);
	printf("Heap Memory address %p contains %i\n",(array+3),array[3]);
	printf("Heap Memory address %p contains %i\n",(array+4),*(array+4));
	printf("Heap Memory address %p contains %i\n",(array+5),*(array+5));

	/*So here we've seen heap memory is dynamic except when it's defined in
	 * a dedicated and designed OS and can be expanded or decreased as well
	 * as we see though we have defined heap memory of 4 spaces but we managed
	 * to increse it and able to store more data */



}

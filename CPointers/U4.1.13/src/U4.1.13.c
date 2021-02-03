/*
 ============================================================================
 Name        : U4.1.13.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Allocate memory in the heap using malloc in C, Ansi-style
 ============================================================================
 */
/*
 * In c we can allocate memory on heap(RAM) using malloc function that
 * returns a void pointer holding starting address pointing to the memory
 * space during reserved during a program run time, it depends upon the
 * underlying architecture how it implements this malloc function however
 * in the beginning of memory view we see that on adjacent left most side
 * of reserved memory space a hexadecimal number shows how many memory spaces
 * are reserved by malloc and on adjacent right side of memory space another
 * hexadecimal number indicates how much memory space is left/free or empty
 * for use thus we can use both of these numbers through the malloc provided
 * returned pointer by performing pinter arithmetic upon it
 *          */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *ptr1;
	double *ptr2;
	ptr1 = (int*)( malloc( sizeof(int) ) ); /*Always cast malloc as it returns a void pointer   */
	ptr2 = (double*) ( malloc(sizeof(double) ) );
	*ptr1 = 5;        /*      */
	*ptr2 = 9.01;
	return EXIT_SUCCESS;
}

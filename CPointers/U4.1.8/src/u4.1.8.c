/*
 ============================================================================
 Name        : U4.1.8.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Use pointers to pointers and dereference in  C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void settozero(short **t);
int main(void) {
	short a[3] = {222,1111,777};
	short b[2] = {1234,5678};
	short *t[2] = {a,b};
	settozero(t);
	return EXIT_SUCCESS;
}
void settozero(short **t){
	/* Method 1 : Using Dereference Pointer and Performing Pointer Arithmetic

	*(t[0]+0) =  11;    // Here t[0] is the address of a[0] thus upon performing pointer arithmetic addition we can access a[1],a[2] elements of array a
	*(t[0]+1) =  22;
	*(t[0]+2) =  77;
	*(t[1]+0) =  33;
	*(t[1]+1) =  44;*/

	/* Method 2 : Accessing & Modifying Array Elements Using Multidimensional
	t[0][0] = 1;
	t[0][1] = 2;
	t[0][2] = 3;
	t[1][0] = 44;
	t[1][1] = 56;*/

    /* By Using Any of the Above methods we can access and modify array a and b elements whose initial addresses held by
       a & b in array of pointers t   */
}


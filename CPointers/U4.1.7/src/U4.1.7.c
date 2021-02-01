/*
 ============================================================================
 Name        : U4.1.7.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Define and work with arrays of pointers and use multiple ways
               for dereferencing in C, Ansi-style

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	short a[3] = {234,655,843};
	short b[2] = {12,62};
	short c[4] =  {3456, 3467, 23, 276};
	short *arrays[3] = {a,b,c}; /*Array Holding First location Addresses of arrays a,b,c as
	                              we already know that array name itself is a pointer pointing
	                              to 1st element memory location of it */

	/* Method 1 : Accessing/Modifying Using Dereferencing Pointer */

	*arrays[0] = 5;       /* accessing 1st element of arrays array that is address of 1st element's  memory location in array a*/
	*(arrays[0]+1) = 6;   /* accessing 2nd element of arrays array that is address of 2nd element's  memory location in array a*/
	*(arrays[0]+2) = 7;   /* accessing 3rd element of arrays array that is address of 2nd element's  memory location in array a*/
	*(arrays[1]) = 1;     /* accessing 1st element of arrays array that is address of 1st element's  memory location in array b*/
	*(arrays[1]+1) = 2;   /* accessing 2nd element of arrays array that is address of 2nd element's  memory location in array b*/
	*(arrays[2]) = 3;     /* accessing 1st element of arrays array that is address of 1st element's  memory location in array c*/
	*(arrays[2]+1) = 4;   /* accessing 2nd element of arrays array that is address of 2nd element's  memory location in array c*/
	*(arrays[2]+2) = 5;   /* accessing 3rd element of arrays array that is address of 3rd element's  memory location in array c*/
	*(arrays[2]+3) = 6;   /* accessing 4th element of arrays array that is address of 4th element's  memory location in array c*/


	/* Method 2 : Accessing/Modifying Using Multi dimensional array concept */

	arrays[0][0] = 1;    /* accessing 1st element of array a through array arrays pointer*/
	arrays[0][1] = 2;    /* accessing 2nd element of array a through array arrays pointer */
	arrays[0][2] = 3;    /* accessing 3rd element of array a through array arrays pointer*/

	arrays[1][0] = 4;    /* accessing 1st element of array b through array arrays pointer*/
	arrays[1][1] = 5;    /* accessing 2nd element of array b through array arrays pointer*/

	arrays[2][0] = 6;    /* accessing 1st element of array c through array arrays pointer*/
	arrays[2][1] = 7;    /* accessing 2nd element of array c through array arrays pointer*/
	arrays[2][2] = 8;    /* accessing 3rd element of array c through array arrays pointer*/
	arrays[2][3] = 9;    /* accessing 4th element of array c through array arrays pointer*/

	/* so we can access elements and locations being pointed out by array pointers that
	   are stored in an array of pointers named as arrays as in this array arrays each memory location contains address of
	   1st elements present in array of a,b,c and pointed out by these names in the array arrays i.e. value held by a is
	   address of a[0] element , and value held by b is address of b[0] element and value held by c is address of c[0] element
	   so we can access and modify these elements and others consequitively by performing pointer arithmetic  */


    return 0;



}

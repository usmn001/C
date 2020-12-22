/*
 ============================================================================
 Name        : U4.1.5.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer arithmetic in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[]={6, 2, -4, 8, 5, 1};
	int *ptr1,*ptr2;

	printf("Array Contains %d,%d,%d,%d,%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]);
	printf("Stored at :%p,%p,%p,%p,%p,%p\n ",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5]);

	ptr1 = arr;      /*arr points to first location of arr[0]
	                 now pointer ptr1 has address of 1st location of array */
	ptr2 = &arr[1];  /*ptr2 pointer has address of 2nd element of array */

	*ptr1=10;        /* we can update memory locations of array by copying
	                 respective address of it's location into a pointer
	                 and then we can use that pointer for performing
	                 different operations on consequitive locations
	                 ptr1 now updates 1st location of array with 10 */


	*(ptr1+1)=11;
    *(ptr1+2)=99;

    *arr = 3;
    *(arr+1)=10;
    *(arr+2)=99;

    ptr1++;
    *ptr1 =7;

    ptr1 +=3;
    *ptr1=8;

    return 0;
}

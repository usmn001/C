/*
 ============================================================================
 Name        : U4.1.14.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Deallocate memory in the heap using free in C, Ansi-style
 ============================================================================

 We need to deallocate memory in the heap as we know that both heap and stack
 are stored in RAM so if we keep filling & storing data heap wihtout managing
 or freeing it during execution of a program then RAM memory will get occupied
 and overflow casuing our program and entire system to crash this is carefully
 taken into account when porting,developing,refining a program on a target
 embedded mcu,soc where we have limited RAM memory unlike large RAM found
 in the development systems.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *ptr1,*ptr2;
	ptr1 = (int*) malloc (  sizeof(int)       );
	*ptr1=5;
	//free(ptr1);
	ptr2 = (int*) malloc (  sizeof(int) );
	*ptr2 = 10;

	printf("Without Using free call for deallocating heap \n");
	printf("Address of ptr1 : %p,  Value Stored at ptr1 : %i \n",ptr1,*ptr1);
	printf("Address of ptr2 : %p,  Value Stored at ptr2 : %i  ",ptr2,*ptr2);


	printf(" \n Using free call for deallocating heap \n");
	free(ptr1); free(ptr2);
	ptr1 = (int*) malloc (  sizeof(int)       );
	*ptr1=55;
	free(ptr1);
	ptr2 = (int*) malloc (  sizeof(int) );
	*ptr2 = 19;
	printf("Address of ptr1 : %p,  Value Stored at ptr1 : %i \n",ptr1,*ptr1);
	printf("Address of ptr2 : %p,  Value Stored at ptr2 : %i  " ,ptr2,*ptr2);

	/* So we can clearly see that when we use free function call for deallocating
	 * or freeing up heap memory it gets reassigned to other data pointed out
	 * by memory address returned by malloc when allocating it to again heap thus
	 * we cannot access previous old stored value when free library function from
	 * stdlib header file is used as same heap memory address get assigned to
	 * new value and moreover memory allocation and address assignment also varies
	 * one underlying architecture to another one.
	 */


}

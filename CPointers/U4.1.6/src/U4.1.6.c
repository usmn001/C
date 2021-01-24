/*
 ============================================================================
 Name        : U4.1.6.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Pass arrays to functions in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void printarray(int *,int);
void squarearray(int *,int);

int main(void) {
	int arr[] = {1,2,3,4,5,6};
	int ptr=NULL;
	int size = 6;
	printarray(arr,size);
	squarearray(arr,size);
    return 0;
}
void printarray(int *ptr,int size){
	for(int i=0;i<=(size-1);i++){
		printf("%d\n",*(ptr+i));   /* print array by dereferencing pointer*/


	}
	for(int i=0;i<=(size-1);i++){
	printf("%d\n",ptr[i]);     /* by looping on the array indices through
			                            pointer as arr array variable itself points
			                            to array locations as ptr=arr*/
	}

}

void squarearray(int *ptr,int size){
	for(int i=0;i<=(size-1);i++){
		ptr[i] = ptr[i] * ptr[i];
/*/*(ptr+i)=*(ptr+i)*(*(ptr+i)); we can also use this method of changing
array elements by dereferencing the pointer */
	}

}

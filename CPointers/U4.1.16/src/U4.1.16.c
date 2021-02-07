/*
 ============================================================================
 Name        : U4.1.16.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Learn from another example of array memory allocation in C, Ansi-style
 ============================================================================
 Here we've learn't how to allocated exact precise memory/address space on heap
 located in RAM through the use of sizeof function inside malloc as sizeof
 operator or function returns the size of a single data type to be placed
 on heap here in our case thus saving memory or address space from non
 essential and extra usage. Moreover here in malloc besides using sizeof
 we also defined how many memory spaces we require for each data type in the
 form of a number stored in variable num and multiplied with sizeof in
 malloc function.
 */

#include <stdio.h>
#include <stdlib.h>
double * allocateheap(int);
double findavggrade(double *array,int num);
int main(void) {
	int num,i;
	double *array_g;
	double avg=0;
	printf("Enter number of grades you want to enter : ");
	scanf("%i",&num);
	array_g=allocateheap(num);

	for(i=1;i<=num;i++){
	printf("\n Enter Grade of %i Student : ",i);
	scanf("%lf",array_g+i);   /*Iterating and storing data in heap memory
	                            through pointer arithmetic*/
	}


	avg=findavggrade(array_g,num);
	printf("\n Average Grade of %i Students : %.2lf",num,avg);
	free(array_g);
	return EXIT_SUCCESS;
}
double *allocateheap(int num){
	double *mem_p;
	mem_p=(double*)malloc(num*(sizeof(int)));
	return mem_p;
}

double findavggrade(double *array,int num){
	int i;
	double avg_grade=0;
	for(i=1;i<=num;i++){
		avg_grade += array[i];
	}
	avg_grade = avg_grade/num;
	return avg_grade;
}



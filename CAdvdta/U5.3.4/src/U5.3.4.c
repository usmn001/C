/*
 ============================================================================
 Name        : U5.3.4.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Free all space allocated for a linked list in C, Ansi-style
 ============================================================================
For freeing the heap memory we pass'd the start structure/list pointer to another function
freeNumber where we before using it saves the address of next structure of the list present
in a temp pointer and then again copies the address of next structure in the start and then
repeat this process again & again until next pointer shows NULL value.
 */



#include <stdio.h>
#include <stdlib.h>

struct digit{
	int num;
	struct digit *next;
};

struct digit *createDigit(int digit);
struct digit *append(struct digit *end,struct digit *newDigit);
void printNumber(struct digit *sptr);
void freeNumber(struct digit *sptr);

int main(void) {
	struct digit *start,*end,*newDigit;
	int a=5;
	int b=9;
	int c=10;
	start=createDigit(a);
	end=start;
	newDigit=createDigit(b);
	end=append(end,newDigit);
	newDigit=createDigit(c);
	printNumber(start);
	freeNumber(start);
	return EXIT_SUCCESS;
}

void freeNumber(struct digit *sptr){
	struct digit *tmp;
	while(sptr!=NULL){
		tmp=sptr->next; /*Address of next strucuture is being copied from current structure
		                  member pointer next to another structure pointer tmp,
		                  it should be noted that here that strcutre pointer sptr
		                  has address of heap memory locations where contents of
		                  cureent structure are stored*/

		/*Debug Statements
		 *printf("\nBefore Execution Of Free Func.Call The Address of Pointer tmp  is : %p, Address of sptr : %p",tmp,sptr);
		 *printf("\n Before Free Memory Space Reserved is %x ",*(sptr-1));*/
		free(sptr);
		/*Debug statement
		 *printf("\n Memory Space Reserved is %x ",*(sptr-1));*/
		sptr=tmp;
		/*Debug statement
		 *printf("\nAfter  Execution Of Free Func.Call The Address of Pointer sptr is : %p",sptr);
		 */
	}
}

void printNumber(struct digit *sptr){
	while(sptr!=NULL){
	printf("%i\n",sptr->num);
	sptr=sptr->next;
	}

}

struct digit *createDigit(int digit){
	struct digit *ptr;
	ptr=(struct digit*)malloc(sizeof(int));
	ptr->num=digit;
	ptr->next=NULL;
	return ptr;
}

struct digit *append(struct digit *end,struct digit *newDigit){
	end->next=newDigit;
	return end->next;
}

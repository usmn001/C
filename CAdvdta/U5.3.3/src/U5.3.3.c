/*
 ============================================================================
 Name        : U5.3.3.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Print a linked list in C, Ansi-style
 ============================================================================
A linked list is formed when two or more structures or more memory locations
containing data are linked together through an inside structure pointer that stores
address of next structure memory location. It should be noted that these memory locations
are on heap created by malloc function call returning a pointer that can be casted.
 */



#include <stdio.h>
#include <stdlib.h>
struct Digit{
	int num;
	struct Digit *next;
};
struct Digit* createDigit(int rnum);
struct Digit* append(struct Digit*end,struct Digit*sptr);
void printlist(struct Digit *ptr);
int main(void) {
	int a=5;
	int b =6;
	int c =9;
	struct Digit *st,*end,*newDigit,*tmp;
	st = createDigit(a);
	printf("1st list address on heap %p ",st);
	end=st;
	newDigit=createDigit(b);
	printf("\n2nd list address on heap %p ",newDigit);
	end=append(end,newDigit);
	newDigit=createDigit(c);
	printf("\n3rd list address on heap %p ",newDigit);
	end = append(end,newDigit);
	printlist(st);
	tmp=st->next;
	free(st);
	free(tmp);
	printf("\nHeap address in tmp %p ",tmp);
	free(end);
	printf("\nHeap address in end %p ",end);

	return EXIT_SUCCESS;
}

struct Digit* createDigit(int rnum){
	struct Digit *hptr;
	hptr = (struct Digit*)malloc(sizeof(struct Digit));
	hptr->num=rnum;
	hptr->next=NULL;
	return hptr;
}

struct Digit* append(struct Digit*end,struct Digit*sptr){
	printf("\n Heap Address %p is Appended In Next Pointer Of List %p",sptr,end);
	end->next=sptr;
	return end->next;
}

void printlist(struct Digit *ptr){
	while(ptr!=NULL){
	printf("\n%i is stored in list at heap memory address %p",ptr->num,ptr);
    ptr = ptr->next;
	}
}

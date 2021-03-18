/*
 ============================================================================
 Name        : U5.3.10.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Insert a new node at the start of a linked list in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct digit{
	int num;
	struct digit *next;
};

struct digit *createDigit(int);
struct digit *append(struct digit *,struct digit *);
void freelist(struct digit*);
void printlist(struct digit*);
struct digit * reverseNumber(struct digit*);
struct digit * readNumber(void);

int main(void) {
	struct digit *start,*bstart;
    printf("Enter A Number : ");
    start=readNumber();
    printlist(start);
    bstart=reverseNumber(start);
    printf("\nReverse Number : ");
    printlist(bstart);
    freelist(start);
    freelist(bstart);
	return EXIT_SUCCESS;
}

struct digit *insertAtFront(struct digit *start,struct digit *newptr){
	printf("\n newptr : %p",newptr);
	newptr->next=start;
	printf("\n newptr->next after : %p ",newptr->next);
	return newptr;
}

struct digit *reverseNumber(struct digit *start){
	struct digit *bstart=NULL,*newDigit;

	if(start!=NULL){
		bstart=createDigit(start->num);
		start=start->next;
	}
	while(start!=NULL){
		newDigit=createDigit(start->num);
		printf("\nbstart : %p ,newDigit : %p",bstart,newDigit);
		bstart=insertAtFront(bstart,newDigit);
		start=start->next;
	}
	return bstart;
}


struct digit *readNumber(){

struct digit *start, *end, *newDigit;
char c;
int d;
start=NULL;
scanf("%c",&c);

while(c!='\n'){
	d=c-48;
	newDigit=createDigit(d);
	if(start==NULL){
		start=newDigit;
		end=start;
	}
	else{
		end=append(end,newDigit);
	}
	scanf("%c",&c);
}
return (start);

}

struct digit *createDigit(int n){
    struct digit *ptr;
	ptr=malloc(sizeof(struct digit));
	ptr->num=n;
	ptr->next=NULL;
	return ptr;
}

struct digit *append(struct digit *end,struct digit *newDigit){
	end->next=newDigit;
	return (end->next);
}

void freelist(struct digit *start){
	struct digit *tmp;
	while(start!=NULL){
		tmp=start->next;
		free(start);
		start=tmp;
	}
}

void printlist(struct digit *start){
	while(start!=NULL){
		printf("%i",start->num);
		start=start->next;
	}
}

/*
 ============================================================================
 Name        : U5.3.8.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Search for a node in a linked list in C, Ansi-style
 ============================================================================
The structures containing data and next pointer storing address on next structure
are often called nodes or elements and are also known as records oof a linked list.
In this program we traverse and search'd across each node (structure)
member variable num for finding out a digit whether it's present in that node's
member variable . If a node contains that digit of the entered number then our
member function searchNumber returns address of that node's memory location and
if that digit is not found then it returns NULL.
 */

#include <stdio.h>
#include <stdlib.h>

struct digit {
	int num;
	struct digit *next;
};

/* Function Prototypes */
struct digit *createDigit(int);
struct digit *append(struct digit *,struct digit *);
void freelist(struct digit *);
void printNumber(struct digit *);
struct digit *readNumber(struct digit *);
struct digit *searchNumber(struct digit *,int);

int main(void) {
	int num=0;
	struct digit *start=NULL,*ptr=NULL;
	printf("Enter A Number : ");
	start=readNumber(start);
	printNumber(start);
	/* Debug statement */
	printf("Size of struct digit is : %i bytes\n",sizeof(struct digit));
	printf("Enter A Digit To Search :");
	scanf("%i",&num);
	ptr=searchNumber(start,num);
	if(ptr!=NULL){
				printf("Found Digit %i At location %p",num,ptr);
			}
			else {
				printf("Digit %i not found ",num);
			}
	freelist(start);
	return EXIT_SUCCESS;
}
/* Function Definitions */
struct digit *createDigit(int num){
	struct digit *hptr;
	hptr=(struct digit *)malloc(sizeof(struct digit));
	hptr->num=num;
	hptr->next=NULL;
	return hptr;
}

struct digit *append(struct digit *end,struct digit *newDigit){
	end->next=newDigit;
	return (end->next);
}

struct digit *readNumber(struct digit *start){
	start=NULL;
	struct digit *end,*newDigit;
	int b=0;
	char c=0;
	scanf("%c",&c);

	while(c!='\n'){
		b=c-48;
		newDigit=createDigit(b);
		/* Debug Statement */
		//printf("Digit %d is stored at %p of %i bytes \n",b,newDigit,(sizeof(newDigit)));
		if(start==NULL){
		start=newDigit;
		end=start;
		}
		else{
			end=append(end,newDigit);
		}
		scanf("%c",&c);
	}
	/* Debug Statments */
	   //printf("Size of struct digit next pointer is %d Bytes\n ",sizeof(start->next));
	   //printf("Linked list starts at %p , ends at %p\n",start,end);
	return start;
}

void freelist(struct digit *start){
	struct digit *tmp;
	while(start!=NULL){
		tmp=start->next;
		free(start);
		start=tmp;
	}
}

void printNumber(struct digit *start){
	while(start!=NULL){
		printf("%i",start->num);
		start=start->next;
	}
	printf("\n");
}

struct digit *searchNumber(struct digit *start,int num){
	while((start!=NULL) && (start->num!=num)){ /* Here condition start!=NULL in while loop is checked 1st before
	                                              second condition start->num!=num and 2nd condition is only checked if first one
	                                              is held true */
		start=start->next;
	}
	return start;
}

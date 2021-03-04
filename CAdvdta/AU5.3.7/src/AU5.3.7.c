/*
 ============================================================================
 Name        : AU5.3.7.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Activity: check divisibility (External resource) in C, Ansi-style
 ============================================================================
In this activity we are using a function divisibleByThree for checking whether an integer entered by user and stored in a linked list
at different memory locations in heap is divisible by 3 or not . For checking this we add all the digits of number entered by user then
divide that sum of digits by 3 and then check the remainder if it's zero then function returns 1 indicating entered number is divisble by
three while if remainder is not 0 then it returns 0 indicating entered number is not divisible by 3. It should be noted that here again we
are using scanf for getting nput from user , the scanf reads one by one each digit of entered number and then we pass each digit to another
function createDigit where each of the digit get's stored in heap memory at specific location pointed by return'd address from malloc and
stored in a pointer after casting.
 */

#include <stdio.h>
#include <stdlib.h>

struct digit *createDigit(int num);
struct digit *append(struct digit *end,struct digit *newDigit);
void printNumber(struct digit *start);
void freelist(struct digit *start);
int divisibleByThree(struct digit *start);
struct digit *readnumber();

struct digit{
	int num;
	struct digit *next;
};

int main(void) {
	struct digit *start;
    printf("Enter A Number Please: ");
    start=readnumber();
    printNumber(start);
    printf("The number ");
    if(divisibleByThree(start)){
    	printf("is divisible by 3.\n");
    }
    else{
    	printf("is not divisible by 3.\n");
    }
    freelist(start);
	return EXIT_SUCCESS;
}
struct digit *readnumber(){
    struct digit *start,*end,*newDigit;
	int a;
	char c=0;
	start=NULL;
	scanf("%c",&c);   /* Whenever we enter a character input in scanf like here then instead
	                     of itself it's ASCII code is stored in memory, scanf reads
	                     1 by 1 all entered characters and stores them in subsequent
	                     memory locations in the form of their ASCII codes.
	                     To display it's ASCII code stored in memory we can use
	                     printf statement with %d as output format specifier */

	while(c!='\n'){      /*\n symbol will read by scanf at end of entered characters*/

		a = c-48;     /* Performing Conversion From Character Data Type
		              To Integer Data Type */
		newDigit = createDigit(a); /*Saving Enter'd Character On Heap Memory & Returning
		                             A Pointer Containing Address Of That Location*/
		printf("Input'd Character %c with ASCII code : %d ",c,c);
		printf("is stored at heap address %p\n",newDigit);
	    if(start==NULL){              /* Here we are checking as for 1st digit our start pointer is null as we cannot call append function
	                                     for updating next pointer so we are copying address of 1st structure of linked list from
	                                     start pointer into end pointer so that upon 2nd enter'd digit we can pass this address
	                                     to append function for updating next pinter of first structure and end pointer as shown
	                                     below in else section */

	    	start=newDigit;
	    	end=start;
	    }
	    else{
	    	end=append(end,newDigit);   /* Updating end and next pointers, passing initial linked list structure heap address
	    	                               and of newly created heap memory location storing new data value */
	    }
	    scanf("%c",&c);
	}
	return start;
}
int divisibleByThree(struct digit *start){
	int sum = 0;
	while(start!=NULL){
	sum += start->num;
	start=start->next;
	}
	//printf("\n sum = %i",sum);
	if(sum%3==0)
		return 1;
	else
		return 0;

	//printf("\n sum = %i",sum);

}
void freelist(struct digit *start){
	struct digit *tmp;
	while(tmp!=NULL){
		tmp=start->next;
		free(start);
		start=tmp;
	}
}

void printNumber(struct digit *start){
	while(start!=NULL){
		printf("%d",start->num);
		start=start->next;
	}
	printf("\n");
}

struct digit *createDigit(int num){
	struct digit *ptr;
	ptr=(struct digit*)malloc(sizeof(struct digit));
	ptr->num=num;
	ptr->next=NULL;
	return ptr;
}

struct digit *append(struct digit *end,struct digit *newDigit){
           end->next=newDigit;
           return newDigit;
}

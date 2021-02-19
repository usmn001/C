/*
 ============================================================================
 Name        : U5.3.1.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Append a node to a linked list in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct digit *createDigit(int digit);
struct digit *append(struct digit *end,struct digit *newptr);

struct digit {
	int num;
	struct digit *next;
};


int main(void) {
	struct digit *start, *end, *newDigit,*tmp;
	int a =5;
	int b=6;
	int c=7;
	start = createDigit(a);          // 1st heap memory location address pointing to 1st instance of structure containing digit 5 of variable a
	end = start;                     // linked list ends at 1st memory location of 1st structure instance
	newDigit=createDigit(b);         // 2nd Heap memory location address pointing to 2nd instance of structure containing digit 6 of variable b
	end = append(start,newDigit);    // appending 2nd reserved heap memory location storing it's address in 1st instance of structure next pointer.
	newDigit =createDigit(c);        // 3rd Heap memory location address pointing to 3rd instance of structure containing digit 7 of variable c
	end = append(end,newDigit);      // Appending 3rd reserved heap memory location storing it's address in 2nd instance of structure next pointer.
    tmp=start->next;                 // copying 2nd heap memory address location in another pointer
	free(start);                     // Freeing 1st memory address location
	start = tmp;                     // Copying again 2nd heap memory location address
	tmp = start->next;               // Copying 3rd Heap memory location address
	free(start);                     // Freeing 2nd heap memory locations
	printf("%i",newDigit->num);
	free(tmp);                       // Freeing 3rd Heap memory location
	printf("\n%i",newDigit->num);
	return EXIT_SUCCESS;
}

struct digit *createDigit(int digit){
	struct digit *ptr;
	ptr = (struct digit*)malloc(sizeof(struct digit));
	ptr->num=digit;
	ptr->next=NULL;
	return ptr;
}

struct digit *append(struct digit *end, struct digit *newptr){
	end->next=newptr;
	end = newptr;
	return end;

}




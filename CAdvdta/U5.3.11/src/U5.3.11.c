/*
 ============================================================================
 Name        : U5.3.11.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Create a sorted copy of a linked list in C, Ansi-style

 Explanation : In this program we are generating a linked list in ascending order from
 an unordered list by using it's starting pointer passed from main function by sorted=sortedCopy(start) statement
 for accessing and comparing elements stored in it's structure nodes while this comparison is performed in insertIntoSorted() function
 where two elements of this unordered list are compared while addresses of these nodes  are passed from sortedCopy() function into
 it while also performing continous updation of starting or beginning node address in the statement
 sortedStart=insertIntoSorted(sortedStart,newDigit) continously being executed inside while loop until end of this unordered list
 pointed by ptr pointer isn't reached and the initial value of this sortedStart pointer is got from
 statement sortedStart=createDigit(ptr->num) before going  into the while loop. This comparison performed inside insertIntoSorted() function
 is done by while((ptr!=NULL) && (ptr->num < newDigit->num)) loop this loop keeps on executing until initial node num value pointed by
 ptr->num  remains lesser than newer nodes num values pointed by newDigit->num and when this condition becomes we change the order of
 these nodes by updating next pointers such that the node containing smaller num value comes before the node containing larger
 num value i.e. prev->next = newDigit ( "here prev contains address of node for which last time this condition "ptr->num < newDigit->num"
 held true before breaking away from while loop" ) and newDigit->next=ptr (" here as ptr->num is greater than newDigit->num so we copy address
 of node ptr in newDigit node's member structure pointer next ) thus node with address in newDigit pointer comes first before that of node
 ptr. Moreover if while loop with condition ((ptr!=NULL) && (ptr->num < newDigit->num)) doesn't satisified even in 1st iteration i.e.
 (in i1st iteration this condition ptr->num < newDigit->num) isn't met then  to bring the nodes in ascending order we execute function
 insertAtFront() where we copy the addess of node cotaining higher num value than that of newDigit node inside newDigit's next pointer by
 newptr->next=start here newptr held's the value of newDigit node thus this is how we can sort an unordered list in an ascending order
 sequence with "next member pointer's playing a crucial role in that as the list get's printed by function printlist() to that we pass
 starting address of list and this address kept on getting updated by statement ptr=ptr->next until end of list indicated by
 NULL terminator isn't reached".
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

struct digit{
	int num;
	struct digit *next;
};

struct digit *createDigit(int);
struct digit *append(struct digit*,struct digit *);
void freelist(struct digit*);
void printlist(struct digit*);
struct digit *readNumber();
struct digit *reverseNumber(struct digit*);
struct digit *insertAtFront(struct digit*,struct digit*);
struct digit *insertIntoSorted(struct digit*,struct digit*);
struct digit *sortedCopy(struct digit*);
struct digit *searchNumber(struct digit*,int num);

int main(void) {
struct digit *start,*bstart,*sorted;
printf("Enter A Number : ");
start=readNumber();
printlist(start);
bstart=reverseNumber(start);
printf("\nReverse Number : ");
printlist(bstart);
printf("\n");
sorted=sortedCopy(start);
printf("\nSorted by Digit : ");
printlist(sorted);
freelist(start);
freelist(bstart);
freelist(sorted);
return 0;
}

struct digit *insertIntoSorted(struct digit *start,struct digit *newDigit){
	struct digit *ptr=start;
	struct digit *prev=NULL;
	while((ptr!=NULL) && (ptr->num < newDigit->num)){
		prev=ptr;
		ptr=ptr->next;
	}
	if(prev==NULL){
		start=insertAtFront(start,newDigit); /*if while loop does not execute even for
		                                       one time due to ptr->num is greater than newDigit->num then
		                                       we go in the func. insertAtFront and change the order how next pointers
		                                       of each node points by making newDigit node next pointer to point at
		                                       start strcture node of linked list and start pointer here get's updated with add.of newDigit
		                                       node so that at first place we have a node in our linked list whose num member variable is lesser than
		                                       next node's num member variable outputting a liked list in ascending order .*/
	}else{
		//printf("prev c.add.ptr = %p, prev num_val = %i, prev_next_add = %p \n",prev,prev->num,prev->next);

		prev->next=newDigit;                   /*This line of code execute only when 2nd condition of while loop get's false (ptr->num becomes greater than newDigit->num)
		                                         so what we do is that since we've saved the address of last node in prev structure pointer whose num mem.variable was
		                                         lesser than that of newDigit node num variable  so we update the next pointer of prev node with address of newDigit node
		                                         such that prev node next pointer points to a node containing greater number   */

		//printf("prev u_next_add = %p,prev u_next.pval =%i \n\n",prev->next,newDigit->num);

		newDigit->next=ptr;                     /*As we know that newDigit->num is lesser than current node ptr->num so we update the next pointer of newDigit node
		                                          with address of current node pointer pointed by pointer ptr such that our list get's sorted in ascending order i.e.
		                                          prev->num < newDigit->num < ptr->num  it should be noted that the order of this list
		                                          is due to the entires that we have made in next pointers of each structure nodes of the list
		                                          moreover here we are performing these operations on an unsorted list and from that unsorted list
		                                          we are generating a sorted list we are just using starting address of that unordered list
		                                          to access it's elements and create our own new ordered list whose starting address is stored
		                                          in sortedStart pointer that is present in sortedCopy() function*/

		//printf("newDigit c.add = %p,newDigit next_add = %p,newDigit num_val = %i,newDigit next_pval =%i\n",newDigit,newDigit->next,newDigit->num,ptr->num);
	}
	return (start);
}

struct digit *sortedCopy(struct digit *start){
struct digit *sortedStart=NULL,*ptr,*newDigit;
ptr=start;
if(start!=NULL){
sortedStart=createDigit(ptr->num);
ptr=ptr->next;
}
while(ptr!=NULL){
	newDigit=createDigit(ptr->num);
	sortedStart=insertIntoSorted(sortedStart,newDigit);
	ptr=ptr->next;
}
return (sortedStart);
}


struct digit *readNumber(){
	struct digit *start=NULL,*end,*newDigit;
	char c;
	int d;
	scanf("%c",&c);
	while(c!='\n')
	{
	d=c-48;/* Converting character data type to integer one through subtracting 48
	                from each character ASCII code */

	newDigit=createDigit(d);/*Storing digit d on heap memory in createDigit() function and
	                            returning address of heap location provided by malloc to
	                            newDigit pointer*/
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

/*Here we are putting address of previous structure node passed from
bstart pointer to new strucutre node next pointer in that way
every consequtive next or new node points to previous node location
generating a list that points backward*/

struct digit *insertAtFront(struct digit *start,struct digit *newptr){
	newptr->next=start;
	return (newptr);
}

struct digit *reverseNumber(struct digit *start){
	struct digit *bstart=NULL, *newDigit;
	if(start!=NULL){                         /*Here we are checking for starting address of list as a
	                                        list will only be created if the user enters a number in
		                                    readNumber() function call*/
       bstart=createDigit(start->num);
       start=start->next;
	}
	while(start!=NULL){
		newDigit=createDigit(start->num);
		bstart=insertAtFront(bstart,newDigit);/*Here bstart contains address of 1st structure node while newDigit contains address of 2nd
		                                         structure node both addresses are passed to function insertAtFront while a new address
		                                         in bstart structure pointer is returned from it */
		start=start->next;
	}
	return bstart;
}

struct digit *searchNumber(struct digit *start,int num){
	while((start!=NULL) && (start->num!=num)){
	start=start->next;
	}
	return(start);

}

void printlist(struct digit *start){
	while(start!=NULL){
		printf("%i",start->num);
		start=start->next;
	}
}

void freelist(struct digit *start){
	struct digit *tmp;
	while(start!=NULL){
		tmp=start->next;
		free(start);
		start=tmp;
	}
}

struct digit *append(struct digit *end,struct digit *newDigit){
	end->next=newDigit;
	return (end->next);
}

struct digit *createDigit(int num){
	struct digit *ptr;
	ptr=(struct digit*)malloc(sizeof(struct digit));
	ptr->num=num;
	ptr->next=NULL;
	return ptr;
}







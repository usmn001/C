/*
 ============================================================================
 Name        : stack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Stack Implementation Using Arrays
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MXSIZE   10

void push();
void pop();
void peek();
bool isEmpty();

struct stack{
	unsigned int stck[MXSIZE];
	unsigned int top;
};

typedef struct stack STACK;

STACK s;


void push()
{
int num;

	if(s.top!=MXSIZE)
	{
		printf("Enter the element to push : ");
		scanf("%u",&num);
		s.top=s.top+1;
		s.stck[s.top]=num;
	}
	else
		printf("Stack is full");

}


void pop()
{
	if(isEmpty()==false)
	{
		printf("\n Popped Element %u",s.stck[s.top]);
		s.top=s.top-1;
	}
	else
		printf("Stack is empty");

}



void peek()
{

	if (isEmpty()==false)
	{
	printf("Top Element is %u",s.stck[s.top]);
	}

}



bool isEmpty()
{

uint8_t state;

if(s.top==-1)
{
	state=true;
}

else
	state =false;

return state;
}


void display()
{

	if(isEmpty()==false)
	{
        printf("Stack Elements : \n");
		for(int index=s.top;index>=0;index--)
		{

		printf("%u  ",s.stck[index]);
		}

	}

	else if(isEmpty()==true)
	{
	printf("\n Stack is empty");
	}

}

int main(void)
{

unsigned int choice;
s.top=-1;

while(choice!=8)
{

printf("\nPress 1 To Push\n");
printf("Press 2 To Pop \n");
printf("Press 3 To Peek the Top \n");
printf("Press 4 to Display Stack \n");
printf("Press 8 Exit \n");
printf("Enter your choice : \n");
scanf("%u",&choice);

switch(choice)
{

case 1 : push();
         break;

case 2 : pop();
         break;

case 3 : peek();
         break;

case 4 : display();
         break;

}

}

return 0;
}


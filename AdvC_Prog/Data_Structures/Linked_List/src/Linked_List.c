/*
 ============================================================================
 Name        : Linked_List.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t display();

struct Node{
     struct Node *next;
     struct Node *prev;
     uint8_t data;
};

typedef struct Node Node_t;

Node_t *head;
Node_t *tail;

void insertNodeStart(uint8_t value){
	Node_t *new_head = (Node_t*)malloc( sizeof(Node_t) ) ;
	if(){

	}

}

int main(void) {
uint8_t input;
uint8_t value;
input = display();

switch(input)

{
case 1 : printf ("Enter Value : %i ",value);
	     insertNodeStart(value);
	     break;

case 2 : break;
}
	return EXIT_SUCCESS;
}


uint8_t display()
{
	char input;
	printf("Press 1 To Inset Node At Begining \n");
	printf("Press 2 To Insert Node At End \n");
	scanf("%c",&input);
    return input;
}

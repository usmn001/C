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

void insertNodePos(uint8_t pos,uint8_t value);
void insertNodeStart(uint8_t value);
void DeleteNodePos(uint8_t pos);
void UpdateNodeValue(uint8_t value,uint8_t loc);
void SearchValue(uint8_t value);
void displayList();
void display();

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
	Node_t *temp;
	if(head!=NULL && new_head!=NULL){
		temp = head;
        new_head->next = head;
        new_head->data= value;
        temp->prev = new_head;
		head = new_head;
	}
	else if(head==NULL){
		head = new_head;
		head->data=value;
		head->prev=NULL;
		head->next=NULL;
	}

}

void insertNodeEnd(uint8_t value)
{
	Node_t *new_node = (Node_t*)malloc( sizeof(Node_t) ) ;
	Node_t *temp;
	temp = head;
	if(head!=NULL && new_node!=NULL)
	{

		if(head->next!=NULL)
		{
            while(temp->next!=NULL)
		 	{
			temp=temp->next;
			}
		    tail = temp;
            new_node->next=NULL;
            new_node->data=value;
            new_node->prev=tail;
            tail->next=new_node;
            tail = new_node;
		}
		else if(head->next==NULL)
        {
            tail = head;
            new_node->next=NULL;
            new_node->data=value;
            new_node->prev=tail;
            tail->next=new_node;
            tail = new_node;
		}
	}

}


void insertNodePos(uint8_t pos,uint8_t value)
{
	Node_t *new_node = (Node_t*)malloc(sizeof(Node_t));
	if(head!=NULL && new_node!=NULL)
	{
		Node_t *temp = head;
		for(uint8_t index=1;index<=pos;index++)
		{
		temp = temp->next;
		}

		new_node->data=value;
		new_node->next = temp;
		new_node->prev=temp->prev;
		temp->prev->next=new_node;
		temp->prev=new_node;
	}

}


void DeleteNodePos(uint8_t pos)
{
uint8_t index;
	if(head!=NULL)
	{
		Node_t *temp = head;
		for(index=0;index<pos-1;index++)
		{
		temp = temp->next;
		}
		temp->prev->next=temp->next;
		if(temp->next!=NULL)
		{
		temp->next->prev=temp->prev;
		}
		free(temp);
	}

}



void UpdateNodeValue(uint8_t value,uint8_t loc)
{
uint8_t index;
	if(head!=NULL)
	{
		Node_t *temp = head;
		for(index=0;index<loc-1;index++)
		{
		temp = temp->next;
		}
		temp->data=value;
	}

}

void SearchValue(uint8_t value)
{
    Node_t *temp;
    uint8_t pos=0;
    uint8_t flag=0;
    temp =head;
    if(head!=NULL)
        {
        for(temp=head;temp!=NULL;temp=temp->next)
        {
        if(temp->data==value)
        {
        flag=1;
        pos+=1;
        }

        }
        }
if(pos==0)
    {
    printf("Entered Value is not found in the list\n");
    }
else
	printf("Entered Value is found at Position %i in the list \n",pos);

}

void displayList()
{
    Node_t *temp;
    if(head!=NULL)
    {
      for(temp=head;temp!=NULL;temp=temp->next)
        {
        printf("%i  ",temp->data);
        }
    }
}

int main(void)
{


while(1)
	{

   unsigned int input = 0;
   unsigned int value = 0;
   unsigned int pos = 0;
   display();
   scanf("%u",&input);
   switch(input)
		{


	 	case 1 : printf ("Enter Value : ");
				 scanf("%u",&value);
				 insertNodeStart(value);
				 break;

		case 2 : printf ("Enter Value : ");
		         scanf("%u",&value);
		         insertNodeEnd(value);
		         break;


		case 3 :
			     printf ("Enter Value : ");
                 scanf("%u",&value);
		     	 printf("Entered Value = %i \n",value );
		     	 printf ("\nEnter Position : ");
		     	 scanf("%u",&pos);
		     	 insertNodePos(pos,value);
		     	 break;

		case 4 : printf("Enter The Position To Delete : ");
		         scanf("%u",&pos);
		    	 DeleteNodePos(pos);
                 break;

        case 5 : printf("Enter The Position To Update : ");
                 scanf("%u",&pos);
                 printf("\nEnter The New Value :");
                 scanf("%u",&value);
                 UpdateNodeValue(value,pos);
                 break;

        case 6 : printf("Enter the value to search : ");
                 scanf("%u",&value);
                 SearchValue(value);
                 break;

		case 7:  displayList();
		         break;

		case 8 : printf("Exiting\n");
		         fflush(stdout);
			     return 0;
       	}

	}

return EXIT_SUCCESS;
}


void display()
{
printf("\nPress 1 To Insert Node At Beginning \n");
printf("Press 2 To Insert Node At End \n");
printf("Press 3 To Insert Node At Position \n");
printf("Press 4 To Delete Node At Position \n");
printf("Press 5 To Update Node Value \n");
printf("Press 6 To Search Element In The Linked List \n");
printf("Press 7 To Display Linked List \n");
printf("Press 8 Exit \n");
printf("Enter your choice : \n");
}

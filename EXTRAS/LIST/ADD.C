/*
	PROGRAM TO ADD & DISPLAY NODES
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list_node *list_ptr;
typedef struct list_node
{
	int data;
	list_ptr link;
};

list_ptr ptr=NULL;
void add_el(list_ptr *,int);
void disp_el(list_ptr *);
main()
{
	int choice,item;
	do
	{
		printf( "Enter ur choice\n" );
		printf( "1->ADD NEW NODE\n" );
		printf( "2->DISPLAY NODE\n" );
		printf( "3->EXIT\n" );
		scanf( "%d",&choice );

		switch(choice)
		{
			case 1:
					printf( "Enter the data u want to insert\n" );
					scanf( "%d",&item );
					add_el(&ptr,item);
					break;

			case 2: printf( "Entered elements are : \n" );
					disp_el(&ptr);
					break;

			case 3: exit(0);
					break;
		}
	}while(choice!=3);
getch();
}

void add_el(list_ptr *ptr,int item)
{
	list_ptr temp;
	temp=(list_ptr)malloc(sizeof(struct list_node));
	temp->data=item;
	if(*ptr!=NULL)
	{
		temp->link=*ptr;
		*ptr=temp;
		printf( "ONE NODE ADDED\n" );
	}
	else
	{
		temp->link=NULL;
		*ptr=temp;
		printf( "THIS IS FIRST NODE\n" );
	}
}

void disp_el(list_ptr *ptr)
{
	list_ptr t;
	if(*ptr==NULL)
		printf( "EMPTY\n" );
	for(t=*ptr;t!=NULL;t=t->link)
	{
		printf( "%d",t->data );
	}
}
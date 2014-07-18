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

void add(list_ptr *);
void del(list_ptr *);
void display(list_ptr *);

void main()
{
	int ch;
	clrscr();

	do
	{
		clrscr();

		printf("\n\t 1... Add ");
		printf("\n\t 2... Del ");
		printf("\n\t 3... Display ");
		printf("\n\t 99... exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				add(&ptr);
				break;
			case 2:
				del(&ptr);
				break;
			case 3:
				display(&ptr);
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

void add(list_ptr *ptr)
{
	list_ptr t,temp;
	int n;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	printf("\n Enter New Data :");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;

		printf("\n Data Added For First Time ");
	}
	else
	{
		for(t=*ptr;t->link!=NULL;t=t->link);
		t->link=temp;
		temp->link=NULL;

		printf("\n Added....");
	}
}

void del(list_ptr *ptr)
{
	list_ptr t,prev;

	if(*ptr==NULL)
	{
		printf("\n The Queue Is Empty....");
	}
	else
	{
		t=*ptr;
		printf("\n The Deleted Item Is : %d",t->data);
		*ptr=(*ptr)->link;
	}
}

void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n The Queue Is empty...");
	}
	else
	{
		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}









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

void push(list_ptr *);
void pop(list_ptr *);
void display(list_ptr *);


void main()
{
	int ch;
	clrscr();

	do
	{
		clrscr();

		printf("\n\t 1... Push ");
		printf("\n\t 2... Pop ");
		printf("\n\t 3... Display ");
		printf("\n\t 99 ... Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				push(&ptr);
				break;
			case 2:
				pop(&ptr);
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

void push(list_ptr *ptr)
{
	list_ptr temp,t;
	int n;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	printf("\n Enter New Data :");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;

		printf("\n Data Added First Time.... ");
	}
	else
	{
		for(t=*ptr;t->link!=NULL;t=t->link);
		t->link=temp;
		temp->link=NULL;
		printf("\n Added.....");
	}
}

void pop(list_ptr *ptr)
{
	list_ptr t,prev;
	int i;

	if(*ptr==NULL)
	{
		printf("\n The Stack Is Empty ");
	}
	else
	{
		for(t=*ptr,i=1;t->link!=NULL;prev=t,i++,t=t->link);

		prev->link=NULL;
		if(i==1)
		*ptr=NULL;
		printf("\n Deleted Data Is : %d",t->data);

	}
}

void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n The Stack Is Empty..........");
	}
	else
	{
		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}










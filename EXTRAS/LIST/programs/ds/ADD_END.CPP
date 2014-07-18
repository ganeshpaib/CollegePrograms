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

void create(list_ptr *,int);
void display(list_ptr *);

void main()
{
	int n,ch;
	do
	{
		clrscr();
		printf("\n\t 1... Add_End ");
		printf("\n\t 2... Display ");
		printf("\n\t 3... Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					printf("\n Enter Element :");
					scanf("%d",&n);
					create(&ptr,n);
					break;
			case 2:
					display(&ptr);
					break;
			case 3:
					exit(0);
					break;
		}
		getch();
	}while(ch!=3);
getch();
}

void create(list_ptr *ptr,int n)
{
	list_ptr temp,t;
	temp=(list_ptr)malloc(sizeof(list_node));
	temp->data=n;

	if(*ptr!=NULL)
	{
		for(t=*ptr;t->link!=NULL;t=t->link);
		temp->link=NULL;
		t->link=temp;
		*ptr=t;

		printf("\n One Node Added ");
	}
	else
	{
		temp->link=NULL;
		*ptr=temp;
		printf("\n First Node Created ");
	}
}

void display(list_ptr *ptr)
{
	list_ptr temp;

	if(*ptr==NULL)
	{
		printf("\n No Node Found..... ");
	}

	for(temp=*ptr;temp!=NULL;temp=temp->link)
	{
		printf("%5d",temp->data);
	}
}











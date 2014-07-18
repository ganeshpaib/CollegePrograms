#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list_node *list_ptr;
typedef struct list_node
{
	list_ptr llink;
	int data;
	list_ptr rlink;
};

list_ptr head,ptr=NULL;

head=(list_ptr)malloc(sizeof(list_node));

head->llink=head;
head->rlink=head;

void insert(list_ptr *);

void main()
{
	int ch;
	clrscr();

	do
	{
		clrscr();
		printf("\n\t 1... Insert ");
		printf("\n\t 2... Delete ");
		printf("\n\t 99.. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					insert(&ptr);
					break;
			/*case 2:
					del(&ptr);
					break;*/
			case 99:
					exit(0);
					break;
		}
		getch();
	}while(ch!=99);

getch();
}

void insert(list_ptr *head)
{
	list_ptr temp,t;
	int n;

	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter New Data :");
	scanf("%d",&n);

	temp->data=n;

	if(*head==NULL)
	{
		(*head)->rlink=temp;
		(*head)->llink=temp;
		temp->llink=*head;
		temp->rlink=*head;

		printf("\n Node Added For First Time ");
	}
	else
	{
		for(t=*head;t->rlink!=*head;t=t->rlink);

		temp->rlink=t->rlink;
		t->rlink=temp;
		temp->llink=t;
		temp->rlink->llink=temp;

		printf("\n Node Added.....");
	}
}



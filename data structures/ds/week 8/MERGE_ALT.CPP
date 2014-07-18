
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list_node *list_ptr;

typedef struct list_node
{
	int data;
	list_ptr link;
};
list_ptr x=NULL,y=NULL,z=NULL;

void add(list_ptr *);
void display(list_ptr *);
list_ptr merge(list_ptr ,list_ptr );
void attach(int,list_ptr *);

void main()
{
	int ch;

	clrscr();

	do
	{
		clrscr();
		printf("\n\t 1... Add List_1 ");
		printf("\n\t 2... Add List_2 ");
		printf("\n\t 3... Merge ");
		printf("\n\t 4... Display ");
		printf("\n\t 99.. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				add(&x);
				break;
			case 2:
				add(&y);
				break;
			case 3:
				z=merge(x,y);
				printf("\n List Merged...");
				break;
			case 4:
				printf("\n\n\t LIST _1 ");
				printf("\n-------------------------\n");
				display(&x);
				printf("\n\n\t LIST _2 ");
				printf("\n---------------------------\n");
				display(&y);
				printf("\n\n\t MERGE LIST ");
				printf("\n----------------------------\n");
				display(&z);

				break;
			case 99:
				   exit(0);
				   break;

		}
		getch();
	}while(ch!=99);
getch();
}

void add(list_ptr *x)
{
	list_ptr temp,t;
	int n;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	printf("\n Enter New Data :");
	scanf("%d",&n);

	temp->data=n;

	if(*x==NULL)
	{
		temp->link=NULL;
		*x=temp;

		printf("\n Node Added For First Time ");
	}
	else
	{
		for(t=*x;t->link!=NULL;t=t->link);

		temp->link=NULL;
		t->link=temp;

		printf("\n Node Added..");
	}
}

void display(list_ptr *x)
{
	list_ptr t;

	if(*x==NULL)
	{
		printf("\n The List Is Empty...");
	}
	else
	{

		for(t=*x;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}

list_ptr merge(list_ptr x,list_ptr y)
{
	list_ptr temp,rear,front;

	rear=(list_ptr)malloc(sizeof(struct list_node));
	front=rear;

	if(x==NULL)
	{
		return(y);
	}
	else if(y==NULL)
	{
		return(x);
	}
	else
	{
		while(x!=NULL && y!=NULL)
		{
			attach(x->data,&rear);
			attach(y->data,&rear);
			x=x->link;
			y=y->link;
		}

		for(;x!=NULL;x=x->link)
		{
			attach(x->data,&rear);
		}
		for(;y!=NULL;y=y->link)
		{
			attach(y->data,&rear);
		}
	}

	rear->link=NULL;
	temp=front;
	front=front->link;
	free(temp);
	return(front);
}

void attach(int n,list_ptr *ptr)
{
	list_ptr temp;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	temp->data=n;

	(*ptr)->link=temp;
	(*ptr)=temp;
}

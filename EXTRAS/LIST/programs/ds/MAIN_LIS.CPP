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

void add_beg(list_ptr *);
void add_end(list_ptr *);
void add_after(list_ptr *);
void add_before(list_ptr *);
void display(list_ptr *);

void main()
{
	int ch;

	do
	{
		clrscr();
		printf("\n\t 1... Add Beg ");
		printf("\n\t 2... Add End ");
		printf("\n\t 3... Add After ");
		printf("\n\t 4... Add Before ");
		printf("\n");
		printf("\n\t 5... Del Beg ");
		printf("\n\t 6... Del End ");
		printf("\n\t 7... Del That ");
		printf("\n\t 8... Del Ater ");
		printf("\n\t 9... Del Before ");
		printf("\n");
		printf("\n\t 10... Reverse ");
		printf("\n\t 11... Sort ");
		printf("\n");
		printf("\n\t 12... Display ");
		printf("\n");
		printf("\n\t 99... Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					add_beg(&ptr);
					break;
			case 2:
					add_end(&ptr);
					break;
			case 3:
					add_after(&ptr);
					break;
			case 4:
					add_before(&ptr);
					break;


			case 12:
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

void add_beg(list_ptr *ptr)
{
	int n;
	list_ptr temp;
	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter Node Data :");
	scanf("%d",&n);
	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;

		printf("\n Added First Node.... ");
	}
	else
	{
		temp->link=*ptr;
		*ptr=temp;

		printf("\n One Node Added In The Beginning..");
	}
}

void add_end(list_ptr *ptr)
{
	int n;
	list_ptr temp,t;
	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter Node Data :");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;

		printf("\n First Node Added....");
	}
	else
	{

		for(t=*ptr;t->link!=NULL;t=t->link);

		t->link=temp;
		temp->link=NULL;

		printf("\n One Node Added In The End...");

	}
}

void add_after(list_ptr *ptr)
{
	int n,search,f=0;
	list_ptr temp,t;

	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n New Node Data : ");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;

		printf("\n  Node Added First Time.... ");
	}
	else
	{

		printf("\n Enter Search Data :");
		scanf("%d",&search);

		for(t=*ptr;t!=NULL;t=t->link)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			temp->link=t->link;
			t->link=temp;

			printf("\n Node Added After... ");
		}
		else
		{
			printf("\n No Such Node Found....");
		}
	}
}

void add_before(list_ptr *ptr)
{
	list_ptr temp,t,prev;
	int n,search,f=0;
	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter New Node Data : ");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->data=NULL;
		*ptr=temp;

		printf("\n Node Added First Time ");
	}
	else
	{
		printf("\n Enter Search Node Data :");
		scanf("%d",&search);

		prev=*ptr;

		for(t=*ptr;t!=NULL;prev=t,t=t->link)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{

			temp->link=prev->link;
			prev->link=temp;

			printf("\n Node Added Before...");
		}
		else
		{
			printf("\n No Such Node Found.... ");
		}
	}
}







void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n No Node Found...");
	}
	else
	{
		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}







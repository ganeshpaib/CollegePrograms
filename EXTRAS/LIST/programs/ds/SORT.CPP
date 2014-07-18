#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list_node *list_ptr;

typedef struct list_node
{
	int data;
	list_ptr link;
};

void add(list_ptr *);
void display(list_ptr *);
void sort(list_ptr *);

list_ptr ptr=NULL;

void main()
{
	int ch;
	do
	{
		clrscr();
		printf("\n\t 1... Add ");
		printf("\n\t 2... Sort ");
		printf("\n\t 3... Display ");
		printf("\n\t 4... Exit " );
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					add(&ptr);
					break;
			case 2:
					sort(&ptr);
					break;
			case 3:
					display(&ptr);
					break;
			case 4:
					exit(0);
					break;
		}
		getch();
	}while(ch!=4);
getch();
}

void add(list_ptr *ptr)
{
	int n,f=0;
	list_ptr temp,t,prev;
	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter New Node Data :");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;
		printf("\n First Node Added.... ");
	}
	else
	{
		 prev=*ptr;
		 for(t=*ptr;t!=NULL;prev=t,t=t->link)
		 {
			 if(n<=t->data)
			 {
				f=1;
				break;
			 }
		 }

		 if(f==1)
		 {
			if(*ptr==t)
			{
				temp->link=*ptr;
				*ptr=temp;
				printf("\n Added In The First....");
			}
			else
			{
				temp->link=prev->link;
				prev->link=temp;

				printf("\n Added In Between.... ");
			}
		 }
		 else
		 {

			for(t=*ptr;t->link!=NULL;t=t->link);
			t->link=temp;
			temp->link=NULL;
			printf("\n Added In Last...");

		}
	}
}

void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n No Node Found..... ");
	}
	else
	{

		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}

void sort(list_ptr *ptr)
{
	list_ptr t1,t2;
	int temp;

	for(t1=*ptr;t1!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if(t1->data>t2->data)
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
		}
	}

	printf("\n Sorted.....");
}











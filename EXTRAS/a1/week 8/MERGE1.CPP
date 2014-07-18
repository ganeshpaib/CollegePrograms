#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list_node  *list_ptr;

typedef struct list_node
{
	int data;
	list_ptr link;
};

list_ptr x=NULL,y=NULL,z=NULL;

void create(list_ptr *);
void sort(list_ptr *);
void display(list_ptr *);
list_ptr merge(list_ptr *,list_ptr *);

void main()
{
	int ch;
	clrscr();

	do
	{
		clrscr();
		printf("\n\n\t  1 -> Create List 1 ");
		printf("\n\n\t  2 -> Create List 2 ");
		printf("\n\n\t  3 -> Merge Two Lists");
		printf("\n\n\t 99 -> Exit ");
		printf("\n\n\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					create(&x);
					sort(&x);
					clrscr();
					printf("\n\nLIST 1\n--------------------------------------\n\n");
					display(&x);
					break;
			case 2:
					create(&y);
					sort(&y);
					clrscr();
					printf("\n\nLIST 2\n--------------------------------------\n\n");
					display(&y);
					break;
			case 3:
					z=merge(&x,&y);
					/*sort(&z);*/
					display(&z);
					x=NULL;y=NULL;z=NULL;
					break;

			case 99:
					exit(0);
					break;
		}
	getch();
	}while(ch!=99);
getch();
}

void create(list_ptr *ptr)
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

	}
	else
	{
		for(t=*ptr;t->link!=NULL;t=t->link);
		t->link=temp;
		temp->link=NULL;

	}
}

void sort(list_ptr *ptr)
{
	list_ptr t,t1;
	int temp;

	if(*ptr==NULL)
	{
		printf("\n the List Is Empty....");
	}
	else
	{

		for(t=*ptr;t!=NULL;t=t->link)
		{
			for(t1=t->link;t1!=NULL;t1=t1->link)
			{
				if(t->data>t1->data)
				{
					temp=t->data;
					t->data=t1->data;
					t1->data=temp;
				}
			}
		}
	}
}

void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n The List Is Empty....");
	}
	else
	{
		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}

list_ptr merge(list_ptr *x,list_ptr *y)
{
	list_ptr t1,t2,prev,temp,z;

	clrscr();
	printf("\n\n\nLIST 1\n-----------------------------------------------\n\n");
	display(x);
	printf("\n\n\nLIST 2\n-----------------------------------------------\n\n");
	display(y);
	printf("\n\n\nMERGED LIST\n-----------------------------------------------\n\n");

	t2=*x;t1=*y;
	if(t2->data>=t1->data)
	{
		z=*y;
	}
	else
	{
		t1=*x;
		t2=*y;
		z=*x;
	}
	for(;t1!=NULL&&t2!=NULL;)
	{
		if(t2->data>=t1->data)
		{
			while(t2->data>=t1->data&&t1->link!=NULL)
			{
				prev=t1;
				t1=t1->link;
			}
			if(t1->link==NULL&&t2->data>=t1->data)
			{
				t1->link=t2;
				break;
			}
			else
			{
			  start:
				temp=t2->link;
				t2->link=prev->link;
				prev->link=t2;
				t2=temp;
			}
		}
		else
		{
			prev=prev->link;
			goto start;
		}
	}
	return z;
}













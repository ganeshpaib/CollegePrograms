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
int f;

void create(list_ptr *,int,int);
void display(list_ptr *);

void main()
{
	int ch,n,n1;
	do
	{
		clrscr();
		printf("\n\t 1... Add_Any ");
		printf("\n\t 2... Display ");
		printf("\n\t 3... Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					printf("\n Enter Element :");
					scanf("%d",&n);
					printf("\n Enter Element After Node Add :");
					scanf("%d",&n1);

					create(&ptr,n,n1);
					break;
			case 2:
					display(&ptr);
					break;
			case 3:
					exit(0);
		}
		getch();
	}while(ch!=3);
getch();
}

void create(list_ptr *ptr,int n,int n1)
{
	f=0;
	list_ptr temp,t;
	temp=(list_ptr)malloc(sizeof(list_node));
	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;
		printf("\n Node Added First Time ");
	}
	else
	{
		for(t=*ptr;t!=NULL;t=t->link)
		{
			if(t->data==n1)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			printf("\n No Node Found ");
		}
		else
		{
				temp->link=t->link;
				t->link=temp;
				 printf("\n Node Added ");
			}
		}
	}


void display(list_ptr *ptr)
{
	list_ptr temp;

	if(*ptr==NULL)
	{
		printf("\n No Node Found ");
	}

	for(temp=*ptr;temp!=NULL;temp=temp->link)
	{
		printf("%5d",temp->data);
	}
}






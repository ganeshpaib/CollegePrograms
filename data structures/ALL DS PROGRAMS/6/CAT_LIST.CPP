#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list_node *list_ptr;

typedef struct list_node
{
	int data;
	list_ptr link;
};


list_ptr ptr1=NULL;
list_ptr ptr2=NULL;
list_ptr ptr3=NULL;

list_ptr cate(list_ptr ,list_ptr );
void add(list_ptr *);
void display(list_ptr *);


void main()
{
	int ch;

	do
	{
		clrscr();

		printf("\n\t 1... Add List_1 ");
		printf("\n\t 2... Add List_2 ");
		printf("\n\t 3... Concatenate ");
		printf("\n\t 99... Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				add(&ptr1);
				display(&ptr1);
				break;
			case 2:
				add(&ptr2);
				display(&ptr2);
				break;
			case 3:
				ptr3=cate(ptr1,ptr2);

				if(ptr3==NULL)
				{
					printf("\n Lists Are Empty ");
				}
				else
				{
					display(&ptr3);
				}
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
	list_ptr temp,t;
	int n;
	temp=(list_ptr)malloc(sizeof(struct list_node));

	printf("\n Enter Data Node :");
	scanf("%d",&n);
	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;
		printf("\n First Node Added...");
	}
	else
	{

		for(t=*ptr;t->link!=NULL;t=t->link);

		temp->link=NULL;
		t->link=temp;

		printf("\n Node Added....");
	}
}

void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n No Node Found....");
	}
	else
	{

		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}

list_ptr cate(list_ptr ptr1,list_ptr ptr2)
{
	list_ptr t;
	if(ptr1==NULL)
	{
		return(ptr2);
	}
	else
	{
		if(ptr2!=NULL)
		{
			for(t=ptr1;t->link!=NULL;t=t->link);
			t->link=ptr2;
		}
	}
	return(ptr1);
}











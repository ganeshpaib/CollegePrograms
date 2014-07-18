/*Program to concatinate 2 singly linked list*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>


typedef struct list_node *list_ptr;

typedef struct list_node
{
	int data;
	list_ptr link;
};
list_ptr x1=NULL;
list_ptr x2=NULL;

void creat(list_ptr *ptr)
{
	list_ptr first,temp;
	int data;
	first=(list_ptr)malloc(sizeof(list_node));
	printf("\nEnter the data : ");
	scanf("%d",&data);
	first->data=data;
	if(*ptr==NULL)
		*ptr=first;
	else
	{
		for(temp=*ptr;temp->link!=NULL;temp=temp->link);
		temp->link=first;
	}
	first->link=NULL;
}

void traverse(list_ptr *ptr)
{
	list_ptr temp;
	for(temp=*ptr;temp!=NULL;temp=temp->link)
		printf("%4d",temp->data);
}


list_ptr concatenate(list_ptr ptr1,list_ptr ptr2)
{
	list_ptr temp;
	if(ptr1==NULL)
		return ptr2;
	else
	{
		if(ptr2!=NULL)
		{
			for(temp=ptr1;temp->link!=NULL;temp=temp->link);
			temp->link=ptr2;
		}
	}
	return ptr1;
}

void main()
{
	char opt;
	clrscr();
	printf("\nCreate the first list\n");
	do
	{
		creat(&x1);
		printf("\nPress 'y' to continue");
		flushall();
		scanf("%c",&opt);
	}while(opt=='y');

	printf("\nCreate the second list\n");
	do
	{
		creat(&x2);
		printf("\nPress 'y' to continue");
		flushall();
		scanf("%c",&opt);
	}while(opt=='y');
	getch();
	clrscr();
	printf("\n\nElements in list1\n\n");
	traverse(&x1);
	printf("\n\nElements in list2\n\n");
	traverse(&x2);
	printf("\n\n\n After concatination\n\n");
	x1=concatenate(x1,x2);
	traverse(&x1);
	getch();
}

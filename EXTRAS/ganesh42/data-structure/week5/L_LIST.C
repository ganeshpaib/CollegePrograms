#include<stdio.h>
#include<conio.h>

typedef struct list_node *list_ptr;
typedef struct list_node
{
	int data;
	list_ptr link;
};

list_ptr creat()
{
	list_ptr first;
	first=(list_ptr)malloc(sizeof(list_node));
	printf("\nEnter the data : ");
	scanf("%d",&data);
	first->data=data;
	first->link=NULL;
	return first;
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct queue *list_ptr;
typedef struct queue
{
int data;
list_ptr rear;
};

list_ptr ptr=NULL;

void insert_queue(list_ptr *ptr)
{
int val;
list_ptr temp,t;
temp=(list_ptr)malloc(sizeof(queue));
printf("\nenter the value to be inserted:");
scanf("%d",&val);
temp->data=val;

	if((*ptr)==NULL)
	{
		(*ptr)=temp;
		 (*ptr)->rear=NULL;
		 printf("\nThe first element is added:");
	}
	else
	{
		for(t=(*ptr);t->rear!=NULL;t=t->rear);
		t->rear=temp;
		temp->rear=NULL;
		printf("\none element is added..");
	}

}
void delete_queue(list_ptr *ptr)
{
if( (*ptr)==NULL)
	printf("\nThe queue is empty:");
else
{
printf("\nThe deleted element is %d",(*ptr)->data);
(*ptr)=(*ptr)->rear;
}

}
void display(list_ptr *ptr)
{
list_ptr t;
if((*ptr)==NULL)
	printf("\nThe stalk is empty:");
else
{
	printf("\nThe element are...");
	for(t=(*ptr);t!=NULL;t=t->rear)
	printf("%5d",t->data);
}
}
void main()
{
int opt;
do
{
clrscr();
printf("\nPress 1 for insert in queue:");
printf("\npress 2 for delete in queue:");
printf("\nPress 3 for display:");
printf("\npress 99 for exit:");
printf("\nenter the option:");
scanf("%d",&opt);
switch(opt)
{
case 1:insert_queue(&ptr);break;
case 2:delete_queue(&ptr);break;
case 3:display(&ptr);break;

}
getch();
}while(opt!=99);
getch();
}


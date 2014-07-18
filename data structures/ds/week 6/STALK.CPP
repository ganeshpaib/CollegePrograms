#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct stalk *list_ptr;
typedef struct stalk
{
int data;
list_ptr top;
};

list_ptr ptr=NULL;

void push(list_ptr *ptr)
{
int val;
list_ptr temp,t;
temp=(list_ptr)malloc(sizeof(stalk));
printf("\nenter the value to be inserted:");
scanf("%d",&val);
temp->data=val;

	if((*ptr)==NULL)
	{
		(*ptr)=temp;
		 (*ptr)->top=NULL;
		 printf("\nThe first element is added:");
	}
	else
	{
		for(t=(*ptr);t->top!=NULL;t=t->top);
		t->top=temp;
		temp->top=NULL;
		printf("\none element is added..");
	}

}
void pop(list_ptr *ptr)
{
list_ptr prev,t;
if((*ptr)==NULL )
	printf("\nThe stalk is empty:");
else if((*ptr)->top==NULL)
{
  printf("\nThe last emement is poped is ..%d",(*ptr)->data);
  (*ptr)=NULL;
}
else
{
	for(t=(*ptr),prev=t;t->top!=NULL;prev=t,t=t->top);
	printf("\nThe one element is poped is ;%d",t->data);
	prev->top=NULL;
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
	for(t=(*ptr);t!=NULL;t=t->top)
	printf("%5d",t->data);
}
}
void main()
{
int opt;
do
{
clrscr();
printf("\nPress 1 for push");
printf("\npress 2 for pop:");
printf("\nPress 3 for display:");
printf("\npress 99 for exit:");
printf("\nenter the option:");
scanf("%d",&opt);
switch(opt)
{
case 1:push(&ptr);break;
case 2:pop(&ptr);break;
case 3:display(&ptr);break;

}
getch();
}while(opt!=99);
getch();
}








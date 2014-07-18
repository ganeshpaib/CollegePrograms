/*PROGRAM TO IMPLEMENT STACK ADT USING ARRAY*/

#include<stdio.h>
#include<conio.h>
#define max_stack_size 10

typedef struct
{
	int key;
}element;

element stack[max_stack_size];
int top=-1,i;

void add(int *top,element item)
{
	if(*top>=max_stack_size-1)
		printf("\n\n\n\t\tStack is full");
	else
		stack[++(*top)]=item;
}

element rem(int *top)
{
	element item;
	if(*top<0)
	{
		printf("\n\n\n\t\tStack is empty");
		item.key=-1;
		return item;
	}
	return stack[(*top)--];
}

void display(int *top)
{
	if(*top<0)
		printf("\n\n\n\t\tStack is empty");
	else
	{
		printf("\n\n\n\t\tElements on the stack\n");
		for(i=*top;i>=0;i--)
			printf("\n\t\t\t%d",stack[i]);
	}
}


void main()
{
	int choice;
	element item;
	clrscr();
	do
	{
	getch();
	clrscr();
	printf("\n\t\t\tMENU");
	printf("\n\n1.PUSH");
	printf("\n2.POP");
	printf("\n3.DISPLAY");
	printf("\n4.EXIT");
	printf("\n\n\tEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				printf("\n\n\n\t\tEnter the element to push : ");
				scanf("%d",&item.key);
				add(&top,item);
				break;
		case 2:
				item=rem(&top);
				if(item.key!=-1)
					printf("\n\n\n\tPoped element is %d",item.key);
				break;
		case 3:
				display(&top);
				break;
		case 4:
				break;
		default:
				printf("\n\n\n\t\tInvalid option. Try again.");

	}
	}while(choice!=4);
	getch();
}


/*program to implement a stack using a linked list*/

#include<stdio.h>
#define NULL 0

typedef struct stack *stack_ptr;
typedef struct stack
{
	int data;
	stack_ptr link;
};

stack_ptr top;

void push(int item)
{
	stack_ptr temp;
	temp=(struct stack *)malloc (sizeof(struct stack));
	temp->data=item;
	temp->link=top;
	top=temp;
}

int pop()
{
	stack_ptr temp;
	int num=0;
	if(top!=NULL)
	{
	   temp=top;
	   num=temp->data;
	   top=temp->link;
	   free(temp);
	}
	else
	   printf("\n\tStack is empty\n");
	   return(num);
}


void display()
{
	stack_ptr temp;
	temp=top;
	if(temp==NULL)
	   printf("\n\tStack is empty\n");
	else
	{
	   printf("\n \tElements in the stack\n\t");
	   for(temp=top;temp!=NULL;temp=temp->link)
	   printf("%3d",temp->data);
	}
}


void main()
{
	int choice,num;
	char x;
	clrscr();
	do
	{
	   printf("\n \t1. Push\n \t2. Pop\n \t3. Display\n \t4. Exit\n");
	   printf("\n\tEnter your Choice\n\t");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	       case 1:
		       printf("\tEnter the number\n\t");
		       scanf("%d",&num);
		       push(num);
		       break;
	       case 2:
		       num=pop();
		       if(num!=0)
		       printf("\n\t%d is deleted",num);
		       break;
	       case 3:
			display();
			break;
	       case 4:
			exit(0);
	   }
     printf("\n \tPress y to continue\n\t");
     scanf(" %c",&x);
     }while(x=='y');
getch();
}





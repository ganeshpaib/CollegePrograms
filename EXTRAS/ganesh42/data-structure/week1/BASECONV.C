/*PROGRAM TO CONVERT A DECIMAL NUMBER TO ANY BASE SPECIFIED*/

#include<stdio.h>
#define max_stack_size 16

int stack[max_stack_size];
int top=-1;


void push(int n)
{
    if(top>=(max_stack_size-1))
	printf("\n\n\n\t\t\tStack is full\n");
    else
	stack[++top]=n;
}

int pop()
{
    if(top==-1)
	 printf("\n\n\n\t\t\tStack is empty\n");
    else
	 return stack[top--];
}

void main()
{
      int i,num,item,rem,base;
      char ch;
      clrscr();
      do
      {
	printf("\n\n\n\t\t\tEnter the number\n\t\t\t");
	scanf("%d",&num);
	printf("\n\n\n\t\t\tEnter the base to which you want to convert the number\n\t\t\t");
	scanf("%d",&base);
	while(num!=0)
	{
	   rem=num%base;
	   push(rem);
	   num=num/base;
	}
	printf("\n\n\n\t\t\tThe base %d equivalent is : ",base);

	for(i=top;i>=0;i--)
	{
	     item=pop();
	     if(item>9)
		printf("%c",item+55);
	     else
		printf("%d",item);
	}

  printf("\n\n\n\n\t\t\t Press y to contiue\n\t\t\t");
  scanf(" %c",&ch);
  getch();
  clrscr();
 }while(ch=='y');
 getch();
}



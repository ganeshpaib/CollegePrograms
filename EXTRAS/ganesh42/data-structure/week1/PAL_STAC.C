/*PROGRAM TO CHECK WHETHER THE STRING IS PALINDROME OR NOT USING STACKS*/

#include<stdio.h>
#include<string.h>
#define max_stack_size 25

char stack[max_stack_size];
int top=-1;

void push(char c)
{
	if(top>=(max_stack_size-1))
		printf("Stack is full\n");
	else
		stack[++top]=c;
}

char pop()
{
	if(top==-1)
		  printf("stack is empty\n");
	else
	   return stack[top--];
}

void main()
{
      char str[25],item;
      int i,n;
      clrscr();
      printf("\nEnter the string\n");
      scanf("%[^\n]",str);
      n=strlen(str);
      for(i=0;i<n;i++)
	  push(str[i]);
      for(i=0;i<n;i++)
      {
	   if(str[i]!=pop())
		break;
      }
	      if(i==n)
		printf("String is a palindrome\n");
	      else
		printf("String is not a palindrome\n");
      getch();
}


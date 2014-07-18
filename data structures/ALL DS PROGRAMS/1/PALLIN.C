#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
	char key;
}element;

element stack[MAX];
int top=-1;

void push(int *,char);
char pop(int *);

void main()
{
	char str[20];
	int i,f=0;

	clrscr();

	printf("\n Enter String :");
	flushall();
	gets(str);

	for(i=0;str[i]!='\0';i++)
	{
		push(&top,str[i]);
	}

	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==pop(&top))
		{
			f=1;
		}
		else
		{
			f=0;
			break;
		}
	}

	if(f==1)
	{
		printf("\n String Is A Pallindrome ");
	}
	else
	{
		printf("\n String Is Not A Pallindrome ");
	}
getch();
}

void push(int *top,char c)
{
	if(*top==MAX-1)
	{
		printf("\n The Stack Is Full ");
	}
	else
	{
		stack[++(*top)].key=c;
	}
}

char pop(int *top)
{
	if(*top==-1)
	{
		return(-1);
	}
	else
	{
		return(stack[(*top)--].key);
	}
}



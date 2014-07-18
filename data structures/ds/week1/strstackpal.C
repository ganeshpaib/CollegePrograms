#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 25

char stk[MAX];
int top=-1;

void push(int *top,char ch)
{
   if(*top==MAX-1)
	printf("\nthe stalk is full");
   else
	stk[++(*top)]=ch;
}
char pop(int *top )
{

	if(*top==-1)
	{
		printf("\nthe stalk is empty:");
		return('l');
	}
	else
		return(stk[(*top)--]);

}
void main()
{
	int i,c=0,f=0;
	char str[MAX];
	clrscr();
	printf("\nenter the string:");
	flushall();
	gets(str);
	for(i=0;str[i]!=NULL;i++)
	{  	c++;
		push(&top,str[i]);
	}

	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=pop(&top))
		{
			f=1;
			break;
		}
	}

	if(f==0)
	{
		printf("\n TRUE");
	}
	else
	{
		printf("\n FALSE");
	}
getch();
}



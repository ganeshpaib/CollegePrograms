#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
	int key;
}element;

element stack[MAX];
int top=-1;

void push(int *,int);
void display(int *);

void main()
{
	int num,base,r,i;
	clrscr();

	printf("\n Enter A Decimal Number :");
	scanf("%d",&num);
	printf("\n Enter The Base :");
	scanf("%d",&base);

	while(num!=0)
	{
		r=num%base;
		push(&top,r);
		num=num/base;
	}

	printf("\n The Converted Number Is : ");
	display(&top);
getch();
}

void push(int *top,int r)
{
	if(*top==MAX-1)
	{
		printf("\n The Stack Is Full ");
	}
	else
	{
		if(r>=0 && r<=9)
		{
			stack[++(*top)].key=r;
		}
		else
		{
			switch(r)
			{
				case 10:
					stack[++(*top)].key='A';
					break;
				case 11:
					stack[++(*top)].key='B';
					break;
				case 12:
					stack[++(*top)].key='C';
					break;
				case 13:
					stack[++(*top)].key='D';
					break;
				case 14:
					stack[++(*top)].key='E';
					break;
				case 15:
					stack[++(*top)].key='F';
			}
		}
	}
}

void display(int *top)
{
	int i;
	if(*top==-1)
	{
		printf("\n The Stack Is Empty ");
	}
	else
	{
		for(i=*top;i>=0;i--)
		{
			if(stack[i].key>=0 && stack[i].key<=9)
			{
				printf("%d",stack[i].key);
			}
		else
		{
			switch(stack[i].key)
			{
				case 65:
					printf("%c",stack[i].key);
					break;
				case 66:
					printf("%c",stack[i].key);
					break;
				case 67:
					printf("%c",stack[i].key);
					break;
				case 68:
					printf("%c",stack[i].key);
					break;
				case 69:
					printf("%c",stack[i].key);
					break;
				case 70:
					printf("%c",stack[i].key);
					break;
			}
		}
	}
}
}





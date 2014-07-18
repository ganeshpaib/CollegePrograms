#include<stdio.h>
#include<conio.h>
#define MAX 5

typedef struct
{
	int key;
}element;
int top=-1,item;
element s[MAX];

void push(int,int *);
int pop(int*);
void display(int *);

void main()
{
	int ch,f;
	clrscr();

	do
	{
		clrscr();
		printf("\n\t 1.. Push ");
		printf("\n\t 2.. Pop ");
		printf("\n\t 3.. Display ");
		printf("\n\t 4.. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\n Enter An Element :");
				scanf("%d",&item);

				push(item,&top);
				break;
			case 2:
				f=pop(&top);

				if(f==0)
				{
					printf("\n Stack Is Empty ");
				}
				else
				{
					printf("\n The Deleted Item Is : %d",f);
				}
				break;
			case 3:
				display(&top);
				break;
			case 4:
				exit(0);
		}
		getch();
	}while(ch!=4);
getch();
}

void push(int item,int *top)
{
	if(*top==MAX-1)
	{
		printf("\n Stack Is Full ");
	}
	else
	{
		s[++(*top)].key=item;
		printf("\n One Element Is Added ");
	}
}

int pop(int *top)
{
	if(*top==-1)
	{
		return(0);
	}
	else
	{
		return(s[(*top)--].key);
	}
}

void display(int *top)
{
	int i;

	if(*top<0)
	{
		printf("\n The Stack Is Empty ");
	}

	for(i=0;i<=*top;i++)
	{
		printf("%5d",s[i]);
	}
}



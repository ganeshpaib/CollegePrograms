#include<stdio.h>
#include<conio.h>
#define MAX 4

typedef struct
{
	int key;
}element;

int rear=0;
int front=0;
int item;

element q[MAX];

void addq(int,int*,int*);
int delq(int*,int*);
void display(int*,int*);

void main()
{
	int ch,f;

	do
	{
		clrscr();
		printf("\n\t 1... Add ");
		printf("\n\t 2... Delete ");
		printf("\n\t 3... Display ");
		printf("\n\t 4... Exit ");
		printf("\n Enter Your Choice ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\n Enter Element :");
				scanf("%d",&item);

				addq(item,&rear,&front);
				break;
			case 2:
				f=delq(&rear,&front);

				if(f==0)
				{
					printf("\n The Queue Is Empty ");
				}
				else
				{
					printf("\n The Deleted Item Is : %d",f);
				}
				break;
			   case 3:
				display(&rear,&front);
				break;
			case 4:
				exit(0);
		}
		getch();
	}while(ch!=4);
getch();
}

void addq(int item,int *rear,int *front)
{
	*rear=(*rear+1)%MAX;

	if(*rear==*front)
	{
		printf("\n The Queue Is Full ");

		if(*rear==0)
		{
			*rear=MAX-1;
		}
		else
		{
			*rear=*rear-1;
		}
	}
	else
	{
		q[*rear].key=item;
		printf("\n One Element Is Added ");
	}
}

int delq(int *rear,int *front)
{
	if(*rear==*front)
	{
		return(0);
	}
	else
	{
		*front=(*front+1)%MAX;
		return q[*front].key;
	}
}

void display(int *rear,int *front)
{
	int i;

	if(*rear==*front)
	{
		printf("\n The Queue Is Empty ");
	}
	else
	{

		if(*front<*rear)
		{
			for(i=(*front+1);i<=*rear;i++)
			{
				printf("%5d",q[i]);
			}
		}
		else if(*front>=*rear)
		{
			for(i=(*front+1);i<MAX;i++)
			{
				printf("%5d",q[i]);
			}
			for(i=0;i<=*rear;i++)
			{
				printf("%5d",q[i]);
			}
		}
	}
}









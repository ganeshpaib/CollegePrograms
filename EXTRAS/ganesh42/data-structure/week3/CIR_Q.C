#include<stdio.h>
#include<conio.h>
#define max_q_size 10

typedef struct
{
	int key;
}element;

element queue[max_q_size];
int front=0,rear=0,i;

void add(int *rear,int *front,element item)
{
	*rear=(*rear+1)%max_q_size;
	if(*rear==*front)
	{
		printf("\n\n\n\t\tQueue is full");
		if(*rear==0)
			*rear=max_q_size-1;
		else
			*rear=*rear-1;
	}

	else
		queue[*rear]=item;
}

element rem(int *rear,int *front)
{
	element item;
	if(*front==*rear)
	{
		printf("\n\n\n\t\tQueue is empty");
		item.key=-1;
		return item;
	}
	else
		*front=(*front+1)%max_q_size;
	return queue[*front];
}

void display(int *rear,int *front)
{
	if(*front==*rear)
		printf("\n\n\n\t\tQueue is empty");
	else
	{
		printf("\n\n\n\t\tElements in the queue\n");
		if(*front<*rear)
		{
			for(i=*front+1;i<=*rear;i++)
			printf("\n%d",queue[i]);
		}
		else
		{
		for(i=*front+1;i<=max_q_size-1;i++)
			 printf("\n%d",queue[i]);
		for(i=0;i<=*rear;i++)
		printf("\n%d",queue[i]);
		}
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
	printf("\n\n1.INSERT");
	printf("\n2.DELETE");
	printf("\n3.DISPLAY");
	printf("\n4.EXIT");
	printf("\n\n\tEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				printf("\n\n\n\t\tEnter the element to insert : ");
				scanf("%d",&item.key);
				add(&rear,&front,item);
				break;
		case 2:
				item=rem(&rear,&front);
				if(item.key!=-1)
					printf("\n\n\n\tDeleted element is %d",item.key);
				break;
		case 3:
				display(&rear,&front);
				break;
		case 4:
				break;
		default:
				printf("\n\n\n\t\tInvalid option. Try again.");

	}
	}while(choice!=4);
	getch();
}


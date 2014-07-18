#include<stdio.h>
#include<conio.h>

typedef struct
{
	int val;
}element;

element cq[4];
int rear=0;
int front=0;
void add_cq(int *,int *,int);
int del_cq(int *,int *);
main()
{
	int ch,item,i,num;
	clrscr();

	do
	{
		printf( "\n\n\n1->ADD\n" );
		printf( "2->DISPLAY\n" );
		printf( "3->DELETE\n" );
		printf( "4->EXIT\n" );
		scanf( "%d",&ch);

		switch(ch)
		{
			case 1: printf( "Enter the element\n" );
					scanf( "%d",&item );

					add_cq(&front,&rear,item);
					break;

			case 2: printf( "Entered elements are :\n" );
					if(front<rear)
					{
						for( i=front+1;i<=rear;i++ )
						{
							printf( "%d\t",cq[i].val );
						}
					}
					else if(front>rear)
					{
						for(i=front+1;i<=3;i++)
							printf( "%d\t",cq[i].val );
						for(i=0; i<=rear;i++)
							printf( "%d\t",cq[i].val );
					}
					else
						printf( "EMPTY\n" );

					break;

			case 3:num=del_cq(&rear,&front);
					 if(num==0)
						printf( "EMPTY\n" );
					 else
						printf( "Element %d deleted\n",num );

				   break;

			case 4: exit();
		}

	}while(ch!=4);
 getch();
}

void add_cq(int *front, int *rear,int item)
{
	*rear=(*rear+1)%4;
	if(*rear==*front)
	{
		printf( "CIRC QUEUE FULL\n" );
		if(*rear==0)
			*rear=3;
		else
			*rear=*rear-1;
	}

	else
	{
		cq[*rear].val=item;
	}
}

int del_cq(int *rear,int *front)
{
	int num1;

	if(*front==*rear)
	{
		printf( "EMPTY\n" );
		return 0;
	}
	else
	{
		*front = (*front+1)%4;
		num1= cq[*front].val;
		return num1;
	}
}
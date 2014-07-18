#include<stdio.h>
#include<conio.h>
#define max_term 10
typedef struct
{
	int key;
}element;
element queue[max_term],item;
int front=-1,rear=-1;
void add(int *,int *,element );

main()
{
	int choice,i;
	clrscr();
	do
	{
		printf( "PRESS 1-> ADD NEW RECORD\n" );
		printf( "PRESS 2-> DISPLAY RECORDS\n" );
		printf( "PRESS 3-> DELETE RECORD\n" );
		printf( "PRESS 4-> EXIT\n" );
		scanf( "%d",&choice );

		switch(choice)
		{
			case 1: printf( "Enter the element to be entered\n" );
					scanf( "%d",&item.key);
					add(&rear,&front,item);
					break;

			case 2: printf( "The entered elemnts are: \n" );
					if(front<rear)
					{
						for(i = front + 1; i <= rear; i++)
						printf( "%d\n",queue[i].key);
					}
					if(front > rear)
					{
						for( i = front+1; i < max_term; i++ )
							printf( "%d\n",queue[i].key );

						for( i = 0; i <= rear; i++ )
							printf( "%d\n",queue[i].key);
					}
					break;
			 case 4: exit();
			}
		}while(choice==1||choice==2||choice==3);
	getch();
}

void add(int *rear, int *front, element item)
{
	*rear=(*rear+1)%max_term;
	if(*rear==*front)
	{
		printf( "QUEUE IS FULL\n" );

		if(*rear==0)
			*rear=max_term - 1;
		else
			*rear=*rear-1;
	}
	queue[*rear]=item;
}
#include<stdio.h>
#include<conio.h>
typedef struct
{
	int val;
}element;
element q[4],ans;

void add(int *,int *,int);
element rem(int * );
int front=-1;
int rear=-1;
main()
{
   int ch,item,i;
   clrscr();
   do
   {
	printf( "\n1-> ADD\n" );
	printf( "2-> DISP\n" );
	printf( "3-> DEL\n" );
	printf( "4-> EXIT\n" );
	scanf( "%d",&ch );

	switch(ch)
	{
		case 1:printf( "Enter the elemnt\n" );
			   scanf( "%d",&item );
			   add(&rear,&front,item);
			   break;
		case 2:for(i=front+1;i<=rear;i++)
				{
					printf( "%d",q[i].val);
				}
				break;
		case 3:ans=rem(&front);
				printf( "%d deleted\n",ans );
				break;
		 case 4: exit();
	}
}while(ch!=4);
getch();
}

void add(int *rear,int *front,int item)
{
	if(*(rear)>=3)
		printf( "QUEUE FULL\n" );
	else
	{
		q[++(*rear)].val=item;
	}

}

element rem(int *front)
{
	return(q[++(*front)]);
}

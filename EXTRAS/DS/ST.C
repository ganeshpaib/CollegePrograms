#include<stdio.h>
#include<conio.h>
#define max_size 4
typedef struct stack1
{
	int val;
}a;
a stack[max_size];
int top=-1;

void add(int *, int );
main()
{
	int choice,item,i;
	clrscr();
	do
	{
		printf( "Enter ur choice!!!!!\n" );
		printf( "1 -> INSERT ELEMENTS\n" );
		printf( "2 -> DELETE ELEMENTS\n" );
		printf( "3 -> DISPLAY ELEMNTS\n" );
		printf( "4 -> DISPLAY ELEMNTS\n" );
		printf( "5 -> EXIT\n" );
		scanf( "%d",&choice );

		switch(choice)
		{
			case 1: printf( "Enter the element\n" );
					scanf( "%d",&item );

					add(&top,item);
					break;

			case 4:for(i = 1; i <= top; i++ )
				   {
						printf( "%d\t",stack[i].val );
				   }
				   break;

			case 5:exit();


		}
	}while(choice!=5);
 getch();
}

void add(int *top, int item)
{
	if(stack[++(*top)].val >= max_size )
		printf( "STACK FULL\n" );
	else
	{
		stack[++(*top)].val=item;
		printf( "ELEMNT %d INSERTED\n",item );
	}
}
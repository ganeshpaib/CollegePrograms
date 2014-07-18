#include<stdio.h>
#include<conio.h>
#define max_size 4

typedef struct
{
	int val;
}element;
void add_el(int *,int);
element del_el(int *);
element stack[max_size],elem,ans;
int top=-1;
main()
{
	int ch,i,item;
	clrscr();
	do
	{
	printf( "1-> ADD ELEMENT\n" );
	printf( "2-> DISPLAY ELEMENTS\n" );
	printf( "3-> DELETE\n" );
	printf( "4-> EXIT\n");
	scanf( "%d",&ch );

		switch(ch)
		{
			case 1: printf( "Enter element\n" );
					scanf( "%d",&item );

					add_el(&top,item);
					break;

			case 2: for(i = top; i >= 0; i-- )
					{
						printf( "%d\t",stack[i].val );
					}
					break;

			case 3: elem=del_el(&top);
					printf( "deleted elemnt is %d\n",elem );
					break;

			case 4: exit();
		}
	}while(ch!=4);
getch();
}

void add_el(int *top, int item )
{

	if((*top)>=max_size-1)
		printf( "STACK FULL\n" );
	else
		stack[++(*top)].val=item;
}

element del_el( int *top)
{

	if(*top<0)
		printf( "STACK EMPTY\n" );
	else
	{
	  return (stack[(*top)--]);

	  }
}

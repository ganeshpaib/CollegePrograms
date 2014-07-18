#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_TERM 10


typedef enum
{
	lpara,rpara,plus,minus,times,divide,mod,operand,eos
}precedence;

int stack[MAX_TERM],n,top=-1,size,ctr=0;
char *expr,symbol;
precedence token;

int evaluation();
void push(int *,int);
int pop(int *);
precedence get_token(char *,int *);


void main()
{
	int i,x;

	clrscr();

	printf( "\n Enter the size of the expression :" );
	scanf( "%d",&size );

	expr=(char *) malloc(sizeof(char) * size);

	printf("\n Enter the postfix expression which is to be evaluated \n");

	for( i = 0; i < size; i++)
	{
		printf( " expr[%d] :",i );
		flushall();
		scanf( "%c",&expr[i]);
	}

	x=evaluation();

	printf( "\n The Result Is : %d",x);
getch();
}
int evaluation()
{
	int op1,op2;
	token=get_token(&symbol,&ctr);

	while(token!=eos)
	{
		if( token==operand )
		{
			push(&top,symbol-'0');
		}
		else
		{
			op2=pop(&top);
			op1=pop(&top);

			switch(token)
			{
				case plus :
						push(&top,op1+op2);
						break;
				case minus :
						push(&top,op1-op2);
						break;
				case divide :
						push(&top,op1/op2);
						break;
				case mod :
						push(&top,op1%op2);
						break;
				case times :
						push(&top,op1*op2);
						break;
			}
		}
		token=get_token(&symbol,&ctr);
	}
	return(pop(&top));
}


void push(int *top,int element)
{
	if(*top==MAX_TERM - 1)
	{
		printf( "\nStack Full" );
	}
	else
	{
		stack[++(*top)]=element;
	}
}

int pop(int *top)
{
	if(*top==-1)
	{
		printf( "\nStack Empty" );
		return(-1);
	}
	else
	{
		return(stack[(*top)--]);
	}
}

precedence get_token(char *symbol,int *ctr)
{
	*symbol=expr[(*ctr)++];

	switch(*symbol)
	{
		case '(' : return lpara;
		case ')' : return rpara;
		case '+' : return plus;
		case '-' : return minus;
		case '/' : return divide;
		case '*' : return times;
		case '%' : return mod;
		case '\n': return eos;
		default  : return operand;
	}
}









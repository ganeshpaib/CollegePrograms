#include<stdio.h>
#include<conio.h>

typedef enum{ lpara,rpara,plus,minus,times,divide,mod,operand,eos}precedence;

int top=0;
precedence token;
char symbol;
int n=0;
main()
{
	int size,i;
	char expr[10];
	printf( "Enter the size of the expression\n" );
	scanf( "%d",&size );
	for(i=0;i<size;i++)
	{
		printf( "expr[%d]= ",i );
		flushall();
		scanf( "%c",&expr[i]);
	}
	postfix();
	getch();
}

void postfix()
{

	for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n))
	{
		if(token==operand)
			printf( "%c",token );

		else if(token==rpara)
		{
			while(token!=lpara)
			{
				print_token(pop(&top));
			}
			pop(&top);
		}
		else
		{

			while(isp[stack[top]]>=icp[stack[top]])
			{
				print_token(pop(&top));
			}
			push(&top,token);
		}
	}

	while(token=pop(&top))!=eos)
		print_token(token);
}

precedence get_token(char *symbol,int *n)
{
	*symbol=expr[*n++];
	switch(*symbol)
	{
		case '+':return plus;
		case '-':return minus;
		case '(':return lpara;
		case ')':return rpara;
		case '*':return times;
		case '/':return divide;
		case '%':return mod;
		default: return operand;
	}
}

void print_token(precedence token)
{
	switch(token)
	{
		case plus:printf("+");
				  break;
		case minus:printf( "-");
				   break;
		case times:printf( "*" );
				   break;
		case divide:printf( "/" );
					break;
	}
}
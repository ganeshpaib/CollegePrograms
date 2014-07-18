#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 15

typedef enum{lpara,rpara,plus,minus,times,divide,mod,operand,eos} precedence;
static isp[]={0,19,12,12,13,13,13,0,0};
static icp[]={20,19,12,12,13,13,13,0,0};
precedence stack[MAX];
char expr[MAX];

void eval(void);
precedence pop(int *);
void push(int *,precedence);
precedence get_token(char *,int *);
void print_token(precedence);


void main()
{
	clrscr();
	printf("\n Enter An Infix Expression :");
	flushall();
	gets(expr);

	eval();
getch();
}

void eval()
{
	int top=0,n=0;
	char symbol;
	precedence token;
	stack[0]=eos;

	for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n))
	{
		if(token==operand)
		{
			printf("%c",symbol);
		}
		else if(token==rpara)
		{
			while(stack[top]!=lpara)
			{
				print_token(pop(&top));
			}
			pop(&top);

		}
		else
		{
			while(isp[stack[top]]>=icp[token])
			{
				print_token(pop(&top));
			}
			push(&top,token);
		}
	}

	while((token=pop(&top))!=eos)
	{
		print_token(token);
	}
}

precedence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)++];

	switch(*symbol)
	{
		case'(':return lpara;
		case')':return rpara;
		case'+':return plus;
		case'-':return minus;
		case'*':return times;
		case'/':return divide;
		case'%':return mod;
		case'\0':return eos;
		default : return operand;
	}
}

void print_token(precedence token)
{
	switch(token)
	{
		case lpara:
			printf("(");
			break;
		case rpara:
			printf(")");
			break;
		case plus:
			printf("+");
			break;
		case minus:
			printf("-");
			break;
		case times:
			printf("*");
			break;
		case divide:
			printf("/");
			break;
		case mod:
			printf("%");
			break;
	}
}

void push(int *top,precedence token)
{
	if((*top)==MAX-1)
	{
		printf("\n The Stack Is Full ");
	}
	else
	{
		stack[++(*top)]=token;
	}
}

precedence pop(int *top)
{
	if((*top)==-1)
	{
		printf("\n The Stack Is Empty ");
		return(-1);
	}
	else
	{
		return(stack[(*top)--]);
	}
}








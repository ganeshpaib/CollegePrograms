#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 15

typedef enum{lpara,rpara,plus,minus,times,divide,mod,operand,eos} precedence;
static isp[]={19,0,12,12,13,13,13,0,0};
static icp[]={19,20,12,12,13,13,13,0,0};
precedence stack[MAX];
char expr[MAX],expr1[MAX];
int i=0;

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
	strrev(expr);

	eval();

	expr1[i]='\0';

	printf("%s",strrev(expr1));
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
			expr1[i++]=symbol;
		}
		else if(token==lpara)
		{
			while(stack[top]!=rpara)
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
			expr1[i++]='(';
			break;
		case rpara:
			expr1[i++]=')';
			break;
		case plus:
			expr1[i++]='+';
			break;
		case minus:
			expr1[i++]='-';
			break;
		case times:
			expr1[i++]='*';
			break;
		case divide:
			expr1[i++]='/';
			break;
		case mod:
			expr1[i++]='%';
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

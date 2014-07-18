#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15


typedef enum{lpara,rpara,plus,minus,times,divide,mod,operand,eos} precedence;

int stack[MAX],n,top=-1,n1,ctr=0;
char expr[15],symbol;
precedence token;

int eval();
void push(int *,int);
int pop(int *);
precedence get_token(char *,int *);


void main()
{
	int i,x;

	clrscr();

	printf("\n Enter The Prefix Expression For Evalution \n ");
	flushall();
	gets(expr);
	strrev(expr);
	x=eval();

	printf("\n The Result Is : %d",x);
getch();
}
int eval()
{
	int op1,op2;
	token=get_token(&symbol,&ctr);

	while(token!=eos)
	{
		if(token==operand)
		{
			push(&top,symbol-'0');
		}
		else
		{
			op1=pop(&top);
			op2=pop(&top);

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
	if(*top==MAX-1)
	{
		printf("\n The Stack Is Full ");
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
		printf("\n Stack Empty ");
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
		case'(': return lpara;
		case')':return rpara;
		case'+':return plus;
		case'-':return minus;
		case'/':return divide;
		case'*':return times;
		case'%':return mod;
		case'\0':return eos;
		default: return operand;
	}
}

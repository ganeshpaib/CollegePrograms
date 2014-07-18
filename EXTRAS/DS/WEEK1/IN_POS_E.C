#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

typedef enum{lpara,rpara,plus,minus,times,divide,operand,eos}precedence;
char *expr;
int s[MAX],top=-1,i,n;
precedence token;
char symbol;

int eval();
void push(int *,int);
int pop(int *);
precedence get_token(char *,int *);

void main()
{
	int n,x;
	clrscr();

	printf("\n Expr Size :");
	scanf("%d",&n);

	expr=(char *)malloc(sizeof(char)*n);

	for(i=0;i<n;i++)
	{
		printf("Expr[%d] :",i+1);
		flushall();
		scanf("%c",&expr[i]);
	}

	x=eval();

	printf("\n The Result Is  : %d",x);
getch();
}

int eval()
{
	int op1,op2;

	token=get_token(&symbol,&n);

	while(token!=eos)
	{
		if(token==operand)
		{
			push(&top,symbol-'0');
		}
		else
		{
			op2=pop(&top);
			op1=pop(&top);

			switch(token)
			{
				case plus:
							push(&top,op1+op2);
							break;
				case minus:
							push(&top,op1-op2);
							break;
				case times:
							push(&top,op1*op2);
							break;
				case divide:
							push(&top,op1/op2);
							break;
			}
		}
		token=get_token(&symbol,&n);
	}
	return pop(&top);
}

precedence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)++];

	switch(*symbol)
	{
		case '(':return lpara;
		case ')':return rpara;
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '\n':return eos;
		default : return operand;
	}
}

void push(int *top,int item)
{
	if(*top==MAX-1)
	{
		printf("\n The Stack Is Full ");
	}
	else
	{
		s[++(*top)]=item;
	}
}

int pop(int *top)
{
	if(*top==-1)
	{
		printf("\n The Stack Is Empty");
		return(0);
	}
	else
	{
		return s[(*top)--];
	}
}











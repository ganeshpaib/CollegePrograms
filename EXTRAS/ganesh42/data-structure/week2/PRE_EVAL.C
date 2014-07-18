#include<stdio.h>
#include<conio.h>
#define max_stack_size 10
#define max_expr_size 10

typedef enum{lparen,rparen,plus,minus,times,divide,mod,operand,eos}precedence;

int stack[max_stack_size];
char expr[max_expr_size];
int len;

void push(int *top,int item)
{
	stack[++(*top)]=item;
}
int pop(int *top)
{
	return stack[(*top)--];
}


precedence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)--];
	switch(*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return times;
		case '/': return divide;
		case '%': return mod;
		case '\0': return eos;
		default : return operand;
	}
}

int eval(void)
{
	precedence token;
	int op1,op2;
	char symbol;
	int n=len-1;
	int top=-1;

	token=get_token(&symbol,&n);
	while(n>=-1)
	{
		if(token==operand)
			push(&top,symbol-'0');
		else
		{
		op1=pop(&top);
		op2=pop(&top);
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
		    case mod:
				push(&top,op1%op2);
		}
		}
	token=get_token(&symbol,&n);
	}
	return pop(&top);
}

void main()
{
	int res;
	clrscr();
	printf("\n\n\n\t\t\tEnter the expression : ");
	scanf("%s",&expr);
	for(len=0;expr[len]!='\0';len++);

	res=eval();
	printf("\n\n\n\t\t\tResult = %d",res);
	getch();
}
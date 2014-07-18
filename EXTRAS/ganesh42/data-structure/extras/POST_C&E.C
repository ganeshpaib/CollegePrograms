#include<stdio.h>
#include<conio.h>
#define max_stack_size 10
#define max_expr_size 10

typedef enum{lparen,rparen,plus,minus,times,divide,mod,operand,eos}precedence;

int stack[max_stack_size];
char expr[max_expr_size];


void push(int *top,int item)
{
	stack[++(*top)]=item;
}


precedence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
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

precedence pop(int *top)
{

	return stack[(*top)--];
}

void printtoken(int token)
{
	switch(token)
	{
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
	}
}



int isp(char *symbol)
{
	switch(*symbol)
	{
		case '(': return 0;
		case '+': return 2;
		case '-': return 3;
		case '*': return 4;
		case '/': return 5;
		case '%': return 6;
		case '\0': return 7;
	}
}


/*
int eval(void)
{
	precedence token;
	int op1,op2;
	char symbol;
	int n=0;
	int top=-1;
	token=get_token(&symbol,&n);
	while(token!=eos)
	{
		if(token==operand)
			push(&top,symbol-'0');
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
		    case mod:
				push(&top,op1%op2);
		}
		}
	token=get_token(&symbol,&n);
	}
	return pop(&top);
} */


void postfix(void)
{
	char symbol;
	precedence token;
	int n=0;
	int top=0;
	stack[0]=eos;
	for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n))
	{
		if(token==operand)
			printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				printtoken(pop(&top));
		}
		else
		{


			if (isp(&stack[top])>=isp(&token))
				printtoken(pop(&top));
			push(&top,token);
		}
	}
	while((token=pop(&top))!=eos)
		printtoken(token);
}


void main()
{
	int i,res;
	clrscr();
	printf("\n\n\n\t\t\tEnter the expression : ");
	scanf("%s",&expr);
	postfix();
  /*	res=eval();
	printf("\n\n\n\t\t\tResult = %d",res);    */
	getch();
}
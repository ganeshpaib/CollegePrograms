#include<stdio.h>
#include<conio.h>
#define max_stack_size 10
#define max_expr_size 10

typedef enum{lparen,rparen,plus,minus,times,divide,mod,operand,eos}precedence;

precedence stack[max_stack_size];
static int isp[]={0,19,12,12,13,13,13,0,0};
static int icp[]={20,19,12,12,13,13,13,0,0};
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
				print_token(pop(&top));
		}
		else
		{
			if (isp[stack[top]]>=icp[token])
				print_token(pop(&top));
			push(&top,token);
		}
	}
	while((token=pop(&top))!=eos)
		printtoken(token);
}

void printtoken(precedence token)
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



void main()
{
	int i,res;
	clrscr();
	printf("\n\n\n\t\t\tEnter the expression : ");
	scanf("%s",&expr);
	postfix();
	getch();
}
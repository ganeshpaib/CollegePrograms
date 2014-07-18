#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max_stack_size 20
#define max_expr_size 20

typedef enum{lparen,rparen,plus,minus,times,divide,mod,operand,eos}precedence;

precedence stack[max_stack_size];
static int isp[]={0,19,12,12,13,13,13,0,0};
static int icp[]={20,19,12,12,13,13,13,0,0};
char expr[max_expr_size];
char expr1[max_expr_size];
int stack1[max_stack_size];



void push(int *top,int item)
{
	stack[++(*top)]=item;
}

void push1(int *top,int item)
{
	stack1[++(*top)]=item;
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

int pop(int *top)
{

	return stack[(*top)--];
}


int pop1(int *top)
{

	return stack1[(*top)--];
}
void printtoken(precedence token)
{
	switch(token)
	{
		case plus:
			  printf("+");
			  strcat(expr1,"+");
			  break;
		case minus:
			  printf("-");
			  strcat(expr1,"-");
			  break;
		case times:
			  printf("*");
			  strcat(expr1,"*");
			  break;
		case divide:
			  printf("/");
			  strcat(expr1,"/");
			  break;
		case mod:
			  printf("%");
			  strcat(expr1,"%");
	}
}

void postfix(void)
{
	char symbol;
	precedence token;
	int n=0,i;
	int top=0;
	stack[0]=eos;
	for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n))
	{
		if(token==operand)
		{
			printf("%c",symbol);
			for(i=0;expr1[i]!='\0';i++);
			expr1[i++]=symbol;
			expr1[i]='\0';
		}

		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				printtoken(pop(&top));
		}
		else
		{
			if (isp[stack[top]]>=icp[token])
				printtoken(pop(&top));
			push(&top,token);
		}
	}
	while((token=pop(&top))!=eos)
		printtoken(token);
}



int eval(void)
{
	precedence token;
	int op1,op2;
	char symbol;
	int n=0;
	int top=-1;
	strcpy(expr,expr1);
	token=get_token(&symbol,&n);
	while(token!=eos)
	{
		if(token==operand)
			push1(&top,symbol-'0');
		else
		{
		op2=pop1(&top);
		op1=pop1(&top);
		switch(token)
		{
		    case plus:
				push1(&top,op1+op2);
				break;
		    case minus:
				push1(&top,op1-op2);
				break;
		    case times:
				push1(&top,op1*op2);
				break;
		    case divide:
				push1(&top,op1/op2);
				break;
		    case mod:
				push1(&top,op1%op2);
		}
		}
	token=get_token(&symbol,&n);
	}
	return pop1(&top);
}


void main()
{
	int i,res;
	clrscr();
	printf("\n\n\n\t\t\tEnter the expression : ");
	scanf("%s",&expr);
	postfix();
	res=eval();
	printf("\nResult = %d",res);
	getch();
}
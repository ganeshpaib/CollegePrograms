#include<stdio.h>
#include<conio.h>
#define MAX 30

typedef enum
{ lparen , rparen , plus , minus , times,divide,mod,operand,eos}precidence;

static int isp[]={0,19,12,12,13,13,13,0,0};
static int icp[]={20,19,12,12,13,13,13,0,0} ;

int top=-1;
 precidence stk[MAX];
 char expr[MAX];
void puch(int *top,precidence token)
{
	if(*top==MAX-1)
	{
		 printf("\nthe stalk is full:");
	}
	else
	{
		 stk[++( *top) ] = token;
	}
}
precidence pop(int *top)
{
	   if(*top==-1)
		  printf("\nthe stalk is empty:");
	   else
		return(stk[(*top)--]);
}
precidence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)++] ;

	 switch(*symbol)
	 {
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '%':return mod;
		case '\0':return eos;
		case '(':return lparen;
		case ')':return rparen;
		default:return operand;
	 }

}
void print_token(precidence token)
{
	switch( token )
	{
		case plus:printf("+"); break;
		case minus :printf("-"); break;
		case times :printf("*"); break;
		case divide :printf("/"); break;
		case mod :printf("%"); break;
		case eos :printf("\0"); break;
		case lparen :printf("("); break;
		case rparen :printf(")"); break;

 }

}


void postfix(void)
{
	char symbol;

	precidence token;

	int n=0;

	int top=0;

	stk[0]=eos;

	for( token = get_token( &symbol , &n ) ; token != eos ; token = get_token( &symbol , &n ))
	{
		if(token==operand)
		  printf("%c",symbol);

		else if( token == rparen )
		{
			  while((stk[top]) != lparen )

				  print_token( pop(&top ) ) ;

				  pop(&top);
		}
		else
		{
			 while ( isp[stk[top]] >=  icp[token] )
			  print_token(pop(&top));

			   puch(&top,token);
		}

	}
	while( (token= pop(&top))!= eos)
	print_token(token);

}

void main()
{
 int i,j,n;
 clrscr();
 printf("\nenter the expresion:");
 flushall();
 gets(expr);
 printf("\nthe post fix expersion is :...");
 postfix();
 getch();
}
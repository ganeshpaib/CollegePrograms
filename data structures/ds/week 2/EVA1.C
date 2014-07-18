#include<stdio.h>
#include<conio.h>
#define MAX 10

int stk[MAX];
char expr[MAX];

typedef enum{lparen,rparen,plus,minus,times,divide,mod,operand,eos}precidence;
int top=-1;


int pop(int *top)
{
	  if(*top==-1)
	  {
		  return(0);
	  }
	  else
	  {
		   return (stk[(*top)--]);
	  }
}

void puch(int *top,int n)
{
	if(*top==MAX-1)
	{
		  printf("the stalk is full:");
	}
	else
	{
		stk[++(*top)]=n;
	}
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
int eval(void)
{
  precidence token;
  int op1,op2;
  char symbol;
  int n=0;top=-1;
  token=get_token(&symbol,&n);
  while(token!=eos)
  {
	    if(token==operand)
	    {
	      puch(&top,symbol-'0');
	    }
	    else
	    {
	       op1=pop(&top);
	       op2=pop(&top);

	       switch(token)
	       {
		 case plus:
			   puch(&top,op1+op2);
			   break;
		 case minus:
			    puch(&top,op1-op2);
			    break;
		 case times:
			     puch(&top,op1*op2);
			     break;
		 case divide:
			      puch(&top,op1/op2);
			      break;
		 case mod:
			    puch(&top,op1%op2);
			    break;
	       }

	    }
	token=get_token(&symbol,&n);
  }
     return(pop(&top));
}

void main()
{
  int i,j,n;
  clrscr();
  printf("%d",rparen);
  printf("\nenter the experision:");
  flushall();
  gets(expr);
  strrev(expr);
  n=eval();
  printf("\nthe evaluation is %d",n);

  getch();
}

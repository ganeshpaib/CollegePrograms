#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 25

typedef enum{lparen,rparen,plus,minus,times,divide,mod,operand,eos}precedence;

char expr[MAX];
char stk[MAX][MAX];
char* infix(void);
precedence get_token( char *,int *);
void puch(int *,char *);
char* pop(int *);
int top=-1;

void main()
{
  int i;
 /* char res[' '][' '];*/
  clrscr();
  printf("\nenter the experision:");
  flushall();
  gets(expr);
  strrev(expr);
  /*strcpy(stk ,NULL);*/
  printf("%s",expr);
/*  strcpy(res,infix());*/
  printf("\n The resultant infix expersion is  : %s",infix());
  getch();
}
void puch(int *top,char *symbol)
{
       if(*top==MAX-1)
		printf("\nthe stalk is full");
       else
       {
		/*strcat(stk ,symbol);*/
		strcpy(stk[++(*top)],symbol);
       }
}

char* pop(int *top)
{
     if(*top==-1)
     {	printf("\nthe stalk is empty;");
	  return(NULL);
     }
     else
	{
		return(stk[(*top)--]);
	}

}

precedence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
  switch(*symbol)
  {
	case '+':return plus;
	case '-':return minus;
	case '*':return times;
	case '/':return divide;
	case '\0':return eos;
	default:return operand;
  }

}
char * infix(void)
{
     int n=0;
     char symbol;
     char temp[MAX];
     precedence token;
     char  op1[MAX],op2[MAX];

     token=get_token(&symbol,&n);

     while(token!=eos)
     {

     if(token==operand)
     {
	       /*strcat(stk ,symbol);*/
/**/	       temp[0]=symbol;
	       temp[1]='\0';
	       puch(&top,temp);
     }
     else
     {
     /**/	strcpy(op1,pop(&top) );
		strcpy(op2,pop(&top) );
		strcpy(temp,NULL);
		switch(token)
		{
			case plus:
		   /**/		  strcpy(temp,"(");
				  strcat(temp,op1);
				  strcat(temp, "+");
				  strcat(temp,op2);
				  strcat(temp,")");
				  puch(&top,temp);
				  break;
			case minus:
				  strcpy(temp,"(");
				  strcat(temp,op1);
				  strcat(temp, "-");
				  strcat(temp,op2);
				  strcat(temp,")");
				  puch(&top,temp);
				  break;
			case times:
				  strcpy(temp,"(");
				  strcat(temp,op1);
				  strcat(temp, "*");
				  strcat(temp,op2);
				  strcat(temp,")");
				  puch(&top,temp);
				  break;
			case divide:
				  strcpy(temp,"(");
				  strcat(temp,op1);
				  strcat(temp, "/");
				  strcat(temp,op2);
				  strcat(temp,")");
				  puch(&top,temp);
				  break;
		}
     }
     token=get_token(&symbol,&n);
}
return(pop(&top));
}

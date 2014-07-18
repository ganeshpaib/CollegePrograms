#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20

typedef enum{lpara,rpara,plus,minus,times,divide,mod,eos,operand}precedence;

char stack[MAX][MAX],expr[MAX],symbol,str[MAX];
char op1[MAX],op2[MAX],temp[2];
precedence token;
int top=-1,i=0,n=0;

void push(int *,char *);
char *pop(int *);
char *infix();
precedence get_token(char *,int *);

void main()
{
	clrscr();

	printf("\n Enter PreFix Expression :");
	flushall();
	gets(expr);
	strrev(expr);

	strcpy(str,infix());
	printf("\n %s",str);
getch();
}

char* infix()
{
	token=get_token(&symbol,&n);

	while(token!=eos)
	{
		if(token==operand)
		{
			str[0]=symbol;
			str[1]='\0';
			push(&top,str);

		}
		else
		{
			strcpy(op1,pop(&top));
			strcpy(op2,pop(&top));
			strcpy(str,NULL);

			switch(token)
			{
				case plus:
						temp[0]='(';
						temp[1]='\0';
						strcpy(str,temp);
						strcat(str,op1);
						temp[0]='+';
						temp[1]='\0';
						strcat(str,temp);
						strcat(str,op2);
						temp[0]=')';
						temp[1]='\0';
						strcat(str,temp);

						push(&top,str);
						break;

				case minus:
						temp[0]='(';
						temp[1]='\0';
						strcpy(str,temp);
						strcat(str,op1);
						temp[0]='-';
						temp[1]='\0';
						strcat(str,temp);
						strcat(str,op2);
						temp[0]=')';
						temp[1]='\0';
						strcat(str,temp);
						push(&top,str);
						break;
			case times:
						temp[0]='(';
						temp[1]='\0';
						strcpy(str,temp);
						strcat(str,op1);
						temp[0]='*';
						temp[1]='\0';
						strcat(str,temp);
						strcat(str,op2);
						temp[0]=')';
						temp[1]='\0';
						strcat(str,temp);
						push(&top,str);
						break;
				case divide:
						temp[0]='(';
						temp[1]='\0';
						strcpy(str,temp);
						strcat(str,op1);
						temp[0]='/';
						temp[1]='\0';
						strcat(str,temp);
						strcat(str,op2);
						temp[0]=')';
						temp[1]='\0';
						push(&top,str);
						break;
				case mod:
						temp[0]='(';
						temp[1]='\0';
						strcpy(str,temp);
						strcat(str,op1);
						temp[0]='%';
						temp[1]='\0';
						strcat(str,temp);
						strcat(str,op2);
						temp[0]=')';
						temp[1]='\0';
						strcat(str,temp);
						push(&top,str);
						break;
			}
		}
		token=get_token(&symbol,&n);
	  }
	return(pop(&top));
}

precedence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)++];

	switch(*symbol)
	{
		case'(':return lpara;
		case ')':return rpara;
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case'%':return mod;
		case'\0':return eos;
		default: return operand;
	}
}

void push(int *top,char *str)
{
	strcpy(stack[++(*top)],str);
}

char * pop(int *top)
{
	char str[3];
	if(*top==-1)
	{
		strcpy(str,"NO");
		return(str);
	}
	else
	{
		return(stack[(*top)--]);
	}
}





/* Program to parenthesise the prefix expr to infix expr */

#include<stdio.h>
#include<conio.h>
#include<string.h>

#define Max_Stack_Size 15
#define Max_Expr_Size 30

char stack[Max_Stack_Size][Max_Expr_Size];
char expr[Max_Expr_Size];
int top=-1;

char gettoken(int *n)
{
	return expr[(*n)--];
}

void push(char t)
{
	stack[++top][0]=t;
	stack[top][1]='\0';
}

void pushstr(char *t)
{
	strcpy(stack[++top],t);
}

void pop(char *t)
{
	strcpy(t,stack[top--]);
}

void convert()
{
	int n=strlen(expr)-1,i,j,k;
	char t,op1[Max_Expr_Size],op2[Max_Expr_Size],temp[Max_Expr_Size];
	for(t=gettoken(&n);t!='$';t=gettoken(&n))
	{
	 if(t>=48&&t<=57||t>=65&&t<=90||t>=97&&t<=122)
	  push(t);
	 else
	  if(t=='*'||t=='/'||t=='+'||t=='-'||t=='%')
	  {
	   pop(temp);
	   strcpy(op1,temp);
	   pop(temp);
	   strcpy(op2,temp);
	   for(k=strlen(op1)+1;k>0;k--)
	    op1[k]=op1[k-1];
	   op1[0]='(';
	   j=strlen(op1);
	   op1[j]=t;
	   op1[j+1]='\0';
	   for(i=strlen(op1),j=0;op2[j]!='\0';i++,j++)
	    op1[i]=op2[j];
	   op1[i]=')';
	   op1[i+1]='\0';
	   pushstr(op1);
	  }
	}
}


void main()
{
	char res[Max_Expr_Size];
	clrscr();
	printf("Enter valid postfix expression\n");
	gets(expr);
	expr[-1]='$';
	convert();
	pop(res);
	puts(res);
	getch();
}

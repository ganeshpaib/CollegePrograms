/* postfix to infix  paranthesis */

#include<stdio.h>
#include<conio.h>
#include<string.h>

char stack[15][30];
char expr[30];
int top=-1;

char gettoken(int *n)
{
    return expr[(*n)++];
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

void postfix_to_infix(void)
{
  int i,j,k,n=0;
  char t,op1[20],op2[30],temp[30];
  for(t=gettoken(&n);t!='\0';t=gettoken(&n))
  {
    if(t>='0' && t<='9' || t>='a' && t<='z' || t>='A' && t<='Z')
    push(t);
    else if(t=='+' || t=='-' || t=='*' || t=='/' || t=='%')
    {
    pop(temp);
    strcpy(op2,temp);
    pop(temp);
    strcpy(op1,temp);
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
   char result[30];
   clrscr();
   printf("\nEnter the postfix expression: ");
   scanf("%s",expr);
   //expr[-1]='$';
   postfix_to_infix();
   pop(result);
   printf("%s",result);
   getch();
 }
#include<stdio.h>
#include<ctype.h>

struct stack
{
 int top;
 char item[30];
};

void push(struct stack *ps,char n)
{
 ps->top++;
 ps->item[ps->top]=n;
}

void pop(struct stack *ps)
{
 ps->top--;
}

int isempty(struct stack *ps)
{
 if(ps->top==-1)
   {
    return(1);
   }
 else
   {
    return(0);
   }
}

int prcd(char stktop,char op)
{
 if(((stktop=='+')||(stktop=='-'))&&((op=='*')||(op=='/')))
   {
    return(0);
   }
 if(stktop=='(')
   {
    return(0);
   }
 if((stktop!=')')&&(op=='('))
   {
    return(0);
   }
 if((stktop!='(')&&(op==')'))
   {
    return(1);
   }
}

void main()
{
 struct stack s;
 char input[30],output[30];
 char optop,ans;
 int i=0,j=0,k=0;
 s.top=-1;
 printf("enter an expression in infix form:\n");
 scanf("%s",input);
  while(input[i]!='\0')
   {
     if(isalpha(input[i]))
       {
        output[j]=input[i];
        j++;
       }
     else
       {
        while(!isempty(&s)&&(prcd(s.item[s.top],input[i])))
             {
              optop=s.item[s.top];
              pop(&s);
              output[j]=optop;
              j++;
             }
        if(isempty(&s)||input[i]!=')')
          {
           push(&s,input[i]);
          }
        else
          {
           pop(&s);
          }
        }

   i++;
  }

 while(!isempty(&s))
  {
   optop=s.item[s.top];
   pop(&s);
   output[j]=optop;
   j++;
  }
 printf("\npostfix form:\t");
 output[j]='\0';

 while(output[k]!='\0')
  {
   printf("%c",output[k]);
   k++;
  }
 scanf("%c",&ans);
 getchar();
}





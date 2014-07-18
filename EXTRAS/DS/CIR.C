circular queue:


#include<stdio.h>
#include<conio.h>
#define MAX 4

typedef struct
{
	int key;
}element;

int rear=0;
int front=0;
int item;

element q[MAX];

void addq(int,int*,int*);
int delq(int*,int*);
void display(int*,int*);

void main()
{
	int ch,f;

	do
	{
		clrscr();
		printf("\n\t 1... Add ");
		printf("\n\t 2... Delete ");
		printf("\n\t 3... Display ");
		printf("\n\t 4... Exit ");
		printf("\n Enter Your Choice ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\n Enter  
Element :");
				scanf("%d",&item);

				 
addq(item,&rear,&front);
				break;
			case 2:
				 
f=delq(&rear,&front);

				if(f==0)
				{
					printf("\n  
The Queue Is Empty ");
				}
				else
				{
					printf("\n  
The Deleted Item Is : %d",f);
				}
				break;
			   case 3:
				 
display(&rear,&front);
				break;
			case 4:
				exit(0);
		}
		getch();
	}while(ch!=4);
getch();
}

void addq(int item,int *rear,int *front)
{
	*rear=(*rear+1)%MAX;

	if(*rear==*front)
	{
		printf("\n The Queue Is Full ");

		if(*rear==0)
		{
			*rear=MAX-1;
		}
		else
		{
			*rear=*rear-1;
		}
	}
	else
	{
		q[*rear].key=item;
		printf("\n One Element Is Added ");
	}
}

int delq(int *rear,int *front)
{
	if(*rear==*front)
	{
		return(0);
	}
	else
	{
		*front=(*front+1)%MAX;
		return q[*front].key;
	}
}

void display(int *rear,int *front)
{
	int i;

	if(*rear==*front)
	{
		printf("\n The Queue Is Empty ");
	}
	else
	{

		if(*front<*rear)
		{
			 
for(i=(*front+1);i<=*rear;i++)
			{
				printf("%5d",q[i]);
			}
		}
		else if(*front>=*rear)
		{
			for(i=(*front+1);i<MAX;i++)
			{
				printf("%5d",q[i]);
			}
			for(i=0;i<=*rear;i++)
			{
				printf("%5d",q[i]);
			}
		}
	}
}



in pos:


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

typedef  
enum{lpara,rpara,plus,minus,times,divide,operand,eo 
s}precedence;
char *expr;
int s[MAX],top=-1,i,n;
precedence token;
char symbol;

int eval();
void push(int *,int);
int pop(int *);
precedence get_token(char *,int *);

void main()
{
	int n,x;
	clrscr();

	printf("\n Expr Size :");
	scanf("%d",&n);

	expr=(char *)malloc(sizeof(char)*n);

	for(i=0;i<n;i++)
	{
		printf("Expr[%d] :",i+1);
		flushall();
		scanf("%c",&expr[i]);
	}

	x=eval();

	printf("\n The Result Is  : %d",x);
getch();
}

int eval()
{
	int op1,op2;

	token=get_token(&symbol,&n);

	while(token!=eos)
	{
		if(token==operand)
		{
			push(&top,symbol-'0');
		}
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
			}
		}
		token=get_token(&symbol,&n);
	}
	return pop(&top);
}

precedence get_token(char *symbol,int *n)
{
	*symbol=expr[(*n)++];

	switch(*symbol)
	{
		case '(':return lpara;
		case ')':return rpara;
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '\0':return eos;
	}
}

void push(int *top,int item)
{
	if(*top==MAX-1)
	{
		printf("\n The Stack Is Full ");
	}
	else
	{
		s[++(*top)]=item;
	}
}

int pop(int *top)
{
	if(*top==-1)
	{
		printf("\n The Stack Is Empty");
		return(0);
	}
	else
	{
		return s[(*top)--];
	}
}

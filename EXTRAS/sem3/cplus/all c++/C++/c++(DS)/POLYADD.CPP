#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define COMP(a,b) ((a >b)?1:(a==b)?0:-1)

int c;
typedef struct poly_node *poly_ptr;

typedef struct poly_node
{
	int coef;
	int exp;
	poly_ptr link;
};
void insert_end(poly_ptr *ptr ,int c,int e)
{
	poly_ptr t,t1;
	t=(poly_ptr)malloc(sizeof(poly_node) );
	t->coef=c;
	t->exp=e;
	if(*ptr==NULL)
	{
		*ptr=t;
		t->link=NULL;
	}
	else
	{

		for(t1=*ptr;t1->link!=NULL;t1=t1->link);
		t1->link=t;
		t->link=NULL;
		printf("\nthe element is added:");

	}
}
 void attach( int coef ,int exp ,poly_ptr *ptr)
 {
	poly_ptr temp;
	temp=(poly_ptr)malloc(sizeof(poly_node));
	temp->coef=coef;
	temp->exp=exp;
	(*ptr)->link=temp;
	*ptr=temp;
 }
poly_ptr polyadd(poly_ptr a , poly_ptr b)
{
	poly_ptr front,rear,temp;
	int sum;
	rear=(poly_ptr)malloc(sizeof(poly_node));
	front=rear;
	while(a != NULL && b != NULL)
	{
		c=COMP(a->exp , b->exp);
		 switch(c)
		 {
			case -1:
				attach(b->coef,b->exp,&rear);
				b=b->link;
				break;
			case 0: sum=a->coef + b->coef;
				if(sum)
				attach(sum,a->exp,&rear);
				a=a->link;
				b=b->link;
				break;
			case 1:attach(a->coef,a->exp,&rear);
				a=a->link;
				break;
		 }
	}

	for( ;a!=NULL ; a=a->link)
		attach(a->coef,a->exp,&rear);

	for(;b!=NULL;b=b->link)
		attach(b->coef,b->exp,&rear);

		rear->link=NULL;
		temp=front;
		front=front->link;
		free(temp);
		return(front);
}


void display(poly_ptr ptr)
{
	poly_ptr t;
	if (ptr==NULL)
	printf("\nthe list is empty:");
	else
	{
	 t=ptr;
	while(t != NULL)
	{
		 if(t->link==NULL)
		 printf("%dx^%d",t->coef,t->exp);
		 else
		 printf("%dx^%d+" ,t->coef,t->exp);

		 t=t->link;
	}
  }

}
void main()
{
	poly_ptr eq1=NULL,eq2=NULL,eq3=NULL;
	int e,c,opt;
	clrscr();
	printf("\nenter the equation1:");
	 do
	 {
		printf("\nenter the coef and exp");
		scanf("%d%d" ,&c,&e);
		insert_end(&eq1,c,e);
		printf("\nenter the 99 if u not want to creater a node");
		scanf("%d" ,&opt);
	}while(opt!=99);

	printf("\nenter the equation2:");
	 do
	 {
		printf("\nenter the coef and exp");
		scanf("%d%d" ,&c,&e);
		insert_end(&eq2,c,e);
		printf("\nenter the 99 if u not want to creater a node");
		scanf("%d" ,&opt);
	}while(opt!=99);

	display(eq1);
	printf("\n");
	display(eq2);
	printf("\n the addition of polynomial is :");
	eq3=polyadd(eq1,eq2);
	display(eq3);
	getch();
}
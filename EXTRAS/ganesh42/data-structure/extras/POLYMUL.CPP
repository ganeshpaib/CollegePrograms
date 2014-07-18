#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct poly_node *poly_ptr;

typedef struct poly_node
{
	int coef;
	int expon;
	poly_ptr link;
};
void insert_end(poly_ptr *ptr ,int c,int e)
{
	poly_ptr t,t1;
	t=(poly_ptr)malloc(sizeof(poly_node) );
	t->coef=c;
	t->expon=e;
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
	}
}
 void attach( int coef ,int exp ,poly_ptr *ptr)
 {
	poly_ptr temp;
	temp=(poly_ptr)malloc(sizeof(poly_node));
	temp->coef=coef;
	temp->expon=exp;
	(*ptr)->link=temp;
	*ptr=temp;
 }
poly_ptr polymul(poly_ptr a , poly_ptr b)
{
	poly_ptr front,rear,temp,t;
	int sum;
	rear=(poly_ptr)malloc(sizeof(poly_node));
	front=rear;
	while(a != NULL)
	{
		t=b;
		while(t!=NULL)
		{
			attach((a->coef*t->coef),(a->expon+t->expon),&rear);
			t=t->link;
		}
		a=a->link;
	}

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
	printf("\nThe list is empty:");
	else
	{
	 t=ptr;
	while(t != NULL)
	{
		 if(t->link==NULL)
		 printf("%dx^%d",t->coef,t->expon);
		 else
		 printf("%dx^%d+" ,t->coef,t->expon);

		 t=t->link;
	}
  }

}
void main()
{
	poly_ptr poly1=NULL,poly2=NULL,res_poly=NULL;
	int e,c;
	char opt;
	clrscr();
	printf("\n\n\n\t\t\tEnter the first polynomial: ");
	 do
	 {
		printf("\n\n\n\t\t\tEnter the coef and exp  :");
		scanf("%d%d" ,&c,&e);
		insert_end(&poly1,c,e);
		printf("\n\n\n\t\t\tPress 'y' to continue  ");
		flushall();
		scanf("%c" ,&opt);
	}while(opt=='y');

	printf("\n\n\n\t\t\tEnter the second polynomial: ");
	 do
	 {
		printf("\n\n\n\t\t\tEnter the coef and exp");
		scanf("%d%d" ,&c,&e);
		insert_end(&poly2,c,e);
		printf("\n\n\n\t\t\tPress 'y' to continue  ");
		flushall();
		scanf("%c" ,&opt);
	}while(opt=='y');

	printf("\n\n\n( ");
	display(poly1);
	printf(" ) * ( ");
	display(poly2);
  printf(" ) =  ");
	res_poly=polymul(poly1,poly2);
	display(res_poly);
	getch();
}
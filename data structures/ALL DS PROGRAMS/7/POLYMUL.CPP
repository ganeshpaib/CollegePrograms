#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
		printf("\n The Element Is Added");

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
poly_ptr polymul(poly_ptr a , poly_ptr b)
{
	poly_ptr front,rear,temp,t;
	rear=(poly_ptr)malloc(sizeof(poly_node));
	front=rear;
	while(a != NULL)
	{
		t=b;
		while(t!=NULL)
		{
			attach((a->coef*t->coef),(a->exp+t->exp),&rear);
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
	printf("\n The List Is Empty....");
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
	poly_ptr a=NULL,b=NULL,x=NULL;
	int e,c,i=1,n;
	clrscr();
	printf("\n Enter Number Of Nodes For Equation 1 :");
	scanf("%d",&n);
	printf("\n Enter Equation 1...");

	while(i<=n)
	{
		printf("\n Enter coef[%d] : ",i);
		scanf("%d" ,&c);
		printf("\n Enter Expo[%d] : ",i);
		scanf("%d",&e);

		insert_end(&a,c,e);
		printf("\n");
		i++;
	}

	printf("\n Enter Number Of Nodes For Equation 2 :");
	scanf("%d",&n);
	printf("\n Enter Equation 2...");
	i=1;

	while(i<=n)
	{
		printf("\n Enter coef[%d] : ",i);
		scanf("%d" ,&c);
		printf("\n Enter Expo[%d] : ",i);
		scanf("%d",&e);

		insert_end(&b,c,e);
		printf("\n");
		i++;
	}

	printf("\n\n\t.........OUTPUT.........\n");


	printf("\n Equation 1 :: ");
	display(a);
	printf("\n Equation 2 :: ");
	display(b);
	printf("\n The Result Is ::  ");
	x=polymul(a,b);
	display(x);
	getch();
}
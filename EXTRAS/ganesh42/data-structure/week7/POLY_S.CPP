#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#define compare(x,y) ((x<y)?-1:((x==y)?0:1))

typedef struct poly_node *poly_ptr;
typedef struct poly_node
{
	int coef;
	int expon;
	poly_ptr link;
};
poly_ptr x1=NULL;
poly_ptr x2=NULL;
poly_ptr x3=NULL;
poly_ptr x4=NULL;

void creat(poly_ptr *ptr)
{
	poly_ptr first,temp;
	int data;
	first=(poly_ptr)malloc(sizeof(poly_node));
	printf("\nEnter the coefficient : ");
	scanf("%d",&data);
	first->coef=data;
	printf("\nEnter the exponent : ");
	scanf("%d",&data);
	first->expon=data;
	if(*ptr==NULL)
		*ptr=first;
	else
	{
		for(temp=*ptr;temp->link!=NULL;temp=temp->link);
		temp->link=first;
	}
	first->link=NULL;
}

void traverse(poly_ptr *ptr)
{
	poly_ptr temp;
	for(temp=*ptr;temp!=NULL;temp=temp->link)
	{
		printf("%dx^%d ",temp->coef,temp->expon);
		if(temp->link!=NULL)
			printf("+ ");
	}
}


void attach(int coeff, int exponent,poly_ptr *ptr)
{
	poly_ptr temp;
	temp=(poly_ptr)malloc(sizeof(poly_node));
	temp->coef=coeff;
	temp->expon=exponent;
	(*ptr)->link=temp;
	*ptr=temp;
}


poly_ptr poly_add(poly_ptr a,poly_ptr b)
{
	poly_ptr front, rear,temp;
	int sum;
	rear=(poly_ptr)malloc(sizeof(poly_node));
	front=rear;
	while(a!=NULL && b!=NULL)
	{
		switch(compare(a->expon,b->expon))
		{
			case -1:
				attach(b->coef,b->expon,&rear);
				b=b->link;
				break;
			case 0:
				sum=a->coef+b->coef;
				if(sum)
					attach(sum,a->expon,&rear);
				a=a->link;
				b=b->link;
				break;
			case 1:
				attach(a->coef,a->expon,&rear);
				a=a->link;
				break;
		}
	}
	for(;a!=NULL;a=a->link)
		attach(a->coef,a->expon,&rear);
	for(;b!=NULL;b=b->link)
		attach(b->coef,b->expon,&rear);
	rear->link=NULL;
	temp=front;
	front=front->link;
	free(temp);
	return front;
}

poly_ptr poly_mul(poly_ptr a , poly_ptr b)
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




void main()
{
	char opt;
	clrscr();
	printf("\nCreate the first list\n");
	do
	{
		creat(&x1);
		printf("\nPress 'y' to continue");
		flushall();
		scanf("%c",&opt);
	}while(opt=='y');

	printf("\nCreate the second list\n");
	do
	{
		creat(&x2);
		printf("\nPress 'y' to continue");
		flushall();
		scanf("%c",&opt);
	}while(opt=='y');
	getch();
	clrscr();
	printf("\n\nElements in list1\n\n");
	traverse(&x1);
	printf("\n\nElements in list2\n\n");
	traverse(&x2);
	printf("\n\n\n After addition\n\n");
	x3=poly_add(x1,x2);
	traverse(&x3);
	printf("\n\n\n After multiplication\n\n");
	x4=poly_mul(x1,x2);
	traverse(&x4);
	getch();
}


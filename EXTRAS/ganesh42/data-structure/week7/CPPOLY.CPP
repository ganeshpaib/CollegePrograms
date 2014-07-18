#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#define compare(x,y) ((x<y)?-1:((x==y)?0:1))
#define TRUE 1
#define FALSE 0

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


int data;

void create(poly_ptr head)
{
	poly_ptr temp,t;
	temp=(poly_ptr)malloc(sizeof(poly_node));
	printf("\nEnter the coefficient : ");
	scanf("%d",&data);
	temp->coef=data;
	printf("\nEnter the exponent : ");
	scanf("%d",&data);
	temp->expon=data;
	for(t=head;t->link!=head;t=t->link);
	t->link=temp;
	temp->link=head;
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

void traverse(poly_ptr head)
{
	poly_ptr temp;
	if(head->link==head)
		printf("\nList is empty ");
	else
	{
		for(temp=head->link;temp!=head;temp=temp->link)
		{
			printf("%dx^%d ",temp->coef,temp->expon);
			if(temp->link!=head)
				printf("+ ");
		}
	}
}




poly_ptr cpadd(poly_ptr a, poly_ptr b)
{
	poly_ptr starta,d,lastd;
	int sum,done=FALSE;
	starta=a;
	a=a->link;
	b=b->link;
	d=(poly_ptr)malloc(sizeof(poly_node));
	d->expon=-1;
	lastd=d;
	do
	{
		switch(compare(a->expon,b->expon))
		{
			case -1:
					attach(b->coef,b->expon,&lastd);
					b=b->link;
					break;
			case 0:
					if(starta==a)
						done=TRUE;
					else
					{
						sum=a->coef+b->coef;
						if(sum)
							attach(sum,a->expon,&lastd);
					}
					a=a->link;
					b=b->link;
					break;
			case 1:
					attach(a->coef,a->expon,&lastd);
					a=a->link;
					break;
		}
	}while(!done);
	lastd->link=d;
	return d;
}

void main()
{
	char opt;
	clrscr();
	printf("\nCreate the first list\n");
	x1=(poly_ptr)malloc(sizeof(poly_node));
	x1->link=x1;
	x1->expon=-1;
	do
	{
		create(x1);
		printf("\nPress 'y' to continue");
		flushall();
		scanf("%c",&opt);
	}while(opt=='y');

	printf("\nCreate the second list\n");
	x2=(poly_ptr)malloc(sizeof(poly_node));
	x2->link=x2;
	x2->expon=-1;
	do
	{
		create(x2);
		printf("\nPress 'y' to continue");
		flushall();
		scanf("%c",&opt);
	}while(opt=='y');
	getch();
	clrscr();
	printf("\n\nElements in list1\n\n");
	traverse(x1);
	printf("\n\nElements in list2\n\n");
	traverse(x2);
	printf("\n\n\n After addition\n\n");
	x3=(poly_ptr)malloc(sizeof(poly_node));
	x3->link=x3;
	x3->expon=-1;
	x3=cpadd(x1,x2);
	traverse(x3);
	getch();
}






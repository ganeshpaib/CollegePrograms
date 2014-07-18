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
	t=(poly_ptr)malloc(sizeof(struct poly_node) );
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
	temp=(poly_ptr)malloc(sizeof(struct poly_node));
	temp->coef=coef;
	temp->exp=exp;
	(*ptr)->link=temp;
	*ptr=temp;
 }

int compare(int x,int y)
{
	if(x<y) return -1;
	else if(x>y) return 1;
	else return 0;
}

poly_ptr polyadd(poly_ptr a , poly_ptr b)
{
	int sum;
	poly_ptr front,rear,temp,t;
	rear=(poly_ptr)malloc(sizeof(struct poly_node));
	front=rear;

	while(a!=NULL && b!=NULL)
	{
		switch(compare(a->exp,b->exp))
		{
			case -1 :
				attach(b->coef,b->exp,&rear);
				b=b->link;
				break;
			case 0:
				sum=a->coef+b->coef;
				if(sum)
					attach(sum,a->exp,&rear);
					a=a->link;
					b=b->link;
				break;
			case 1:
				attach(a->coef,a->exp,&rear);
				a=a->link;
				break;
		}
	}

	for(;a!=NULL;a=a->link)
	{
		attach(a->coef,a->exp,&rear);
	}
	for(;b!=NULL;b=b->link)
	{
		attach(b->coef,b->exp,&rear);
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
		printf("Enter Expo[%d] : ",i);
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
		printf("Enter Expo[%d] : ",i);
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
	x=polyadd(a,b);
	display(x);
	getch();
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct poly_node *poly_ptr;
typedef struct ploy_node
{
	int coeff;
	int expo;
	poly_ptr link;
};

ploy_ptr a,b,c;
a=NULL;
b=NULL;
c=NULL;

void main()
{
	int p1,p2;
	clrscr();

	printf("\n Enter Number Of Term For First Equation :");
	scanf("%d",&p1);

	for(i=0;i<p1;i++)
	{
		add(&a);
	}

	printf("\n Enter Number Of Term For Second Equation :");
	scanf("%d",&p2);

	for(i=0;i<p2;i++)
	{
		add(&b);
	}

	c=ploy_add(a,b);

	for(t=*c;t!=NULL;t=t->link)
	{
		printf("%2d %2d",t->coeff,t->expo);
		printf("%5d");
	}
getch();
}



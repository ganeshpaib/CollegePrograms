#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list_node *list_ptr;

typedef struct list_node
{
	int coef;
	int expo;
	list_ptr link;
};
list_ptr a=NULL,b=NULL,c=NULL;

list_ptr polyadd(list_ptr,list_ptr);
void add(int,int,list_ptr *);
int compare(int,int);
void attach(int,int,list_ptr *);
void display(list_ptr);

void main()
{
	int i,f1,coef,expo;
	clrscr();

	a=(list_ptr)malloc(sizeof(struct list_node));
	b=(list_ptr)malloc(sizeof(struct list_node));
	c=(list_ptr)malloc(sizeof(struct list_node));
	a->expo=-1;
	b->expo=-1;
	a->link=a;
	b->link=b;
	c->link=c;


	printf("\n Enter Number Of Term For First Equation : ");
	scanf("%d",&f1);

	for(i=0;i<f1;i++)
	{
		printf("\n Enter Coef [%d] : ",i+1);
		scanf("%d",&coef);
		printf("\n Enter Expo [%d] :",i+1);
		scanf("%d",&expo);

		add(coef,expo,&a);
	}

	printf("\n Enter Number Of Term For Second Equation : ");
	scanf("%d",&f1);

	for(i=0;i<f1;i++)
	{
		printf("\n Enter Coef [%d] : ",i+1);
		scanf("%d",&coef);
		printf("\n Enter Expo [%d] :",i+1);
		scanf("%d",&expo);

		add(coef,expo,&b);
	}
	c=c->link;

	c=polyadd(a,b);
	printf("\n\n\t OUTPUT \n");
	display(c);

getch();
}

void add(int coef,int expo,list_ptr *a)
{
	list_ptr t=NULL,temp=NULL;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	temp->coef=coef;
	temp->expo=expo;

	for(t=*a;t->link!=*a;t=t->link);

	t->link=temp;
	temp->link=*a;

	printf("\n Added..");

}

list_ptr polyadd(list_ptr a,list_ptr b)
{
	list_ptr lastd,d,starta;
	int done=0,sum;

	starta=a;
	a=a->link;
	b=b->link;

	d=(list_ptr)malloc(sizeof(struct list_node));
	d->expo=-1;
	lastd=d;

	do
	{
		switch(compare(a->expo,b->expo))
		{
			case -1:
					attach(b->coef,b->expo,&lastd);
					b=b->link;
					break;
			case 0:
					if(starta==a)
					{
						done=1;
					}
					else
					{
						sum=a->coef+b->coef;
						if(sum)
						{
							attach(sum,a->expo,&lastd);
							a=a->link;
							b=b->link;
						}
					}
					break;
			case 1:
					attach(a->coef,a->expo,&lastd);
					a=a->link;
					break;
		}
	}while(!done);

	lastd->link=d;
	return(d);
}

int compare(int a,int b)
{
	if(a==b)
		return(0);
	else if(a<b)
		return(-1);
	else
		return(1);
}

void attach(int coef,int expo,list_ptr *ptr)
{
	list_ptr temp;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	temp->coef=coef;
	temp->expo=expo;
	(*ptr)->link=temp;
	(*ptr)=temp;
}

void display(list_ptr c)
{
	list_ptr t;

	if(c->link==c)
	{
		printf("\n The List Is Empty....");
	}
	else
	{
		for(t=c->link;t!=c;t=t->link)
		{
			if(t->link==c)
			{
				printf("%dx^%d ",t->coef,t->expo);
			}
			else
			{
				printf("%dx^%d + ",t->coef,t->expo);
			}
		}
	}
}













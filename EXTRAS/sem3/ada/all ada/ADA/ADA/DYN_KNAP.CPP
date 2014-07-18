#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *p,*w,*x,n,c;

int F(int,int);
void traceback(int,int);
int max(int,int);

void main()
{
	int i,z;
	clrscr();
	printf("\n Enter Number Of Elements :");
	scanf("%d",&n);
	printf("\n Enter Total Capacity :");
	scanf("%d",&c);

	p=(int *)malloc(sizeof(int)*n);
	w=(int *)malloc(sizeof(int)*n);
	x=(int *)malloc(sizeof(int)*n);

	for(i=1;i<=n;i++)
	{
		printf("p[%d] :",i);
		scanf("%d",&p[i]);
		printf("w[%d] :",i);
		scanf("%d",&w[i]);
		printf("\n");
	}

	z=F(1,c);
	traceback(c,n);

	for(i=1;i<=n;i++)
	{
		printf("%5d",x[i]);
	}
	printf("\n\n Total Profit Is : %5d",z);

getch();
}

int F(int i,int y)
{
	if(i==n)
		return(y<w[n])?0:p[n];
	if(y<w[i])
		return F(i+1,y);
	else
		return max(F(i+1,y),F(i+1,y-w[i])+p[i]);
}

int max(int i,int j)
{
	if(i>j)
		return(i);
	else
		return(j);
}

void traceback(int c,int n)
{
	int i;

	for(i=1;i<=n;i++)
	{
		x[i]=0;
	}

	for(i=1;i<n;i++)
	{
		if(F(i,c)==F(i+1,c))
			x[i]=0;
		else
		{
			x[i]=1;
			c-=w[i];
		}
	}

	if(F(n,c)==0)
		x[n]=0;
	else
		x[n]=1;
}


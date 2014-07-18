#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *p,*w,*x,n,c,**f;

int max(int,int);
void traceback(int,int);
void F(int,int);

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
	f=(int **)malloc(sizeof(int)*n*c);

	for(i=1;i<=n;i++)
	{
		printf("p[%d] :",i);
		scanf("%d",&p[i]);
		printf("w[%d] :",i);
		scanf("%d",&w[i]);
		printf("\n");
		f[i]=(int *)malloc(sizeof(int)*c);
	}

	F(c,n);
	traceback(c,n);

	for(i=1;i<=n;i++)
	{
		printf("%5d",x[i]);
	}
	printf("\n Total Profit Is : %5d",f[1][c]);

getch();
}

void F(int c,int n)
{
	int y,i,j;

	for(y=0;y<w[n];y++)
	{
		f[n][y]=0;
	}
	for(y=w[n];y<=c;y++)
	{
		f[n][y]=p[n];
	}

	for(i=n-1;i>1;i--)
	{
		for(y=0;y<w[i];y++)
			f[i][y]=f[i+1][y];
		for(y=w[i];y<=c;y++)
			f[i][y]=max(f[i+1][y],f[i+1][y-w[i]]+p[i]);
	}
	f[1][c]=f[2][c];
	if(c>=w[1])
		f[1][c]=max(f[1][c],f[2][c-w[1]]+p[1]);
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
		if(f[i][c]==f[i+1][c])
			x[i]=0;
		else
		{
			x[i]=1;
			c-=w[i];
		}
	}

	if(f[n][c]==0)
		x[n]=0;
	else
		x[n]=1;
}



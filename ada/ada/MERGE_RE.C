#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *a,*b;

void mergesort(int*,int,int);
void merge(int*,int *,int,int,int);
void copy(int*,int*,int,int);

void main()
{
	int n,i;
	clrscr();
	printf("\n Enter Number Of Elements : ");
	scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		printf("a[%d] :",i);
		scanf("%d",&a[i]);
	}

	mergesort(a,0,n-1);


	for(i=0;i<n;i++)
	{
		printf("%5d",b[i]);
	}

getch();
}

void mergesort(int a[],int left,int right)
{
	int mid;

	if(left<right)
	{
		mid=(left+right)/2;

		mergesort(a,left,mid);
		mergesort(a,mid+1,right);

		merge(a,b,left,mid,right);
		copy(b,a,left,right);
	}
}

void merge(int x[],int y[],int l,int m,int r)
{
	int i,j,k,p;
	i=l;j=m+1,k=l;

	while((i<=m)&&(j<=r))
	{
		if(x[i]<=x[j])
			y[k++]=x[i++];
		else
			y[k++]=x[j++];
	}

	if(i>m)
	{
		for(p=j;p<=r;p++)
		{
			y[k++]=x[p];
		}
	}
	else
	{
		for(p=i;p<=m;p++)
		{
			y[k++]=x[p];
		}
	}
}

void copy(int *a,int *b,int l,int r)
{
	int i;

	for(i=l;i<=r;i++)
	{
		a[i]=b[i];
	}
}




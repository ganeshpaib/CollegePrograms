#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void mergesort(int *,int,int);
void merge(int *,int *,int,int,int);
void copy(int *,int *,int,int);
int *a,*b,n;

void main()
{
	int i;
	clrscr();
	printf("\n Enter Number Of Elements :");
	scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);

	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
getch();
}

void mergesort(int *a,int l,int r)
{
	int mid;

	if(l<r)
	{
		mid=(l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,b,l,mid,r);
		copy(b,a,l,r);
	}
}

void copy(int *b,int *a,int l,int r)
{
	int i;

	for(i=l;i<=r;i++)
	{
		a[i]=b[i];
	}
}

void merge(int *x,int *y,int l,int m,int r)
{
	int i,j,k,q;
	i=l,j=m+1,k=l;

	while((i<=m)&&(j<=r))
	{
		if(x[i]<=x[j])
			y[k++]=x[i++];
		else
			y[k++]=x[j++];
	}

	if(i>m)
	{
		for(q=j;q<=r;q++)
		{
			y[k++]=x[q];
		}
	}
	else
	{
		for(q=i;q<=m;q++)
		{
			y[k++]=x[q];
		}
	}
}


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *a,*b;
void mergesort(int *,int);
void merge(int *,int *,int,int,int);
void merge_pass(int*,int *,int,int);


void main()
{
	int i,n;
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

	mergesort(a,n);

	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
getch();
}

void mergesort(int *a,int n)
{
	int s=1;

	while(s<n)
	{
		merge_pass(a,b,s,n);
		s*=2;
		merge_pass(b,a,s,n);
		s*=2;
	}
}

void merge_pass(int *a,int *b,int s,int n)
{
	int i=0,q;

	while(i<=n-2*s-1)
	{
		merge(a,b,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}

	if(i+s<n)
	{
		merge(a,b,i,i+s-1,n-1);
	}
	else
	{
		for(q=i;q<n;q++)
		{
			b[q]=a[q];
		}
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


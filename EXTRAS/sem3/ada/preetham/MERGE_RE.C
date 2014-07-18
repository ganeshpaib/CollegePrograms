#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *a,*b,n;

void merge_sort(int*,int,int);
void merge(int*,int*,int,int,int);
void copy(int*,int*,int,int);


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
		printf("a[%d] :",i);
		scanf("%d",&a[i]);
	}

	merge_sort(a,0,n-1);

	printf("\n");

	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
getch();

}

void merge_sort(int *a,int l,int r)
{
	int mid;

	if(l<r)
	{
		mid=(l+r)/2;

		merge_sort(a,l,mid);
		merge_sort(a,mid+1,r);

		merge(a,b,l,mid,r);
		copy(b,a,l,r);
	}

}

void merge(int *a,int *b,int l,int m,int r)
{
	int i=l,j=m+1,k=l,s;

	while((i<=m)&&(j<=r))
	{
		if(a[i]<=a[j]) b[k++]=a[i++];
		else b[k++]=a[j++];
	}

	if(i>m)
	{
		for(s=j;s<=r;s++)
		{
			b[k++]=a[s];
		}
	}
	else
	{
		for(s=i;s<=m;s++)
		{
			b[k++]=a[s];
		}
	}
}

void copy(int *b,int *a,int l,int r)
{
	int i;

	for(i=l;i<r;i++)
	{
		a[i]=b[i];
	}
}




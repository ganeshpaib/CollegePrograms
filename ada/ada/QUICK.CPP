#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *a;
void quicksort(int *,int,int);
void swap(int&,int&);

void main()
{
	int n,i;
	clrscr();
	printf("\n Enter Number Of Elements :");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		printf("a[%d] :",i);
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);

	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
getch();
}

void quicksort(int *a,int l,int r)
{
	int pivot,i,j;

	if(l>r)
		return;
	i=l,j=r+1,pivot=a[l];

	while(1)
	{
		do
		{
			i++;
		}while(a[i]<pivot);
		do
		{
			j--;
		}while(a[j]>pivot);

		if(i>=j)
			break;
		swap(a[i],a[j]);
	}
	a[l]=a[j];
	a[j]=pivot;

	quicksort(a,l,j-1);
	quicksort(a,j+1,r);
}

void swap(int &i,int &j)
{
	int t;
	t=i;
	i=j;
	j=t;
}


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *a;
int select(int *,int,int);
int selection(int *,int,int,int);
void swap(int &,int &);

void main()
{
	int n,i,j,k,x;
	clrscr();

	printf("\n Enter Number Of Elements :");
	scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		printf("a[%d] :",i);
		scanf("%d",&a[i]);
	}

	printf("\n Enter Position :");
	scanf("%d",&k);

	x=select(a,n,k);

	printf("\n The Elements Is : %d ",x);
getch();
}

int select(int *a,int n,int k)
{
	if(k<1 || k>n)
	{
		printf("\n ERROR");
		return(-1);
	}
	else
	{
		return(selection(a,0,n-1,k));
	}
}

int selection(int *a,int l,int r,int k)
{
	int i=l,j=r+1,pivot=a[l];
	if(l>r)
		return(a[j]);

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
	if((j-l+1)==k)
		return(pivot);


	a[l]=a[j];
	a[j]=pivot;


	if((j-l+1)<k)
	{
		return selection(a,j+1,r,k-j+l-1);
	}
	else
	{
		return selection(a,l,j-1,k);
	}
}
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}








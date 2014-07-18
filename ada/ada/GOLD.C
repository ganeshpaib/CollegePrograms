#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int maxmin(int *,int);
int max,min;

void main()
{
		int *a,n,i,x;
		clrscr();

		printf("\n Enter Number Of Elements : ");
		scanf("%d",&n);

		a=(int *)malloc(sizeof(int)*n);

		for(i=0;i<n;i++)
		{
			printf("a[%d] :",i);
				scanf("%d",&a[i]);
		}

		x=maxmin(a,n);

		if(x==1)
		{
			printf("\n The Max Value Is : %5d",a[max]);
				printf("\n The Min Value Is : %5d",a[min]);
		}
		else
		{
			printf("\n No Data");
		}
getch();
}

int maxmin(int *a,int n)
{
	int s,i;

		if(n<1)
			return(0);
		if(n==1)
		{
			max=min=0;
				return(1);
		}
		if(n%2)
		{
			max=min=0;
				s=1;
		}
		else
		{
			if(a[0]>a[1])
				{
					max=0;
					min=1;
				}
				else
				{
					max=1;
						min=0;
				}
				s=2;
		}

		for(i=s;i<n;i+=2)
		{
			if(a[i]>a[i+1])
				{
					if(a[i]>a[max]) max=i;
						if(a[i+1]<a[min]) min=i+1;
				}
				else
				{
					if(a[i]<a[min]) min=i;
						if(a[i+1]>a[max]) max=i+1;
				}
		}
		return(1);
}





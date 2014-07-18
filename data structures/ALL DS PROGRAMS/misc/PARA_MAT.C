#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int para(int);

void main()
{
	int **a,m,n,i,j,f,ctr=0;
	clrscr();

	printf("\n Enter Row Size :");
	scanf("%d",&m);
	printf("\n Enter Column Size :");
	scanf("%d",&n);

	a=(int **)malloc(sizeof(int)*m*n);

	for(i=0;i<m;i++)
	{
		*(a+i)=(int *)malloc(sizeof(int)*n);
	}

	printf("\n");

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d] :",i,j);
			scanf("%d",(*(a+i)+j));
		}
	}

	printf("\n\n");

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",*(*(a+i)+j));
			f=para(*(*(a+i)+j));
			if(f==1)
			{
				ctr++;
			}
		}
		printf("%10d",ctr);
		ctr=0;
		printf("\n");
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			f=para(*(*(a+i)+j));
			if(f==1)
			{
				ctr++;
			}
		}
		printf("\n Column [%d] : %d",i+1,ctr);
		ctr=0;
	}
getch();
}
int para(int x)
{
	int t,s=0,r;
	t=x;
	while(t>0)
	{
		r=t%10;
		s=s*10+r;
		t=t/10;
	}
	if(s==x)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}






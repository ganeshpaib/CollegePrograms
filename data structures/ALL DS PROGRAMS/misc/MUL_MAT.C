#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int **a,**b,**c,m,n,m1,n1,k,i,j,f=0;
	clrscr();

	printf("\n Enter Row Of First Matrix :");
	scanf("%d",&m);
	printf("\n Enter Column Of First Matrix :");
	scanf("%d",&n);
	printf("\n\n Enter Row Of Second Matrix :");
	scanf("%d",&m1);
	printf("\n Enter Column Of Second Matrix :");
	scanf("%d",&n1);

	a=(int **)malloc(sizeof(int)*m*n);
	b=(int **)malloc(sizeof(int)*m1*n1);
	c=(int **)malloc(sizeof(int)*m*n1);

	for(i=0;i<m;i++)
	{
		*(a+i)=(int *)malloc(sizeof(int)*n);
	}

	for(i=0;i<m1;i++)
	{
		*(b+i)=(int *)malloc(sizeof(int)*n1);
	}

	for(i=0;i<m;i++)
	{
		*(c+i)=(int *)malloc(sizeof(int)*n1);
	}

	if(n==m1)
	{
		f=1;
	}

	if(f==0)
	{
		printf("\n The Multiplication Is Not Possible ");
	}
	else
	{
		printf("\n\t Enter Elements For First Matrix\n ");

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("a[%d][%d] : ",i,j);
				scanf("%d",&a[i][j]);
			}
		}

		printf("\n\t Enter Elements For First Matrix\n ");

		for(i=0;i<m1;i++)
		{
			for(j=0;j<n1;j++)
			{
				printf("b[%d][%d] : ",i,j);
				scanf("%d",&b[i][j]);
			}
		}

		for(i=0;i<m;i++)
		{
			for(j=0;j<n1;j++)
			{
				c[i][j]=0;

				for(k=0;k<n;k++)
				{
					c[i][j]+=a[i][k]*b[k][j];
				}
			}
		}

		printf("\n");

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%5d",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		for(i=0;i<m1;i++)
		{
			for(j=0;j<n1;j++)
			{
				printf("%5d",b[i][j]);
			}
			printf("\n");
		}

		printf("\n");

		for(i=0;i<m;i++)
		{
			for(j=0;j<n1;j++)
			{
				printf("%5d",c[i][j]);
			}
			printf("\n");
		}
	}
getch();
}





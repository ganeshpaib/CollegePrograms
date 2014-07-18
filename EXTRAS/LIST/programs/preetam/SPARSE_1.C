#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

typedef struct
{
	int row;
	int col;
	int value;
}term;
int v=0,ctr=1;

term a[MAX],b[MAX];
void transpose(term *,int);

void main()
{
	int **mat,m,n,i,j;
	clrscr();

	printf("\n Enter Row Size :");
	scanf("%d",&m);
	printf("\n Enter Column Size :");
	scanf("%d",&n);

	mat=(int **)malloc(sizeof(int)*m*n);

	for(i=0;i<m;i++)
	{
		*(mat+i)=(int *)malloc(sizeof(int)*n);
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("mat[%d][%d] :",i,j);
			scanf("%d",&mat[i][j]);
			if(mat[i][j]!=0)
			{
				a[ctr].row=i;
				a[ctr].col=j;
				a[ctr].value=mat[i][j];
				v++;
				ctr++;
			}
		}
	}
	a[0].row=m;
	a[0].col=n;
	a[0].value=v;

	printf("\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("\n\t .... Structure A.......\n");

	for(i=0;i<ctr;i++)
	{
		printf("\n %d \t %d \t %d ",a[i].row,a[i].col,a[i].value);
	}

	transpose(a,v);

	printf("\n");
	printf("\n\t ........ Transpose B ....... \n");

	for(i=0;i<ctr;i++)
	{
		printf("\n %d \t %d \t %d ",b[i].row,b[i].col,b[i].value);
	}




getch();
}

void transpose(term *a,int v)
{
	int i,j,n,k;
	n=a[0].value;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=n;
	k=1;

	for(i=0;i<b[0].col;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[j].col==i)
			{
				b[k].row=a[j].col;
				b[k].col=a[j].row;
				b[k].value=a[j].value;
				k++;
			}
		}
	}
}



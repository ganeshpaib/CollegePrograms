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
	int row_term[MAX],starting_pos[MAX],i,j,n,nc;

	n=a[0].value;
	nc=a[0].col;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=n;

	for(i=0;i<nc;i++)
	{
		row_term[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		row_term[a[i].col]++;
	}
	starting_pos[0]=1;
	for(i=1;i<nc;i++)
	{
		starting_pos[i]=starting_pos[i-1]+row_term[i-1];
	}

	for(i=1;i<=n;i++)
	{
		j=starting_pos[a[i].col]++;

		b[j].row=a[i].col;
		b[j].col=a[i].row;
		b[j].value=a[i].value;
	}
}


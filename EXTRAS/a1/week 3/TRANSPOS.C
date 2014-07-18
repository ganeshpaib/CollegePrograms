#include<stdio.h>
#include<conio.h>
#define MAX 10
#define MAX_COL 10
struct sparce
{
   int row;
   int col;
   int val;
}a[MAX],b[MAX],c[MAX];
void fast_transpose(struct sparce a[],struct sparce c[])
{
  int row_term[MAX_COL],starting_pos[MAX_COL];
  int i,j,n,n_c;
  n=a[0].val;
  n_c=a[0].col;
  c[0].col=a[0].row;
  c[0].row=a[0].col;
  c[0].val=n;
  for( i=0 ; i<a[0].col ; i++)
	   row_term[i]=0;

	for(i=1;i<=n;i++)
	{
	   row_term[a[i].col]++;
	}
	starting_pos[0]=1;

	for(i=1;i<n_c;i++)
	{
		starting_pos[i]=starting_pos[i-1]+row_term[i-1];
	}
	for(i=1;i<=n;i++)
	{
		j=starting_pos[a[i].col]++;
		c[j].row=a[i].col;
		c[j].col=a[i].row;
		c[j].val=a[i].val;
	}
}
void transpose(struct sparce a[] , struct sparce b[] )
{
   int i,j,k=1;
   b[0].row=a[0].col;
   b[0].col=a[0].row;
   b[0].val=a[0].val;
   for(i=0;i<a[0].col;i++)
	 for(j=1;j<=a[0].val;j++)
		if(i==a[j].col)
		{
			 b[k].row=a[j].col;
			 b[k].col=a[j].row;
			 b[k].val=a[j].val;
			 k++;
		}

}
void main()
{
int x[10][10],i,j,k=1,m,n,count=0;
clrscr();
printf("\nenter the size of matrix:");
scanf("%d%d",&m,&n);

for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		printf("a[%d][%d]",i,j);
		scanf("%d" ,&x[i][j]);
		if(x[i][j] != 0 )
		{
		   count++;
		   a[k].row=i;
		   a[k].col=j;
		   a[k].val=x[i][j];
		   k++;
		}
	}
}
a[0].row=m;
a[0].col=n;
a[0].val=count;
	printf(" \n row \t col \tvalue:");
	for(i=0;i<=count;i++)
	{
		printf("\n%d \t %d \t%d",a[i].row,a[i].col,a[i].val);
	}
	transpose(a,b);
	printf("\nthe transpose of matrix is :");

	printf(" \n row \t col \tvalue:");
	for(i=0;i<=count;i++)
	{
			printf("\n%d \t%d \t%d",b[i].row , b[i].col , b[i].val);
	}
	fast_transpose(a,c);
	printf("\nthe transpose of matrix is :");

	printf(" \n row \t col \tvalue:");
	for(i=0;i<=count;i++)
	{
			printf("\n%d \t%d \t%d",c[i].row , c[i].col , c[i].val);
	}

	getch();

}
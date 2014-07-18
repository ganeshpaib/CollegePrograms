#include<stdio.h>
#include<conio.h>
#include<alloc.h>

void input_mat(int **mx,int a,int b)
{
	int i,j;
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			scanf("%d",*(mx+i)+j);

}

void display_mat(int **mx,int a,int b)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			printf("%5d",*(*(mx+i)+j));
		printf("\n");
	}
}

void mul(int **mx1,int **mx2,int **mx3,int a,int b,int c)
{
	int i,j,k;
	for(i=0;i<a;i++)
		for(j=0;j<c;j++)
			{
				*(*(mx3+i)+j)=0;
				for(k=0;k<b;k++)
					*(*(mx3+i)+j)=(*(*(mx3+i)+j))+(*(*(mx1+i)+k))*(*(*(mx2+k)+j));
			}
}



void main()
{
	int **mx1,**mx2,**mx3,i,j,m,n,p;
	clrscr();

	printf("\n\t\tEnter the dimensions of the first matrix  :  ");
	scanf("%d%d",&m,&n);
	mx1=(int **)malloc((sizeof(int))*m*n);
	for(i=0;i<m;i++)
		*(mx1+i)=(int *) malloc((sizeof(int))*n);

	printf("\n\tEnter the elements of first matrix : \n");
	input_mat(mx1,m,n);

	printf("\n\t\tEnter the dimensions of the second matrix  : ");
	scanf("%d%d",&n,&p);
		mx2=(int **)malloc((sizeof(int))*n*p);
	for(i=0;i<n;i++)
		*(mx2+i)=(int *)malloc((sizeof(int))*p);
	printf("\n\tEnter the elements of second matrix : \n");
	input_mat(mx2,n,p);
	mx3=(int **)malloc((sizeof(int))*m*p);
	for(i=0;i<m;i++)
		*(mx3+i)=(int *)malloc((sizeof(int))*p);
	mul(mx1,mx2,mx3,m,n,p);
	printf("\n\t\tMatrix 1\n");
	display_mat(mx1,m,n);
	printf("\n\t\tMatrix 2\n");
	display_mat(mx2,n,p);
	printf("Product of two matrix:\n");
	display_mat(mx3,m,p);
	getch();
}
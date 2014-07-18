/*program to find the transpose of a sparse matrix*/

#include<stdio.h>
#include<conio.h>
#define MAX_TERM 10

typedef struct
{
	int row,col,value;
}term;

term a[MAX_TERM];
term b[MAX_TERM];

void transpose(term a[],term b[])
{
	int i,j,k,n;
	n=a[0].value;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=n;
	k=1;
	for(i=0;i<a[0].col;i++)
		for(j=1;j<=n;j++)
			if(a[j].col==i)
			{
				b[k].row=a[j].col;
				b[k].col=a[j].row;
				b[k].value=a[j].value;
				k++;
			}
}
void display(term mx[])
{
	int i;
	printf("\n\n\trow\t\tcol\t\tvalue\n");
	for(i=0;i<=mx[0].value;i++)
		printf("\n\t%d\t\t%d\t\t%-3d",mx[i].row,mx[i].col,mx[i].value);
}

void main()
{
	int i,j,num,k;
	clrscr();
	printf("\nEnter the number of rows : ");
	scanf("%d",&a[0].row);
	printf("\nEnter the number of columns : ");
	scanf("%d",&a[0].col);
	printf("\nEnter the  elements of the matrix: \n\n\n");
	a[0].value=0;
	for(i=0;i<a[0].row;i++)
	{
		for(j=0;j<a[0].col;j++)
		{
			printf("\t\ta[%d][%d] = ",i,j);
			scanf("%d",&num);
			if(num!=0)
			{       a[0].value++;
				k=a[0].value;
				a[k].value=num;
				a[k].row=i;
				a[k].col=j;
			}
		}
	}
	getch();
	clrscr();
	printf("\n\n\nEntered sparse matrix is : ");
	display(a);
	transpose(a,b);
	getch();
	clrscr();
	printf("\n\n\nTranspose : ");
	display(b);
	getch();
}
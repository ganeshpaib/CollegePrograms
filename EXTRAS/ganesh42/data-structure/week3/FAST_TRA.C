/*program to find the transpose of a sparse matrix*/

#include<stdio.h>
#include<conio.h>
#define MAX_TERM 10
#define MAX_COL 10

typedef struct
{
	int row,col,value;
}term;
term a[MAX_TERM];
term b[MAX_TERM];

void fast_transpose(term a[],term b[])
{
	int i,j,n_c,n;
	int row_terms[MAX_COL],starting_pos[MAX_COL];
	n=a[0].value;
	n_c=a[0].col;
	b[0].row=n_c;
	b[0].col=a[0].row;
	b[0].value=n;

	for(i=0;i<n_c;i++)
		row_terms[i]=0;
	for(i=1;i<=n;i++)
		row_terms[a[i].col]++;
	starting_pos[0]=1;
	for(i=1;i<n_c;i++)
		starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
	for(i=1;i<=n;i++)
	{
		j=starting_pos[a[i].col]++;
		b[j].row=a[i].col;
		b[j].col=a[i].row;
		b[j].value=a[i].value;
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
	int i,j,k,num;
	clrscr();
	printf("\nEnter the number of rows : ");
	scanf("%d",&a[0].row);
	printf("\nEnter the number of columns : ");
	scanf("%d",&a[0].col);
	a[0].value=0;
	printf("\nEnter the elements : \n");
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
	fast_transpose(a,b);
	getch();
	clrscr();
	printf("\n\n\nTranspose : ");
	display(b);
	getch();
}
#include<stdio.h>
#include<conio.h>
#define max_term 10
typedef struct
{
	int row;
	int col;
	int value;
}term;
term a[max_term],b[max_term];
void transp(term [],term []);
main()
{
	int row1,col1,mat[10][10],i,j,k=1;
	clrscr();
	printf( "Enter the order of matrix\n" );
	scanf( "%d%d",&row1,&col1);
	a[0].row=row1;
	a[0].col=col1;


	printf( "Enter the elements of the matrix\n" );
	for(i = 0; i  < row1; i++ )
	{
		for(j = 0; j < col1; j++ )
		{
			printf( "mat[%d][%d]= ",i,j);
			scanf( "%d",&mat[i][j]);
			if(mat[i][j]>0)
			{
				a[k].col=j;
				a[k].row=i;
				a[k].value=mat[i][j];
				k++;
			}
		}
	}
	a[0].value=k-1;
	printf( "Entered elements of the matrix are\n" );
	for(i = 0; i  < row1; i++ )
	{
		for(j = 0; j < col1; j++ )
		{
			printf( "%d ",mat[i][j]);

		}
		printf( "\n" );
	}

	printf( "Non zero elements are : \n" );
	for( i = 1 ; i  < k; i++ )
		printf( "%d\n",a[i].value);

	transp(a,b);
getch();
}

void transp(term a[],term b[])
{
	int i, j, k=0, n;
	/*printf( "%d%d%d",a[0].row,a[0].col,a[0].value);*/
	n=a[0].value;
	b[0].value=n;
	b[0].row=a[0].col;
	b[0].col=a[0].row;

	for(i = 0; i < a[0].col; i++ )
	{
		for( j =1; j <= n; j++ )
		{
			if(a[j].col==i)
			{
				b[k].row=a[j].col;
				b[k].col=a[j].row;
				b[k].value=a[j].value;

				printf( "ROW\tCOL\t\VALUE\n" );
				printf( "%d\t%d\t%d\n",b[k].row,b[k].col,b[k].value);
				k++;
			}
		}
	}

}




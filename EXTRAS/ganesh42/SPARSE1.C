#include<stdio.h>
#include<conio.h>
#define max_term 10

typedef struct
{
	int row;
	int col;
	int value;
}term;
term mat1[max_term],mat2[max_term];
void transp(term [],term []);
main()
{
	int matrix[10][10],i,j,k=1,row1,col1;
	clrscr();

	printf( "Enter the order of the matrix\n" );
	scanf( "%d%d",&row1,&col1);

	mat1[0].row=row1;
	mat1[0].col=col1;

	printf( "Enter the elements of the matrix\n" );
	for(i = 0; i < row1; i++ )
	{
		for( j = 0; j < col1; j++ )
		{
			printf( "MAT[%d][%d]= ",i,j );
			scanf( "%d",&matrix[i][j] );
			if(matrix[i][j] > 0 )
			{
				mat1[k].row=i;
				mat1[k].col=j;
				mat1[k].value=matrix[i][j];
				k++;
			}
		}
	}
	mat1[0].value=k-1;

	printf( "Entered elements of the matrix are :\n" );
	for( i = 0; i < row1; i++ )
	{
		for( j = 0; j < col1; j++ )
		{
			printf( "%5d",matrix[i][j]);
		}
		printf( "\n" );
	}

	printf( "Non zero elements are : \n" );
	for(j = 1; j < k; j++ )
	{
		printf( "%d\n",mat1[j].value);
	}

	transp(mat1,mat2);

	getch();
}



void transp(term mat1[],term mat2[])
{
	int k=1,i,j,n;
	n=mat1[0].value;
	mat2[0].value=n;
	mat2[0].col=mat1[0].row;
	mat2[0].row=mat1[0].col;

	printf( "\nROW\tCOL\tVALUES\n" );
	for( i = 0; i < mat1[0].col; i++ )
	{
		for(j = 1; j <=n; j++ )
		{
			if( mat1[j].col==i)
			{
				mat2[k].row=mat1[j].col;
				mat2[k].col=mat1[j].row;
				mat2[k].value=mat1[j].value;

				printf( "%d\t%d\t%d\n",mat2[k].row,mat2[k].col,mat2[k].value );
				k++;
			}
		}
	}
}
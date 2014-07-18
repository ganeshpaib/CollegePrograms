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
void fast_transp(term [],term []);
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

	fast_transp(mat1,mat2);

	getch();
}

void fast_transp(term mat1[],term mat2[])
{

	int row_terms[max_term],st_pos[max_term],n,i,j=1;

	n=mat1[0].value;
	mat2[0].row=mat2[0].col;
	mat2[0].col=mat2[0].row;
	mat2[0].value=n;

	for( i = 0; i < mat1[0].col; i++ )
	{
		row_terms[i]=0;
	}

	for( i = 1; i <= n; i++ )
	{
		row_terms[mat1[i].col]++;
	}

	st_pos[0]=1;
	printf( "ROW\tCOL\tVALUE\n" );
	for(i = 1; i <= mat1[0].col; i++ )
	{
		st_pos[i] = st_pos[i-1] + row_terms[i-1];
	}

	for( i =1; i <= n; i++ )
	{
		j=st_pos[mat1[i].col]++;
		mat2[j].row=mat1[i].col;
		mat2[j].col=mat1[i].row;
		mat2[j].value=mat1[i].value;
		printf( "%d\t%d\t%d\n",mat2[j].row,mat2[j].col,mat2[j].value );
		j++;
	}
}
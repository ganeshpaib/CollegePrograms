/*
	PRIMS
*/

#include<stdio.h>
#include<conio.h>

struct vertex
{
	int stvertex, endvertex;
}v[10];

static int z;
int n, i, j, ans=1,flg=0,count=0,val,min, mat[10][10],lowest[10],closest[10];
void input();
void disp();
void init_lowest(int);
int init_closest(int);

void main()
{

	clrscr();
	input();
	disp();
  //	while(count!=n-1)
	{


	}

		printf( "\n\n");
		printf( "RESULT : \n\n" );

		for(i=0;i<z;i++)
			printf( "%d\t%d\n",v[i].stvertex,v[i].endvertex);
	getch();
}

void disp()
{
	for( i = 1; i <= n; i++ )
	{
		printf( "\n\n" );

		for(j = 1; j <=n; j++ )
		{
			printf( "%5d",mat[i][j] );
		}
	}
}


void input()
{
	printf( "Enter the order of matrix : " );
	scanf( "%d",&n );

	printf( "Enter the elements of the matrix : " );
	for( i = 1; i <= n; i++ )
	{
		for( j = 1; j <= n; j++ )
		{
			printf( "\nmat[%d][%d] = ",i,j );
			scanf( "%d",&mat[i][j] );
		}
	}
}
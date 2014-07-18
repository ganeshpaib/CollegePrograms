#include<stdio.h>
#include<conio.h>

int count=0,mat[10][10],indegree[10],i,j,n,ans=0,visited[10];
void input_mat();
void disp_mat();
int calc();

void main()
{
	clrscr();
	printf( "ENTER INPUT MATRIX\n" );
	input_mat();
	disp_mat();

	for(i = 1; i <= n; i++ )
	{
		count=0;
		for( j = 1; j <= n; j++ )
		{
			if(mat[j][i]>0)
			{
				count++;
			}
		}
		indegree[i]=count;
	}

	printf( "\n\nINDEGREE : \n" );
	for( i=1; i <= n; i++ )
		printf("%d\t",indegree[i]);

		printf ("\n\n" );

	ans=calc();
	if(ans==-1)
		printf( "NOT TOPOLOGY\n" );
	getch();
}

int ctr=0;

int calc()
{
	int flg=0;
	for(i = 1; i <= n; i++ )
	{
		if((indegree[i]==0)&&(visited[i]!=1))
		{
			visited[i]=1;
			printf( "%d\t",i );
			ctr++;
			flg=1;
			break;
		}
	}
	for(j = 1; j <=n; j++ )
	{
		if(mat[i][j]>0)
		{
			indegree[j]-=1;
		}
	}

	if(ctr==n)
		return 1;
	else if(flg==0)
		return -1;
	else
		return(calc());


}



void input_mat()
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

void disp_mat()
{
	printf( "\n\nINPUT MATRIX :\n\n" );

	for( i = 1; i <= n; i++ )
	{
		for( j = 1; j <= n; j++ )
		{
			printf( "%d\t",mat[i][j] );
		}
		printf( "\n" );
	}
}
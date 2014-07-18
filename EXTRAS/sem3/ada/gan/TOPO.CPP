/*
	TOPOLOGICAL SORTING
*/

#include<stdio.h>
#include<conio.h>
#include<process.h>

int mat[10][10], indegree[20],visited[20],v[20],z=0,i,j,k,order,count=0,flag=0;
int calc();

void main()
{
	int z,ans;
	clrscr();

	printf( "\nEnter the order of input matrix : " );
	scanf( "%d",&order );

	for( i = 0; i < order; i++ )
	{
		for( j = 0; j < order; j++ )
		{
			printf( "mat[%d][%d] = ",i,j );
			scanf( "%d",&mat[i][j] );
		}
	}
	for( i = 0; i < order; i++ )
	{
		for( j = 0; j < order; j++ )
		{
			if(mat[j][i]==1)
				count++;
		}
		indegree[i]=count;
		count=0;
	}

	getch();
	clrscr();

	printf( "INPUT : \n\n" );

	for( i = 0; i < order; i++ )
	{
		for( j = 0; j < order; j++ )
		{

			printf( "%d\t",mat[i][j] );

		}
		printf( "\n\n\n" );
	}

	printf( "\n\nINDEGREE : " );
	for( i = 0; i < order; i++ )
	{
		printf( "%d\t",indegree[i] );
	}

	for(i=0;i<order;i++)
	{
		if(indegree[i]==0)
		{
			flag=1;
			break;
		}
		else
			flag=0;
	}
	if(flag==0)
	{
		printf( "\n\n\n\n\nNOT A TOPOLOGY\n" );
		getch();
	}

	else
	{
		for( i =0; i < order; i++ )
		{
			visited[i]=0;
		}

		getch();
		clrscr();

		printf( "\n\n\t" );

		ans=calc();
		if(ans==1)
		{
			for( i = 0; i < order; i++)
				printf( "%d\t",v[i]+1 );
		}
		else
		{
			printf( "Not a topology" );
		}
	}

	getch();
}

int inc=0,l=0;

int calc()
{

	for( i = 0; i < order; i++ )
	{
		if(visited[i]!=1)
		{
			if(indegree[i]==0)
			{
				inc++;
				v[l]=i;
				l++;
					visited[i]=1;
				for( j = 0; j < order; j++ )
				{
					if(mat[i][j]==1)
					{
						indegree[j]=indegree[j]-1;
					}
				}
			}
		}
	}

	if(inc==order)
		return(1);
	else
		return(calc());
}





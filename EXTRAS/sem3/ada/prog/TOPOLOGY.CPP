/*
	TOPOLOGICAL SORTING
*/

#include<stdio.h>
#include<conio.h>
#include<process.h>

int mat[10][10], indegree[20],visited[20],v[20],z=0,i,j,k,order,count=0,flag=0;
void calc();

void main()
{
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
		exit(0);
	}

	calc();
	getch();
	clrscr();

	printf( "\n\n\t" );

	printf( "RESULT : \n\n\t" );
	for(i=0;i<z;i++)
		printf( "%d\t",v[i]+1 );

	getch();
}

int flg=0;
void calc()
{
	for( i =0; i < order; i++ )
	{
		visited[i]=0;
	}

   cal :for(i=0;i<order;i++)
		{
			if(visited[i]==0)
			{
				if(indegree[i]==0)
				{
					v[z]=i;
					visited[i]=1;
					z++;
					break;
				}
			}
		}


		for( k = 0; k < order; k++ )
		{
			if(mat[i][k]>0)
			{
				indegree[k]=indegree[k]-1;
			}
		}
		for(i = 0; i < order; i++ )
		{
			if(visited[i]!=1)
			{
				flg=1;
				break;
			}
			else
				flg=0;
		}
		if(z!=order&&flg==0)
		{
			printf( "NOT TOPOLOGY" );
			exit(0);
		}


		if(z!=order)
			goto cal;

}

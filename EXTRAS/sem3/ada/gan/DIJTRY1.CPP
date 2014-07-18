/*

	DIJKSTRA'S PROBLEM
*/

#include <stdio.h>
#include<conio.h>

void input();
void initialize();
int dmin();
int findj(int);
void findl();

int n, i, j, k=1,prevdj,flag=0, mat[10][10],d[10],p[10],l[10],min,visited[10];

void main()
{
	clrscr();
	printf( "\n" );
	input();
	initialize();

	while(1)
	{
		min=dmin();
		visited[min]=1;
		flag=0;
		for( i = 1; i <=n; i++ )
		{
			if((mat[min][i]>0)&&(visited[i]==0))
			{
				j=i;
				flag=1;
				prevdj=d[j];

					if( d[j] > 0)
					{
						if(d[j]<(d[min]+mat[min][j]))
							d[j]=d[j];

						else
							d[j]=(d[min]+mat[min][j]);
					}
					else
						d[j]=(d[min]+mat[min][j]);

				if(prevdj!=d[j])
					p[j]=min;
			}
		}
		if((flag==0)&&(i==(n+1)))
			break;

		findl();

	}
	printf( "\n RESULT : " );

	for( i = 1; i <= n; i++ )
		printf( "%d\t",p[i] );

	getch();
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

void initialize()
{
	printf( "\n" );
	for( i = 1; i <= n; i++ )
	{

		if( mat[1][i] > 0 )
		{
			p[i]=1;
			l[k]=i;
			k++;
		}
		else
		{
			p[i]=0;

		}

	}
	for( i = 1; i <= n; i++ )
		d[i]=mat[1][i];

	for( i =1; i <=k; i++ )
		visited[i]=0;
}

int dmin()
{
	min=100;
	for( i = 1; i <= n; i++ )
	{
		if( d[i] > 0 )
		{
			if((min > d[i])&&(visited[i]!=1) )
			{
				min=d[i];
			}
		}
	}
	for( i = 1; i <= n; i++ )
	{
		if(d[i]==min)
		{
			break;
		}
	}
	return i;
}

void findl()
{
	int c=0;
	for( i =1; i <= n; i++ )
	{
		if( (d[i] > 0) && visited[i]==0 )
		{
			l[c]=i;
			c++;
		}
	}
}
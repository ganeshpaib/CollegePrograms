#include <stdio.h>
#include <conio.h>
#include <process.h>

void input_mat();
void disp_mat();
int mat[10][10],c[10][10],i,j,order,ctr=0,h,cost[10],k=1,x,y,p[10];
int find(int e);

void main()
{
	clrscr();

	printf( "Enter the input matrix : \n" );
	printf( "\nEnter the order of the matrix : " );
	scanf( "%d",&order );

	input_mat();
	disp_mat();

	for( h = 1; h <= k; h++ )
	{
		for( i = 1; i <= order; i++ )
		{
			for( j = 1; j <= order; j++ )
			{
				if(c[i][j]==cost[h])
				{
					x=find(i);
					y=find(j);

					if(x!=y)
					{
						p[j]=i;
						printf( "\n%d,%d",i,j);
					}
				}
			}
		}
	}
	getch();
}




void input_mat()
{
	int temp;

	for( i = 1; i <= order; i++ )
	{
		for( j = 1; j <= order; j++ )
		{
			printf( "\nmat[%d][%d] = ",i,j );
			scanf( "%d",&mat[i][j]);
			if(mat[i][j]==1)
			{
				if(i<j)
				{
					printf( "\nEnter the cost : " );
					scanf( "%d",&c[i][j]);
					cost[k]=c[i][j];
					k++;
				}
				else
					c[i][j]=-1;
			}
			else if(i==j)
				c[i][j]=0;
			else
				c[i][j]=-1;

		}
	}
	k--;
	for( i = 1; i < k; i++ )
	{
		for( j = i+1; j <= k; j++ )
		{
			temp=cost[i];
			cost[i]=cost[j];
			cost[j]=temp;
		}
	}

}

void disp_mat()
{
	printf( "\n\nINPUT MATRIX :\n\n" );

	for( i = 1; i <= order; i++ )
	{
		for( j = 1; j <= order; j++ )
		{
			printf( "%d\t",mat[i][j] );
		}
		printf( "\n" );
	}
}

int find(int e)
{
	while(p[e]!=0)
		e=p[e];
	return e;
}
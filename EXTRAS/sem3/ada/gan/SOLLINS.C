#include<stdio.h>
#include<conio.h>

void input();
void disp();
int i, j, k, n, mat[10][10], cost[10][10];

void main()
{
	input();
	disp();
	cal();
	getch();
}
void input()
{
	printf("\nENTER THE SIZE : ");
	scanf("%d",&n);
	printf("\nENTER THE ELEMENTS");
	k=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("mat[%d][%d] = ",i,j);
			{
				scanf("%d",&mat[i][j]);
				if(mat[i][j]==1)
				{
					if(i<j)
					{
						printf("\n  ENTER THE COST : ");
						scanf("%d",&cost[i][j]);
						k++;
					}
					else
					cost[i][j]=-1;

				}
				else
				{
					if(i==j)
						cost[i][j]=0;
					else
						cost[i][j]=-1;
				}
			}
		}
		clrscr();
	}
}

void disp()
{
	for( i = 1; i <= n; i++ )
	{
		printf( "\n\n" );

		for(j = 1; j <=n; j++ )
		{
			printf( "%5d",cost[i][j] );
		}
	}
}



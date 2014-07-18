#include "header.cpp"

int size,i,j,k,mat[10][10],cost[10][10],b[10];
void input()
{
	printf("\nENTER THE SIZE : ");
	scanf("%d",&size);
	printf("\nENTER THE ELEMENTS");
	k=1;
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
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
						b[k]=cost[i][j];
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
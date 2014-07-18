#include<stdio.h>
#include<conio.h>
#define max 20

int r[max],kay[max][max],c[max][max];

void chain(int);
void traceback(int,int);

void main()
{
	int i,q,n;
	clrscr();
	printf("\n Number Of Matrix :");
	scanf("%d",&q);

	for(i=1;i<=q+1;i++)
	{
		printf("r[%d] :",i);
		scanf("%d",&r[i]);
	}
	chain(q);
	printf("\n\n Total Computation : %5d",c[1][5]);
	printf("\n\n Kay Value : %5d",kay[1][q]);

	traceback(1,q);
getch();
}

void chain(int q)
{
	int i,s,k,j,t;
	for(i=1;i<q;i++)
	{
		c[i][j]=0;
		c[i][i+1]=r[i]*r[i+1]*r[i+2];
		kay[i][i+1]=i;
	}
	c[q][q]=0;

	for(s=2;s<q;s++)
	{
		for(i=1;i<=q-s;i++)
		{
			c[i][i+s]=c[i][i]+c[i+1][i+s]+r[i]*r[i+1]*r[i+s+1];
			kay[i][i+s]=i;

			for(k=i+1;k<i+s;k++)
			{
				t=c[i][k]+c[k+1][i+s]+r[i]*r[k+1]*r[i+s+1];

				if(t<c[i][i+s])
				{
					c[i][i+s]=t;
					kay[i][i+s]=k;
				}
			}
		}
	}
}

void traceback(int i,int j)
{
	if(i==j) return;
	traceback(i,kay[i][j]);
	traceback(kay[i][j]+1,j);
	printf("\n\n M[%d][%d] * M[%d][%d] = M[%d][%d]",i,kay[i][j],kay[i][j]+1,j,i,j);
}


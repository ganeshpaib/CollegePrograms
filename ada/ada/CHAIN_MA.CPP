#include<stdio.h>
#include<conio.h>
#define max 20

int r[max],kay[max][max];

int c(int,int);
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
	n=c(1,q);
	printf("\n\n Total Computation : %5d",n);
	printf("\n\n Kay Value : %5d",kay[1][q]);

	traceback(1,q);
getch();
}

int c(int i,int j)
{
	int k,u,t;

	if(i==j)
	{
		return(0);
	}
	if(i==(j-1))
	{
		kay[i][i+1]=i;
		return(r[i]*r[i+1]*r[i+2]);
	}
	u=c(i,i)+c(i+1,j)+r[i]*r[i+1]*r[j+1];
	kay[i][j]=i;

	for(k=i+1;k<j;k++)
	{
		t=c(i,k)+c(k+1,j)+r[i]*r[k+1]*r[j+1];

		if(t<u)
		{
			u=t;
			kay[i][j]=k;
		}
	}
	return (u);
}

void traceback(int i,int j)
{
	if(i==j) return;
	traceback(i,kay[i][j]);
	traceback(kay[i][j]+1,j);
	printf("\n\n M[%d][%d] * M[%d][%d] = M[%d][%d]",i,kay[i][j],kay[i][j]+1,j,i,j);
}


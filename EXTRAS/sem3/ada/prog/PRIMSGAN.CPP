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
int init_closest();

void main()
{

	clrscr();
	input();
	disp();
	while(count!=n-1)
	{
		val=ans;
		init_lowest(val);
		ans=init_closest();
		count++;

	}

		printf( "\n\n");
		printf( "RESULT : \n\n" );

		for(i=0;i<z;i++)
			printf( "%d\t%d\n",v[i].stvertex,v[i].endvertex);
	getch();
}

void init_lowest(int i)
{
   int	k=1;
   if(flg==0)
	{
		for( j = 1; j <=n; j++ )
		{
			lowest[k]=mat[i][j];
			if((mat[i][j]>0)&&(mat[i][j]<999))
				closest[k]=i;
			else
				closest[k]=0;

			k++;
			flg=1;
		}
	}
	else
	{
		k=2;
		for( j = 2; j <=n; j++ )
		{
			if((lowest[k]<1000)&&(lowest[k]>0)&&(mat[i][j]>0)&&(lowest[k]>mat[i][j]))
			{
				lowest[k]=mat[i][j];
				closest[k]=i;
			}

			k++;
		}
	}
}

int init_closest()
{

	min=100;
	for(j=1;j<=n;j++)
	{

		if((lowest[j]>0)&&(min>lowest[j]))
		{
			min=lowest[j];
		}
	}
	for(j=1;j<=n;j++)
	{
		if(min==lowest[j])
		{
			lowest[j]=1000;
			break;
		}
	}
	v[z].stvertex=closest[j];
	v[z].endvertex=j;
	z++;
	return j;

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
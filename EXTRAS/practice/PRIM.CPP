#include "header.cpp"

void input_mat();
void disp_mat();
void init_lowest(int);
int init_closest();

int val,ans=1,flg=0,k,count=0,n,i,j,closest[10],low[10],mat[10][10];
void main()
{

	printf( "Enter the input matrix: \n" );
	input_mat();
	disp_mat();

	while((count)!=(n-1))
	{
		val=ans;
		init_lowest(val);
		ans=init_closest();
		count++;
	}


	getch();
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

void init_lowest(int val)
{
	if(flg==0)
	{
		k=1;
		for( i = 1; i <= n; i++ )
		{
			flg=1;
			low[k]=mat[1][i];
			if((mat[1][i]>0)&&(mat[1][i]<999))
				closest[k]=1;
			else
				closest[k]=0;
			k++;
		}
	}
	else
	{
		k=2;
		for( i = 2; i <= n; i++ )
		{
			if((mat[val][i]>0)&&(mat[val][i]<999)&&(low[i]>mat[val][i])&&(low[i]>0))
			{
				low[k]=mat[val][i];
				closest[k]=val;
			}
		}
	}
}

int init_closest()
{
	int min=100;
	for( i = 1; i <= n; i++ )
	{
		if((min>low[i])&&(low[i
		{
			min=low[i];
		}
	}

	for( j = 1; j <= n; j++ )
	{
		if(low[j]==min)
		{
			low[j]=1000;
			break;
		}
	}
	printf( "%d,%d",closest[j],j);
	return j;
}
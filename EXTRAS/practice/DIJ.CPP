#include "header.cpp"
int n,k=1,i,j,flg=0,min,mat[10][10],p[10],d[10],l[10],visited[10],m=1;
void input_mat();
void disp_mat();
void initialize();
int dmin();
void main()
{
	clrscr();
	printf( "Enter the input matrix :\n" );
	input_mat();
	disp_mat();
	initialize();

	while(1)
	{
		min=dmin();
		visited[min]=1;
		flg=0;

		for(i = 1; i <= n; i++ )
		{
			if((mat[min][i]>0)&&(visited[i]!=1))
			{
				flg=1;
				j=i;
				prevj=d[j];

				if((d[j]>0)&&(d[j]<(d[min]+mat[min][i])))
				{
					d[j]=d[j];
				}
				else

					d[j]=d[min]+mat[min][i];

				if(prevj!=d[j])
					p[i]=
			}
		}
		if((i==n+1)||(flg==0))
			break;
		findl();


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

void initialize()
{


		for( j = 1; j <= n; j++ )
		{
			if( mat[1][j] > 0 )
			{
				p[k]=1;
				l[m]=j;
				k++;
				m++;
			}
			else
			{
				p[k]=0;

				k++;
			}
		}


	for( i = 1; i <= n; i++ )
	{
		d[i]=mat[1][i];
		visited[i]=0;
	}

	printf( "INITIALIZE VALUES: \n" );
	for( i = 1; i <= n; i++ )
	{
		printf( "%d\t",d[i]);
	}
	printf("\n\n\n");
	for( i = 1; i < k; i++ )
	{
		printf( "%d\t",p[i]);
	}
	printf("\n\n\n");
	for( i = 1; i < m; i++ )
	{

		printf( "%d\t",l[i]);
	}
}

int dmin()
{
	int min=100;
	for( i = 1; i < k; i++ )
	{
		if((min>d[i])&&(d[i]>0))
		{
			min=d[i];
		}
	}

	for(i = 1;i < k; i++ )
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
	int z=1;

	for(i = 0; i < k; i++)
	{
		if((d[i]>0)&&(visited[i]!=1))
		{
		   l[z]=i;
		}
	}
}
/*
	Container loading problem
*/

#include<stdio.h>
#include<conio.h>

main()
{
	int n,i,a[10],rank[10],min,eq,j,q=0,x[10],cap,sum=0;
	clrscr();

        printf( "Enter the capacity : " );
	flushall();
	scanf( "%d",&cap );
	printf( "Enter the number of elements u wanna enter.....: " );
	scanf( "%d",&n );


	printf( "\nEnter the elements...: \n" );
	for(i = 0; i < n; i++)
	{
		printf( "a[%d]= ",i );
		flushall();
		scanf( "%d",&a[i] );
		x[i]=0;
	}



	i=0;
	while( i < n )
	{
		rank[i]=0;
		min=0;
		eq=0;

		for( j = 0; j < n; j++ )
		{

			if( a[i] > a[j] )
				min++;
			while(q < i)
			{
				if( a[i] == a[q] )
				eq++;
				q++;
			}
		}
		rank[i]=min+eq;
		i++;
		q=0;
	}

	j=0;
	for(i = 0 ; i < n; i++ )
	{
		j=0;
		while(j<n)
		{
			if(rank[j]==i)
			{
				if(sum<=cap)
				{
					sum=sum+a[j];
					if(sum<=cap)
						x[j]=1;
				}

			}
			j++;
		}

	}

	printf( "\n\nOUTPUT :"  );
	printf( "\n\n" );
	for(i=0;i<n;i++)
		printf( "%d\t ",a[i] );

	printf( "\n\n" );
    for(i=0;i<n;i++)
		printf( "%d\t ",x[i] );

	getch();
}
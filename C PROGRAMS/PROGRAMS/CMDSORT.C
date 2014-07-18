#include<stdio.h>
#include<conio.h>
main(int argc,char *argv[])
{
	int a[10],k=0,i;

	for( i = 1; i < argc; i++ )
	{
		strcpy(a[k],argv[i]);
		k++;
	}

	for(i = 0; i < k; i++ )
	{
		printf( "%s",a[k]);
	}


}
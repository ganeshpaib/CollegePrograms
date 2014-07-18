#include<stdio.h>

int main()
{
	static int i=5;
	int j=9;

	if(--i)
	{
		printf( "%d\n",i);
		main();
		printf( "%d\n",j );
	}
	return 0;
}
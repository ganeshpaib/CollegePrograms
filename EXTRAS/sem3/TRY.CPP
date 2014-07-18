#include<stdio.h>
#include<conio.h>

int main()
{
	static int i = 5;

	if(--i)
	{
		printf( "%d\n",main());
		printf("%d",i);
	}
	return 0;
	getch();
}
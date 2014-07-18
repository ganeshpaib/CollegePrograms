#include <stdio.h>
int function()
{
printf("function called before main.\n");
return 10;
}
static int x= function();

int main()
{
	printf( "%d",x );
printf("Main function.\n");
return 0;
}

#include<stdio.h>
#include<conio.h>

long int fact(long int num)
{
	int k;

	if((!num)||(num==1))
		return 1;
	k=num;

	while(--num)
		k*=num;
	return k;
}

int main()
{
	long int n,r;
	int i;
	printf("Enter the number of lines of the Pascal's triangle:");
	scanf("%ld",&n);

	for(i=0;i<n;printf("\n"),i++)
		for(r=-(n-i);r<=i;r++)
			r<0?printf(" "" "" "):printf("%6ld",fact(i)/(fact(r)*fact(i-r)));

	getch();
	return 1;
}
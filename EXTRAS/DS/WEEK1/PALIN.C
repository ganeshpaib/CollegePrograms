#include<stdio.h>
#include<conio.h>
int stack[10],top=-1,i;
void push(int *,char[],int);
main()
{

	int j=0,flg=0;
	char str[20],ch;
	clrscr();

	printf( "Enter the string\n" );
	scanf( "%s",str);
	i=0;
	while(str[i]!='\0')
	{
		push(&top,str,i);
		i++;
	}


	while(str[j]!='\0')
	{
		if(str[j]!=stack[top--])
		{
			flg=1;
			break;
		}
	  j++;
	}

	if(flg==1)
		printf( "NOT PALINDROME\n" );
	else
		printf( "PALINDROME\n" );
	getch();
}

void push(int *top,char str[],int i )
{
	stack[++(*top)]=str[i];
}



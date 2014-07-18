#include<stdio.h>
#include<conio.h>
#include<process.h>

class Swapp
{
	public:

	int num1, num2;
	char ch1, ch2;
	float fnum1, fnum2;

		void swapi(int );
		void swapi(char, char);
		void swapi(float, float);
}s,t;

void main()
{
	int ch,num1,num2;

	printf( "1 -> Integer Swapping\n" );
	printf( "2 -> Charecter Swapping\n" );
	printf( "3 -> Float Swapping\n" );
	printf( "99 -> Exit\n" );

	printf( "Enter ur choice......... :" );
	scanf( "%d",&ch );

	switch(ch)
	{
		case 1: printf( "Enter the value of num1 : " );
				scanf( "%d",&num1);

				printf( "Enter the value of num2 : " );
				scanf( "%d",&s.num2);

				t.swapi(s);
				printf( "Num 1: %d\t\t Num 2: %d\n",s.num1,s.num2 );
				break;

		case 99: exit(0);
	}
	getch();
}

void Swapp::swapi( s)
{
	 int temp;
	 temp=s.num1;
	 s.num1=s.num2;
	 s.num2=temp;
}
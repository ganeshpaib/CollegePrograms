#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	clrscr();
	int i=15;
	cout.setf(ios::hex,ios::basefield);
	cout.setf(ios::uppercase);
	cout.setf(ios::showbase);

	cout<<i;
getch();
}


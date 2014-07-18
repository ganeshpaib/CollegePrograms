#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class  A
{
	int a;
	public:
		class B
		{
			int b;
			public:
				void display()
				{
					cout<< "second class: ";
				}
		}b;
	void display()
	{
		cout<< "first class: ";
	}
}a;

void main()
{
	clrscr();
	a.display();
	a.b.display();
	getch();
}
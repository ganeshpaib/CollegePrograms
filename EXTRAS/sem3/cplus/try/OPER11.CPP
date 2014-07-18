#include <stdio.h>
#include "header.cpp"

class Complex
{
	int real, imag;
	public:
		void get()
		{
			cout << "\nEnter real : ";
			cin >> real;

			cout << "\nEnter float : ";
			cin >> imag;
		}
		void disp()
		{
			cout <<endl<<real<<"+"<<imag<<"i";
		}
		void operator +=(Complex s2)
		{
			real=real+s2.real;
			imag=imag+s2.imag;
		}
};

void main()
{
	clrscr();
	Complex c1, c2, c3;
	c1.get();
	c2.get();
	c1.disp();
	c2.disp();
	c3=c1;
	c3+=c2;
	c3.disp();
	getch();
}

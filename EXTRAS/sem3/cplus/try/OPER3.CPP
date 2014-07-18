#include "header.cpp"

class Complex
{
	int real, imag;
	public:
		Complex()
		{
			real=0;
			imag=0;
		}
		Complex(int r,int i)
		{
			real=r;
			imag=i;
		}
		Complex operator+(Complex c2)
		{
			return Complex(real+c2.real,imag+c2.imag);
		}
		void show()
		{
			cout<< real<<"+"<<imag<<"i";
		}
};

void main()
{
	clrscr();
	Complex c1,c2(2,3),c3(3,5);
	c1=c2+c3;
	cout<<"\n\nc1 : ";
	c1.show();
	cout<<"\n\nc2 : ";
	c2.show();
	cout<<"\n\nc3 : ";
	c3.show();
	getch();
}


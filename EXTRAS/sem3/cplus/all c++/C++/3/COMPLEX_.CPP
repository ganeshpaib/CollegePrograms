#include<iostream.h>
#include<conio.h>

class Complex
{
	int r,i;
	public:
		Complex()
		{
			r=i=0;
		}
		Complex(int r,int i)
		{
			this->i=i;
			this->r=r;
		}
		Complex add(int,Complex);
		Complex add(Complex,Complex);
		void read();
		void display();
};

void Complex::read()
{
	cout<<"\n Enter Real Part : ";
	cin>>r;
	cout<<"\n Enter Imaginary Part : ";
	cin>>i;
}

void Complex::display()
{
	cout<<"\n"<<r<<" + i "<<i<<endl;
}

Complex Complex::add(int n,Complex c)
{
	return Complex((n+c.r),c.i);
}

Complex Complex::add(Complex c,Complex c1)
{
	return Complex((c.r+c1.r),(c1.i+c.i));
}

void main()
{
	int n;
	Complex c1,c2,c3;
	clrscr();
	cout<<"\n Enter Integer Number : ";
	cin>>n;
	cout<<"\n Enter First Complex Number \n";
	c1.read();
	c3=c3.add(n,c1);
	c3.display();
	cout<<"\n Enter Second Complex Number \n";
	c2.read();
	c3=c3.add(c1,c2);
	c3.display();
getch();
}






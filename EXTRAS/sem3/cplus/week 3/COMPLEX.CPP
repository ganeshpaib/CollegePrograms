#include<conio.h>
#include<iostream.h>
#include<process.h>

class Complex
{
	int real,imag;
	public:
		void get_data()
		{
			cout << "\nReal : ";
			cin >> real;

			cout << "\nImag : ";
			cin >> imag;
		}
		void disp_data()
		{
			cout << real<< "+" <<imag<<"i";
		}

		void add(int num,Complex c1)
		{
			 this->real=num+c1.real;
			 this->imag=c1.imag;
		}

		void add(Complex c1,Complex c2)
		{
			this->real=c1.real + c2.real;
			this->imag=c1.imag + c2.imag;
		}
}c1,c2,c3;

void main()
{
	int num;
	clrscr();
	cout << "Enter the first complex number :";
	c1.get_data();
	cout << "Enter the number to be added : ";
	cin >> num;

	c3.add(num,c1);
	cout << "\n\n\nINPUT : \n\n";
	c1.disp_data();
	cout << "\n\n\nRESULT : \n\n";
	c3.disp_data();

	cout << "\n\nEnter second complex number : ";
	c2.get_data();

	cout << "\n\nINPUT : ";
	cout << "\n\nFirst complex number : ";
	c1.disp_data();
	cout << "\n\nSecond complex number : ";
	c2.disp_data();
	c3.add(c1,c2);
	cout << "\n\nRESULT : ";
	c3.disp_data();
	getch();
}
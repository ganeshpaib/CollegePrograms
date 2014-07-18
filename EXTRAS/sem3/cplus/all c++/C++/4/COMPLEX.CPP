#include<iostream.h>
#include<conio.h>
#include<process.h>

class Complex
{
	int r,i;
	public:
		Complex(){r=0,i=0;}
		Complex(int r,int i){this->r=r;this->i=i;}
		void read();
		void display();
		void operator +=(Complex);
		void operator -=(Complex);
		void  operator *=(Complex);
		void operator /=(Complex);
};

void main()
{
	Complex c1,c2,c3;
	int ch;
	clrscr();

	do
	{
		clrscr();
		cout<<"\n\t 1... += ";
		cout<<"\n\t 2... -= ";
		cout<<"\n\t 3... *= ";
		cout<<"\n\t 4... /= ";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\n Enter First Complex Number \n";
				c1.read();
				cout<<"\n Enter Second Complex Number \n";
				c2.read();
				c1+=c2;
				c1.display();
				break;
			case 2:
				cout<<"\n Enter First Complex Number \n";
				c1.read();
				cout<<"\n Enter Second Complex Number \n";
				c2.read();
				c1-=c2;
				c1.display();
				break;
			case 3:
				cout<<"\n Enter First Complex Number \n";
				c1.read();
				cout<<"\n Enter Second Complex Number \n";
				c2.read();
				c1*=c2;
				c1.display();
				break;
			case 4:
				cout<<"\n Enter First Complex Number \n";
				c1.read();
				cout<<"\n Enter Second Complex Number \n";
				c2.read();
				c1/=c2;
				c1.display();
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

void Complex::read()
{
	cout<<"\n Enter Real Part : ";
	cin>>r;
	cout<<"\n Enter Imaginary Part :";
	cin>>i;
}

void Complex::display()
{
	cout<<"\n"<<r<<" i"<<i<<endl;
}

void Complex::operator +=(Complex c)
{
	r=r+c.r;
	i=i+c.i;
}

void Complex::operator -=(Complex c)
{
	r=r-c.r;
	i=i-c.i;
}

void Complex::operator *=(Complex c)
{
	Complex temp;

	temp.r=temp.r+(r*c.r);
	temp.i=temp.i+(r*c.i);
	temp.i=temp.i+(i*c.r);
	temp.r=temp.r+(i*c.i);

	r=temp.r;
	i=temp.i;

}

void Complex::operator /=(Complex c)
{
	Complex temp;
        float qt;
        qt=c.r*c.r+c.i*c.i;
        temp.r=(r*c.r+i*c.i)/qt;
        temp.i=(i*c.r-r*c.i)/qt;

        r=temp.r;
        i=temp.i;
}










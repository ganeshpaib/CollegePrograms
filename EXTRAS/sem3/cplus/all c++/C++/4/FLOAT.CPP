#include<iostream.h>
#include<conio.h>
#include<process.h>

class Float
{
	float f;
	public:
		Float(){f=0;}
		Float(float f){this->f=f;}
		void read();
		void display();
		Float operator +(Float);
		Float operator -(Float );
		Float operator *(Float);
		Float operator /(Float);
};

Float Float::operator +(Float f1)
{
	return Float(f+f1.f);
}
Float Float::operator -(Float f1)
{
	return Float(f-f1.f);
}
Float Float::operator *(Float f1)
{
	return Float(f*f1.f);
}
Float Float::operator /(Float f1)
{
	return Float(f/f1.f);
}

void Float::read()
{
	cout<<"\n Enter A Floating Number :";
	cin>>f;
}
void Float::display()
{
	cout<<"\n The Floating Number : "<<f;
}

void main()
{
	Float f1,f2,f3;
        int ch;
	clrscr();
	cout<<"\n Enter First Floating Number \n";
	f1.read();
	cout<<"\n Enter Second Floating Number \n";
	f2.read();

	do
	{
		clrscr();

		cout<<"\n\t 1... ADD";
		cout<<"\n\t 2... SUB";
		cout<<"\n\t 3... MUL";
		cout<<"\n\t 4... DIV";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				f3=f1+f2;
				f3.display();
				break;
			case 2:
				f3=f1-f2;
				f3.display();
				break;
			case 3:
				f3=f1*f2;
				f3.display();
				break;
			case 4:
				f3=f1/f2;
				f3.display();
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}
















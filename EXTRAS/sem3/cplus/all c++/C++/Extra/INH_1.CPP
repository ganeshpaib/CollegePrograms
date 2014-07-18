#include<iostream.h>
#include<conio.h>

class A
{
	public:
		A(){cout<<"\n Constructor A "<<endl;}
};
class B :private A
{
	public:
		B(){cout<<"\n Constructor B "<<endl;}
};

class C : private A
{

	public:
		C(){cout<<"\n Constructor C"<<endl;}
};
class D: private B,private A,virtual C
{
	public:
		D(){cout<<"\n Constructor D"<<endl;}
};

void main()
{
clrscr();
	D d;
getch();
}
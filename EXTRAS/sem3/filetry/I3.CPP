#include "header.cpp"

class A
{
	protected :
		int a1,a2;
	public:
		A(){ cout << "\nempty constructor...\n";}
		A(int x, int y) : a1(x),a2(y){}
};
class B
{
	protected:
		int b1;
	public:
		B(){cout <<"\nempty constructor B";}
		B(int y):b1(y){}

};
class C:public A, public B
{
	protected:
		int c1;
	public:
		C(){}
		C(int x, int y, int z):A(x,y),B(y),c1(z){}
		void show()
		{
			cout<<"\na1="<<a1<<"\ta2 = "<<a2<<"\tb1 = "<<b1<<"\tc1 :"<<c1;
		}
};

void main()
{
	C c(10,20,30);
	c. show();
	getch();
}

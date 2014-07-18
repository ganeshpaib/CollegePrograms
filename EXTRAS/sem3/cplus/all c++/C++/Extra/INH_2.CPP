#include<iostream.h>
#include<conio.h>

class A
{
	private:
		int prix;
	protected:
		int prox;
	public:
		int pubx;
		A()
		{
			prix=prox=pubx=10;
		}
};

class B : public A
{
	//public:
		//B() {cout<<"prix ="<<prix<<"\t"<<"prox = "<<prox<<"\t"<<"pubx = "<<pubx<<endl;}
};

void main()
{
clrscr();
	B b;
	cout<<b.pubx<<endl;
getch();

}




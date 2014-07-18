#include<iostream.h>
#include<conio.h>

class A
{
	int dataA;
        public:
        	A(){dataA=0;}
                A(int i){dataA=i;}
                void display(){cout<<dataA<<endl;}
};

class B
{
	int dataB;
        public:
        	B(){dataB=0;}
                B(int i){dataB=i;}
                void display(){cout<<dataB<<endl;}
                operator A(){return A(dataB);}
};

void main()
{
	clrscr();
        A a=100;
        B b=200;

        a=b;
        a.display();
getch();
}




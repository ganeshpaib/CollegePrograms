#include<iostream.h>
#include<conio.h>

class A
{
	int data;
        public:
        	A(){data=0;}
                A(int i){data=i;}
                void display(){cout<<data<<endl;}
                operator int(){return data;}
                operator float(){return float(data);}



};

void main()
{
clrscr();
	A a=10;
        int i=a;
        cout<<i<<endl;
        float j=a;
        cout<<j<<endl;
getch();
}


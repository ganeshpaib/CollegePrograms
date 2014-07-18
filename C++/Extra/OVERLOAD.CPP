#include<iostream.h>
#include<conio.h>

class Sample
{
	public:
        	void operator ++(int){ cout<<"\n Postfix"<<endl;}
                void operator ++(){cout<<"\n Prefix"<<endl;}


};

void main()
{
clrscr();
	Sample s;
        ++s;
        s++;
getch();
}
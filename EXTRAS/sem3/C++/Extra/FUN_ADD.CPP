#include<iostream.h>
#include<conio.h>

void dis()
{
	cout<<"\n Function 1"<<endl;
}

void dis1()
{
	cout<<"\n Function 2"<<endl;
}

void fun(void(*f)())
{
        cout<<(void *)(*f)<<endl<<endl;
	f();
}

void main()
{
clrscr();
	//cout<<(void *)dis<<endl<<(void *)dis1;

	fun(dis);
        fun(dis1);

getch();
}


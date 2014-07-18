#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class Time
{
	int hours, min, sec;
	public:
	void set_data(int h,int m,int s)
	{
		hours=h;
		min=m;
		sec=s;
	}

	void disp_data()
	{
		cout<<"\n\n" ;
		cout<<hours<<":"<<min<<":"<<sec;
	}

	void sum_time(Time x,Time y)
	{
		hours=x.hours+y.hours;
		min=x.min+y.min;
		hours=hours+min/60;
		min=min%60;
		sec=x.sec+y.sec;
		min=min+sec/60;
		sec=sec%60;
	}
};

void main()
{
	clrscr();
	int hrs,min,sec;
	Time t1,t2,t3;
	printf( "\nEnter TIME 1: \n\n" );
	cout<<"\nHours : "; cin>>hrs;
	cout<<"\nMin : "; cin>>min;
	cout<<"\nSec : "; cin>>sec;
	t1.set_data(hrs,min,sec);
		printf( "\nEnter TIME 2: \n\n" );
	cout<<"\nHours : "; cin>>hrs;
	cout<<"\nMin : "; cin>>min;
	cout<<"\nSec : "; cin>>sec;
	t2.set_data(hrs,min,sec);
	t3.sum_time(t1,t2);
	t3.disp_data();
	getch();
}
#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class Sample
{
	int a,b,result;
	public:
		void get_data()
		{
			cout<< "a : ";
			cin >> a;
			cout<< "\nb : ";
			cin >> b;
		}
		void disp_result()
		{
		   cout << "Result : "<< result;
		}
		friend void add();
}a1;

void add()
{
	a1.result=a1.a+a1.b;
}

void main()
{
	a1.get_data();
	add();
	a1.disp_result();

	getch();
}
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
class sample1
{
	protected:
	int a;
	public:

	sample1()
	{
		cout<< "Enter a: ";
		cin>>a;
	}
	/*int geta()
	{
		return a;
	} */
	void disp()
	{
		cout<< a;
	}
};

class sample2:public sample1
{
	protected:
	int b,c;
	public:
		sample2()
		{
			cout<<"b: ";
			cin>>b;
		}
		void add()
		{
			c=a+b;
			cout<<c;
		}
};

main()
{
	sample2 s2;
	s2.add();
}

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class Sample1
{
	static int ctr,c;

	public:
		Sample1(){ctr++;}
		~Sample1(){c++;}

	void disp()
	{
		cout<<"ctr : "<<ctr<<"c : "<<c;
	}
}t;
int Sample1:: ctr;
int Sample1:: c;

void main()
{
	int i,n,m;
	Sample1 **s;
	cout<<"n: ";

	cin>>n;
	s=new Sample1*[n];

	for(i = 0; i < n; i++ )
	{
		s[i]=new Sample1();
	}
	cout<<"\nm : ";
	cin>>m;
	for(i = 0 ; i < m; i++ )
	{
		delete(s[i]);
	}

	t.disp();
	getch();
}

#include "header.cpp"

class Meter
{
	float met;
	public:
		Meter()
		{
			met=0.0;
		}
		Meter(float m)
		{
			met=m/100;
		}
		void show()
		{
			cout<<met;
		}
		void get()
		{
			cout<<"\nEnter Meter : ";
			cin>>met;
		}
		 operator float()
		{
			return (float)(met*100.0);
		}


};

void main()
{
	Meter m;
	float len;
	cout<<"\nEnter length : ";
	cin>>len;

	m=len;
	m.show();
	m.get();
	len=m;
	cout<<len;
	getch();
}

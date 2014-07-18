#include "header.cpp"

class sample
{
	int t;
	public:
		sample()
		{
			t=0;
		}
		void get()
		{
			cout<<"data : ";
			cin>>t;
		}
		sample(sample &s1)
		{
			t=s1.t;
		}
		void show()
		{
			cout<<t<<endl;
		}
};

void main()
{
	sample s1;
	s1.get();
	s1.show();
	sample s2=s1;
	s2.show();
	getch();
}
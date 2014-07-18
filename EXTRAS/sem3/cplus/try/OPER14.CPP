#include "header.cpp"

class Sample
{
	int data;
	public:
		Sample()
		{
			data=0;
		}
		Sample(int d)
		{
			data=d;
		}
		void get()
		{
			cout<<"\nData = " ;
			cin>>data;
		}
		void disp()
		{
			cout<<"\n"<<data;
		}
		friend Sample operator +(Sample,Sample );
};

Sample operator +(Sample s1,Sample s2)
{
	return Sample(s1.data+s2.data);
}
void main()
{
	clrscr();
	Sample s1,s2,s3;
	s1.get();
	s2.get();
	s3=s1+s2;
	s3.disp();
	s3=s1+10;
	s3.disp();
	getch();
}
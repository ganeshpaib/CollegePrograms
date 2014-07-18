#include "header.cpp"

class Sample
{
	int i;
	public:
		Sample()
		{
			i=0;
		}
		Sample(int j)
		{
			i=j;
		}


		Sample operator ++()
		{
			return Sample(++i);
		}

		Sample operator -()
		{
			return Sample(-i);
		}
		int show()
		{
			return i;
		}
};

void main()
{
	clrscr();
	Sample s1,s2;
	++s1;
	cout<<"\ns1 : "<<s1.show();
	s2=++s1;
	cout<<"\ns2 : "<<s2.show();
	s2=-s1;
	cout<<"\n-s2 : "<<s2.show();
	getch();
}
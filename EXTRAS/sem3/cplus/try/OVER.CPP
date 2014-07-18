#include "header.cpp"

class Sample
{
	int i;
	public:
		Sample(){i=0;}
		Sample operator ++(int)
		{
			Sample temp;
			temp.i=i++;
			return temp;
		}
		int show()
		{
			return i;
		}
};

void main()
{
	Sample s1, s2;
	s2=s1++;
	cout<<s1.show();
	cout<<s2.show();
	getch();
}

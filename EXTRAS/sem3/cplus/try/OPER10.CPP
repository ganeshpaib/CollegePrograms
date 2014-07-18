#include "header.cpp"
istream& operator >>(istream &, char []);

class Inp
{
	char str[20];
	public:
		friend istream& operator >>(istream &in,Inp &i);
		friend ostream& operator <<(ostream &out, Inp i);
};

void main()
{
	Inp i;

	cin>>i;
	cout<<i;
	getch();
}

istream& operator >>(istream &in, Inp &i)
{
	cin>>i.str;
	return in;
}
ostream& operator <<(ostream &out, Inp i)
{
	::cout<<i.str;
	return out;
}
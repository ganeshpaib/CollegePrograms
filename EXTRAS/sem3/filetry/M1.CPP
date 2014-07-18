#include "header.cpp"
ostream& hx(ostream& out)
{
	cout.setf(ios::uppercase);
	cout<<hex;
	return out;
}

ostream &ta(ostream& out)
{
	out<<"\t";
	return out;
}
/*istream& hx(istream& in)
{
	in>>hex;
	return in;
} */

void main()
{
	int z;
	//cin>>hx>>z;
	cin>>z;
	cout<<hx<<z;
	cout<<"ganesh"<<ta<<ta<<"pai";
	getch();
}
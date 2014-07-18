#include "header.cpp"

void main()
{
	char *ms="ganesh";
	cout<<ms;
	getch();
}


ostream& operator <<(ostream &out, char *msg)
{
	::cout<<msg;
	return out;
}
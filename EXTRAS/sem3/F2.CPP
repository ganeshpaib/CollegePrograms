#include "header.cpp"
#include <fstream.h>

void main()
{
	char ch;
	ofstream outfile( "c:\\ga1.txt" );
	cin>>ch;
	while(cin)
	{
		outfile<<ch;
		cin>>ch;
	}
	outfile.close();

	ifstream infile( "c:\\ga1.txt" );
	while(infile)
	{
		infile.get(ch);
		cout<<ch;
	}
	infile.close();
	getch();
}

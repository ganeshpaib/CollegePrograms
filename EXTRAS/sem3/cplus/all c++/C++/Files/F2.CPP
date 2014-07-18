#include<iostream.h>
#include<conio.h>
#include<fstream.h>

void main()
{
	clrscr();
	int ch;
	ofstream o_file("c:\\test.dat");
	do
	{
		cin>>ch;
		o_file<<ch;
	}while(ch);

	o_file.close();
	ifstream i_file("c:\\test.dat");
	do
	{
		i_file>>ch;
		cout<<ch<<"\t";
	}while(cin);
	i_file.close();
getch();
}
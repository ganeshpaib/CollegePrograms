#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <fstream.h>

void main()
{

	ofstream outf( "c:\\s.dat");
	char name[100];
	int roll;
	if(!outf)
		cout<< "file opening error\n";
	cout <<"\nEnter the name : ";
	cin>>name;
	cout << "\nEnter roll no. : ";
	cin >>roll;
	outf << name<< "\t"<<roll;
	outf.close();

	ifstream inf("c:\\s.dat");
	if(!inf)
		cout<< "file opening error\n";
	inf>>name>>roll;
	cout<< name <<"\t"<<roll;
	inf.close();
	getch();
}
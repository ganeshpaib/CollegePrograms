#include<iostream.h>
#include<conio.h>
#include<fstream.h>

void main()
{
	clrscr();
	int roll;
	char name[' '];
	ofstream ofile("c:\\test.dat");
	if(!ofile)
	{
		cout<<"\n Error In Opening File";
	}
	cout<<"\n Enter Roll : ";
	cin>>roll;
	cout<<"\n Enter Name : ";
	cin>>name;
	ofile<<roll<<"\t"<<name<<endl;
	ofile.close();
	ifstream ifile("c:\\test.dat");
	ifile>>roll>>name;
	cout<<"\t"<<roll<<"\t"<<name<<endl;
	ifile.close();
getch();
}


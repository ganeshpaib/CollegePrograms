#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<conio.h>
struct Student
{
	int rollno;
	char name[20];
	void get_data()
	{
		cout << "\nEnter roll no. : ";
		cin >> rollno;
		cout << "\nEnter Name : ";
		cin >> name;
	}
	void disp()
	{
		cout <<"\n Name : "<<name;
		cout<< "\nRoll no. :"<<rollno;
	}
};

void main()
{
	ifstream in;
	ofstream out;
	int opt, num;
	Student s;

	while(1)
	{
		cout<< "1 -> CREATE....\n";
		cout<< "2 -> DISPLAY....\n" ;
		cout<< "3 -> DELETE...\n" ;
		cout<< "4 -> UPDATE....\n" ;
		cout<< "99 -> EXIT\n ";
		cin>>opt;

		switch(opt)
		{
			case 1: out.open("e:\stud.dat",ios::binary||ios::app);
			if(!out)
			{
				cout<< "FILE OPENING ERROR......\n";
				getch();
				exit(0);
			}
			s.get_data();
			out.write((char *)&s, sizeof(s));
			out.close();
			break;

			case 2: in.open("e:\\stud.dat",ios::binary||ios::app);
					if(!in)
					{
						cout<< "FILE OPENING ERROR......\n";
						getch();
						exit(0);
					}
					cout<< "ROLL No.\tName";
					while(in.read((char *)&s,sizeof(s)))
					{
						s.disp();
					}
					in.close();
					break;

			case 99:exit(0);
		}
	}
	getch();
}
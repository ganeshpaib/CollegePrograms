#include "header.cpp"

struct stud
{
	char name[100];
	int roll;
	void get()
	{
		cout <<"\nEnter Name : ";
		cin >> name;

		cout << "\nRoll No. : ";
		cin >> roll;
	}

	void disp()
	{
		cout << "\n\nRoll No. : "<<roll<<"\tName : "<<name;
	}
	int find_s(int r)
	{
		if(roll==r)
			return 1;
		else
			return 0;
	}


};

void main()
{
	int opt,ro,inc;
	long int loc;
	char nam[100];
	ofstream outf;
	ifstream inf;
	stud s;
	clrscr();
	cout<<sizeof(s);
	do
	{
		cout << "\n1 -> ADD NEW RECORD\n" ;
		cout << "\n2 -> DISPLAY RECORD\n" ;
		cout << "\nEnter ur choice.......\n" ;
		cin >> opt;

		switch(opt)
		{
			case 1 : outf.open( "c:\\tc\\sem3\\filetry\\test\\f2.dat",ios::binary|ios::app );
					 if(!outf)
						cout << "\nerror.......";
					 cout << "\nEnter the details...\n";
					 s.get();
					 outf.write((char *)&s,sizeof(s));
					 outf.close();

					 break;
			case 2 :  inf.open( "c:\\tc\\sem3\\filetry\\test\\f2.dat",ios::binary|ios::in );

					 cout << "Entered details.... : ";
					 while(inf.read((char *)&s,sizeof(s)))
					 {
						s.disp();
					 }
					 inf.close();
					 break;
			case 3 :inf.open( "c:\\tc\\sem3\\filetry\\test\\f2.dat",ios::binary|ios::in );
					if(!inf)
					{
						cout << "\nerror1.......";
						getch();
						exit(0);
					}
					outf.open( "c:\\tc\\sem3\\filetry\\test\\temp.dat",ios::binary|ios::app );
					if(!outf)
					{
						cout << "\nerror2.......";
						getch();
						exit(0);
					}
					cout<< "\nEnter search roll no. : ";
					cin>>ro;
					while(inf.read((char *)&s,sizeof(s)))
					 {
						if(s.roll==ro)
						{
							cout<<"in";
							s.get();
						}
						outf.write((char *)&s,sizeof(s));

					 }
					 inf.close();
					 outf.close();
					 remove("c:\\tc\\sem3\\filetry\\test\\f2.dat");
					 rename("c:\\tc\\sem3\\filetry\\test\\temp.dat","c:\\tc\\sem3\\filetry\\test\\f2.dat");
					break;


			case 99 : exit(0);
		}
	}while(opt!=99);
	getch();
}


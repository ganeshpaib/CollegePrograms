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
			case 1 : ofstream outf( "c:\\tc\\sem3\\filetry\\test\\f2.dat",ios::binary|ios::app );
					 if(!outf)
						cout << "\nerror.......";
					 cout << "\nEnter the details...\n";
					 s.get();
					 outf.write((char *)&s,sizeof(s));
					 outf.close();

					 break;
			case 2 : ifstream inf( "c:\\tc\\sem3\\filetry\\test\\f2.dat",ios::binary|ios::in );
					 if(!inf)
						cout << "\nerror.......";
					 cout << "Entered details.... : ";
					 while(inf.read((char *)&s,sizeof(s)))
					 {
						s.disp();
					 }
					 inf.close();
					 break;
			case 3 :  ifstream inf1;
						inf1.open( "c:\\tc\\sem3\\filetry\\test\\f2.dat",ios::binary|ios::in );
					 inf1.seekg(0,ios::beg);
					 if(!inf1)
						cout<< "ERROR\n";
					 cout <<"\nROLL No. :";
					 cin >> ro;
					 inc=0;
					 while(inf1.read((char *)&s,sizeof(s)))
					 {
						inc++;
						if(s.find_s(ro))
						{
							break;
						}
					 }
					 cout<<inc;
					 printf( "%d",sizeof(s));
					 loc=(inc-1) * sizeof(s);

					 inf1.close();

					 ofstream outf1;
					 outf1.open( "c:\\tc\\sem3\\filetry\\test\\f2.dat",ios::binary|ios::out );

					 outf1.seekp(loc,ios::beg);
					 cout<<outf1.tellp();
					 //s.get();
					 cin>>ro;
					 cin>>nam;
					 //outf1.write((char *)&s,sizeof(s));
					 outf1<<ro<<"\t"<<nam;
					 outf1.close();
					 break;

			case 99 : exit(0);
		}
	}while(opt!=99);
	getch();
}


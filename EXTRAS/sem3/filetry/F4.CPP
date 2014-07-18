#include "header.cpp"
struct stud
{
	char name[100];
	int roll;
	friend istream& operator>>(istream& in,stud &s)
	{
		cout << "\nName : ";
		cin >> s.name;
		cout << "\nRoll No. : ";
		cin >> s.roll;
		return in;
	}
   friend ostream& operator<<(ostream& out,stud s)
	{
		cout << "\nName : "<<s.name<<"\tRoll No. : "<<s.roll;
		return out;
	}
	friend fstream& operator<<(fstream& outf,stud s)
	{
		outf<<s.name<<"\t"<<s.roll;
		return outf;
	}
	friend fstream& operator>>(fstream& inf,stud &s)
	{
		inf>>s.name>>s.roll;
		return inf;
	}

};



void main()
{
	fstream inout( "c:\\tc\\sem3\\filetry\\test\\f4.dat",ios::binary|ios::in|ios::out|ios::app );;
	//ifstream in;
	stud s,z;
	int ch;
	clrscr();

	do
	{
		cout << "\n1 -> ADD RECORD\n";
		cout << "\n2 -> DISPLAY RECORD\n" ;
		cout << "\n99 -> EXIT\n";
		cin >>ch;
		switch(ch)
		{
			case 1: inout.seekp(0,ios::end);
					if(!inout)
					{
						cout<< "\nerror in opening write file...\n";
						getch();
						exit(0);
					}
					cout << "\nEnter details....\n";
					cin >> s;
					inout<<s;
					//out.close();
					break;
			case 2:  //inout.open( "c:\\tc\\sem3\\filetry\\test\\f4.dat",ios::binary|ios::in );
					if(!inout)
					{
						cout<< "\nerror in opening read file...\n";
						getch();
						exit(0);
					}
					inout.seekg(0,ios::beg);
					while(inout.read((char *)&s,sizeof(s)))
					{
						cout<<"in";
						//in>>z;
						cout<<s;
					}
					//in.close();
					break;
			case 99:inout.close();
					exit(0);
		}

	}while(ch!=99);
	getch();
}
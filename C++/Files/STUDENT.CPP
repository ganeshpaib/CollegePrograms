#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>

class student
{
	int roll;
	char name[' '];

	public:

	void getdata()
	{
		cout<<"\n Enter Roll :";
		cin>>roll;
		cout<<"\n Enter Name :";
		cin>>name;
	}
	void display()
	{
		cout<<"\n"<<roll<<"\t"<<name;
	}
	int getroll(){return(roll);}
};

void main()
{
	clrscr();
	student s;
	int ch;

	ofstream out;
	ifstream in;

	out.open("c:\\student.dat");
	if(!out)
	{
		cout<<"\n Error In Opening File ";
		getch();
		exit(0);
	}
	out.close();

	do
	{
		clrscr();
		cout<<"\n\t 1... Create ";
		cout<<"\n\t 2... Display ";
		cout<<"\n\t 3... Delete ";
		cout<<"\n\t 4... Update ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				out.open("c:\\student.dat",ios::binary|ios::app);
				if(!out)
				{
					cout<<"\n Error In Opening File "<<endl;
					getch();
					exit(0);
				}
				s.getdata();
				out.write((char *)&s,sizeof(s));
				cout<<"\n One Record Inserted..."<<endl;
				out.close();
				break;
			case 2:
				in.open("c:\\student.dat",ios::binary);
				if(!in)
				{
					cout<<"\n Error In opening"<<endl;
					getch();
					exit(0);
				}
				while(in.read((char *)&s,sizeof(s)))
				{
					s.display();
				}
				in.close();
				break;
			case 3:
				int search,f=0;
				out.open("c:\\temp.dat",ios::binary);
				in.open("c:\\student.dat",ios::binary);

				cout<<"\n Enter Roll Number :";
				cin>>search;

				while(in.read((char *)&s,sizeof(s)))
				{
					if(s.getroll()!=search)
					{
						out.write((char *)&s,sizeof(s));
					}
					else
					{
						f=1;
					}
				}

				out.close();
				in.close();

				if(f==0)
				{
					cout<<"\n Search Record Not Found.."<<endl;
				}
				else
				{
					cout<<"\n One Record Deleted..."<<endl;
				}

				remove("c:\\student.dat");
				rename("c:\\temp.dat","c:\\student.dat");

				break;

			case 4:
				f=0;
				out.open("c:\\temp.dat",ios::binary);
				in.open("c:\\student.dat",ios::binary);

				cout<<"\n Enter Roll Number :";
				cin>>search;

				while(in.read((char *)&s,sizeof(s)))
				{
					if(s.getroll()==search)
					{
						s.getdata();
						f=1;
					}
						out.write((char *)&s,sizeof(s));
				}

				out.close();
				in.close();

				if(f==0)
				{
					cout<<"\n Search Record Not Found.."<<endl;
				}
				else
				{
					cout<<"\n One Record Updated..."<<endl;
				}

				remove("c:\\student.dat");
				rename("c:\\temp.dat","c:\\student.dat");

				break;

			case 99:
				exit(0);
		}
		getch();
	}while(ch!=99);
getch();
}










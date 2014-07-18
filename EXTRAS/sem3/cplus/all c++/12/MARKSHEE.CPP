#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>


class student
{
	public:

	int roll;
	char name[' '];
	char course[' '];
	int m1,m2,m3;
	char div[' '];

	void getdata()
	{
		cout<<"\n Enter Roll Number :";
		cin>>roll;
		cout<<"\n Enter Name :";
		cin>>name;
		cout<<"\n Enter Course :";
		cin>>course;
		getmark();
	}
	void display()
	{
		cout<<"\n"<<roll<<"\t"<<name<<"\t"<<course<<"\t"<<m1<<"\t"<<m2<<"\t"<<m3;
	}
	void getmark()
	{
		cout<<"\n OOPS  :";
		cin>>m1;
		cout<<"\n LINUX : ";
		cin>>m2;
		cout<<"\n ADA   : ";
		cin>>m3;
	}
};

void main()
{
	student s;
	ofstream out;
	ifstream in;
	struct date d;
	int ch;
	char str[100];
	clrscr();

	//out.open("c:\\mark.dat",ios::binary);
	//out.close();

	do
	{
		clrscr();
		cout<<"\n\t 1... Create ";
		cout<<"\n\t 2... Display ";
		cout<<"\n\t 3... Delete ";
		cout<<"\n\t 4... Update ";
		cout<<"\n\t 5... Marksheet ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				out.open("c:\\mark.dat",ios::binary|ios::app);
				if(!out)
				{
					cout<<"\n Error In Opening File "<<endl;
					getch();
					exit(0);
				}
				s.getdata();
				out.write((char *)&s,sizeof(s));
				cout<<"\n Record Inserted..."<<endl;
				out.close();
				break;
			case 2:
				int f=0;
				in.open("c:\\mark.dat",ios::binary);
				if(!in)
				{
					cout<<"\n Error In Opening File";
					getch();
					exit(0);
				}
				while(in.read((char *)&s,sizeof(s)))
				{
					s.display();
					f=1;
				}

				if(f==0)
				{
					cout<<"\n No Data"<<endl;
				}
				in.close();
				break;
			case 3:
				 int search;
				 f=0;
				out.open("c:\\temp.dat",ios::binary);
				in.open("c:\\mark.dat",ios::binary);

				cout<<"\n Enter Search Data :";
				cin>>search;

				while(in.read((char *)&s,sizeof(s)))
				{
					if(s.roll!=search)
					{
						out.write((char *)&s,sizeof(s));
					}
					else
					{
						f=1;
					}
				}

				if(f==1)
				{
					cout<<"\n One Record Deleted...";
				}
				else
				{
					cout<<"\n No Record Found....";
				}
				in.close();
				out.close();

				remove("c:\\mark.dat");
				rename("c:\\temp.dat","c:\\mark.dat");
				break;

			case 4:
				f=0;
				out.open("c:\\temp.dat",ios::binary);
				in.open("c:\\mark.dat",ios::binary);

				cout<<"\n Enter Search Data :";
				cin>>search;

				while(in.read((char *)&s,sizeof(s)))
				{
					if(s.roll==search)
					{
						s.getdata();
						f=1;
					}

					out.write((char *)&s,sizeof(s));
				}

				in.close();
				out.close();
				if(f==1)
				{
					cout<<"\n One Record Updated...";
				}
				else
				{
					cout<<"\n No Record Found....";
				}

				remove("c:\\mark.dat");
				rename("c:\\temp.dat","c:\\mark.dat");
				break;
			case 5:
				str[0]='\0';
				getdate(&d);
				f=0;
				int total;
				float m;
				strcpy(str,"c:\\reg");
				in.open("c:\\mark.dat",ios::binary);

				cout<<"\n Enter Search Roll : ";
				cin>>search;

				while(in.read((char *)&s,sizeof(s)))
				{
					if(s.roll==search)
					{

						total=s.m1+s.m2+s.m3;

						m=total/3;

						if(m>=60 && m<=99)
						{
							strcpy(s.div,"FIRST");
						}
						else if(m>=50 && m<=59)
						{
							strcpy(s.div,"SECOND");
						}
						else if(m>=40 && m<=49)
						{
							strcpy(s.div,"THIRD");
						}
						else
						{
							strcpy(s.div,"FAIL");
						}
						f=1;
						break;
					}
				}
				in.close();

				if(f==0)
				{
					cout<<"\n No Record Found..."<<endl;
				}
				else
				{
					clrscr();
					char temp[' '];
					temp[0]='\0';
					itoa(s.roll,temp,10);
					strcat(str,temp);
					strcat(str,".txt");

					out.open(str);


					out.width(46);
					out<<"MANIPAL INSTITUTE OF TECHNOLOGY "<<endl<<endl;
					out.width(35);
					out<<"MANIPAL  576104 "<<endl<<endl;
					out.width(15);
					out<<"*****************************************************"<<endl<<endl;

					out<<"\n ROLL NUMBER :: "<<s.roll<<endl;
					out<<"\n NAME        :: "<<s.name<<endl;
					out<<"\n COURSE      :: "<<s.course<<endl<<endl<<endl;
					out<<"\n SUBJECTS \t\t MARKS \n\n";
					out<<" -------- \t\t ----- \n\n";
					out<<"\n OOPS    \t\t "<<s.m1<<endl;
					out<<"\n LINUX    \t\t "<<s.m2<<endl;
					out<<"\n ADA      \t\t "<<s.m3<<endl<<endl<<endl<<endl;

					out<<"\n TOTAL :: "<<total<<endl<<endl;
					out<<"\n CLASS :: " <<s.div<<"\t\t\t"<<"DATE :: "<<(int)d.da_day<<"\/"<<(int)d.da_mon<<"\/"<<d.da_year<<endl;

					out.close();

					cout<<"\n Master Card Created...";


				}
				break;


			case 99:
				exit(0);
		}
		getch();
	}while(ch!=99);
getch();
}




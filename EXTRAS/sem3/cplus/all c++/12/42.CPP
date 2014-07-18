#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>

class Employee
{
	public:
		char name[' '];
		int empid;
		char dept[' '];
		float sal;

		void read()
		{
			cout<<"\n Enter Name :";
			cin>>name;
			randomize();
			empid=random(1000);
			cout<<"\n Enter Department :";
			cin>>dept;
			cout<<"\n Enter Basic Salary :";
			cin>>sal;
		}

		void display()
		{
			cout<<"\n"<<name<<"\t"<<empid<<"\t"<<dept<<"\t"<<sal<<endl;
		}
};

void main()
{
	clrscr();
	Employee e;
	int ch;
	fstream inout("d:\\preetam\\employee.dat",ios::binary|ios::in|ios::out|ios::app);

	if(!inout)
	{
		cout<<"\n Error In Opening File ";
		return;
	}

	do
	{
		clrscr();
		cout<<"\n\t 1... Create ";
		cout<<"\n\t 2... Display ";
		cout<<"\n\t 3... Delete ";
		cout<<"\n\t 4... Update ";
		cout<<"\n\t 5... Pay Slip";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				inout.seekp(0,ios::end);
				e.read();
				inout.write((char *)&e,sizeof(e));
				cout<<"\n Created...";
				break;

			case 2:
				inout.seekg(0,ios::beg);

				while(inout.read((char *)&e,sizeof(e)))
				{
					e.display();
				}
				inout.clear();
				break;
			case 3:
				int search,f=0;
				inout.seekg(0,ios::beg);
				ofstream out("d:\\preetam\\temp.dat");
				cout<<"\n Enter Employee ID : ";
				cin>>search;

				while(inout.read((char *)&e,sizeof(e)))
				{
					if(e.empid!=search)
					{
						out.write((char *)&e,sizeof(e));
					}
					else
					{
						f=1;
					}
				}

				inout.close();
				out.close();

				if(f==0)
				{
					cout<<"\n Search Record Not Found...";
				}
				else
				{
					cout<<"\n One Record Deleted...";
				}
				remove("d:\\preetam\\employee.dat");
				rename("d:\\preetam\\temp.dat","d:\\preetam\\employee.dat");
				fstream inout("d:\\preetam\\employee.dat",ios::binary|ios::in|ios::out|ios::app);
				break;
			case 4:
				f=0,search;
				inout.clear();
				int loc;
				cout<<"\n Enter Record Number : ";
				cin>>search;
				e.read();
				loc=((search-1)*sizeof(e));
				inout.seekp(loc,ios::beg);
				inout.write((char *)&e,sizeof(e));
				cout<<"\n Updated...";
				break;

			case 99:
				inout.close();
				exit(0);
		}
		getch();

	}while(ch!=99);
getch();
}





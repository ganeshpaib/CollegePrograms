#include<iostream.h>
#include<conio.h>

class Employee
{
	int empid;
	char name[' '];

	public:
		void read()
		{
			cout<<"\n Enter Empid : ";
			cin>>empid;
			cout<<"\n Enter Name : ";
			cin>>name;
		}
		void display()
		{
			cout<<"\n"<<empid<<"\t"<<name;
		}
};

class Education
{
	char qual[' '];
	public:
		void read()
		{
			cout<<"\n Enter Qualification : ";
			cin>>qual;
		}
		void display()
		{
			cout<<"\t"<<qual;
		}
};

class Labour:public Employee
{
	int salary;
	public:
		void read()
		{
			Employee::read();
			cout<<"\n Enter Salary :";
			cin>>salary;
		}
		void display()
		{
			Employee::display();
			cout<<"\t"<<salary<<endl;
		}
};

class Scientist:public Employee,public Education
{
	int sal;
	public:
		void read()
		{
			Employee::read();
			Education::read();
			cout<<"\n Enter Salary : ";
			cin>>sal;
		}
		void display()
		{
			Employee::display();
			Education::display();
			cout<<"\t"<<sal<<endl;
		}
};

class Manager:public Employee,public Education
{
	int sal;
	public:
		void read()
		{
			Employee::read();
			Education::read();
			cout<<"\n Enter Salary : ";
			cin>>sal;
		}
		void display()
		{
			Employee::display();
			Education::display();
			cout<<"\t"<<sal<<endl;
		}
};

void main()
{
	clrscr();

	Labour l;
	Scientist s;
	Manager m;

	cout<<"\n\t LABOUR DETAILS \n\n";
	l.read();
	cout<<"\n\n\t SCIENTIST DETAILS \n\n";
	s.read();
	cout<<"\n\n\t MANAGER DETAILS \n\n";
	m.read();
	clrscr();

	cout<<"\n\n\t LABOUR DISPLAY \n\n";
	l.display();
	cout<<"\n\n\t SCINTIST DISPLAY \n\n";
	s.display();
	cout<<"\n\n\t MANAGER DISPLAY \n\n";
	m.display();
getch();
}







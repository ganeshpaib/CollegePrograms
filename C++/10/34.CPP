#include<iostream.h>
#include<conio.h>

class Person
{
	char name[' '];
	int age;

	public:
		void read()
		{
			cout<<"\n Enter Name :";
			cin>>name;
			cout<<"\n Enter Age :";
			cin>>age;
		}
		void display()
		{
			cout<<"\n"<<name<<"\t"<<age;
		}
};

class Teacher:public Person
{
	int exp;
	public:
		void read()
		{
			Person::read();
			cout<<"\n Enter Experience :";
			cin>>exp;
		}
		void display()
		{
			Person::display();
			cout<<"\t"<<exp<<endl;
		}
};

class Student:public Person
{
	char qual[' '];
	public:
		void read()
		{
			Person::read();
			cout<<"\n Enter Qualification :";
			cin>>qual;
		}
		void display()
		{
			cout<<"\t"<<qual;
		}
};

class Exams:public Student
{
	int percentage;
	public:
		void read()
		{
			Student::read();
			cout<<"\n Enter Percentage :";
			cin>>percentage;
		}
		void display()
		{
			Student::display();
			cout<<"\t"<<percentage;
		}
};

class Talents
{
	char type[' '];

	public:
		void read()
		{
			cout<<"\n Enter Talent Type :";
			cin>>type;
		}
		void display()
		{
			cout<<"\t"<<type;
		}
};

class Awards:public Exams,public Talents
{
	public:
		void read()
		{
			Exams::read();
			Talents::read();
		}
		void display()
		{
			Exams::display();
			Talents::display();
		}
};

void main()
{
	clrscr();
	Teacher t;
	Awards a;

	cout<<"\n\n\t Enter Teachers Details \n\n";
	t.read();
	cout<<"\n\n\t Enter Student Details \n\n";
	a.read();

	clrscr();

	cout<<"\n\n\t TEACHERS DETAILS \n\n";
	t.display();
	cout<<"\n\n\t STUDENT DETAILS \n\n";
	a.display();
getch();
}


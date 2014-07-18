#include "header.cpp"

class Student
{
	protected:
		int rollno;
		char name[20];
	public:
		void get()
		{
			cout << "\nName : ";
			cin >> name;

			cout << "\nRoll No. : ";
			cin >>rollno;
		}
};

class Amarks:public Student
{
	protected:
		int sub1_a, sub2_a;
	public:
		void get_amarks()
		{
			cout << "\nARTS Sub1 : ";
			cin >> sub1_a;

			cout << "\nARTS Sub2 : ";
			cin >> sub2_a;
		}
};

class Arts:public Amarks
{
	protected:
		int total_a;
	public:
		void total_arts()
		{
			total_a=sub1_a+sub2_a;
		}
		void a_disp()
		{
			cout<<"\nName : "<<name;
			cout<< "\nRoll No. : "<<rollno;
			cout<< "\nArts Sub 1 : "<<sub1_a;
			cout<< "\nArts Sub 2 : "<<sub2_a;
			cout<< "\nArts Total : "<<total_a;
		}
};

class Smarks:public Student
{
	protected:
		int sub1_s, sub2_s;
	public:
		void get_smarks()
		{
			cout << "\nScience Sub1 : ";
			cin >> sub1_s;

			cout << "\nScience Sub2 : ";
			cin >> sub2_s;
		}
};

class Science:public Smarks
{
	protected:
		int total_s;
	public:
		void total_science()
		{
			total_s=sub1_s+sub2_s;
		}
		void s_disp()
		{
			cout<<"\nName : "<<name;
			cout<< "\nRoll No. : "<<rollno;
			cout<< "\nScience Sub 1 : "<<sub1_s;
			cout<< "\nScience Sub 2 : "<<sub2_s;
			cout<< "\nScience Total : "<<total_s;
		}
};

void main()
{
	clrscr();
	Arts a;
	Science s;
	a.get();
	a.get_amarks();
	a.total_arts();
	a.a_disp();
	s.get();
	s.get_smarks();
	s.total_science();
	s.s_disp();
	getch();
}
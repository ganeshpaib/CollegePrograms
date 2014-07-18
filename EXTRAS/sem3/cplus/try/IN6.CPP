#include "header.cpp"

class student
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
			cin >> rollno;
		}
};

class Marks:public virtual student
{
	protected:
		int sub1, sub2;
	public:
		void get_marks()
		{
			cout << "\nS1 : ";
			cin>>sub1;

			cout << "\nS2 : ";
			cin >> sub2;
		}
};

class Sports:public virtual student
{
	protected:
		int smark;
	public:
		void get_sport()
		{
			cout<< "\nSports Marks : ";
			cin>>smark;
		}
};

class Result:public Marks,public Sports
{
	protected:
		int total;
	public:
		void find_total()
		{
			total=sub1+sub2+smark;
		}
		void disp()
		{
			cout<< "\nName : "<<name<<"\nRoll No. : "<<rollno;
			cout<< "\nS1 : "<<sub1<<"\tS2 : "<<sub2<<"\nSports mark : "<<smark;
			cout<< "\nTotal Marks : "<<total;
		}
};

void main()
{
	clrscr();
	Result r;
	r.get();
	r.get_marks();
	r.get_sport();
	r.find_total();
	r.disp();
	getch();
}
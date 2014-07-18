#include "header.cpp"

class Student
{
	protected:
		int rollno;
		char name[20];
	public:
		void get()
		{
			cout<< "\nROLL No. : ";
			cin>>rollno;

			cout << "\nNAME : ";
			cin>>name;
		}
};
class Marks:public Student
{
	protected:
		int sub1, sub2, total_m;
	public:

		void get_marks()
		{
			cout << " \nsub1 : ";
			cin >> sub1;

			cout << " \nsub2 : ";
			cin >> sub2;
		}
		void total()
		{
			total_m=sub1+sub2;
		}

		void disp()
		{
			cout << "\nRoll No. : "<<rollno;
			cout << "\nName : "<<name;
			cout << "\nSub1 : "<<sub1<<"\tSub2 : "<<sub2;
			cout << "\nTotal : "<<total_m;
		}
};

void main()
{
	clrscr();
	Marks m1;
	m1.get();
	m1.get_marks();
	m1.total();
	m1.disp();
	getch();
}

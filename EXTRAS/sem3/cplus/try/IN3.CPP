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
		int sub1, sub2;
	public:

		void get_marks()
		{
			cout << " \nsub1 : ";
			cin >> sub1;

			cout << " \nsub2 : ";
			cin >> sub2;
		}
};

class Total:public Marks
{
	protected:
		int total_m;
	public:
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
	Total t1;
	t1.get();
	t1.get_marks();
	t1.total();
	t1.disp();
	getch();
}

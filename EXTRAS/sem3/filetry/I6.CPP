#include "header.cpp"

class Student
{
	protected:
		char name[20];
		int roll;
	public:
		void get_data()
		{
			cout << "\nName : ";
			cin >> name;
			cout << "\nRoll No. : ";
			cin >> roll;
		}
		void disp_data()
		{
			cout << "\nName : "<<name;
			cout<< "\nRoll No. :"<<roll;
		}
};

class Internal:public virtual Student
{
	protected:
		int sub1,sub2,tot;
	public:
		void get_data()
		{
			cout << "\n\nSub 1:";
			cin >> sub1;
			cout << "\nSub 2: ";
			cin >>sub2;
		}
		int calc()
		{
			tot=sub1+sub2;
			return tot;
		}
		void disp()
		{
			Student::disp_data();
			cout << "\n\nSub 1: "<<sub1<< "\tSub 2: "<<sub2<< "\nTotal :"<<calc();
		}
};
class External:virtual public Student
{
	protected:
		int sub1,sub2,tot;
	public:
		void get_data()
		{
			cout << "\n\nSub 1:";
			cin >> sub1;
			cout << "\nSub 2: ";
			cin >>sub2;
		}
		int calc()
		{
			tot=sub1+sub2;
			return tot;
		}
		void disp()
		{

			cout << "\n\nSub 1: "<<sub1<< "\tSub 2: "<<sub2<< "\nTotal :"<<calc();
		}
};

class Results:public Internal,public External
{
	protected:
		int tot_marks;
	public:
		int calc()
		{
			tot_marks=External::calc()+Internal::calc();
			return tot_marks;
		}
		void disp_data()
		{
			Student::disp_data();
			Internal::get_data();
			External::get_data();
			cout<< "\n\nTotal :"<<calc();
		}
};

void main()
{
	Results r;
	r.get_data()
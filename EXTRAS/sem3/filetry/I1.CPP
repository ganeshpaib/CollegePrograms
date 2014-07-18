#include "header.cpp"

class Stud
{
	protected:
		char name[20];
		int roll;
	public:
		void get_data()
		{
			cout << "\nEnter name : ";
			cin.getline(name,15,'\n');

			cout << "\nRoll No. : ";
			cin >> roll;
		}
		void disp()
		{
			cout << "\n\nName... : "<<name<<"\tRoll No.. : "<<roll;
		}
};
class Marks:public Stud
{
	protected:
		int m1,m2,m3,tot;
	public:
		void get()
		{
			cout << "\nM1 :";
			cin >> m1;
			cout << "\nM2 :";
			cin >> m2;
			cout << "\nM3 :";
			cin >> m3;
			tot=m1+m2+m3;
		}
		 void disp_d()
		 {
			cout<< "\nM1 :"<<m1<<"\tM2 : "<<m2<<"\tM3 : "<<m3<<"\n\nTotal :"<<tot;
		 }

};

void main()
{
	Marks m;
	m.get_data();
	m.get();
	m.disp();
	m.disp_d();
	getch();
}
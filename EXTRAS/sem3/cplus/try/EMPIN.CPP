#include "header.cpp"

class Employee
{

	protected:
		int empno,sal;
		char name[20];
		public:
		Employee()
		{
			cout << "Empno : ";
			cin >> empno;

			cout << "Empname : ";
			cin >> name;

			cout << "Sal : ";
			cin >> sal;
		}


};

class Salary:public Employee
{
	public:

	void disp()
		{
			cout << "Name : "<<name<<"Empno. : "<<empno<<"Sal : "<<sal;
		}
};

void main()
{

	Salary s;

	s.disp();
}

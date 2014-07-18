#include<iostream.h>
#include<conio.h>
#include<process.h>

class Employee
{
	char name[' '];
	int code;
	public:
		void read()
		{
			cout<<"\n Enter Name :";
			cin>>name;
			cout<<"\n Enter Code :";
			cin>>code;
		}
		void display()
		{
			cout<<"\n"<<name<<"\t"<<code;
		}
		int getcode(){return(code);}
};
class Account:public virtual Employee
{
	int pay;
	public:
		void read()
		{
			cout<<"\n Enter Pay :";
			cin>>pay;
		}
		void display()
		{
			cout<<"\t"<<pay;
		}
};
class Admin:public virtual Employee
{
	int exp;
	public:
		void read()
		{
			cout<<"\n Enter Experience :";
			cin>>exp;
		}
		void  display()
		{
			cout<<"\t"<<exp;
		}
};

class Master:public Account,public Admin
{
	public:
		void read()
		{
			Employee::read();
			Admin::read();
			Account::read();
		}
		void display()
		{
			Employee::display();
			Admin::display();
			Account::display();
		}
};

void main()
{
	int ctr=0;
	clrscr();
	int n,ch;
	cout<<"\n Enter Number Of Employees : ";
	cin>>n;
	Master *m;
	m=new Master[n];

	do
	{
		clrscr();
		cout<<"\n\t 1... Create";
		cout<<"\n\t 2... Display ";
		cout<<"\n\t 3... Update ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				m[ctr++].read();
				cout<<"Created..."<<endl;
				break;
			case 2:
				for(int i=0;i<ctr;i++)
				{
					m[i].display();
				}
				break;
			case 3:
				int search,f=0;
				cout<<"\n Enter The Search Code :";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(m[i].getcode()==search)
					{
						f=1;
						break;
					}
				}

				if(f==1)
				{
					m[i].read();
					cout<<"\n Record Updated..";

				}
				else
				{
					cout<<"\n Search Record Not Found...";
				}
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}















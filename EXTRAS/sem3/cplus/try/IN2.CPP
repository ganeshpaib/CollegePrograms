#include "header.cpp"

class name
{
	protected:
		char name[20];
	public:
		void get_name()
		{
			cout<< "\nEnter name : ";
			cin>>name;
		}
};

class phone
{
	protected:
		int pno;
	public:
		void get_phone()
		{
			cout<< "\nEnter phone no. : ";
			cin>>pno;
		}
};

class Address:public name,public phone
{
	protected:
		char addr[20];
	public:
		void get_addr()
		{
			cout << "\nEnter addr : ";
			cin >>addr;
		}

		void disp()
		{
			cout << "\n\nName : "<<name;
			cout << "\nAddress : "<<addr;
			cout << "\nPhone No. : "<<pno;
		}
};

void main()
{
	clrscr();
	Address a;
	a.get_name();
	a.get_phone();
	a.get_addr();
	a.disp();
	getch();
}


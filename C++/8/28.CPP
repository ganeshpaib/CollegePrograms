#include<iostream.h>
#include<conio.h>

class Account
{
	int accno;
	public:
		void read()
		{
			cout<<"\n Enter Account Number : ";
			cin>>accno;
		}
		void display()
		{
			cout<<"\n"<<accno;
		}
};

class Saving:public Account
{
	int amount;
	public:
		void read()
		{
			Account::read();
			cout<<"\n Enter Amount : ";
			cin>>amount;
		}
		void display()
		{
			Account::display();
			cout<<"\t"<<amount<<endl;
		}
};

class Fixed:public Account
{
	int amount;
	public:
		void read()
		{
			Account::read();
			cout<<"\n Enter Amount  :";
			cin>>amount;
		}
		void display()
		{
			Account::display();
			cout<<"\t"<<amount;
		}
};

class Current:public Account
{
	int amount;
	public:
		void read()
		{
			Account::read();
			cout<<"\n Enter Amount :";
			cin>>amount;
		}
		void display()
		{
			Account::display();
			cout<<"\t"<<amount<<endl;
		}
};

class Short:public Fixed
{
	int term;
	public:
		void read()
		{
			Fixed::read();
			cout<<"\n Enter Term :";
			cin>>term;
		}
		void display()
		{
			Fixed::display();
			cout<<"\t"<<term<<endl;
		}
};

class Medium:public Fixed
{
	int term;
	public:
		void read()
		{
			Fixed::read();
			cout<<"\n Enter Term :";
			cin>>term;
		}
		void display()
		{
			Fixed::display();
			cout<<"\t"<<term<<endl;
		}
};

class Long:public Fixed
{
	int term;
	public:
		void read()
		{
			Fixed::read();
			cout<<"\n Enter Term :";
			cin>>term;
		}
		void display()
		{
			Fixed::display();
			cout<<"\t"<<term<<endl;
		}
};

void main()
{
	clrscr();
	Saving sa;
	Short sh;
	Medium me;
	Long lo;
	Current cu;

	cout<<"\n\n\t Enter Saving Details \n\n";
	sa.read();
	cout<<"\n\n\t Enter Short Term Details \n\n";
	sh.read();
	cout<<"\n\n\t Enter Medium Term Detaisl \n\n";
	me.read();
	cout<<"\n\n\t Enter Long Term Details \n\n";
	lo.read();
	cout<<"\n\n\t Enter Current Accounts Details \n\n";
	cu.read();

	clrscr();

	cout<<"\n\n\t SAVINGS \n\n";
	sa.display();
	cout<<"\n\n\t SHORT TERM \n\n";
	sh.display();
	cout<<"\n\n\t MEDIUM TERM \n\n";
	me.display();
	cout<<"\n\n\t LONG TERM \n\n";
	lo.display();
	cout<<"\n\n\t CURRENT ACCOUNT \n\n";
	cu.display();

getch();
}







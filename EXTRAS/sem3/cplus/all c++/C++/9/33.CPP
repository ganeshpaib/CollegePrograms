#include<iostream.h>
#include<conio.h>
#include<process.h>

class Account
{
	char name[' '];
	int accno;
	char type[' '];

	public:
		void getdata()
		{
			cout<<"\n Enter Name :";
			cin>>name;
			cout<<"\n Enter Account Number :";
			cin>>accno;
			cout<<"\n Enter Account Type  :";
			cin>>type;
		}
		void display()
		{
			cout<<"\n"<<name<<"\t"<<accno<<"\t"<<type;
		}
		int getcno(){return(accno);}
};

class Curr_acc:public Account
{
	int balance;
	int min;
	public:
		void getdata()
		{
			Account::getdata();
			cout<<"\n Enter Balance :";
			cin>>balance;
			cout<<"\n Enter Minimum Balance :";
			cin>>min;
		}
		void display()
		{
			Account::display();
			cout<<"\t"<<balance<<"\t"<<min<<endl;
		}
		void deposit()
		{
			int amt;
			cout<<"\n Enter Amount : ";
			cin>>amt;
			balance+=amt;
		}
		void interest()
		{
			balance+=(0.05*balance);
		}
		void withdraw()
		{
			int amt;
			cout<<"\n Enter Amount :";
			cin>>amt;

			if((balance-amt)<=min)
			{
				cout<<"\n No Fund...";
			}
			else
			{
				balance-=amt;
			}
		}

};

class Sav_acc:public Account
{
	int balance;
	int min;
	public:
		void getdata()
		{
			Account::getdata();
			cout<<"\n Enter Balance :";
			cin>>balance;
			cout<<"\n Enter Minimum Balance :";
			cin>>min;
		}
		void display()
		{
			Account::display();
			cout<<"\t"<<balance<<"\t"<<min<<endl;
		}
		void deposit()
		{
			int amt;
			cout<<"\n Enter Amount : ";
			cin>>amt;
			balance+=amt;
		}
		void interest()
		{
			balance+=(0.05*balance);
		}
		void withdraw()
		{
			int amt;
			cout<<"\n Enter Amount :";
			cin>>amt;

			if((balance-amt)<=min)
			{
				cout<<"\n No Fund...";
			}
			else
			{
				balance-=amt;
			}
		}
};

void main()
{
	clrscr();
	int ch,n,ctr=0,sctr=0,f=0,search,i;

	Curr_acc c[20];
	Sav_acc s[20];


	do
	{
		clrscr();
		cout<<"\n\n\t CURR_ACCOUNT \n\n";
		cout<<"\n\t 1... Create ";
		cout<<"\n\t 2... Display ";
		cout<<"\n\t 3... Deposit ";
		cout<<"\n\t 4... Withdraw ";
		cout<<"\n\t 5... Interese Paid ";
		cout<<"\n\n\t SAV_ACCOUNT \n\n";
		cout<<"\n\t 6... Create ";
		cout<<"\n\t 7... Display ";
		cout<<"\n\t 8... Deposit ";
		cout<<"\n\t 9... Withdraw ";
		cout<<"\n\t 10.. Interese Paid ";
		cout<<"\n\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				c[ctr++].getdata();
				cout<<"\n Created...";
				break;
			case 2:
				for(i=0;i<ctr;i++)
				{
					c[i].display();
				}
				break;
			case 3:
				cout<<"\n Enter Acount Number :";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(c[i].getcno()==search)
					{
						f=1;
						break;
					}
				}

				if(f==1)
				{
					c[i].deposit();
				}
				else
				{
					cout<<"\n Invalid Account Number ";
				}
				break;
			case 4:

				f=0;
				cout<<"\n Enter Account Number :";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(c[i].getcno()==search)
					{
						f=1;
						c[i].withdraw();
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n Invalid Account Number ";
				}
				break;
			case 5:
				f=0;
				cout<<"\n Enter Account Number : ";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(c[i].getcno()==search)
					{
						c[i].interest();
						f=1;
						cout<<"\n Interest Paid...";
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n Invalid Account Number ";
				}
				break;
			case 6:
				s[sctr++].getdata();
				cout<<"\n Created...";
				break;
			case 7:
				for(i=0;i<sctr;i++)
				{
					s[i].display();
				}
				break;
			case 8:
				cout<<"\n Enter Acount Number :";
				cin>>search;

				for(i=0;i<sctr;i++)
				{
					if(s[i].getcno()==search)
					{
						f=1;
						break;
					}
				}

				if(f==1)
				{
					s[i].deposit();
				}
				else
				{
					cout<<"\n Invalid Account Number ";
				}
				break;
			case 9:

				f=0;
				cout<<"\n Enter Account Number :";
				cin>>search;

				for(i=0;i<sctr;i++)
				{
					if(s[i].getcno()==search)
					{
						f=1;
						s[i].withdraw();
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n Invalid Account Number ";
				}
				break;
			case 10:
				f=0;
				cout<<"\n Enter Account Number : ";
				cin>>search;

				for(i=0;i<sctr;i++)
				{
					if(s[i].getcno()==search)
					{
						s[i].interest();
						f=1;
						cout<<"\n Interest Paid...";
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n Invalid Account Number ";
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

















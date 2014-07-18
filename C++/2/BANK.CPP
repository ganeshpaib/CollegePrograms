#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

class Bank
{
	private:
		char CustomerName[20];
		int AccountNumber;
		char AccountType[2];
		float Amount;
	public:
		Bank()
		{
			strcpy(CustomerName,NULL);
			AccountNumber=0;
			strcpy(AccountType,NULL);
			Amount=0;
		}
		int find();
		void create();
		void deposit();
		void withdraw();
		void display();
};

int Bank::find()
{
	return(AccountNumber);
}


void Bank::create()
{
	cout<<"\n Enter Customer Name : ";
	cin>>CustomerName;
	cout<<"\n Enter AccountNumber : ";
	cin>>AccountNumber;
	cout<<"\n Enter Account Type(S/R) : ";
	cin>>AccountType;
	cout<<"\n Enter Amount : ";
	cin>>Amount;
}

void Bank::display()
{
	cout<<"\n Name :: "<<CustomerName;
	cout<<"\n AccountNumber ::"<<AccountNumber;
	cout<<"\n AccountType ::"<<AccountType;
	cout<<"\n Amount ::"<<Amount;
}

void Bank::withdraw()
{
	int amt;
	cout<<"\n Enter Amount : ";
	cin>>amt;

	if(amt<Amount)
	{
		Amount=Amount-amt;
		cout<<"\n Amount Debited..."<<endl;
	}
	else
	{
		cout<<"\n No Balance "<<endl;
	}
}

void Bank::deposit()
{
	int amt;
	cout<<"\n Enter Amount: ";
	cin>>amt;
	Amount+=amt;
	cout<<"\n Amount Deposited...";
}


void main()
{
clrscr();
	Bank **b;
	int n,ch,search,f=0,ctr=0,amt;
	cout<<"\n Enter Number Of Customer : ";
	cin>>n;

	b=new Bank *[n];
	for(int i=0;i<n;i++)
	{
		b[i]=new Bank();
	}

	do
	{
		clrscr();
		cout<<"\n\t 1... Create";
		cout<<"\n\t 2... Deposit";
		cout<<"\n\t 3... Withdraw";
		cout<<"\n\t 4... Display ";
		cout<<"\n\t 5... Delete ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				b[ctr++]->create();
				cout<<"\n Created...";
				break;
			case 2:
				f=0;
				cout<<"\n Enter Account Number : ";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(b[i]->find()==search)
					{
						b[i]->deposit();
						f=1;
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n No Record...";
				}
				break;
			case 4:
				f=0;
				cout<<"\n Enter Account Number : ";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(b[i]->find()==search)
					{
						b[i]->display();
						f=1;
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n No Record Found...";
				}
				break;

			case 3:
				f=0;
				cout<<"\n Enter Account Number : ";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(b[i]->find()==search)
					{
						b[i]->withdraw();
						f=1;
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n No Record Found...";
				}
				break;
			case 5:
				f=0;
				cout<<"\n Enter Account Number :";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(b[i]->find()==search)
					{
						delete((b+i));
						f=1;
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n No Record Found...";
				}
				else
				{
					cout<<"\n Account Deleted...";
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






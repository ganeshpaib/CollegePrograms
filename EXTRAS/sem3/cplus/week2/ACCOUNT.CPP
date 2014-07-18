#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class Account
{
	int accno;
	char name[20];
	float amt;

	public:
		void get_data()
		{
			cout<< "\n\n\n\t\t\tACCOUNT INFO" ;

			cout<< "\nAcc. No. : ";
			cin >>accno;

			cout<< "\n\n\nName : ";
			cin>>name;



			cout<< "\nAmount : ";
			cin>> amt;

		}

		void display()
		{
			cout<< "\n\n\n\t\t\tACCOUNT INFO";
			cout<< "\n\nName : "<< name;
			cout<< "\n\nAcc No. : "<<accno;
			cout<< "\n\nAmount : "<<amt;
		}

		void transfer(int ,int );




}**a,temp;

int ano,i,acno;
void main()
{

	clrscr();

	cout << "\nEnter number of accounts : " ;
	cin >>ano;

	a=new Account*[ano];

	for( i = 0; i < ano; i++ )
	{
		getch();
		clrscr();
		a[i]=new Account();
		a[i]->get_data();

	}
	for( i = 0; i < ano; i++ )
	{
		getch();
		clrscr();
		a[i]->display();
	}

	getch();
	clrscr();

	cout<< "\n\nEnter the account number from which amount has to be transfered : ";
	cin>>acno;
	temp.transfer(acno,ano);

	for( i = 0; i < ano; i++ )
	{
		getch();
		clrscr();
		a[i]->display();
	}

	getch();
}

void Account::transfer(int acno1,int ano)
		{
			int acno2,flg=0,amot;
			clrscr();
			for(i = 0; i < ano; i++ )
			{
			  if(a[i]->accno==acno1)
			  {
				cout<< "\n\nAmount to be transfered : ";
				cin>>amot;
				if(a[i]->amt>=amot)
				{
					clrscr();

					cout<< "\n\n\n\n\n\n\n\n\n\t\t\tACCOUNT EXISTS & TRANSACTION POSSIBLE" ;
					flg=1;
					a[i]->amt=a[i]->amt-amot;
					clrscr();
					cout << "\n\nEnter the acc no. where amount has to be transferred : ";
					cin >> acno2;

				}
				else
					cout<< "\n\nACCOUNT EXISTS BUT AMOUNT IS LOW TO BE TRANSFERRED";
				break;
			  }
			}
			if(flg==1)
			{
				for(i=0;i<ano;i++)
				{
					if(a[i]->accno==acno2)
					{
						a[i]->amt=a[i]->amt+amot;
					}
				}
			}
			else
				cout << "INVALID ACC No. ";
		}
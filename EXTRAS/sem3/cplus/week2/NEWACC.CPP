/*
	BANK
*/

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<process.h>
#include<string.h>


class Account
{
	int accno;
	char name[50],acctype[20];
	float amt;

	public:
		void get_data()
		{
			char cha;
			cout<< "\n\n\n\t\t\tACCOUNT INFO" ;

			cout<< "\nAcc. No. : ";
			flushall();
			cin>>accno;


				cout << "\nEnter Acc. Type : ";
				cout << "\n\n\nPRESS 'C' for Current Acc. \n\n"<<" 'S' Savings Account ";
				flushall();
				cha=getche();
				strupr(&cha);



			if( cha=='S')
			{
				strcpy(acctype,"Savings Acc." );
				cout<< "\n\n\nName : ";
				flushall();
				cin>>name;
			}
			else
			{
				strcpy(acctype,"Current Acc." );
				cout << "\n\nEnter firm name : ";
				flushall();
				cin>>name;
			}

			cout<< "\nAmount : ";
			flushall();
			cin>> amt;

		}

		void display(int accno)
		{
			int flg=0;

			for( i = 0; i < ano; i++ )
			{
				if(a[i]->accno==accno)
				{
					flg=1;
					cout<< "\n\n\n\t\t\tACCOUNT INFO";
					cout<< "\n\nName : "<< a[i]->name;
					cout<< "\n\nAcc Type : "<< a[i]->acctype;
					cout<< "\n\nAcc No. : "<<a[i]->accno;
					cout<< "\n\nAmount : "<<a[i]->amt;
					getch();
				}
			}
			if(flg==0)
			{
				clrscr();
				cout<< "\n\n\n\n\n\n\n\n\n\t\tSORRY......Account number  "<<accno<<" does not exist\n\n";
				getch();
			}
		}


		void draw(int accno)
		{
			int flg=0;
			float amount;

			for( i = 0; i < ano; i++ )
			{
				if(a[i]->accno==accno)
				{
					flg=1;
					cout << " \n\nEnter the amount to be withdrawn : " ;
					cin >> amount;

					if((a[i]->amt - amount)>=500)
					{
						a[i]->amt=a[i]->amt - amount;
						display(accno);
					}
					else
					{
						clrscr();
						cout << " \n\n\n\n\n\n\n\n\t\t\tSORRY......CANNOT WITHDRAW " ;
						getch();
					}

				}
			}
			if(flg==0)
			{
				clrscr();
				cout<< "\n\n\n\n\n\n\n\n\n\t\tSORRY......Account number  "<<accno<<" does not exist\n\n";
				getch();
			}
		}

		void dep(int accno)
		{
			int flg=0;
			float amount;

			for( i = 0; i < ano; i++ )
			{
				if(a[i]->accno==accno)
				{
					flg=1;
					cout << " \n\nEnter the amount to be deposited : " ;
					cin >> amount;

						a[i]->amt=a[i]->amt + amount;
						display(accno);

				}
			}
			if(flg==0)
			{
				clrscr();
				cout<< "\n\n\n\n\n\n\n\n\n\t\tSORRY......Account number  "<<accno<<" does not exist\n\n";
				getch();
			}
		}



}**a,temp;

int ano,i,acno,ch,accno;
void main()
{


		clrscr();

		cout << "\nEnter number of accounts : " ;
		flushall();
		cin >>ano;

		a=new Account*[ano];

		for(i = 0; i < ano; i++ )
		a[i]=new Account();

		for( i = 0; i < ano; i++ )
		{
			getch();
			flushall();
			clrscr();
			a[i]->get_data();

		}

	do
	{
		clrscr();
		flushall();
		cout << "1 -> DISPLAY ACCOUNT INFO\n\n" ;
		cout << "2 -> WITHDRAW AMOUNT\n\n" ;
		cout << "3 -> DEPOSIT AMOUNT\n\n" ;
		cout << "99 -> EXIT\n\n" ;
		flushall();
		cin >> ch;

		switch(ch)
		{
			case 1: clrscr();
					cout << "Enter the account number : " ;
					flushall();
					cin >> accno;
					temp.display(accno);
					break;

			case 2: clrscr();
					cout << "Enter the account number : ";
					flushall();
					cin >> accno;
					temp.display(accno);

					temp.draw(accno);
					break;

			case 3: clrscr();
					cout << "Enter the account number : ";
					flushall();
					cin >> accno;
					temp.display(accno);

					temp.dep(accno);
					break;

			case 99: exit(0);
		}
		flushall();
	}while(ch!=99);

	getch();
}


#include<iostream.h>
#include<conio.h>
#include<string.h>

class Account
{
	int count;
	char name[10][20];
	float acc_no[10];

	public:
		Account(){count=0;};
		Account(int c){count=c;}
		void read();
		char * operator [](int);
		int operator [](char *);
};

int Account::operator [](char *s)
{
	for(int i=0;i<count;i++)
	{
		if(strcmp(name[i],s)==0)
		{
			return(acc_no[i]);
		}
	}
	return(0);
}

char * Account::operator [](int search)
{
	for(int i=0;i<count;i++)
	{
		if(acc_no[i]==search)
		{
			return name[i];
		}
	}
	return(NULL);
}

void Account::read()
{
	for(int i=0;i<count;i++)
	{
		cout<<"\n Enter Name :";
		cin>>name[i];
		cout<<"\n Enter Account Number :";
		cin>>acc_no[i];
	}
}

void main()
{
clrscr();
	Account act(3);
	int search;
	char name[20];
	act.read();
	clrscr();
	cout<<"\n Enter Account Number :";
	cin>>search;

	cout<<"\n Name : "<<act[search]<<endl;

	cout<<"\n Enter Name :";
	cin>>name;
	cout<<"\n Account Number :"<<act[name]<<endl;
getch();
}




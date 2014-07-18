#include<iostream.h>
#include<conio.h>
#include<process.h>

class Account
{
	private:
		char name[20];
		int acc_no;
		float amount;
	public:
		int find();
		void getdata();
		void display();
		void transfer(Account *,float);
};
int Account::find()
{
	return(acc_no);
}

void Account::getdata()
{
	cout<<"\n Enter Name : ";
	cin>>name;
	cout<<"\n Enter Account Number : ";
	cin>>acc_no;
	cout<<"\n Enter Amount : ";
	cin>>amount;
}
void Account::display()
{
	cout<<"\n Name : "<<name<<endl;
	cout<<"\n Account Number : "<<acc_no<<endl;
	cout<<"\n Amount : "<<amount<<endl;
}

void Account::transfer(Account *temp,float amt)
{
	if(amt<temp->amount)
	{
		amount=amount+amt;
		temp->amount=temp->amount-amt;
		cout<<"\n Amount Transfered...";
	}
	else
	{
		cout<<"\n No Balance";
	}

}

void main()
{
clrscr();
	Account **a;

	int n,ch,search,f=0,ctr=0,f1=0,source,target,j,i;
	float amt;

	cout<<"\n Enter Number Of Accounts :";
	cin>>n;

	a=new Account *[n];
	for(i=0;i<n;i++)
	{
		a[i]=new Account();
	}
	clrscr();

	do
	{
		clrscr();
		cout<<"\n\t 1... Insert ";
		cout<<"\n\t 2... Display ";
		cout<<"\n\t 3... Transfer ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:

				if(ctr<=n)
				{
					a[ctr]->getdata();
					cout<<"\n Added...";
					ctr++;
				}
				else
				{
					cout<<"\n Sorry..";
				}
				break;
			case 2:
				f=0;

				cout<<"\n Enter Account Number : ";
				cin>>search;

				for(i=0;i<ctr;i++)
				{
					if(a[i]->find()==search)
					{
						f=1;
						a[i]->display();
						break;
					}
				}

				if(f==0)
				{
					cout<<"\n No Data ";
				}

				break;
			case 3:
				f=f1=0;
				cout<<"\n Enter Source Account : ";
				cin>>source;
				cout<<"\n Enter Target Account : ";
				cin>>target;

				for(i=0;i<ctr;i++)
				{
					if(a[i]->find()==source)
					{
						f=1;
						break;
					}
				}

				if(f==1)
				{
					for(j=0;j<ctr;j++)
					{
						if(a[j]->find()==target)
						{
							f1=1;
							break;
						}
					}
				}

				if(f==1&&f1==1)
				{
					cout<<"\n Enter Amount To Be Transfer : ";
					cin>>amt;
					a[j]->transfer(a[i],amt);
				}
				else
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




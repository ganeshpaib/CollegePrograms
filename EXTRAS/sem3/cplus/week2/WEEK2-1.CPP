#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
class account
{

	char name[10];
	int acno;
	double amt;
	public:
		account() {acno=0;amt=0;}
		void getdata()
		{
			clrscr();
			cout<<"\nENTER THE NAME : ";
			cin>>name;
			cout<<"\nENTER THE A/C NO : ";
			cin>>acno;
			cout<<"\nENTER THE AMOUNT : ";
			cin>>amt;
		}
		void display()
		{
			clrscr();
			cout<<"\nNAME : "<<name<<"\tA/C NO : "<<acno<<"\tAMOUNT : "<<amt;
			getch();
		}
		void transfer(int,account *);
};
void main()
{
	account a[10];
	char ch;
	int i=0,j;
	clrscr();
	do
	{
		clrscr();
		a[i].getdata();
		getch();
		clrscr();
		cout<<"DO U WANT ADD 1 MORE [Y/N]";
		cin>>ch;
		strupr(&ch);
		i++;
	}while(ch=='Y');

	for(j=0;j<i;j++)
		a[j].display();
	do
	{
	clrscr();
	cout<<"PRESS ENTER TO TRANSFER MONEY";
	ch=getch();
	if(ch=='\r')
	{
		a[i].transfer(i,a);
	}
	else
		exit(0);
	getch();
	for(j=0;j<i;j++)
		a[j].display();
	clrscr();
	cout<<"\nDO YOU WANT TO CONTINUE [Y/N] : ";
	cin>>ch;
	strupr(&ch);
	}while(ch=='Y');
	getch();
}
void account::transfer(int n,account a[])
{
	int fno,tno,i,j=0,g,h,k=0;
	double famt;
	clrscr();
	cout<<"ENTER THE ACCOUNT NO [FROM - TO]  :  ";
	cin>>fno>>tno;
	for(i=0;i<n;i++)
	{
		if(fno==a[i].acno)
		{
			j=1;
			g=i;
		}
		if(tno==a[i].acno)
		{
			k=1;
			h=i;
		}
	}
	if(g==h)
	cout<<"\nERROR";
	else
		if(j==1&&k==1)
		{
			clrscr();
			cout<<"\nENTER THE AMOUT TO BE TRANSFERED  -> ";
			cin>>famt;
			clrscr();
			if(a[g].amt<famt)
				cout<<"\nYOU DNT HAVE ENOUGH MONEY";
			else
			{
				a[g].amt-=famt;
				a[h].amt+=famt;
			}
		}
		else
		{clrscr();cout<<"\nACCOUNT NO. NOT VALID";}
}










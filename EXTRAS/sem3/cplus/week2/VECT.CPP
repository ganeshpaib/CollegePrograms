#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class vector
{
	int i,size;
	float v[10];
	public:
		vector(){i=0;}
		void create(int);
		void modify(int);
		void multiply();
		void add(vector);
		void disp();
};

void vector::create(int n)
{
		size=n;
		for(i=0;i<n;i++)
		{
			cout<<"\nEnter value:: ";
			cin>>v[i];
		}
}

void vector::modify(int n)
{
		float x;
		cout<<"\nEnter the new value ";
		cin>>x;
		v[n]=x;
}

void vector::multiply()
{
		float f;
		cout<<"\nEnter scaler value::";
		cin>>f;
		for(i=0;i<size;i++)
			 v[i] *=f;
}

void vector::add(vector v1)
{
		for(i=0;i<size;i++)
				v[i] += v1.v[i];
}

void vector::disp()
{
		for(i=0;i<size;i++)
			cout<<"\n\t v["<<i<<"]= "<<v[i];
}

void main()
{
		int ch,n;
		vector vtr,vtr1,vtr2;
		while(ch!=99)
		{
			clrscr();
			cout<<"\n Enter among the following::";
			cout<<"\n 1 To create a vector";
			cout<<"\n 2 To display";
			cout<<"\n 3 To modify a value";
			cout<<"\n 4 To multiply by scalar";
			cout<<"\n 5 To add 2 vector";
			cout<<"\n 99 Exit ";
			cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"\nEnter no of element in vector ";
					cin>>n;
					vtr.create(n);
					break;
				case 2:
					clrscr();
					cout<<"\nThe element of vector: ";
					vtr.disp();
					getch();
					break;
				case 3:
					cout<<"\nEnter the index no to modify";
					cin>>n;
					vtr.modify(n);
					getch();
					break;
				case 4:
					vtr.multiply();
					break;
				case 5:
					cout<<"\nPlease enter the same size of the vector::n= ";
					cin>>n;
					cout<<"\n Enter 1st vector: ";
					vtr1.create(n);
					cout<<"\n Enter 2nd vector: ";
					vtr2.create(n);
					vtr1.add(vtr2);
					vtr1.disp();
					getch();
					break;
				case 99:
					break;
			}
		}
}
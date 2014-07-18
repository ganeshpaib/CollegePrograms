#include<iostream.h>
#include<conio.h>
#include<process.h>
#define size 10

int n;

class Vector
{
	private:
		float number[size];
	public:
		Vector();
		void insert(int &);
		void modify(int &);
		void multi(int);
		void display();
		void add(Vector,Vector);
};

Vector::Vector()
{
	for(int i=0;i<size;i++)
	{
		number[i]=0;
	}
}

void Vector::display()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<number[i];
	}
}

void Vector::insert(int &i)
{
	cout<<"\n Enter Number : ";
	cin>>number[i];

}

void Vector::modify(int &pos)
{
	float value;
	cout<<"\n Enter New Value : ";
	cin>>value;
	number[pos-1]=value;

}

void Vector::multi(int scalar)
{
	for(int i=0;i<n;i++)
	{
		number[i]*=scalar;
	}
}

void Vector::add(Vector v1,Vector v2)
{
	for(int i=0;i<n;i++)
	{
		number[i]=v1.number[i]+v2.number[i];
	}
}

void main()
{
	Vector v,v1,v2;
	int ch,pos,scalar;
	clrscr();

	cout<<"\n Enter Number Of Floating Numbers :";
	cin>>n;

	do
	{
		clrscr();
		cout<<"\n\t 1... Insert";
		cout<<"\n\t 2... Modify";
		cout<<"\n\t 3... Multiply By A Scalar Value";
		cout<<"\n\t 4... Display";
		cout<<"\n\t 5... Addition";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				for(int i=0;i<n;i++)
				{
					v.insert(i);
				}
				break;
			case 2:
				cout<<"\n Enter Element Position : ";
				cin>>pos;
				v.modify(pos);
				cout<<"\n Value Modified...";
				break;
			case 3:
				cout<<"\n Enter A Scalar Value : ";
				cin>>scalar;
				v.multi(scalar);
				cout<<"\n Done..";
				break;
			case 4:
				v.display();
				break;
			case 5:
				cout<<"\n\t  Enter Elements For Second List \n\n";
				for(i=0;i<n;i++)
				{
					v1.insert(i);
				}
				 v2.add(v,v1);
				 clrscr();
				 cout<<"\n\n\t FIRST VECTOR \n\t";
				 v.display();
				 cout<<"\n\n\t SECOND VECTOR \n\t";
				 v1.display();
				 cout<<"\n\n\t THIRD VECTOR \n\t";
				 v2.display();

				 break;

			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

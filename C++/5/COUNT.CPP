#include<iostream.h>
#include<conio.h>
#include<process.h>

class Count
{
	int ctr;
	public:
		Count(){ctr=0;}
		Count(int ctr){this->ctr=ctr;}
		Count operator ++(){return Count(++ctr);}
		Count operator ++(int){return Count(ctr++);}
		Count operator --(){return Count(--ctr);}
		Count operator --(int){return Count(ctr--);}
		Count operator +(Count c){return Count(ctr+c.ctr);}
		void read();
		void display();
};

void Count::read()
{
	cout<<"\n Enter A Number : ";
	cin>>ctr;
}
void Count::display()
{
	cout<<"\n"<<ctr;
}


void main()
{
	Count c1,c2,c3;
	int ch;
	clrscr();
	do
	{
		clrscr();
		cout<<"\n\t 1... ++(pretfix)";
		cout<<"\n\t 2... ++(postfix) ";
		cout<<"\n\t 3... --(pretfix) ";
		cout<<"\n\t 4... --(postfix) ";
		cout<<"\n\t 5... +";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				c1.read();
				c2=++c1;
				cout<<"\n First Number :";
				c1.display();
				cout<<"\n Second Number : ";
				c2.display();
				break;
			case 2:
				c1.read();
				c2=c1++;
				cout<<"\n First Number :";
				c1.display();
				cout<<"\n Second Number : ";
				c2.display();
				break;
			case 3:
				c1.read();
				c2=--c1;
				cout<<"\n First Number :";
				c1.display();
				cout<<"\n Second Number : ";
				c2.display();
				break;
			case 4:
				c1.read();
				c2=c1--;
				cout<<"\n First Number :";
				c1.display();
				cout<<"\n Second Number : ";
				c2.display();
				break;
			case 5:
				c1.read();
				c2.read();
				c3=c1+c2;
				c3.display();
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}





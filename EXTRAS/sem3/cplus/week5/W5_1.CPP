#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <process.h>

class increment
{
	static int i,j;
	int in,de;
	public:
		increment()
		{
			i=0; j=0; de=0; in=0;
		}
		increment(int z)
		{
			i=z;
		}
		void operator ++(int)
		{
			j=++i;
			in=i;
		}

		void operator --(int)
		{
			i=--j;
			de=j;
		}
		int operator +(increment dec)
		{

			cout << "\nIncrement val : "<<in;
			cout << "\nDecrement val : "<<dec.de;
			return(in+dec.de);
		}
		void disp()
		{
			cout <<i;
		}

};



int increment::i;
int increment::j;
void main()
{
	int ch;
	increment inc,dec,temp,inc1,inc2,inc3;
	clrscr();
	do
	{
		clrscr();
		cout << "\n\nPress 1 -> Increment" ;
		cout << "\n\nPress 2 -> Decrement" ;
		cout << "\n\nPress 3 -> Adding Counters" ;
		cout << "\n\nPress 99 -> Exit" ;
		cout << "\n\nEnter ur choice ....... : ";
		flushall();
		cin >> ch;

		switch(ch)
		{
			case 1:	inc++;
					cout << "\nIncrement Result : ";
					temp.disp();
					getch();
					break;

			case 2: dec--;
					cout << "\nDecrement Result : ";
					temp.disp();
					getch();
					break;

			case 3: temp=inc+dec;
					cout << "\nResult : ";
					temp.disp();
					getch();
					break;

			case 99: exit(0);
		}
	}while(ch!=99);

	getch();
}

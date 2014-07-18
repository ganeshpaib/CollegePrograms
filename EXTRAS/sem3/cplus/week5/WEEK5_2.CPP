#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<process.h>
class Rupee
{
	float rs;
	public:
		Rupee(){rs=0.0;}
		Rupee(float r){rs=r;}
		void display(){cout << "\nRs."<<rs;}
		float  get_rupee(){return rs;}
		void get_data()
		{
				cout << "\n\nENTER RUPEE : " ;
				cin >> rs;
		}
};

class Paise
{
	float ps;
	public:
		Paise(){ps=0;}
		Paise(int p){ps=p;}
		void display(){cout <<endl<< ps<<"paise";}
		operator Rupee(){return Rupee(ps/100);}
		Paise(Rupee r){ps=((r.get_rupee())*100);}
		void get_data()
		{
				cout << "\n\nENTER PAISE : ";
				cin >> ps;
		}
};

void main()
{
	Rupee r;
	Paise p;
	int ch;
	do
	{
		clrscr();
		cout << "\n\n1 -> Rupee to Paisa ";
		cout << "\n\n2 -> Paisa to Rupee ";
		cout << "\n\n99 -> Exit";
		cout << "\n\nEnter ur choice .... : ";

		cin >> ch;
		switch(ch)
		{
			case 1:	r.get_data();
					p=r;
					p.display();
					getch();
					break;
			case 2:	p.get_data();
					r=p;
					r.display();
					getch();
					break;
			case 3: exit(0);
		}
	}while(ch!=99);
	getch();
}
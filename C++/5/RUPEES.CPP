#include<iostream.h>
#include<conio.h>
#include<process.h>


class Paise
{
	float pa;
	public:
		Paise(){pa=0;}
		Paise(float i){pa=i;}
		void read(){cin>>pa;}
		void display(){cout<<pa;}
		float getdata(){return(pa);}
};

class Rupees
{
	float rs;
	public:
		Rupees(){rs=0;}
		Rupees(float i){rs=i;}
		void read(){cin>>rs;}
		void display(){cout<<rs;}
		operator Paise(){return Paise(rs*100);}
		Rupees(Paise p){ rs=p.getdata()/100;}

};


void main()
{
	clrscr();
	int ch;
	Rupees r;
	Paise p;

	do
	{
		clrscr();
		cout<<"\n\t 1... Rs To Paise ";
		cout<<"\n\t 2... Paise To Rs ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\n Enter Amount In Rs :";
				r.read();
				p=r;
				p.display();
				break;
			case 2:
				cout<<"\n Enter Amount In Paise :";
				p.read();
				r=p;
				r.display();
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}







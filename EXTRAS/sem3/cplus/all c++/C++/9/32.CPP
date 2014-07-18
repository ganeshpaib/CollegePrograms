#include<iostream.h>
#include<conio.h>

class Item
{
	char title[' '];
	int price;
	public:
		void read()
		{
			cout<<"\n Enter Title :";
			cin>>title;
			cout<<"\n Price :";
			cin>>price;
		}
		void display()
		{
			cout<<"\n"<<title<<"\t"<<price;
		}
};

class Sale
{
	float m[3];
	public:
		void read()
		{
			cout<<"\n\n\t Enter Price \n\n";
			cout<<"\n Month 1: ";
			cin>>m[0];
			cout<<"\n Month 2: ";
			cin>>m[1];
			cout<<"\n Month 3: ";
			cin>>m[2];
		}
		void display()
		{
			cout<<"\t"<<m[0]<<"\t"<<m[1]<<"\t"<<m[2];
		}
};

class Hardware:public Item,public Sale
{
	char cat[' '];
	char man[' '];

	public:
		void read()
		{
			Item::read();
			Sale::read();
			cout<<"\n Enter Category : ";
			cin>>cat;
			cout<<"\n Enter Manufacturer Name :";
			cin>>man;
		}
		void display()
		{
			Item::display();
			Sale::display();
			cout<<"\t"<<cat<<"\t"<<man<<endl;
		}
};

class Software:public Item,public Sale
{
	char type[' '];
	char os[' '];

	public:
		void read()
		{
			Item::read();
			Sale::read();
			cout<<"\n Enter Type :";
			cin>>type;
			cout<<"\n Enter OS Name :";
			cin>>os;
		}
		void display()
		{
			Item::display();
			Sale::display();
			cout<<"\t"<<type<<"\t"<<os<<endl;
		}
};

void main()
{
	clrscr();
	Hardware h;
	Software s;

	cout<<"\n\n\t Enter Hardware Details \n\n";
	h.read();
	cout<<"\n\n\t Enter Software Details \n\n";
	s.read();
	clrscr();
	cout<<"\n\n\t HARDWARE \n\n";
	h.display();
	cout<<"\n\n\t SOFTWARE \n\n";
	s.display();
getch();
}






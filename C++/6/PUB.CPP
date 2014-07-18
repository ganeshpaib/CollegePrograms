#include<iostream.h>
#include<conio.h>
#include<process.h>

class Publication
{
	private:
		char title[' '];
		float price;
	public:
		void getdata()
		{
			cout<<"\n Enter Title :";
			cin>>title;
			cout<<"\n Enter Price :";
			cin>>price;
		}
		void display()
		{
			cout<<"\t"<<title<<"\t"<<price<<endl;
		}
};
class Sale
{
	private:
		float arr[3];
	public:
		void getdata();
		void display();
};

void Sale::getdata()
{
	int i;

	for(i=0;i<3;i++)
	{
		cout<<"\n Month "<<i+1<<":";
		cin>>arr[i];
	}
}

void Sale::display()
{
	int i;
	for(i=0;i<3;i++)
	{
		cout<<"\t"<<arr[i];
	}
}

class Book:public Publication,public Sale
{
	private:
		int page;
	public:
			void getdata()
			{
				Publication::getdata();
				Sale::getdata();
				cout<<"\n Enter Number Of Pages :";
				cin>>page;
			}
			void display()
			{
				Publication::display();
				Sale::display();
				cout<<"\t"<<page;
			}
};

class Tape:public Publication,public Sale
{
	private:
		int time;
	public:
			void getdata()
			{
				Publication::getdata();
				Sale::getdata();
				cout<<"\n Enter Time :";
				cin>>time;
			}
			void display()
			{
				Publication::display();
				Sale::display();
				cout<<"\t"<<time<<endl;
			}
};

class Pamphlet:public Publication
{
	public:
		void getdata()
		{
			Publication::getdata();
		}
		void display()
		{
			Publication::display();
		}
};
class Notice:public Pamphlet
{
	char whom[20];
	public:
			void getdata()
			{
				Pamphlet::getdata();
				cout<<"\n Enter Whom :";
				cin>>whom;
			}
			void display()
			{
				Pamphlet::display();
				cout<<"\t"<<whom<<endl;
			}
};

void main()
{
	clrscr();
	Book b;
	Tape t;
	Notice n;
	int ch;

	do
	{
		clrscr();
		cout<<"\n\t 1... Book Data";
		cout<<"\n\t 2... Book Display ";
		cout<<"\n\t 3... Tape Data ";
		cout<<"\n\t 4... Tape Display ";
		cout<<"\n\t 5... Notice Data ";
		cout<<"\n\t 6... Notice Display";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
					b.getdata();
					break;
			case 2:
					b.display();
					break;
			case 3:
					t.getdata();
					break;
			case 4:
					t.display();
					break;
			case 5:
					n.getdata();
					break;
			case 6:
					n.display();
					break;
			case 99:
					exit(0);
					break;
		}
		getch();
	}while(ch!=99);
getch();
}












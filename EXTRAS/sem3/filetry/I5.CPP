#include "header.cpp"
int i;
class Publication
{
	protected:
		char title[100];
		int price;
	public:
		void get_data()
		{
			cout << "Enter Title... : ";
			cin.ignore();
			cin.getline(title,75,'\n');
			cout<< "\nEnter Price....: ";
			cin>>price;
		}
		void disp_data()
		{
			cout<< "\nTitle :"<<title<<"\nPrice : "<<price;
		}
};

class Sales
{
	protected:
		int sales[3],totsales;
	public:
		void get_data()
		{
			for( i = 0; i < 3; i++ )
			{
				cout << "Sales["<<i<<"] = ";
				cin>>sales[i];
			}
		}
		int tot_sales()
		{
			totsales=sales[0]+sales[1]+sales[2];
			return totsales;
		}
		void disp_data()
		{
			for(i = 0; i < 3; i++ )
			{
				cout<< "\nSales["<<i<<"] = "<<sales[i];
			}

			cout << "\nTotal Sales... : "<<tot_sales();
		}
};

class Book:public Publication,public Sales
{
	protected:
		int pages;
	public:
		void get_data()
		{
			Publication::get_data();
			cout<< "\nEnter pages : ";
			cin>>pages;
			Sales::get_data();
		}
		void disp_data()
		{
			Publication::disp_data();
			cout << "\nPages : "<<pages;
			Sales::disp_data();
		}
};

class Pamphlet:public Publication
{
};
class Notice:public Pamphlet
{
	protected:
		char whom[100];
	public:
		void get_data()
		{
			Pamphlet::get_data();
			cout<<"\nType of Distributor : ";
			cin>>whom;
		}
		void disp_data()
		{
			Pamphlet:: disp_data();
			cout<<"\nType of Distributor : "<<whom;
		}
};

void main()
{
	Book b;
	Notice n;
	clrscr();
	cout << "\nEnter book publication Data...:";
	b.get_data();
	cout << "\nEnter notice publication data... : ";
	n.get_data();
	b.disp_data();
	n.disp_data();
	getch();
}



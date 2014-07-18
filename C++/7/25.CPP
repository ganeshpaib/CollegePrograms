#include<iostream.h>
#include<conio.h>

class Media
{
	private:
		char title[' '];
		char publication[' '];
	public:
		virtual void read()
		{
			cout<<"\n Enter Title :";
			cin>>title;
			cout<<"\n Enter Publication :";
			cin>>publication;
		}
		virtual void show()
		{
			cout<<"\n"<<title<<"\t"<<publication;
		}
};

class Book:public Media
{
	int page;
	public:
		void read()
		{
			Media::read();
			cout<<"\n Enter Number Of Pages : ";
			cin>>page;
		}
		void show()
		{
			Media::show();
			cout<<"\t"<<page;
		}
};

class Tape:public Media
{
	int time;
	public:
		void read()
		{
			cout<<"\n Enter Playing Time :";
			cin>>time;
		}
		void show()
		{
			cout<<"\t"<<time<<endl;
		}
};

void main()
{
clrscr();
	Tape t;
	Book b;

	Media *ptr[]={&b,&t};

	cout<<"\n\n Enter Book Details \n\n";
	ptr[0]->read();
	cout<<"\n\n Enter Tape Details \n\n";
	ptr[1]->read();
	cout<<"\n\n Book Details \n\n";
	ptr[0]->show();
	cout<<"\n\n Tape Details \n\n";
	ptr[1]->show();
getch();
}




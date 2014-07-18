#include<iostream.h>
#include<conio.h>

class Date
{
	int d,m,y;
	public:
		Date()
		{
			d=m=y=0;
		}
		Date(int d,int m,int y)
		{
			this->d=d;
			this->m=m;
			this->y=y;
		}
		void operator ++(int);
		void read();
		void display();
};

void Date::read()
{
	cout<<"\n Enter Date : ";
	cin>>d;
	cout<<"\n Enter Month :";
	cin>>m;
	cout<<"\n Enter Year : ";
	cin>>y;

}

void Date::display()
{
	cout<<"\n"<<d<<"\\"<<m<<"\\"<<y<<endl;
}

void Date::operator ++(int)
{
	if(m==2 && d==28)
	{
		d=1;
		m++;
	}
	else if(m==2 && (y%4==0||y%100==0 && y%400==0) && d==29)
	{
		d=1;
		m++;
	}
	else if((m==1 || m==3||m==5||m==7||m==8||m==10)&&(d==31))
	{
		d=1;
		m++;
	}
        else if((m==1 || m==3||m==5||m==7||m==8||m==10)&&(d>=32))
        {
        	cout<<"\n Invalid Date "<<endl;
        }
	else if((m==4||m==6||m==9||m==11) && (d==30))
	{
		d=1;
		m++;
	}
        else if((m==4||m==6||m==9||m==11) && (d>=31))
        {
        	cout<<"\n Invalid Date "<<endl;
        }
	else if(m==12&&d==31)
	{
		d=1;
		y++;
		m=1;
	}
        else if(m==12&&d>=32)
        {
        	cout<<"\n Invalid Date "<<endl;
        }
	else
	{
		d++;
	}
}


void main()
{
	Date d;
	clrscr();
	d.read();
	d++;
	d.display();
getch();
}


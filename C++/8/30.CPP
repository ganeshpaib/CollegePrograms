#include<iostream.h>
#include<conio.h>

class Vehicle
{
	char name[' '];
	int wheel_count;
	public:
		void getdata()
		{
			cout<<"\n Enter Vehicle Name : ";
			cin>>name;
			cout<<"\n Enter Wheel Count :";
			cin>>wheel_count;
		}
		void displaydata()
		{
			cout<<"\n"<<name<<"\t"<<wheel_count;
		}
};

class Light:public Vehicle
{
	int speed;
	public:
		void getdata()
		{
			Vehicle::getdata();
			cout<<"\n Enter Speed Limit : ";
			cin>>speed;
		}
		void displaydata()
		{
			Vehicle::displaydata();
			cout<<"\t"<<speed;
		}
};

class Gear:public Light
{
	int count;
	public:
		void getdata()
		{
			Light::getdata();
			cout<<"\n Enter Gear Count : ";
			cin>>count;
		}
		void displaydata()
		{
			Light::displaydata();
			cout<<"\t"<<count<<endl;
		}
};

class Nongear:public Light
{
	public:
		void getdata()
		{
			Light::getdata();
		}
		void displaydata()
		{
			Light::displaydata();
		}
};

class Heavy:public Vehicle
{
	int capacity;
	char permit[2];

	public:
		void getdata()
		{
			Vehicle::getdata();
			cout<<"\n Enter Total Capacity : ";
			cin>>capacity;
			cout<<"\n Permit(y/n) : ";
			cin>>permit;
		}
		void displaydata()
		{
			Vehicle::displaydata();
			cout<<"\t"<<capacity<<"\t"<<permit;
		}
};
class Passenger:public Heavy
{
	int sitcap;
	int stdcap;
	public:
		void getdata()
		{
			Heavy::getdata();
			cout<<"\n Enter Sitting Capacity :";
			cin>>sitcap;
			cout<<"\n Enter Standing Capacity :";
			cin>>stdcap;
		}
		void displaydata()
		{
			Heavy::displaydata();
			cout<<"\t"<<sitcap<<"\t"<<stdcap<<endl;
		}
};

class Goods:public Heavy
{
	public:
		void getdata()
		{
			Heavy::getdata();
		}
		void displaydata()
		{
			Heavy::displaydata();
		}
};

void main()
{
	clrscr();
	Gear g;
	Nongear ng;
	Passenger p;
	Goods go;

	cout<<"\n\n\t Gear Motor Details \n\n";
	g.getdata();
	cout<<"\n\n\t Non Gear Motor Details \n\n";
	ng.getdata();
	cout<<"\n\n\t Passenger Motors Details \n\n";
	p.getdata();
	cout<<"\n\n\t Good Motord Details \n\n";
	go.getdata();

	clrscr();

	cout<<"\n\n\t GEAR MOTORS \n\n";
	g.displaydata();
	cout<<"\n\n\t NON GEAR MOTORS \n\n";
	ng.displaydata();
	cout<<"\n\n\t PASSENGER MOTORS \n\n";
	p.displaydata();
	cout<<"\n\n\t GOODS MOTORS \n\n";
	go.displaydata();
getch();
}




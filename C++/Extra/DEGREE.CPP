#include<iostream.h>
#include<conio.h>
#define PI 3.141592

class Radian
{
	float ra;
	public:
		Radian(){ra=0;}
		Radian(float ra){this->ra=ra;}
		void read(){cin>>ra;}
		void display(){cout<<ra<<endl;}
		float getdata(){return ra;}

};

class Degree
{
	float deg;
	public:
		Degree(){deg=0;}
		Degree(float deg){this->deg=deg;}
		void read(){cin>>deg;}
		void display(){cout<<deg;}
		operator Radian(){return Radian(deg*(float)(PI/180));}
		Degree(Radian r){deg=(float)r.getdata()*(180/PI);}
};

void main()
{
	Radian r;
	Degree d;
	clrscr();
	cout<<"\n Enter Degree :";
	d.read();
	r=d;
	r.display();
	cout<<"\n Enter Radian :";
	r.read();
	d=r;
	d.display();

getch();
}






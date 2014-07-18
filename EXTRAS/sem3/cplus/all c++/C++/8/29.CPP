#include<iostream.h>
#include<conio.h>

class Shape
{
	protected:
		double dim1;
		double dim2;
	public:
		Shape(){dim1=0,dim2=0;}
		virtual void getdata()=0;
		virtual void display_area()=0;
};
class Triangle:public Shape
{
	public:
		void getdata()
		{
			cout<<"\n Enter Base : ";
			cin>>dim1;
			cout<<"\n Enter Heigth : ";
			cin>>dim2;
		}
		void display_area()
		{
			cout<<"\n The Area Is : "<<(0.5*dim1*dim2)<<endl;
		}
};

class Rectangle:public Shape
{
	public:
		void getdata()
		{
			cout<<"\n Enter Length : ";
			cin>>dim1;
			cout<<"\n Enter Breadth :";
			cin>>dim2;
		}
		void display_area()
		{
			cout<<"\n The Area Is : "<<(dim1*dim2)<<endl;
		}
};

void main()
{
	clrscr();
	Triangle t;
	Rectangle r;
	Shape *ptr[]={&t,&r};

	cout<<"\n\n\t TRIANGLE \n\n";
	ptr[0]->getdata();
	ptr[0]->display_area();

	cout<<"\n\n\t RECTANGLE \n\n";
	ptr[1]->getdata();
	ptr[1]->display_area();
getch();
}






#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class Distance
{
	int feet, inches;

	public:

		Distance()
		{
			feet=0;
			inches=0;
		}

		Distance(int f, int i)
		{
			feet=f;
			inches=i;
		}


		~Distance(){};

		void get_data()
		{
			cout << "\n\nFeet : ";
			cin >> feet;

			cout << "\n\nInches : ";
			cin >> inches;
		}

		void sum_distance(Distance d1, Distance d2)
		{
			feet=d1.feet + d2.feet;
			inches=d1.inches + d2.inches;
			if(inches>12)
			{
				feet=feet+1;
				inches=inches-12;
			}
		}

		void disp()
		{

			cout << "\n\nFeet : "<<feet;
			cout << "\n\nInches : "<<inches;
		}

};

void main()
{
	Distance d1,d3,d2;
	clrscr();

	cout << "\n\n\t\t\tINPUT";
	d1.get_data();
	d2.get_data();
	d3.sum_distance(d1,d2);
	cout << " \n\n\n\t\t\RESULTANT DISTANCE " ;
	d3.disp();
	getch();
}


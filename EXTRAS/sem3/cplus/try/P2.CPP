#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<iostream.h>
class Distance
{
	int feet;
	float inches;
	public:
		void setdist(int ft,float in)
		{
			feet=ft;
			inches=in;
		}
		void getdist()
		{
			cout<<"\nEnter feet: " ;
			cin>>feet;
			cout<<"\nEnter inches ";
		}

		void showdist()
		{
			cout<<feet<<"\'-"<<inches<<'\"';
			}
	};

	void main()
	{
		Distance dist1,dist2;

		dist1.setdist(11,6.25);
		dist2.getdist();

		cout<<"\ndist1 = ";dist1.showdist();
		cout<<"\ndist2 = ";dist2.showdist();
	}



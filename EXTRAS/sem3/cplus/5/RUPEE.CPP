#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class Paise
{
	private:
		int data_p;
	public:
	   Paise(){data_p=1;}
	   Paise(int i){data_p=i;}
	   int getPaise() { return data_p;}
	   void display(){cout<<endl << data_p;}

};
class Rupee
{
	private:
		float data_r;
	public:
		Rupee(){data_r=1;}
		Rupee(float i){data_r=i;}
		Rupee(Paise p) { data_r =p.getPaise()/100; }
		operator Paise(){return Paise(data_r*100); }
		void display(){ cout << endl << data_r;}
	   //	operator Rupee(Paise a){}
};

void main()
{
	clrscr();
	Rupee r(1);
	Paise p;
	cout << "\nRupee -> Paise";
	p=r;    	 //r=source p=dest;
	p.display();
	r.display();
	getch();
	cout << "\n Paise -> Rupee";
	r = p;
	p.display();
	r.display();
	getch();
}
#include "header.cpp"

class Rupee
{
	float rs;
	public:
		Rupee()
		{
			rs=0.0;
		}
		Rupee(float r)
		{
			rs=r;
		}
		float getrupee()
		{
			return rs;
		}
		void show()
		{
			cout<<rs;
		}
};

class Paise
{
	int ps;
	public:
		Paise()
		{
			ps=0;
		}
		Paise(int p)
		{
			ps=p;
		}
		Paise(Rupee r)
		{
			float z;
			z=r.getrupee();
			ps=z*100;
		}

		operator Rupee()
		{
			return (Rupee((ps/(float)100)));
		}



		void disp()
		{
			cout<<ps;
		}
};

void main()
{
	clrscr();

	Rupee r;
	Paise p;

	r=1.50;
	p=150;
	cout<< "\nRupee = " ;
	r.show();
	cout<<"\nPaise = ";
	p.disp();
	r=p;

	cout<<"\nrupee = ";
	r.show();
	p=r;
	cout<<"\nPaise = ";
	p.disp();
	getch();
}
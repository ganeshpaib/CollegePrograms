#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class Stud
{
	int rollno;
	char name[20];
	public:
		void get_data()
		{
			cout<< " \nName : ";
			cin>>name;
			cout<< "\nRoll No. : ";
			cin>> rollno;
		}

		void disp_data()
		{
			cout<< "Name : "<< name;
			cout<< "Roll No. : "<< rollno;
		}
};

void main()
{
	Stud **s;

	int n, i;

	s=new Stud*[10];

	cout << " Enter number of students: ";
	cin >> n;

	for( i = 0; i < n; i++ )
	{
		s[i]=new Stud();
		s[i]->get_data();
	}

	for( i = 0; i < n; i++ )
	{
		getch();
		clrscr();
		s[i]->disp_data();
	}

	getch();
}
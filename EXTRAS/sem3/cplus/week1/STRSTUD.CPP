/*
	RESULTS USING CLASS
*/

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
#include<string.h>

int i, j, sno;
class Stud
{

	int rollno;
	char name[20];

	float m[6], avg, tot;
	char grade[6][3];

	public:

	void read_input(int sno)
	{
		int i,j;
		s=new Stud*[sno];
		for( i = 0; i < sno; i++ )
			s[i]=new Stud();

		for( i = 0; i < sno; i++ )
		{

			cout << "Name : ";
			cin >> s[i]->name;

			cout << "\nRoll No. : ";
			cin >> s[i]->rollno;

			cout << "\nMarks : " ;

			s[i]->tot=0;

			for( j = 0; j < 6; j++ )
			{
				cout << "\n" ;
				cout << "M"<<j+1<<" : ";
				cin >> s[i]->m[j];
				s[i]->tot=s[i]->tot + s[i]->m[j];
				temp.result(i,j);

			}

			s[i]->avg=(s[i]->tot/6);


		}
	}
	void disp_output(int );
	void result(int, int );

}**s,temp;

char grade[5];
void main()
{
	int sno,i,j;
	clrscr();

	cout << "Enter number of students : " ;
	cin >> sno;

	temp.read_input(sno);

	temp.disp_output(sno);

	getch();

}


void Stud::disp_output(int sno)
{
	int i,j;
	Stud *t;
	t=new Stud();


	for( i = 0; i < sno-1; i++ )
	{
		for(j = i+1; j < sno; j++ )
		{
			if(s[j]->avg>=s[i]->avg)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	getch();
	clrscr();
	cout<<"\n\n\n\t\t\tRESULTS\n\n";
	cout<<"\nNAME\t"<<"RollNo.\t"<<"M1\t"<<"M2\t"<<"M3\t"<<"M4\t"<<"M5\t"<<"M6\t"<<"AVG";
	cout<<"\n";
	for( i = 0; i < sno; i++ )
	{
		cout <<"\n\n"<< s[i]->name<<"\t"<<s[i]->rollno;
		for( j = 0; j < 6; j++ )
			cout<<"\t"<<s[i]->grade[j];
		cout << "\t"<<s[i]->avg;
	}
}

void Stud:: result(int i, int j)
{

	if((s[i]->m[j]>=90)&&(s[i]->m[j]<=100))
		strcpy(s[i]->grade[j],"A+");



	else if((s[i]->m[j]>=80)&&(s[i]->m[j]<=90))
		strcpy(s[i]->grade[j],"A");


	else if((s[i]->m[j]>=70)&&(s[i]->m[j]<=80))
		strcpy(s[i]->grade[j],"B");

	else if((s[i]->m[j]>=60)&&(s[i]->m[j]<=70))
		strcpy(s[i]->grade[j],"C");

	else if((s[i]->m[j]>=50)&&(s[i]->m[j]<=60))
		strcpy(s[i]->grade[j],"D");

	else
		strcpy(s[i]->grade[j],"F");

}
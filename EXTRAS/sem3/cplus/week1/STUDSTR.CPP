#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
#include<string.h>

struct stud
{
	public:
	int rollno;
	char name[20];

	struct marks
	{
		int m1, m2, m3, avg,tot;
		char grade[12];
	}m;

	void read_input();
	void disp_output(int );
	void result();

}*s,temp;

int sno;
void main()
{
	int sno,i;
	clrscr();

	cout << "Enter number of students : " ;
	cin >> sno;

	s=(struct stud *)malloc(sizeof(struct stud)*sno);


	for( i = 0; i < sno; i++ )
	{
		cout << "Name : ";
		cin >> s[i].name;

		cout << "\nRoll No. : ";
		cin >> s[i].rollno;

		cout << "\nMarks : " ;
		cout << "\nM1 : " ;
		cin >>s[i].m.m1;

		cout << "\nM2 : " ;
		cin >> s[i].m.m2;

		cout << "\nM3 : " ;
		cin >> s[i].m.m3;

		s[i].m.tot=(s[i].m.m1 + s[i].m.m2 + s[i].m.m3);
		s[i].m.avg=(s[i].m.tot/3);

		if((s[i].m.avg>=90)&&(s[i].m.avg<=100))
			strcpy(s[i].m.grade,"A+");
		else if((s[i].m.avg>=80)&&(s[i].m.avg<=90))
			strcpy(s[i].m.grade,"A");
		else if((s[i].m.avg>=70)&&(s[i].m.avg<=80))
			strcpy(s[i].m.grade,"B");
		else if((s[i].m.avg>=60)&&(s[i].m.avg<=70))
			strcpy(s[i].m.grade,"C");
		else if((s[i].m.avg>=50)&&(s[i].m.avg<=60))
			strcpy(s[i].m.grade,"D");
		else
			strcpy(s[i].m.grade,"E");
	}
	temp.disp_output(sno);

	getch();

}


void stud::disp_output(int sno)
{
	int i,j;



	for( i = 0; i < sno-1; i++ )
	{
		for(j = i+1; j < sno; j++ )
		{
			if(s[j].m.avg>=s[i].m.avg)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	getch();
	clrscr();
	cout<<"\n\n\n\t\t\tRESULTS\n\n";
	cout<<"\n\tNAME\t"<<"RollNo.\t\t"<<"M1\t"<<"M2\t"<<"M3\t"<<"GRADE";
	cout<<"\n";
	for( i = 0; i < sno; i++ )
	{
		cout <<"\n\n\t"<< s[i].name<<"\t"<<s[i].rollno<<"\t\t"<<s[i].m.m1<<"\t"<<s[i].m.m2<<"\t"<<s[i].m.m3<<"\t"<<s[i].m.grade;
	}
}
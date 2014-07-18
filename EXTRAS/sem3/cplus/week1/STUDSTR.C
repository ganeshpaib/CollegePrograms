#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
#include<string.h>

struct stud
{
	int rollno;
	char name[20];

	struct marks
	{
		int m1, m2, m3, avg;
		char grade[2];
	}m;

	void read_input();
	void disp_output();
	void result();

}*s,temp;

int sno;
void main()
{
	int sno,i;
	clrscr();

	cout << "Enter number of students : " ;
	cin >> sno;

	s=(struct stud *) malloc(sizeof(struct stud)*sno);


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

		s[i].m.avg=(s[i].m.m1 + s[i].m.m2 + s[i].m.m3)/3;

		if((s[i].m.avg>=90)&&(s[i].m.avg<=100))
			strcpy(s[i].m.grade,"A+");
		else if((s[i].m.avg>=80)&&(s[i].m.avg<=90))
			strcpy(s[i].m.grade,"B");
		else if((s[i].m.avg>=70)&&(s[i].m.avg<=80))
			strcpy(s[i].m.grade,"C");
		else if((s[i].m.avg>=60)&&(s[i].m.avg<=70))
			strcpy(s[i].m.grade,"D");
		else if((s[i].m.avg>=50)&&(s[i].m.avg<=60))
			strcpy(s[i].m.grade,"E");
		else
			strcpy(s[i].m.grade,"F");
	}
	temp.disp_output();

	getch();

}


void stud::disp_output()
{
	int i,j;
	for( i = 0; i < sno-1; i++ )
	{
		for(j = i+1; j < sno; j++ )
		{
			if(strcmp(s[i].name,s[j].name)>0)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}

	cout<<"\nNAME\t"<<"Roll No.\t"<<"M1\t"<<"M2\t"<<"M3\t"<<"GRADE";
	for( i = 0; i < sno; i++ )
	{
		cout <<"\n"<< s[i].name<<"\t"<<s[i].rollno<<"\t"<<s[i].m.m1<<"\t"<<s[i].m.m2<<"\t"<<s[i].m.m3<<"\t"<<s[i].m.grade;
	}
}
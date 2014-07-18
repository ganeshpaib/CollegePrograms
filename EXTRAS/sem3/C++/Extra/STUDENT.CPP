#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct student
{
	int rollno;
	char name[' '];
	struct mark
	{
		int mark1;
		int mark2;
		int mark3;
	}m;
	void read_student();
	void display();
	void avg();
}*s;
int ch,n,i,total;

void main()
{
	clrscr();

	cout<<"Enter Number Of Student : ";
	cin>>n;

	s=(struct student *)malloc(sizeof(struct student)*n);


	do
	{
		clrscr();
		cout<<"\n\t 1... READ STUDENT ";
		cout<<"\n\t 2... DISPLAY STUDENT ";
		cout<<"\n\t 3... AVERAGE ";
		cout<<"\n\t 99.. EXIT ";
		cout<<"Enter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				for(i=0;i<n;i++)
				{
					s[i].read_student();
				}

				break;
			case 2:
				cout<<"\n ROLL_NO \t NAME \t MARK_1 \t MARK_2 \t MARK_3 "<<endl;
				for(i=0;i<n;i++)
				{
					s[i].display();

				}
				break;
			case 3:

				for(i=0;i<n;i++)
				{
					s[i].avg();

				}
				break;
			case 99:
				exit(0);
		}
		getch();
	}while(ch!=99);
getch();
}

void student::read_student()
{
		cout<<"\n Enter Roll_Number : ";
		cin>>s[i].rollno;
		cout<<" Enter Name : ";
		cin>>s[i].name;
		cout<<"Mark_1 : ";
		cin>>s[i].m.mark1;
		cout<<"Mark_2 : ";
		cin>>s[i].m.mark2;
		cout<<" Mark_3 : ";
		cin>>s[i].m.mark3;
}

void student::display()
{
	cout<<"\n"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].m.mark1<<"\t\t"<<s[i].m.mark2<<"\t\t"<<s[i].m.mark3;
}

void student::avg()
{
	total=s[i].m.mark1+s[i].m.mark2+s[i].m.mark3;
	cout<<"\n"<<s[i].name<<" : "<<(total)/3<<endl;
}





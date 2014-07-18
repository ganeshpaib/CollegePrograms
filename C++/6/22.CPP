#include<iostream.h>
#include<conio.h>
#include<process.h>

class Student
{
	protected:
		int rollno;
	public:
		void getdata()
		{
			cout<<"\n Enter Roll Number :";
			cin>>rollno;
		}
		void display()
		{
			cout<<"\t"<<rollno;
		}
};

class Exam:public virtual Student
{
	protected:
		int sub1;
		int sub2;
	public:
		void getmark()
		{
			cout<<"\n Enter Subject 1 :";
			cin>>sub1;
			cout<<"\n Enter Subject 2 :";
			cin>>sub2;
		}
		void display()
		{
			cout<<"\t"<<sub1<<"\t"<<sub2;
		}
};

class Sports:public virtual Student
{
	protected:
		int score;
	public:
		void getscore()
		{
			cout<<"\n Enter Score :";
			cin>>score;
		}
		void display()
		{
			cout<<"\t"<<score;
		}
};

class Result:public Exam,public Sports
{
	int total;
	public:
		void cal()
		{
			getdata();
			getmark();
			getscore();
			total=sub1+sub2+score;
		}
		void display()
		{
			Student::display();
			Exam::display();
			Sports::display();
			cout<<"\t"<<total<<endl;
		}
};

void main()
{
	clrscr();
	Result r;
	int ch;

	do
	{
		clrscr();
		cout<<"\n\t 1... Enter Details ";
		cout<<"\n\t 2... Display ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				r.cal();
				cout<<"\n Calculated..";
				break;
			case 2:
				r.display();
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}








#include<iostream.h>
#include<conio.h>
#include<process.h>

class Student
{
	int rollno;
	char name[' '];
	char branch[' '];
	int yoj;

	public:
		void getdata()
		{
			cout<<"\n Enter RollNo :";
			cin>>rollno;
			cout<<"\n Enter Name :";
			cin>>name;
			cout<<"\n Enter Branch :";
			cin>>branch;
			cout<<"\n Enter YOJ :";
			cin>>yoj;
		}
		void display()
		{
			cout<<"\t"<<rollno<<"\t"<<name<<"\t"<<branch<<"\t"<<yoj<<endl;
		}
};

class Exam : public Student
{
	protected:
		int sub[6];
	public:
		void getmark();
		void display();
};

void Exam::getmark()
{
	int i;
	getdata();
	for(i=0;i<6;i++)
	{
		cout<<"\n Mark_"<<i+1<<":";
		cin>>sub[i];
	}
}

void Exam::display()
{
	int i;
	Student::display();
	for(i=0;i<6;i++)
	{
		cout<<"\t"<<sub[i];
	}
}

class Result:public Exam
{
	int totalmark;
	int result;

	public:
		Result()
		{
			totalmark=0;
			result=0;
		}
		void cal()
		{
			int i;
			getmark();
			for(i=0;i<6;i++)
			{
				totalmark+=sub[i];
			}
		}
		void display()
		{
			Exam::display();
			result=totalmark/60;

			switch(result)
			{
				case 10:
				case 9:
					cout<<" A+ ";
					break;
				case 8:
					cout<<" A ";
					break;
				case 7:
					cout<<" B ";
					break;
				case 6:
					cout<<" C ";
					break;
				case 5:
					cout<<" D ";
					break;
				case 4:
					cout<<" E ";
					break;
				default:
					cout<<" F ";
					break;
			}
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
		cout<<"\n\n\t 1... Enter Details ";
		cout<<"\n\n\t 2... Display Details ";
		cout<<"\n\n\t 99.. Exit ";
		cout<<"\n\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				r.cal();
				cout<<"\n Data Inserted...."<<endl;
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











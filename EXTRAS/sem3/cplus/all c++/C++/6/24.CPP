#include<iostream.h>
#include<conio.h>
#include<process.h>

class Student
{
	int rollno;
	char name[' '];
	public:
		void getdata()
		{
			cout<<"\n Enter Roll Number :";
			cin>>rollno;
			cout<<"\n Entre Name :";
			cin>>name;
		}
		void display()
		{
			cout<<"\t"<<rollno<<"\t"<<name;
		}
};

class Internal:public virtual Student
{

	int sub1,sub2;
	public:
		void getintmark()
		{
			cout<<"\n\t ENTER INTERNAL MARKS (20) \n\n";
			cout<<"\n Subject 1 :";
			cin>>sub1;
			cout<<"\n Subject 2:";
			cin>>sub2;
		}
		void display()
		{
			cout<<"\t"<<sub1<<"\t"<<sub2;
		}
		int intmark()
		{
			return(sub1+sub2);
		}
};
class External:public virtual Student
{
	int sub1,sub2;
	public:
		void getextmark()
		{
			cout<<"\n\t ENTER EXTERNAL MARK (80) \n\n";
			cout<<"\n Subject 1 :";
			cin>>sub1;
			cout<<"\n Subject 2:";
			cin>>sub2;
		}
		void display()
		{
			cout<<"\t"<<sub1<<"\t"<<sub2;
		}
		int extmark()
		{
			return(sub1+sub2);
		}
};

class Result:public Internal,public External
{
	int total;
	int result;

	public:
		Result(){total=0,result=0;}

		void getresult()
		{
			getdata();
			getintmark();
			getextmark();
		}

		void cal()
		{
			total=intmark()+extmark();
			result=total/20;

			switch(result)
			{
				case 10:
				case 9:
					cout<<"\t"<<total<<"\t"<<" A+ "<<endl;
					break;
				case 8:
					cout<<"\t"<<total<<"\t"<<" A "<<endl;
					break;
				case 7:
					cout<<"\t"<<total<<"\t"<<" B "<<endl;
					break;
				case 6:
					cout<<"\t"<<total<<"\t"<<" C "<<endl;
					break;
				case 5:
					cout<<"\t"<<total<<"\t"<<" D "<<endl;
					break;
				case 4:
					cout<<"\t"<<total<<"\t"<<" E "<<endl;
					break;
				default:
					cout<<"\t"<<total<<"\t"<<" F "<<endl;
					break;
			}
		}

		void display()
		{
			Student::display();
			Internal::display();
			External::display();
		}
};

void main()
{
	clrscr();

	Result r;
	r.getresult();
	r.display();
	r.cal();
getch();
}







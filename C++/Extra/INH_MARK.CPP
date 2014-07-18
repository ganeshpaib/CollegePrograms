#include<iostream.h>
#include<conio.h>

class Student
{
	protected:
		char name;
		int roll;
	public:
		void readstudentdata()
		{
			cout<<"\n Enter Name :";
			cin>>name;
			cout<<"\n Enter Roll :";
			cin>>roll;
		}
		void displaystudentdata()
		{
			cout<<"\n"<<name<<"\t"<<roll<<endl;
		}
};

class Internal:public virtual Student
{
	protected:
		int s1;
		int s2;
	public:
		void readintdata()
		{
			cout<<"\n Enter Subject_1 :";
			cin>>s1;
			cout<<"\n Enter Subject_2 :";
			cin>>s2;
		}
		void displayintdata()
		{
			cout<<"\n"<<s1<<"\t"<<s2<<endl;
		}
		int inter()
		{
			return(s1+s2);
		}
};

class External:public virtual  Student
{
	protected:
		int s1;
		int s2;
	public:
		void readextdata()
		{
			cout<<"\n Enter Subject_1 :";
			cin>>s1;
			cout<<"\n Enter Subject_2 :";
			cin>>s2;
		}
		void displayextdata()
		{
			cout<<"\n"<<s1<<"\t"<<s2<<endl;
		}
		int exter()
		{
			return(s1+s2);
		}
};

class Result : public Internal,public  External
{
	public:
		int res()
		{
			return(inter()+exter());
		}
};

void main()
{
clrscr();
	Result r;
	/*r.readstudentdata();
	cout<<"\n Enter Internal Mark \n";
	r.readintdata();
	cout<<"\n Enter External Mark \n";
	r.readextdata();
	cout<<"\n\t RESULT \n\n";
	cout<<"\n "<<r.res();*/

	cout<<sizeof(r)<<endl;
getch();
}





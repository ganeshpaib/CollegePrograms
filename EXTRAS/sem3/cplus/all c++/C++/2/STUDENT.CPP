#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>

class Student
{
	private:
		char name[' '];
		int roll;
		int mark[6];
		int total;
		char grade[3];
	public:

		Student();
		void input_data();
		void display();
		void result();
};

void Student::Student()
{
	strcpy(name,NULL);
	roll=0;
	total=0;
	grade[0]='\0';
	for(int i=0;i<6;i++)
	{
		mark[i]=0;
	}
}

void Student::input_data()
{
	cout<<"\n Enter Name : ";
	cin>>name;
	cout<<"\n Enter Roll Number : ";
	cin>>roll;
	cout<<"\n Enter Marks In 6 Subjects "<<endl;

	for(int i=0;i<6;i++)
	{
		cout<<"\n Mark["<<i+1<<"]:";
		cin>>mark[i];
	}
}

void Student::display()
{
	cout<<"\n"<<name<<"\t"<<roll;

	for(int i=0;i<6;i++)
	{
		cout<<"\t"<<mark[i];
	}
	cout<<"\t"<<total<<"\t"<<grade<<endl;

}

void Student::result()
{


	for(int i=0;i<6;i++)
	{
		total+=mark[i];
	}

	switch(total/60)
	{
		case 10:
		case 9:
			strcpy(grade,"A+");
			break;
		case 8:
			strcpy(grade,"A");
			break;
		case 7:
			strcpy(grade,"B");
			break;
		case 6:
			strcpy(grade,"C");
			break;
		case 5:
			strcpy(grade,"D");
			break;
		case 4:
			strcpy(grade,"E");
		default:
			strcpy(grade,"F");
			break;
	}

}


void main()
{
	clrscr();
	Student **s;
	int n,ch,i,ctr=0;

	cout<<"\n Enter Number Of Students : ";
	cin>>n;

	s=new Student*[n];

	for(i=0;i<n;i++)
	{
		s[i]=new Student();
	}

	do
	{
		clrscr();

		cout<<"\n\t 1... Input";
		cout<<"\n\t 2... Display";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				s[ctr++]->input_data();
				cout<<"\n Added..."<<endl;
				break;
			case 2:
				for(i=0;i<ctr;i++)
				{
					s[i]->result();
				}
				for(i=0;i<ctr;i++)
				{
					s[i]->display();
				}
				break;
			case 99:
				exit(0);
				break;
		}
        	getch();
        }while(ch!=99);
getch();
}




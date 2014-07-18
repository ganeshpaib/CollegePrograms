#include<iostream.h>
#include<conio.h>
#include<process.h>

class Student
{
	char name[' '];
	int roll;
	int age;

	public:
		void read()
		{
			cout<<"\n Enter Name :";
			cin>>name;
			cout<<"\n Enter Roll Number :";
			cin>>roll;
			cout<<"\n Enter Age :";
			cin>>age;
		}
		void display()
		{
			cout<<"\n"<<name<<"\t"<<roll<<"\t"<<age;
		}
		int getage(){return(age);}
};

class UGstudent:public Student
{
	int sem;
	int fees;
	public:
		void read()
		{
			Student::read();
			cout<<"\n Enter Semester :";
			cin>>sem;
			cout<<"\n Enter Fees :";
			cin>>fees;
		}
		void display()
		{	Student::display();
			cout<<"\t"<<sem<<"\t"<<fees;
		}
		int getsem(){return(sem);}
};

class PGstudent:public Student
{
	int sem;
	int fees;
	public:
		void read()
		{
			Student::read();
			cout<<"\n Enter Semester :";
			cin>>sem;
			cout<<"\n Enter Fees :";
			cin>>fees;
		}
		void display()
		{	Student::display();
			cout<<"\t"<<sem<<"\t"<<fees;
		}
		int getsem(){return(sem);}
};

void main()
{
	int ch,pctr=0,uctr=0,i,ctr=0,j,total=0;
	int sem[]={1,2,3,4};
	PGstudent p[20];
	UGstudent u[20];
	clrscr();

	do
	{
		clrscr();

		cout<<"\n\n\t PG STUDENT \n\n";
		cout<<"\n\t 1... Create";
		cout<<"\n\t 2... Display";
		cout<<"\n\t 3... Average Age ";
		cout<<"\n\n\t UG STUDENT \n\n";
		cout<<"\n\t 4... Create ";
		cout<<"\n\t 5... Display ";
		cout<<"\n\t 6... Average Age ";
		cout<<"\n\n\t99.. Exit ";
		cout<<"\n\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				p[pctr++].read();
				break;
			case 2:
				for(i=0;i<pctr;i++)
				{
					p[i].display();
				}
				break;
			case 3:
				for(i=0;i<4;i++)
				{
					ctr=0,total=0;
					for(j=0;j<pctr;j++)
					{
						if(p[j].getsem()==sem[i])
						{
							total+=p[j].getage();
							ctr++;
						}
					}

					if(ctr>=1)
					{

						cout<<"\n Semester "<<i+1<<" :"<<(total/ctr);
					}
					else
					{
						cout<<"\n Semester "<<i+1<<" : "<<ctr;
					}

				}
				break;
			case 4:
				u[uctr++].read();
				break;

			case 5:
				for(i=0;i<uctr;i++)
				{
					u[i].display();
				}
				break;

			case 6:
				for(i=0;i<4;i++)
				{
					ctr=0,total=0;
					for(j=0;j<uctr;j++)
					{
						if(u[j].getsem()==sem[i])
						{
							total+=u[j].getage();
							ctr++;
						}
					}

					if(ctr>=1)
					{

						cout<<"\n Semester "<<i+1<<" :"<<(total/ctr);
					}
					else
					{
						cout<<"\n Semester "<<i+1<<" : "<<ctr;
					}

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







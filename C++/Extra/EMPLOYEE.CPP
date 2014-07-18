#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>

class Employee
{
	int emp_no;
	char emp_name[' '];
	float emp_sal;
	Employee *link;

	public:
		Employee()
		{
			emp_no=0;
			emp_name[0]='\0';
			emp_sal=0;
			link=NULL;
		}
		Employee(int no,char *s,float sa)
		{
			emp_no=no;
			strcpy(emp_name,s);
			emp_sal=sa;
			link=NULL;
		}

		Employee * add_beg(Employee *);
		void add_end(Employee *);
		void display();
		Employee * rev();
};

Employee* Employee::add_beg(Employee *ptr)
{
	Employee *t=this;
	ptr->link=t;
	t=ptr;
	return(t);
}

void Employee::add_end(Employee *ptr)
{
	Employee *t=this;
	for(;t->link!=NULL;t=t->link);
	t->link=ptr;
}

void Employee::display()
{
	Employee *t=this;

	for(;t!=NULL;t=t->link)
	{
		cout<<"\t"<<t->emp_no<<"\t"<<t->emp_name<<"\t"<<t->emp_sal<<endl;

	}
}

Employee* Employee::rev()
{
	Employee *ptr=this,*mid=NULL,*prev;

	while(ptr!=NULL)
	{
		prev=mid;
		mid=ptr;
		ptr=ptr->link;
		mid->link=prev;
	}
	return(mid);
}

void main()
{
	clrscr();
	Employee *ptr=NULL;
	Employee *node=NULL;
	int ch,no,sal;
	char name[' '];

	do
	{
		clrscr();
		cout<<"\n\t 1... Add_beg ";
		cout<<"\n\t 2... Add_end ";
		cout<<"\n\t 3... Dislay";
		cout<<"\n\t 4... Reverse";
		cout<<"\n\t 5... Sort(Emp_No) ";
		cout<<"\n\t 6... Sort(Emp_Name) ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\n Enter Employee Number : ";
				cin>>no;
				cout<<"\n Enter Employee Name :";
				cin>>name;
				cout<<"\n Enter Employee Salary :";
				cin>>sal;

				node=new Employee(no,name,sal);

				if(ptr==NULL)
				{
					ptr=node;
					cout<<"\n First Node Created...";
				}
				else
				{
					ptr=ptr->add_beg(node);
					cout<<"\n Added....";
				}
				break;
			case 2:
				cout<<"\n Enter Employee Number : ";
				cin>>no;
				cout<<"\n Enter Employee Name :";
				cin>>name;
				cout<<"\n Enter Employee Salary :";
				cin>>sal;

				node=new Employee(no,name,sal);

				if(ptr==NULL)
				{
					ptr=node;
					cout<<"\n First Node Created...";
				}
				else
				{
					ptr->add_end(node);
					cout<<"\n Added....";
				}
				break;
			case 3:
				ptr->display();
				break;
			case 4:
				ptr=ptr->rev();
				cout<<"\n Reversed..."<<endl;
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}







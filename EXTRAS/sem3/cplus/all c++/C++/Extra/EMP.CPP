#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>

typedef class Employee *emp_ptr;
typedef class Employee
{
	int emp_no;
	char emp_name[' '];
	int salary;
	emp_ptr link;
	public:
		Employee();
		Employee(int,char*,int);
		friend void display(emp_ptr *);
		friend void add_first(emp_ptr *);
		friend void add_last(emp_ptr *);
		friend emp_ptr rev(emp_ptr);
		friend void sort_no(emp_ptr *);
		friend void sort_name(emp_ptr *);
};

Employee::Employee()
{
	emp_no=0;
	emp_name[0]='\0';
	salary=0;
}
Employee::Employee(int n,char *s,int sal)
{
	emp_no=n;
	strcpy(emp_name,s);
	salary=sal;
}

emp_ptr ptr=NULL;


void main()
{
	int ch;
	clrscr();
	do
	{
		clrscr();
		cout<<"\n\t 1... ADD FIRST";
		cout<<"\n\t 2... ADD LAST ";
		cout<<"\n\t 3... DISLAY ";
		cout<<"\n\t 4... REVERSE ";
		cout<<"\n\t 5... SORT(EMP_NO) ";
		cout<<"\n\t 6... SORT(NAME)";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				add_first(&ptr);
				break;
			case 2:
				add_last(&ptr);
				break;
			case 3:
				display(&ptr);
				break;
			case 4:
				ptr=rev(ptr);
				cout<<"\n REVERSED ";
				break;
			case 5:
				sort_no(&ptr);
				break;
			case 6:
				sort_name(&ptr);
				break;

			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

void sort_no(emp_ptr *ptr)
{
	emp_ptr t1,t2,t3;

	for(t1=(*ptr);t1!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if(t1->emp_no>t2->emp_no)
			{
				t3=t1;
				t1=t2;
				t2=t3;
			}
		}
	}

	/*for(emp_ptr t=(*ptr);t!=NULL;t=t->link)
	{
		cout<<"\n"<<t->emp_no<<"\t"<<t->emp_name<<"\t"<<t->salary<<endl;
	}*/

	cout<<"\n Sorted....";
}

void sort_name(emp_ptr *ptr)
{
	emp_ptr t1,t2,t3,t;

	for(t1=(*ptr);t1!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if(strcmp(t1->emp_name,t2->emp_name)>0)
			{
				t3=t1;
				t1=t2;
				t2=t3;
			}
		}
	}

	cout<<"\n Sorted....";
}


emp_ptr rev(emp_ptr ptr)
{
	emp_ptr mid=NULL,temp;

	while(ptr!=NULL)
	{
		temp=mid;
		mid=ptr;
		ptr=ptr->link;
		mid->link=temp;
	}
	return(mid);
}


void  add_last(emp_ptr *ptr)
{
	emp_ptr temp,t;
	temp=(emp_ptr)malloc(sizeof(Employee));
	cout<<"\n Enter Employee Number :";
	cin>>temp->emp_no;
	cout<<"\n Enter Employee Name :";
	cin>>temp->emp_name;
	cout<<"\n Enter Salary :";
	cin>>temp->salary;
	temp->link=NULL;

	if((*ptr)==NULL)
	{
		(*ptr)=temp;
		cout<<"\n Added First Time ";
	}
	else
	{
		for(t=(*ptr);t->link!=NULL;t=t->link);
		t->link=temp;
		cout<<"\n Added ";
	}
}



void add_first(emp_ptr *ptr)
{
	emp_ptr temp;
	temp=(emp_ptr)malloc(sizeof(Employee));

	cout<<"\n Enter Employee Number :";
	cin>>temp->emp_no;
	cout<<"\n Enter Employee Name :";
	cin>>temp->emp_name;
	cout<<"\n Enter Salary :";
	cin>>temp->salary;

	if((*ptr)==NULL)
	{
		temp->link=NULL;
		(*ptr)=temp;
		cout<<"\n FIRST RECORD ADDED";
	}
	else
	{
		temp->link=(*ptr);
		(*ptr)=temp;
		cout<<"\n ADDED ";
	}
}

void display(emp_ptr *ptr)
{
	emp_ptr t;

	for(t=(*ptr);t!=NULL;t=t->link)
	{
		cout<<"\n"<<t->emp_no<<"\t"<<t->emp_name<<"\t"<<t->salary<<endl;
	}
}







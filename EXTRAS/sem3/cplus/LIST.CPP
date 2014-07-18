#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<iostream.h>


class list
{
	list *link;
	int no,salary;
	char name[20];
	public:
		list(){no=0;link=NULL;}
		void addend();
		void addbeg();
		void sortbyno();
		void sortbyname();
		void reverse();
		void disp();
};
list *ptr=NULL;
void list::reverse()
{
	list *t,*temp,*prev;
	for(t=ptr->link;t!=NULL;prev=t,t=t->link)
	{
		if(ptr->link==t)
		{
			ptr->link=t->link;
			temp=ptr;
		}
		else
		{
			prev->link=t->link;
			temp=prev;
		}
		t->link=ptr;
		ptr=t;
		t=temp;
	}
}

void list::addend()
{
	clrscr();
	list *temp,*t;
	temp=new list();
	cout<<"ENTER THE NO -> ";
	flushall();
	cin>>temp->no;
	cout<<"ENTER THE NAME -> ";
	flushall();
	cin>>temp->name;
	cout<<"ENTER THE SALARY -> ";
	flushall();
	cin>>temp->salary;
	temp->link=NULL;
	if((ptr)==NULL)
	{
		ptr=temp;
	}
	else
	{
		for(t=ptr;t->link!=NULL;t=t->link);
			t->link=temp;
	}
}
void list:: sortbyno()
{
	int i;
	list *t,*t1,*temp,*prevt,*prevt1;
	for(t=ptr,i=1;t->link!=NULL;i++,prevt=t,t=t->link)
	{

		for(t1=t->link;t1!=NULL;prevt1=t1,t1=t1->link)
		{
			if(t->no>t1->no)
			{
				if(t->link!=t1)
					prevt1->link=t;

				prevt->link=t1;

				if(t->link!=t1)
					temp=t->link;
				else
					temp=t;

				t->link=t1->link;
				t1->link=temp;
				temp=t1;
				t1=t;
				t=temp;
			}
		}
		if(i==1)
			ptr=t;
	}
}

void list:: sortbyname()
{
	int i;
	list *t,*t1,*temp,*prevt,*prevt1;
	for(t=ptr,i=1;t->link!=NULL;i++,prevt=t,t=t->link)
	{

		for(t1=t->link;t1!=NULL;prevt1=t1,t1=t1->link)
		{
			if(strcmp(t->name,t1->name)>0)
			{
				if(t->link!=t1)
					prevt1->link=t;

				prevt->link=t1;

				if(t->link!=t1)
					temp=t->link;
				else
					temp=t;

				t->link=t1->link;
				t1->link=temp;
				temp=t1;
				t1=t;
				t=temp;
			}
		}
		if(i==1)
			ptr=t;
	}
}
void list::addbeg()
{
	clrscr();
	list *temp;
	temp=new list();
	cout<<"ENTER THE NO -> ";
	flushall();
	cin>>temp->no;
	cout<<"ENTER THE NAME -> ";
	flushall();
	cin>>temp->name;
	cout<<"ENTER THE SALARY -> ";
	flushall();
	cin>>temp->salary;
	temp->link=ptr;
	ptr=temp;
}

void list :: disp()
{
	list *t;
	clrscr();
	for(t=ptr;t!=NULL;t=t->link)
	{
		cout<<t->no<<"\t"<<t->name<<"\t"<<t->salary<<endl;
		getch();
	}

}
void main()
{
	list e;
	int n,ch;
	char opt;
	clrscr();
	do
	{
		clrscr();
		cout<<"PRESS 1 -> ADD AT THE END \n";
		cout<<"PRESS 2 -> ADD AT THE BEGENING \n";
		cout<<"PRESS 3 -> DISPLAY \n";
		cout<<"PRESS 4 -> SORTING \n";
		cout<<"PRESS 5 -> REVERSE \n";
		cout<<"PRESS 6 -> EXIT \n\n\n";
		cout<<"\t\t\tENTER YOUR CHOICE -> ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					do
					{
						e.addend();
						clrscr();
						cout<<"DO U WANT TO ADD 1 MORE [Y/N] -> ";
						cin>>opt;
						strupr(&opt);

					}while(opt=='Y');
					break;
			case 2:
					do
					{
						e.addbeg();
						clrscr();
						cout<<"DO U WANT TO ADD 1 MORE -> ";
						cin>>opt;
						strupr(&opt);
					}while(opt=='Y');

					break;
			case 3:
					e.disp();
					break;
			case 6: exit(0);
			case 4:
					int ch;
					clrscr();
					cout<<"PRESS 1 -> SORT BY NAME \n";
					cout<<"PRESS 2 -> SORT BY NUMBER \n";
					cin>>ch;
					switch(ch)
					{
						case 1: e.sortbyname();
								clrscr();
								cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tSORTED";
								break;
						case 2:e.sortbyno();
								clrscr();
								cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tSORTED";
								break;
					}
					break;
			case 5:
					e.reverse();
					clrscr();
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tREVERSED";
					break;
		}getch();
	}while(ch!=6);
}








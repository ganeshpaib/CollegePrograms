#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdlib.h>

class List
{
	int data;
	List *link;

	public:
		List()
		{
			data=0;
			link=NULL;
		}
		List(int d)
		{
			data=d;
			link=NULL;
		}
		List* add_beg(List *);
		void add_end(List *);
		void display();
		List* rev();
		void del_end();
		void sort();
};

void List::del_end()
{
	List *t=this;

	for(;t->link!=NULL;t=t->link);
	t->link=NULL;
}


void List::sort()
{
	List *ptr=this,*t1,*t2;
	int temp;

	for(t1=ptr;t1!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if(t1->data>t2->data)
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
		}
	}
}


List* List::rev()
{
	List *ptr=this,*mid=NULL,*prev;

	while(ptr!=NULL)
	{
		prev=mid;
		mid=ptr;
		ptr=ptr->link;
		mid->link=prev;
	}
	return(mid);
}

List* List::add_beg(List *node)
{
	List *t=this;
	node->link=t;
	t=node;
	return(t);
}

void List::add_end(List *node)
{
	List *t=this;
	for(;t->link!=NULL;t=t->link);
	t->link=node;
}

void List::display()
{
	List *t=this;

	for(;t!=NULL;t=t->link)
	{
		cout<<"\t"<<t->data;
	}
}



void main()
{
	int ch,d;
	List *ptr=NULL;
	List *node=NULL;
	clrscr();
	do
	{
		clrscr();
		cout<<"\n\t 1... Add_Beg ";
		cout<<"\n\t 2... Add_End ";
		cout<<"\n\t 3... Display ";
		cout<<"\n\t 4... Reverse ";
		cout<<"\n\t 5... Sort ";
		cout<<"\n\t 6... Del_End";
		cout<<"\n\t 7... Del_Beg";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\n Enter Data :";
				cin>>d;
				node=new List(d);

				if(ptr==NULL)
				{
					ptr=node;
					cout<<"\n Add..."<<endl;
				}
				else
				{
					ptr=ptr->add_beg(node);
					cout<<"\n Added..."<<endl;
				}
				break;
			case 2:
				cout<<"\n Enter Data :";
				cin>>d;
				node=new List(d);

				if(ptr==NULL)
				{
					ptr=node;
					cout<<"\n Add..."<<endl;
				}
				else
				{
					ptr->add_end(node);
					cout<<"\n Added..."<<endl;
				}
				break;

			case 3:
				ptr->display();
				break;
			case 4:
				ptr=ptr->rev();
				cout<<"\n Reversd "<<endl;
				break;
			case 5:
				ptr->sort();
				cout<<"\n Sorted..."<<endl;
				break;
			case 6:
				ptr->del_end();
				cout<<"\n Last Element Deleted.."<<endl;
				break;
			case 99:
				exit(0);
		}
		getch();
	}while(ch!=99);
getch();
}



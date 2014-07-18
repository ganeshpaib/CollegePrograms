#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <process.h>
class List
{
	int data;
	List *link;
	public:
	void add_end()
	{
		List *t,*temp;
		temp=new List();
		printf("\nEnter the data u want to enter... : " );
		scanf( "%d",&data);

		temp->data=data;
		temp->link=NULL;

		if((ptr)==NULL)
		{
			(ptr)=temp;
		}
		else
		{
			for(t=(ptr); t->link!=NULL;t=t->link);
			t->link=temp;
		}
	}



	void disp()
	{
		List *t;
		for(t=(ptr);t!=NULL;t=t->link)
			printf( "\n%d", t->data );
	}
	void sort();

	void disp_data(List *ptr)
	{
		List *t;
		for(t=(ptr);t!=NULL;t=t->link)
			printf( "\n%d", t->data );
	}

	List reverse_list();
};


List *ptr=NULL;
List temp1;
void List:: sort()
	{
		List *t, *t1;

		int temp;

		for(t=ptr;t->link!=NULL;t=t->link)
		{
			for(t1=t->link;t1!=NULL;t1=t1->link)
			{
				if((t->data)>=(t1->data))
				{
					temp=t->data;
					t->data=t1->data;
					t1->data=temp;
				}
			}
		}
	}

List List::reverse_list()
{
	List *mid,*prev;
	mid=NULL;
	while(ptr!=NULL)
	{
		prev=mid;
		mid=ptr;
		ptr=ptr->link;
		mid->link=prev;
	}
	return (*mid);
}

void main()
{
	List *mid;
	int ch;
	do
	{
		getch();
		clrscr();

		printf( "\n    1 ->ADD");
		printf( "\n	   2 ->DISPLAY") ;
		printf( "\n	   3 ->SORT" );
		printf( "\n	   4 ->REVERSE" );
		printf( "\n	   99 ->Exit" );
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: temp1.add_end();
					break;
			case 2: temp1.disp();
					break;
			case 3: temp1.sort();
					break;
			case 4: (*mid)=temp1.reverse_list();
					temp1.disp_data(mid);
					break;
			case 99: exit(0);
		}
		getch();
	}while(ch!=99);
	getch();
}





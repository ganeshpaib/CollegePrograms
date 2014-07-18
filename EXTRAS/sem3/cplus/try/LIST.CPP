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
		for(t=ptr;t!=NULL;t=t->link)
			printf( "\n%d", t->data );
	}
	void sort();
};


List *ptr=NULL;
List temp1;
void List:: sort()
	{
		List *t, *t1,*temp,*prev=NULL,*prevt,*prevt1;
		int tem,flg=0,i=0;

		for(t=ptr;t->link!=NULL;prev=t,t=t->link)
		{
			for(t1=t->link;;)
			{
				if((t->data)>=(t1->data))
				{

					temp->link=t1->link;          /*initializing*/
					prevt->link=t;
					prevt1->link=t1->link;

					t->link=t1->link;
					t1->link=t;
					prev->link=t1;

					if( temp->link==NULL)
						break;
					else
					{
						prev=t1;
						t=prevt->link;
						t1=prevt1->link;

					}
				}
				else if((t1->link)!=NULL)
					t1=t1->link;
				else
					break;

			}
		}
	}
void main()
{

	int ch;
	do
	{
		clrscr();

		printf( "\n    1 ->ADD");
		printf( "\n	   2 ->DISPLAY") ;
		printf( "\n	   3 ->SORT" );
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
			case 99: exit(0);
		}
		getch();
	}while(ch!=99);
	getch();
}





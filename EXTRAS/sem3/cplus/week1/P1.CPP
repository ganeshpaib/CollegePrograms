#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>

class Tollbooth
{
	int pcar,upcar;
	double  amt;

	public:
		Tollbooth(){pcar=0,upcar=0,amt=0.0;}
		void payingcar();
		void display();
		void countcar(char);
}t;

void main()
{
	char ch, entry;
	do
	{
		clrscr();

		printf( "\n\n\n\n\n\t\t\tPRESS 'Y' to INPUT 'E' to EXIT \n" );
		printf( "\n\n\n\n\t\tEnter ur choice..........: " );
		flushall();
		scanf( "%c",&ch);

		strupr(&ch);
		switch(ch)
		{
			case 'Y': clrscr();
					  printf( "\n\n\n\n\n\t\tPAID ENTRY(Y) \\ UNPAID ENTRY (N)..... : ");
					  flushall();
					  scanf( "%c",&entry );
					  strupr(&entry);

					  if(entry=='Y')
					  {
						t.payingcar();
						t.countcar(entry);
					  }
					  else if(entry=='N')
					  {
						t.countcar(entry);
					  }
					  else
						break;

					  getch();
					  break;

			case 'E' :  clrscr();
						t.display();
						getch();
						exit(0);
		}
	}while(ch!='E');
	getch();
}


void Tollbooth::payingcar()
{
		t.amt=t.amt+0.5;
}

void Tollbooth::countcar(char entry)
{
	printf( "\n\n\n\n\n\n\n\n\t\t\tDATA ENTERED......." );
	if(entry=='Y')
		t.pcar=t.pcar+1;
	else
		t.upcar=t.upcar+1;
}

void Tollbooth::display()
{
	printf( "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tSTATISTICS" );
	printf(" \n\n\n\t\t\tอออออออออออ   ออออออออออออ" );
	printf( "\n\n\n\t\t\tNUMBER OF PAID CARS : %d",t.pcar );
	printf( "\n\n\t\t\tNUMBER OF UNPAID CARS : %d",t.upcar );
	printf(" \n\n\n\n\t\t\tอออออออออออ   ออออออออออออ" );
	printf( "\n\n\n\t\t\tTOTAL AMOUNT : %.2lf",t.amt );
}
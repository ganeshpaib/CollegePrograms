#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
void main()
{
clrscr();
	int x1,x2;
	struct time t;
	gettime(&t);
	x1=t.ti_sec;
	sleep(10);
	gettime(&t);
	x2=t.ti_sec;

	cout<<x2-x1<<endl;
getch();
}



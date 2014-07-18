#include "header.cpp"
#include "inpkrus.cpp"
#include "sortkrus.cpp"
#include "findkrus.cpp"
#include "cyclekru.cpp"

struct kruscle
{
	int u,v;
}s;

void main()
{
	clrscr();
	input();
	sort();

	printf( "Result : \n\n" );

	cycle();

	getch();
}

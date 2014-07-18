#include <stdio.h>
#include <conio.h>

class sample
{
	int data;
	public:
		void get_data()
		{
			printf( "\nnum : " );
			scanf( "%d",&data );

		}
		void prin();

}s,s1;
void sample:: prin()
		{
			printf( "\naddr mem = %ld",&s.data );
			printf( "\nnum = %d",data );
		}

void main()
{
  //	sample s;
	clrscr();
	s.get_data();

	s.prin();
	printf("\naddr obj = %ld",&s);
	s1.get_data();

	s1.prin();
	printf("\naddr obj = %ld",&s1);

	getch();
}
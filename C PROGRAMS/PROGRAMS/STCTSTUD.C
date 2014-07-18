#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
 {
	struct student
	 {
		int regno;
		char name[20];
	 }s1,s2;


	clrscr();

	printf( " Enter first student information :\n " );
	printf( " Enter regno :\n " );
	scanf("%d",&s1.regno);
	printf( " Enter name :\n ");
	flushall();
	scanf("%[^\n]",s1.name);

	printf( " Enter second student information :\n " );
	printf( " Enter regno :\n " );
	scanf("%d",&s2.regno);
	printf( " Enter name :\n " );
	flushall();
	scanf("%[^\n]",s2.name);

	printf( " \t\tSTUDENT INFORMATION \n " );
	printf( "\t--------------------------------\n " );
	printf( " \t\tRegno\tName\n " );
	printf( "\t\t%d\t%s\n",s1.regno,s1.name);
	printf( "\t\t%d\t%s",s2.regno,s2.name);

	getch();
 }
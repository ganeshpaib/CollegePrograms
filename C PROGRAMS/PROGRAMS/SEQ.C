#include<stdio.h>
#include<conio.h>

struct employee
{
	int eno;
	char ename[20];
}e;

main()
{
	FILE *fp;
	char ch;
	clrscr();

	printf( "ENTER THE DETAILS OF THE EMPLOYEE\n" );
	fp=fopen("employee.dat","w");

	do
	{
		printf( "\nEnter employee details :\n " );

		printf( "Employee name : " );
		flushall();
		scanf( "%[^\n]",e.ename );

		printf( "\nEmployee no. : " );
		flushall();
		scanf( "%d",&e.eno );

		fprintf(fp,"%s\t%d\t",e.ename,e.eno);

		printf( "Enter 'Y' to continue\n" );
		flushall();
		ch=getchar();
		ch=toupper(ch);

	}while(ch=='Y');

	fclose(fp);
	getch();
}
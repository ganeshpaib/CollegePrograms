struct teacher
{
	int tno;
	char tname[10];
	char tsubject[10];
};

#include<stdio.h>
#include<conio.h>
main()
{
	struct teacher t;
	FILE *fp,fp1;
	int choice;
	clrscr();

	fp=fopen("teacher.dat","rb+");

	do
	{
		printf( "ENTER YOUR CHOICE!!!!!\n" );
		printf( "1 -> ADD RECORD\n" );
		printf( "2 -> SEARCH RECORD\n" );
		printf( "3 -> DISPLAY RECORD\n" );
		printf( "4 -> DELETE RECORD\n" );
		printf( "5 -> UPDATE RECORD\n" );
		printf( "6 -> EXIT\n" );
		scanf( "%d",&choice );

		switch(choice)
		{
			case 1:
				   fseek( fp, 0, SEEK_END);
				   printf( "ENTER THE DETAILS\n" );

				   printf( "Enter Number : " );
				   flushall();
				   scanf( "%d",&t.tno );

				   printf( "Enter Name : " );
				   flushall();
				   scanf( "%[^\n]",t.tname );

				   printf( "Enter Subject : " );
				   flushall();
				   scanf( "%[^\n]",t.tsubject );

				   fwrite(&t, sizeof(t),1,fp);
				   break;

		}
	}while(choice!=6);
	fclose(fp);
  getch();
}
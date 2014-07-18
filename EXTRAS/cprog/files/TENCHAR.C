#include<stdio.h>
#include<conio.h>
main()
{
	FILE *fp1;
	char c;
	int count=1,line=0;
	clrscr();

	fp1=fopen("char.dat","w");
	printf( "Enter the contents into the file\n" );
	do
	{
		c=getchar();
		putc(c,fp1);
		if(c=='\n')
			line++;

	}while(c!=EOF);
	fclose(fp1);

	fp1=fopen("char.dat","r");
	printf( "Content of the file:\n" );
	while((c=getc(fp1))!=EOF)
	{
		if(c!='\n'&&count<=10)
		{
			putchar(c);
		}
		else if(c=='\n')
		{
			count=0;
			printf( "\n" );
		}

	 count++;
	}
	fclose(fp1);
	getch();
}
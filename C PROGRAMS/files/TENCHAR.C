#include<stdio.h>
#include<conio.h>
main()
{
	FILE *fp1,*fp2;
	char c;
	int count=1,line=0;
	clrscr();

       /*	fp1=fopen("hi1.doc","w");
	printf( "Enter the contents into the file\n" );
	do
	{
		c=getchar();
		putc(c,fp1);
		if(c=='\n')
			line++;

	}while(c!=EOF);
	fclose(fp1);    */

	fp1=fopen("abc.mp3","rb");
	fp2=fopen("d:\baby.mp3","wb");

	printf( "Content of the file:\n" );
	while((c=getc(fp1))!=EOF)
	{
		if(c!='\n'&&count<=10)
		{
			putc(c,fp2);
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
	fclose(fp2);
	getch();
}
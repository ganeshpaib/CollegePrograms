#include<stdio.h>
#include<conio.h>
main()
{
	FILE * fp;
	int i;
	long int recsize;
	char ch;
	clrscr();
	fp=fopen("al12.dat","ab");
	printf( "Enter the alphabets\n" );
	recsize=2l;
	for( i = 0 ; i < 26; i++ )
	{
		flushall();
		scanf( "%c",&ch);
		fputc(ch,fp);
	}

	fclose(fp);

	fp=fopen("al12.dat","rb");
	fseek(fp,0,SEEK_END);

	do
	{
		putchar(ch=fgetc(fp));
		fseek(fp,-recsize,SEEK_CUR);
	}while(ftell(fp)>=1);

	fclose(fp);
	getch();
}
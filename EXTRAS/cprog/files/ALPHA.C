/*
	PROGRAM TO COUNT NUMBER OF ALPHABETS, DIGITS, SPACES & SPECIAL CHARECTERS
	IN A TEXT FILE
*/

#include<stdio.h>
#include<conio.h>
main()
{
	FILE *fp1;
	char c;
	int spchar=0,alpha=0,digit=0,space=0;
	clrscr();

	fp1=fopen("try.dat","w");
	printf( "Enter the string\n" );
	while((c=toupper(getchar()))!=EOF)
	{
		fputc(c,fp1);

		if(c>='A'&&c<='Z')
			alpha++;
		else if(c>='0'&&c<='9')
			digit++;
		else if(c==' '||c=='\t')
			space++;
		else if(c!='\n')
			spchar++;
	}

	printf( "NUMBER OF ALPHABETS = %d \n",alpha );
	printf( "NUMBER OF DIGITS = %d\n",digit );
	printf( "NUMBER OF SPACES = %d\n",space );
	printf( "NUMBER OF SPECIAL CHARECTERS = %d\n ",spchar);
	fclose(fp1);
	getch();
}
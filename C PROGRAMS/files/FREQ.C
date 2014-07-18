/*
   PROGRAM TO DISPLAY FREQUENCY OF EACH CHARECTER IN A STRING USING FILES
*/


#include<stdio.h>
#include<conio.h>
main()
{
	FILE *fp1;
	char c,search;
	int l=0,a=0,i,j,w,count=0;
	static int b[20][30];
	clrscr();

	fp1=fopen("alpha.dat","w");

	printf( "Enter the data\n" );



	do
	{
		c=getchar();
		c=toupper(c);
		putc(c,fp1);
		if(c=='\n'||c==EOF)
		{
			l++;
		}

	}while(c!=EOF);

	fclose(fp1);

	printf( "ENTER A SEARCH CHARECTER\n" );
	scanf( "%c",&search);
	search=toupper(search);

	fp1=fopen("alpha.dat","r");

	while((c=getc(fp1))!=EOF)
	{
		if(c==search)
			count++;

		while(c=='\n')
		{
			a++;
			break;
		}

		b[a][c-65]=b[a][c-65]+1;
	}

	printf( "%c has repeated %d times in the entered string\n",search,count );

	printf( "The frequency is \n" );
	for(w=0;w<=25;w++)
		printf("%c",65+w);
	printf("\n");
	for( w = 0; w < l-1; w++ )
	{
		for( j = 0; j <=25; j++ )
		{

			printf("%d",b[w][j]);
		}
		printf("\n");
	}

	printf( "\n\n" );
	for( i = 0; i <l-1; i++ )
	{
	 printf( "%d line:\n ",i);
	 for(j=0;j<26;j++)
	 {
	  c=j+65;
	  if(b[i][j]>0)
	  printf( "%c HAS OCCURED %d TIMES\n",c,b[i][j]);
	 }
	}
	fclose(fp1);
	getch();
}



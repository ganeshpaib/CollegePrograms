/*
  PROGRAM TO COUNT NUMBER OF TIMES AN ENTERED WORD IS REPEATED IN A STRING
*/

#include<stdio.h>
#include<conio.h>
main()
{
	int n,i=0,j=0,k=0,wcount=0,l1,l2,flg=0;
	char str1[50],str2[50];
	clrscr();

	printf( "Enter the string\n" );
	flushall();
	scanf( "%[^\n]",str1 );

	printf( "Enter the string to be searched\n" );
	flushall();
	scanf( "%[^\n]",str2 );


	l2=strlen(str2);


	search:     if(str1[i]=='\0')
					goto end;

				while(str1[i]!=str2[j])
				{
					i++;
				}


					for( k = i; str1[k]!='\0'&&j<l2; k++ )
					{

						if(str1[k]==str2[j])
						{
							flg=1;
							j++;
						}
						else
						{
							flg=0;
							j=0;
							break;
						}
					}

					if(flg==1)
					wcount++;
					i=k;
					j=0;
		goto search;


	end: printf( "%s has repeated %d times\n",str2,wcount );
		 getch();
}
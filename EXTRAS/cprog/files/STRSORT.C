#include<stdio.h>
#include<conio.h>

main()
{
	FILE *fp;
	char str[20][20],a[20][20],sname[10],temp[10][10];
	int i = 0, ch,j,k,l;
	clrscr();


	fp=fopen("word.dat","ab+");
	do
	{

		printf( "Enter a word\n" );
		scanf( "%s",str[i]);
		fprintf(fp,"%s\n",str[i]);

		printf( "press 'Y' to enter another word\n" );
		flushall();
		ch=toupper(getchar());

	}while(ch=='Y');
	rewind(fp);
	while(fscanf(fp,"%s",sname)!=EOF)
	{
		strcpy(a[i],sname);
		i++;
	}


	printf( "1 -> Sort\n" );
	printf( "2 -> Remove duplicates\n" );
	flushall();
	scanf( "%d",&ch );

	switch(ch)
	{
		case 1:for( j = 0; j < i; j++ )
				{
					for( k = j + 1; k <= i; k++ )
					{
						if(strcmp(a[j],a[k])>0)
						{
							strcpy(temp,a[j]);
							strcpy(a[j],a[k]);
							strcpy(a[k],temp);
						}
					}
				}

			   for( j = 0 ; j <=i; j++ )
			   {
					printf( "%s\n",a[j]);
			   }
			   break;

		case 2:  for( j = 0; j < i; j++ )
				{
					for( k = j + 1; k <= i; k++ )
					{
						if(strcmp(a[j],a[k])==0)
						{
							for(l = k; l <= i; l++ )
							{
								strcpy(a[l],a[l+1]);
							}
							i=i-1;
						}
					}
				}

				for(j = 0; j < i; j++ )
				{
					printf( "%s",a[j]);
				}
				break;
	 }

	fclose(fp);

	getch();

}
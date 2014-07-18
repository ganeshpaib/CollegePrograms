#include<stdio.h>
#include<conio.h>

struct stud
{
	int roll;
	char name[20];
}s,s1[10],temp;

main()
{
	FILE *fp,*fp1;
	int ch,n,i,j,k;
	char sname[20];
	long int recsize;
	clrscr();

	recsize=sizeof(s);

	printf( "1 -> ADD RECORD\n" );
	printf( "2 -> DISPLAY RECORD ALPHABETICALLY\n" );
	printf( "3 -> UPDATE RECORD\n" );
	printf( "4 -> DELETE RECORD\n" );
	scanf( "%d",&ch );

	switch(ch)
	{
		case 1: fp=fopen( "sinf1234.dat","ab");

				printf( "How many student info do u want to insert?\n" );
				flushall();
				scanf( "%d",&n);

				for( i = 0 ; i < n ; i++ )
				{
					printf( " NAME : " );
					flushall();
					scanf( "%[^\n]",s.name );

					printf( " ROLL : " );
					flushall();
					scanf( "%d",&s.roll );

					fwrite(&s,sizeof(s),1,fp);
				}


				fclose(fp);
				break;

		case 2: i=0;
				fp=fopen("sinf1234.dat","rb");
				while(fread(&s,sizeof(s),1,fp)==1)
				{
					s1[i]=s;
					i++;

				}

				for( j = 0; j < i; j++ )
				{
					for( k = j + 1; k <=i; k++ )
					{
						if(strcmp(s1[j].name,s1[k].name) > 0)
						{
							temp = s1[j];
							s1[j] = s1[k];
							s1[k] = temp;
						}
					}
				}

				for( j = 0; j <=i; j++ )
				{
					printf( "%s\t%d\n",s1[j].name,s1[j].roll);
				}
				fclose(fp);
				break;

		case 3: fp=fopen("sinf1234.dat","rb+");

				printf( "Enter student name : " );
				flushall();
				scanf( "%[^\n]",sname );

				while(fread(&s,sizeof(s),1,fp)==1)
				{
					if(strcmp(s.name,sname)==0)
					{
						printf( "Enter student name: " );
						flushall();
						scanf( "%[^\n]",s.name );

						printf( "Enter student roll: " );
						flushall();
						scanf( "%d",&s.roll );

						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&s,sizeof(s),1,fp);
					}
				}
				fclose(fp);
				break;

		case 4: fp=fopen( "sinf1234.dat","rb" );
				fp1=fopen( "temp.dat","ab" );
				printf( "Enter the student name to be deleted\n" );
				flushall();
				scanf( "%[^\n]",sname);

				rewind(fp);

				while(fread(&s,sizeof(s),1,fp)==1)
				{
					if(strcmp(sname,s.name)!=0)
					{
						fseek(fp1,0,SEEK_END);
						fwrite(&s,sizeof(s),1,fp1);
					}
				}
				remove("sinf1234.dat");
				rename("temp.dat","sinf1234.dat");
				break;


	}
 getch();
}
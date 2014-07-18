#include<stdio.h>
#include<conio.h>

struct info
{
	char onum[10],rnum[10],mnum[10];
	char name[20],addr[20];
}p,p1;
void sort_name(char );

void main()
{
	FILE *fp,*fp1;
	int ch,flg=0,choice,i,j,len,setflg=0;
	char chaq,name[10],str[10][10];

	long int recsize;
	clrscr();
	menu:
	do
	{
		clrscr();
		printf( " \n\n\t\t\t PERSONAL CONTACTS \n\n" );

		printf( "\t\t様様様様様様様様   様様様様様様様様様\n\n" );
		printf( " \t\t\t1 -> ADD NEW CONTACT\n" );
		printf( " \t\t\t2 -> DISPLAY CONTACT\n" );
		printf( " \t\t\t3 -> SEARCH CONTACT\n" );
		printf( " \t\t\t4 -> DELETE CONTACT\n" );
		printf( " \t\t\t5 -> EXIT\n" );
		printf( "\n\t\t様様様様様様様様   様様様様様様様様様\n\n" );

		printf( "\nEnter ur choice......:   " );
		scanf( "%d",&ch);

		switch(ch)
		{
			case 1: fp=fopen("info2.dat","ab+");
					fp1=fopen("temp2.dat","ab+");
					clrscr();
					flg=0;
					printf( "\t\t\tADD NEW CONTACT INFO:\n" );
                    printf( "\n\t\t様様様様様様様様   様様様様様様様様様\n\n" );
					printf( "\n\nEnter the details....\n\n" );

					printf( "NAME :  " );
					flushall();
					scanf( "%[^\n]",p.name );
					strupr(p.name);

					printf( "\nADDRESS : " );
					flushall();
					scanf( "%[^\n]",p.addr);
					strupr(p.addr);

					printf( "\nTEL. No.(O) : " );
					flushall();
					scanf( "%[^\n]",&p.onum);

					printf( "\nTEL. No.(R) : " );
					flushall();
					scanf( "%[^\n]",&p.rnum);


					while(fread(&p1,sizeof(p1),1,fp)==1)
					{
						flg=0;
						if(strcmp(p1.name,p.name)<1)
						{
							fwrite(&p1,sizeof(p1),1,fp1);
							flg=1;
						}
						else
						 break;
					}
					recsize=sizeof(p);
					fwrite(&p,sizeof(p),1,fp1);
					if(flg!=1)
						fseek(fp,-recsize,SEEK_CUR);
					while(fread(&p1,sizeof(p1),1,fp)==1)
						fwrite(&p1,sizeof(p1),1,fp1);
					fclose(fp);
					fclose(fp1);

					remove("info2.dat");
					rename("temp2.dat","info2.dat");
					remove("temp2.dat");

					getch();

					clrscr();
					printf( "\n\n\n\n\n\n\n\n\n\n\t\t\t\t CONTACT ADDED\n" );
					getch();

					break;

			case 2: clrscr();
					printf( "\n\n\t\t1 -> ALL CONTACTS\n" );
					printf( "\t\t2 -> CHARECTERWISE\n" );
					printf( "\t\tENTER UR CHOICE....: " );
					scanf( "%d",&choice );

					switch(choice)
					{
						case 1: printf( "\t\t CONTACT INFORMATION\n\n" );


								for(chaq='A';chaq<='Z';chaq++)
								{
									sort_name(chaq);

									getch();
								}
								getch();
								goto menu;

						case 2: printf( "Enter the charecter: \n" );
								flushall();
								scanf( "%s",&chaq);
								strupr(&chaq);

								sort_name(chaq);
								getch();
								goto menu;

					}
					break;


			case 3: clrscr();
					fp=fopen("info2.dat","rb" );
					printf( "\n\n\n\t--------------------SEARCH CONTACT----------------------\n" );
					printf( "\n\nEnter the name : " );
					flushall();
					scanf( "%s",name);
					strupr(name);
					len=strlen(name);
					i=0;
					clrscr();
					printf( "\n\n\n\t--------------------CONTACT INFORMATION----------------------\n" );
					printf( "\t            -----------------------------------              \n" );
					printf( "\n\tNAME\t\tADDRESS\t\tOFFICE\t\tRECIDENCE\n" );
					printf( "\t            -----------------------------------              \n" );
					setflg=0;
					while(fread(&p,sizeof(p),1,fp)==1)
					{
						j=0;
						strcpy(str[i],p.name);
						for(j=0;j<len&&(str[i][j]==name[j]);j++);
						if(j==len)
						{
							printf( "\n\t%s\t\t%s\t\t%d\t\t%d\n",p.name,p.addr,p.onum,p.rnum);
							setflg=1;
						}
						i++;
					}
					if(setflg==0)
						printf( "\n\n\n\n\n\n\n\n\n\tSORRY!!!! SEARCH FAILED...... CONTACT NAMED %s DOES'NT EXIST!!!!\n",name );
					fclose(fp);
					getch();
					break;

			case 5: exit();

		}



	}while(ch!=5);
	getch();
}



void sort_name(char cha)
{
	FILE *fp;
	char str[20][20];
	int i;
	fp=fopen("info2.dat","rb+");

	i=0;
	clrscr();
	printf( "\n\n\n\t--------------------CONTACT INFORMATION----------------------\n" );
	printf( "\t                           %c                                \n",strupr(cha) );
	printf( "\t            -----------------------------------              \n" );
	printf( "\n\tNAME\t\tADDRESS\t\tOFFICE\t\tRECIDENCE\n" );
	printf( "\n\t-------------------------------------------------------------\n" );
	while(fread(&p,sizeof(p),1,fp)==1)
	{

		strcpy(str[i],p.name);
		if(strcmp(str[i][0],cha)==0)
			printf("\t%s\t\t%s\t\t%s\t\t%s\n",p.name,p.addr,p.onum,p.rnum);
		i++;
	}
	fclose(fp);
}

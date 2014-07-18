#include<stdio.h>
#include<conio.h>

typedef struct addr_book *ptr_node;

typedef struct addr_book
{
	char name[20],addr[50];
	unsigned long int onum,rnum;
	ptr_node link;
};

main()
{
	char choice,cha,str[20][20],name[20],name1[20];
	int i=0,ch,flg=0,opt,len,j;
	ptr_node temp,ptr=NULL,t;
	FILE *fp,*fp1;

	clrscr();

	do
	{
		menu:
		clrscr();
		printf( "\n\n\t\t様様様様様様様様   様様様様様様様様様\n\n" );
		printf( "\t\t\t1 -> ADD NEW CONTACT\n" );
		printf( "\t\t\t2 -> DISPLAY CONTACT\n" );
		printf( "\t\t\t3 -> DELETE CONTACT\n" );
		printf( "\t\t\t4 -> UPDATE CONTACT\n" );
		printf( "\t\t\t99 ->EXIT\n" );
        printf( "\n\n\t\t様様様様様様様様   様様様様様様様様様\n\n" );


		printf( "Enter your choice : " );
		scanf( "%d",&ch );

		switch(ch)
		{

			case 1: ptr=NULL;
					do
					{
						clrscr();
						temp=(ptr_node)malloc(sizeof(struct addr_book));
						printf( "\n\n\t\t\tPERSONAL DETAILS " );
						printf( "\nNAME : ");
						flushall();
						scanf( "%[^\n]",temp->name );
						strupr(temp->name);

						printf( "\nADDRESS : " );

						flushall();
						scanf( "%[^\n]",temp->addr );
						strupr(temp->addr);

						printf( "\nTELEPHONE NUMBER :\n" );
						printf( "OFFICE : " );
						flushall();
						scanf( "%ld",&temp->onum );

						printf( "RECIDENCE : " );
						flushall();
						scanf( "%ld",&temp->rnum );



						if(ptr==NULL)
						{
							ptr=temp;
							temp->link=NULL;
						}

						for(t=ptr;t->link!=NULL;t=t->link);

							t->link=temp;
							temp->link=NULL;

						printf( "\n\nDO U WANNA ADD ANOTHER CONTACT?????(Y/N)" );
						flushall();
						scanf( "%c",&choice);

						strupr(&choice);

					}while(choice=='Y');

					fp=fopen("addrbook.dat","a+");

					t=ptr;
					while(t!=NULL)
					{
						fprintf(fp,"%s\t%s\t%ld\t%ld\n",t->name,t->addr,t->onum,t->rnum);
						t=t->link;
					}
					fclose(fp);
					ptr=NULL;
					break;

			case 2: clrscr();
					flg=0;
					fp=fopen( "addrbook.dat","r");
					ptr=NULL;
					printf( "\t\t様様様様様様様様   様様様様様様様様様\n\n" );
					printf( "\n    NAME    \tADDRESS\t\tPHONE No.(O)\t\tPHONE No.(R)\n");
                    temp=(ptr_node)malloc(sizeof(struct addr_book));
					do
					{

						if(flg==1)
						{
						if(ptr==NULL)
						{
							ptr=temp;
							temp->link=NULL;
						}
						else
						{
						for(t=ptr;t->link!=NULL;t=t->link);

							t->link=temp;
							temp->link=NULL;
						}
						}
						flg=1;
						temp=(ptr_node)malloc(sizeof(struct addr_book));
					}while(fscanf(fp,"%s%s%ld%ld",temp->name,temp->addr,&temp->onum,&temp->rnum)!=EOF);

					fclose(fp);
					do
					{
						clrscr();
						printf( "1 -> DISPLAY ALL CONTACTS\n" );
						printf( "2 -> DISPLAY CHARECTERWISE\n" );
						printf( "3 -> BACK\n" );
						flushall();
						scanf("%d",&opt );
						switch(opt)
						{
							case 1:
							for(cha='A';cha<='Z';cha++)
							{
								clrscr();
								printf("%c",cha);
                                for(t=ptr;t!=NULL;t=t->link)
								{

									strcpy(str[i],t->name);
									if(str[i][0]==cha)
									{
										printf( "\n%s\t%s\t%ld\t%ld\n",t->name,t->addr,t->onum,t->rnum);
									}
									i++;
								}
								getch();

							}
							break;
						case 2: clrscr();
								printf( "ENTER THE CHARECTER: " );
								flushall();
								scanf("%c",&cha );
								strupr(&cha);

                                for(t=ptr;t!=NULL;t=t->link)
								{

									strcpy(str[i],t->name);
									if(str[i][0]==cha)
									{
										printf( "\n%s\t%s\t%ld\t%ld\n",t->name,t->addr,t->onum,t->rnum);
									}
									i++;
								}
								getch();
								break;
						case 3:goto menu;
						case 5: exit(0);
					   }
					}while(opt!=5);


				break;
		case 3: 	fp=fopen( "addrbook.dat","r");
					fp1=fopen( "temp.dat","a+");
					ptr=NULL;
					printf( "\n    NAME    \tADDRESS\t\tPHONE No.(O)\t\tPHONE No.(R)\n");
                    temp=(ptr_node)malloc(sizeof(struct addr_book));
					do
					{

						if(flg==1)
						{
						if(ptr==NULL)
						{
							ptr=temp;
							temp->link=NULL;
						}
						else
						{
						for(t=ptr;t->link!=NULL;t=t->link);

							t->link=temp;
							temp->link=NULL;
						}
						}
						flg=1;
						temp=(ptr_node)malloc(sizeof(struct addr_book));
					}while(fscanf(fp,"%s%s%ld%ld",temp->name,temp->addr,&temp->onum,&temp->rnum)!=EOF);

					fclose(fp);
					printf( "\nEnter the search data to be deleted : " );
					flushall();
					gets(name);
					strupr(name);
					len=strlen(name);
					 i=0;
                     for(t=ptr;t!=NULL;t=t->link)
								{

									strcpy(str[i],t->name);
									for(j=0;(j<strlen(name))&&(str[i][j]==name[j]);j++);
									if(j==len)
									{
										printf( "\n%s\t%s\t%ld\t%ld\n",t->name,t->addr,t->onum,t->rnum);
									}
									i++;
								}
								getch();
					 printf( "\nEnter the name of the contact to be deleted : " );
					 flushall();
					 gets(name1);
					 strupr(name1);
					 for(t=ptr;t!=NULL;t=t->link)
					 {
						if(strcmp(t->name,name1)==0)
						{
						}
						else
						{
							fprintf(fp1,"%s\t %s\t %ld\t %ld\n",t->name,t->addr,t->onum,t->rnum);
						}
					 }
					 fclose(fp);
					 fclose(fp1);
					 remove("addrbook.dat");
					 rename("temp.dat","addrbook.dat");
					 remove("temp.dat");

					 getch();
					 break;



		case 99: exit();
		}
		getch();

	}while(ch!=99);


	getch();
}
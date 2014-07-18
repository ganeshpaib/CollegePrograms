#include<stdio.h>
#include<conio.h>

typedef struct addr_book *ptr_node;

typedef struct addr_book
{
	char name[20],addr[50],city[20],email[30];
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
		printf( "\n\n1 -> ADD NEW CONTACT\n" );
		printf( "2 -> DISPLAY CONTACT\n" );
		printf( "3 -> DELETE CONTACT\n" );
		printf( "4 -> UPDATE CONTACT\n" );
		printf( "99 ->EXIT\n" );

		printf( "Enter your choice : " );
		scanf( "%d",&ch );

		switch(ch)
		{

			case 1: ptr=NULL;
					do
					{
						temp=(ptr_node)malloc(sizeof(struct addr_book));
						printf( "\n\n\t\t\tPERSONAL DETAILS " );
						printf( "\nNAME : ");
						flushall();
						scanf( "%[^\n]",temp->name );
						strupr(temp->name);

						printf( "\nADDRESS : " );
						printf( "\nSTREET ADDRESS : " );
						flushall();
						scanf( "%[^\n]",temp->addr );
						strupr(temp->addr);

						printf( "CITY : " );
						flushall();
						scanf( "%[^\n]",temp->city );
						strupr(temp->city);

						printf( "\nTELEPHONE NUMBER :\n" );
						printf( "OFFICE : " );
						flushall();
						scanf( "%ld",&temp->onum );

						printf( "\nRECIDENCE : " );
						flushall();
						scanf( "%ld",&temp->rnum );

						printf( "\nEMAIL ADDRESS: " );
						flushall();
						scanf( "%s",temp->email );

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
						printf( "\n\nDO U WANNA ADD ANOTHER CONTACT?????(Y/N)" );
						flushall();
						scanf( "%c",&choice);

						strupr(&choice);

					}while(choice=='Y');

					fp=fopen("addrbook.dat","a+");

					t=ptr;
					while(t!=NULL)
					{
						fprintf(fp,"%s\t%s\t%s\t%ld\t%ld\t%s\n",t->name,t->addr,t->city,t->onum,t->rnum,t->email);
						t=t->link;
					}
					fclose(fp);
					ptr=NULL;
					break;

			case 2: clrscr();
					flg=0;
					fp=fopen( "addrbook.dat","r");
					ptr=NULL;

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
					}while(fscanf(fp,"%s%s%s%ld%ld%s",temp->name,temp->addr,temp->city,&temp->onum,&temp->rnum,temp->email)!=EOF);

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
										clrscr();
                    printf("%c",cha);
										printf( "\nNAME :  %s\n",t->name );
										printf( "\nADDRESS :  %s\n",t->addr );
										printf( "\nCITY :  %s\n",t->city );
										printf( "\nPHONE NUMBER : " );
										printf( "\n(R) :  %ld",t->rnum );
										printf( "\t(O) :  %ld",t->onum );
										printf( "\nEMAIL ADDRESS :  %s",t->email );
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
                  	printf( "\nNAME :  %s\n",t->name );
										printf( "\nADDRESS :  %s\n",t->addr );
										printf( "\nCITY :  %s\n",t->city );
										printf( "\nPHONE NUMBER : " );
										printf( "\n(R) :  %ld",t->rnum );
										printf( "\t(O) :  %ld",t->onum );
										printf( "\nEMAIL ADDRESS :  %s",t->email );

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
		case 3: fp=fopen( "addrbook.dat","r");
					fp1=fopen( "temp.dat","a+");
					flg=0;
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
					}while(fscanf(fp,"%s%s%s%ld%ld%s",temp->name,temp->addr,temp->city,&temp->onum,&temp->rnum,temp->email)!=EOF);

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
							fprintf(fp1,"%s %s %s %ld %ld %s",t->name,t->addr,t->city,t->onum,t->rnum,t->email);
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
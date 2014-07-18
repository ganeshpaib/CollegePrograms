#include<stdio.h>
#include<conio.h>

typedef struct addr_book *ptr_node;

typedef struct addr_book
{
	char name[20],addr[50],hno[10],city[20],state[20],country[20],email[20];
	unsigned long int onum,rnum,mnum,zcode;
	ptr_node link;
};

void main()
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
						printf( "\nHOUSE No. : " );
						flushall();
						scanf( "%s",temp->hno );

						printf( "\nSTREET ADDRESS : " );
						flushall();
						scanf( "%[^\n]",temp->addr );
						strupr(temp->addr);

						printf( "\nCITY : " );
						flushall();
						scanf( "%s",temp->city );
						strupr(temp->city);

						printf ("\nZIP CODE :" );
						flushall();
						scanf( "%ld",&temp->zcode );

						printf( "STATE : " );
						flushall();
						scanf("%s",temp->state );
						strupr(temp->state);

						printf( "COUNTRY : " );
						flushall();
						scanf( "%s",temp->country );
						strupr(temp->country);

						printf( "\nTELEPHONE NUMBER :\n" );
						printf( "\nOFFICE : " );
						flushall();
						scanf( "%ld",&temp->onum );

						printf( "\nRECIDENCE : " );
						flushall();
						scanf( "%ld",&temp->rnum );

						printf( "\nMOBILE No. : " );
						flushall();
						scanf( "%ld",&temp->mnum );

						printf( "\nEMAIL ADDRESS : " );
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
						fprintf(fp,"%s\t%s\t%s\t%s\t%ld\t%s\t%s\t%ld\t%ld\t%ld\t%s\n",t->name,t->hno,t->addr,t->city,t->zcode,t->state,t->country,t->onum,t->rnum,t->mnum,t->email);
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
					}while(fscanf(fp,"%s%s%s%s%ld%s%s%ld%ld%ld%s",temp->name,temp->hno,temp->addr,temp->city,&temp->zcode,temp->state,temp->country,&temp->onum,&temp->rnum,&temp->mnum,temp->email)!=EOF);

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

                                for(t=ptr;t!=NULL;t=t->link)
								{

									strcpy(str[i],t->name);
									if(str[i][0]==cha)
									{
										clrscr();
										printf( "\t\t\t\t%c",cha);

										printf( "\nNAME : %s", t->name );
										printf( "\nADDRESS : " );
										printf( "\nHOUSE No. : %s",t->hno );
										printf( "\nSTREET ADDRESS : %s",t->addr );
										printf( "\nCITY :  %s",t->city );
										printf( "\nZIP CODE : %ld",t->zcode );
										printf( "\nSTATE : %s",t->state );
										printf( "\nCOUNTRY : %s",t->country );
										printf( "\n\nPHONE NUMBER : " );
										printf ("\nRECIDENCE : %ld",t->rnum );
										printf( "\tOFFICE : %ld",t->onum );
										printf( "\tMOBILE : %ld",t->mnum );
										printf( "\n\nEMAIL ADDRESS : %s\n",t->email );
										getch();
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
										clrscr();
                                    	printf( "\nNAME : %s", t->name );
										printf( "\nADDRESS : " );
										printf( "\nHOUSE No. : %s",t->hno );
										printf( "\nSTREET ADDRESS : %s",t->addr );
										printf( "\nCITY :  %s",t->city );
										printf( "\nZIP CODE : %ld",t->zcode );
										printf( "\nSTATE : %s",t->state );
										printf( "\nCOUNTRY : %s",t->country );
										printf( "\n\nPHONE NUMBER : " );
										printf ("\nRECIDENCE : %ld",t->rnum );
										printf( "\tOFFICE : %ld",t->onum );
										printf( "\tMOBILE : %ld",t->mnum );
										printf( "\n\nEMAIL ADDRESS : %s\n",t->email );
										getch();

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
					}while(fscanf(fp,"%s%s%s%s%ld%s%s%ld%ld%ld%s",temp->name,temp->hno,temp->addr,temp->city,&temp->zcode,temp->state,temp->country,&temp->onum,&temp->rnum,&temp->mnum,temp->email)!=EOF);

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
										printf( "\n%s\t%s\t%ld\t%ld\n",t->name,t->city,t->onum,t->rnum);
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
							fprintf(fp1,"%s\t%s\t%s\t%s\t%ld\t%s\t%s\t%ld\t%ld\t%ld\t%s\n",t->name,t->hno,t->addr,t->city,t->zcode,t->state,t->country,t->onum,t->rnum,t->mnum,t->email);
						}
					 }
					 fclose(fp);
					 fclose(fp1);
					 remove("addrbook.dat");
					 rename("temp.dat","addrbook.dat");
					 remove("temp.dat");


					 break;


		case 10: exit();

		}
		getch();

	}while(ch!=10);


	getch();
}
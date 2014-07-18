/*
   Project on car booking system
*/


#include<stdio.h>
#include<conio.h>
#include<string.h>
void upper(char *);
struct car
{
	float cprice;
	int cno,cino,cmodelno;
	char cname[50],ccolor[20];

};
struct accesories
{
	char aname[50];
	int aqty;
	float aprice;
}d,e;

struct cus
{
	char cuscname[20],cusname[20],cuscolor[20];
	int  date,mon,year,cusno,cuscmodel,billno;
	float price,tax,total;
};
struct service
{
   char cname[20],carname[50];
   int cno,billnum,cmon,cyear;
   float tcharge,scharge,mcharge;
}s;

main()
{
	struct car a,c;
	struct cus b;
	int choice,qty,opt,flag=0,flag1=0,n,ans=0,aqty,cusno;
	int month,year,pmon,pyear,cmon,period;
	long int recsize,brecsize,drecsize;
	float price,profit,tot=0,temptot=0,tempcharge,tempmcharge;
	char tempname[20], tempcar[20];
	char ch,sname[20],scolor[20],cname[50],ccolor[20],aname[20],name[20],take;
	FILE *fp,*fp1,*fp2,*fp5;
	b.billno=100;

	start:  clrscr();
		recsize=sizeof(a);
		printf( "ENTER UR CHOICE :\nอออออออออออออออออ");
		printf( "\n\t\tPRESS 1 -> PURCHASES FOR STOCK\n" );
		printf( "\n\t\tPRESS 2 -> STOCK DISPLAY\n" );
		printf( "\n\t\tPRESS 3 -> BOOKING A CAR\n" );
		printf( "\n\t\tPRESS 4 -> DISPLAY CUSTOMER INFO\n" );
		printf( "\n\t\tPRESS 5 -> ACCESSIORIES \n" );
		printf( "\n\t\tPRESS 6 -> SERVICE BILL \n" );
		printf( "\n\t\tPRESS 7 -> PROFIT & SALES \n" );
		printf( "\n\t\tPRESS 9 -> EXIT\n\n\t\t\t\t\tENTER HERE -> " );

		scanf( "%d",&choice );

		if(choice==9)
		{
			printf("\n\t\tYOU HAVE OPTED TO EXIT \n");
			printf("\n\n\t\tPRESS AGAIN TO CONFIRM\n\n\t\t\t\t\tENTER HERE -> ");
			scanf("%d",&choice);
		}

		clrscr();

		switch(choice)
		{                                                                                    /* STOCK PURCHASES */
			case 1:
				printf("\nPRESS 1 -> CAR PURCHASES\n\nPRESS 2 -> ACCESSORIES PURCHASES\n");
				scanf("%d",&opt);
				switch(opt)
				{
					case 1:                                                     /* CAR PURCHASES*/
						ans=0;
						fp=fopen("stock.dat","rb+");

						if ( fp  ==  NULL)
						{
							printf("CANNOT OPEN THE FILE \n");
							exit(1) ;
						}

						do
						{
							clrscr();
							rewind(fp);

							printf("CAR NAME : ");
							flushall();
							scanf( "%[^\n]",a.cname);
							upper(a.cname);

							printf("\nQTY      : ");
							flushall();
							scanf( "%d",&a.cno);

							printf("\nPRICE    : ");
							flushall();
							scanf( "%f",&a.cprice);

							printf("\nMODEL    : ");
							flushall();
							scanf( "%d",&a.cmodelno);

							printf("\nCOLOR    : ");
							flushall();
							scanf( "%[^\n]",a.ccolor);
							upper(a.ccolor);



							rewind(fp);
							while(fread(&c,recsize,1,fp)==1)
							{
								if(strcmp(c.cname,a.cname)==0&&strcmp(c.ccolor,a.ccolor)==0&&a.cmodelno==c.cmodelno)
								{
									c.cno=c.cno+a.cno;
									fseek(fp,-recsize,SEEK_CUR);
									fwrite(&c,recsize,1,fp);
									ans=1;
								}
							}

							if(ans==0)
							{
								fseek(fp,0,SEEK_END);
								fwrite(&a,sizeof(a),1,fp);
							}


							printf( "\n\nDO YOU WANT TO CONTINUE (Y\\N) -> " );
							flushall();
							ch=toupper(getchar());

						} while(ch=='Y');

							fclose(fp);

							goto start;

					case 2:
						do                                                                   /* ACCESORY PURCHASES */
						  {
							clrscr();
							drecsize=sizeof(d);
							fp=fopen("accesory.dat","ab+");
							printf("\n\nEnter the accesory name : ");
							flushall();
							scanf("%[^\n]",d.aname);
							upper(d.aname);
							printf("\nEnter the quantity : ");
							flushall();
							scanf("%d",&d.aqty);
							printf("\nEnter the price : ");
							flushall();
							scanf("%f",&d.aprice);

							fwrite(&d,sizeof(d),1,fp);

							printf("\n\n\nDO YOU WANT TO CONTINUE : ");
							flushall();
							ch=toupper(getchar());
						  } while(ch=='Y');

						  fclose(fp);

						  goto start;
					   }

/* STOCK DISPLAY */

			case 2:
				printf("\n\nPRESS 1 ->DISPLAY CAR STOCK\n\nPRESS 2 ->DISPLAY ACCESSORIES STOCK\n");
				printf( "\n\tENTER YOUR CHOICE..... : " );
				flushall();
				scanf("%d",&opt);
				switch(opt)
				{

					case 1:
							clrscr();
/* CAR DISPLAY */ 						fp=fopen("stock.dat","rb");

						if ( fp  ==  NULL)
						{
							printf("CANNOT OPEN THE FILE \n");
							exit(1) ;
						}

						fseek(fp,0,SEEK_SET);

						printf( "\n\t\t\t STOCK INFORMATION\n" );
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						printf( "\t\tCAR NAME\tMODEL\tCOLOR\tQUANTITY\t\n" );
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ \n");

						while(fread(&a,recsize,1,fp)==1)
						{
							if(a.cno>0)
							{
								if(strlen(a.cname)<8)
								{
									printf("\n\t\t%s\t\t%d\t%s\t   %d\n",a.cname,a.cmodelno,a.ccolor,a.cno);
								}
								else
									printf("\n\t\t%s\t\t%d\t%s\t   %d\n",a.cname,a.cmodelno,a.ccolor,a.cno);
							}
						}

						printf( "\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ \n");

						fclose(fp);

						printf( "\nPRESS Y TO GO TO MAIN MENU -> " );
						flushall();
						ch=toupper(getchar());

						goto start;

				case 2:
						clrscr();
/* ACCESORY DISPLAY */						fp=fopen("accesory.dat","rb+");
						rewind(fp);
						printf("\n\n\t\t\t\tSTOCK DISPLAY\n");
						printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
						printf( "\t\tACCESSORY NAME\t\tQUANTITY\t\tPRICE\n" );
						printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						while(fread(&d,sizeof(d),1,fp)==1)
						{
							if(d.aqty>0)
							{
								if(strlen(d.aname)<8)
									printf("\t\t%s\t\t\t%d\t\t\t%f\n\n",d.aname,d.aqty,d.aprice);
								else
									printf("\t\t%s\t\t%d\t\t\t%f\n\n",d.aname,d.aqty,d.aprice);
							}
						}
						printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						fclose(fp);
						printf( "\n\n\nPRESS Y TO GO TO MAIN MENU -> " );
						flushall();
						ch=toupper(getchar());

						goto start;
				}

			case 3:
/* CAR SALES */				clrscr();
				flag=0;flag1=0;

				fp=fopen("sales.dat","ab+");

				if ( fp  ==  NULL)
				{
					printf("CANNOT OPEN THE FILE \n");
					exit(1) ;
				}

				fp1=fopen("custinfo.dat","ab+");

				if ( fp1 ==  NULL)
				{
					printf("CANNOT OPEN THE FILE \n");
					exit(1) ;
				}

				fp2=fopen("stock.dat","rb+");

				if ( fp2  ==  NULL)
				{
					printf("CANNOT OPEN THE FILE \n");
					exit(1) ;
				}

				printf("\n\t\tENTER THE DETAILS \n" );
				printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");

				printf("\nNAME OF THE CAR  : ");
				flushall();
				scanf("%[^\n]",sname);
				upper(sname);

				printf("\nCOLOR OF THE CAR : ");
				flushall();
				scanf("%[^\n]",scolor);
				upper(scolor);

				printf("\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");

				rewind(fp2);

				brecsize=sizeof(b);
				while(fread(&a,sizeof(a),1,fp2)==1)
				{
					if(strcmp(sname,a.cname)==0&&strcmp(scolor,a.ccolor)==0&&a.cno>0)
					{
						while(fread(&b,sizeof(b),1,fp1)==1)
						{
						}
						b.cusno=b.cusno+1;

						strcpy(b.cuscname,sname);
						strcpy(b.cuscolor,scolor);
						b.cuscmodel=a.cmodelno;

						printf( "\n STOCK IS AVAILABLE\n" );

						b.price=a.cprice + (a.cprice * 0.15);
						b.tax=b.price * 0.04;
						b.total=b.price+b.tax;

						printf("\n\t\t    CUSTOMER NAME   : ");
						flushall();
						scanf("%[^\n]",b.cusname);
						upper(b.cusname);

						printf("\n\t\t    DATE MONTH YEAR : ");
						flushall();
						scanf("%d%d%d",&b.date,&b.mon,&b.year);

						printf("\n");

						a.cno= a.cno-1;


						fseek(fp2,-recsize,SEEK_CUR);
						fwrite(&a,recsize,1,fp2);
						fwrite(&b,sizeof(b),1,fp1);
						fwrite(&b,sizeof(b),1,fp);

						flag=1;
					}
					else

					if(strcmp(a.cname,sname)!=0||a.cno<=0)
					{
						flag=2;
					}
					else
					{
						if(strcmp(a.ccolor,scolor)!=0)
						{
							flag1=3;
						}
					}

				   }
				   fclose(fp);
				   fclose(fp1);
				   fclose(fp2);

				   if(flag1==3)
				   {
					printf("\nTHE CAR OF YOUR COLOR IS NOT AVAILABLE \n");
				   }
				   else
				   if(flag==2)
				   printf("\nDONT HAVE THE STOCK\n");
				   if(flag==1)
				   {
					printf( "\nPRESS ENTER TO GO BILL  -> ");
					flushall();
					ch=getchar();
				   }
				   if(ch=='\n')
				   {
					clrscr();

					printf("\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
					fp=fopen("custinfo.dat","rb");
					if ( fp  ==  NULL)
					{
						printf("CANNOT OPEN THE FILE \n");
						exit(1) ;
					}


					fseek(fp,-brecsize,SEEK_END);
					while(fread(&b,sizeof(b),1,fp)==1)
					{
						printf("CUSTOMER NAME : %s\t\t\t\tDATE : %d - %d - %d\n\n",b.cusname,b.date,b.mon,b.year);
						printf("CUSTOMER NO   : %d\n\n",b.cusno);
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						printf("CAR NAME   -> %s\n\nCAR MODEL  -> %d\n\nCOLOR      -> %s\n\nPRICE\t\t\t\t\t\t\t%f\n\nTAX[@ 4 per]\t\t\t\t\t\t%f\n",b.cuscname,b.cuscmodel,b.cuscolor,b.price,b.tax);

						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						printf("TOTAL\t\t\t\t\t\t\t%f\n",b.total);
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
					}
				   }

				   printf("\n\n\n\nENTER 'Y' TO GO TO ADD EXTRA ACCESSIORIES -> ");
				   flushall();
				   ch=toupper(getchar());
				   if(ch=='Y')
				   {
						clrscr();
						goto acc;
				   }

				   else
						goto start;

/* CUSTOMER INFORMATION */
			case 4:
				fp=fopen("custinfo.dat","rb");
				if ( fp  ==  NULL)
				{
						printf("CANNOT OPEN THE FILE \n");
						exit(1) ;
				}
				rewind(fp);
				printf("\n\t\t\tCUSTOMER INFORMATION\n\n");
				printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
				printf("CUSTOMER NAME\tCUSTOMER\tCAR NAME\tCOLOR\t\tDATE OF PURCHASE\n");
				printf("\t\t   NO\n");
				printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
				while(fread(&b,sizeof(b),1,fp)==1)
				{
					/*if(strlen(b.cusname)<8&&strlen(b.cuscolor)<7)*/
					if(strlen(b.cusname)<8)
					printf( "%s\t\t   %d\t  \t%s\t\t%s\t\t%d-%d-%d\n",b.cusname,b.cusno,b.cuscname,b.cuscolor,b.date,b.mon,b.year);
					else
					printf( "%s\t   %d\t  \t%s\t\t%s\t\t%d-%d-%d\n",b.cusname,b.cusno,b.cuscname,b.cuscolor,b.date,b.mon,b.year);
				}
				printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
				fclose(fp);

				printf("\n\n\n\nPRESS 'Y' TO GO TO MAIN MENU -> ");
				flushall();
				ch=getchar();
				goto start;

/* ACCESORY DISPLAY*/
		acc:case 5 :   drecsize=sizeof(d);

					do
					{
						clrscr();
						ans=0;
						printf("\n\nEnter the accesory name : ");
						flushall();
						scanf("%[^\n]",aname);
						upper(aname);
						printf("\nEnter the quantity : ");
						flushall();
						scanf("%d",&aqty);
						fp=fopen("accesory.dat","rb+");
						rewind(fp);
						while(fread(&d,sizeof(d),1,fp)==1)
						{
							if((strcmp(aname,d.aname)==0)&&(d.aqty>=aqty))
							{
								printf("STOCK AVAILABLE");
								d.aqty=d.aqty-aqty;
								price=d.aprice*aqty;
								price=price+(price*0.1);
								fseek(fp,-drecsize,SEEK_CUR);
								fwrite(&d,sizeof(d),1,fp);
								ans=1;
							}
					  }
					  if(ans==0)
					  {
						printf("\nSTOCK NOT AVAILABLE");
					  }
					  if(ans==1)
					  {
						printf("\npress enter to go to bill");
						ch=getchar();
						if(ch=='\n');
						{
							clrscr();
							fseek(fp,-drecsize,SEEK_CUR);
							printf("\n\n\n\tออออออออออออออออออออออออออออออออออออออออ");
							printf( "\n\tACC NAME\tQUANTITY\tPRICE\n" );
							printf("\tออออออออออออออออออออออออออออออออออออออออ\n");
							printf("\t%s\t\t%d\t\t%f\n",d.aname,aqty,price);
						}
					  }
					  printf("\n\tอออออออออออออออออออออออออออออออออออออออออ\n");
					  printf( "\n\nDo U want to continue ?   (Y/N) " );
					  take = toupper(getchar());
					  }while(take=='Y');
					  fclose(fp);
					  goto start;

/* SERVICE DETAILS */
			case 6 :
					flag=0;
					fp=fopen("service.dat","ab+");
					fp1=fopen("custinfo.dat","rb");
					while(fread(&s,sizeof(s),1,fp)==1);
					s.billnum=s.billnum+1;

					printf( "\nPRESS 1-> REGULAR CUSTOMER\n\nPRESS 2-> NEW CUSTOMER\n \n    ENTER YOUR CHOICE...: " );
					scanf( "%d",&opt );
					switch( opt )
					{
/* FOR REGULAR CUSTOMER */
					case 1:
							printf("\nENTER CUSTOMER NAME...: ");
							flushall();
							scanf("%[^\n]",s.cname);
							upper(s.cname);
							rewind(fp1);
							printf("\n\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
							printf( "\tCUST. NAME\tCUST. NO.\tCAR \tYEAR OF PURCHASE\n" );
							printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
							while(fread(&b,sizeof(b),1,fp1)==1)
							{
								if(strcmp(s.cname,b.cusname)==0)
								{
									printf("\t%s\t%d\t\t%s\t%d-%d\n",b.cusname,b.cusno,b.cuscname,b.mon,b.year);
								}
							}
							printf("\n\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
							printf("\nENTER CUSTOMER NO.........: ");
							scanf("%d",&s.cno);
							printf("\n\nENTER MONTH AND YEAR OF PURCHASE.....: ");
							scanf("%d%d",&pmon,&pyear);
							printf("\n\nENTER CURRENT MONTH & YEAR........:");
							scanf("%d%d",&s.cmon,&s.cyear);
							period=12-pmon+s.cmon;
							if((s.cyear-pyear)>=1)
							{
								printf("\n\nENETR SERVICE CHARGES  : ");
								scanf("%f",&s.scharge);
							}
							else

							if(period<=12||pyear==s.cyear)
							{
								flag=1;
								s.scharge=0;
							}
							printf("\nMISCELLANEOUS CHARGES  : ");
							scanf("%f",&s.mcharge);
							s.tcharge=s.mcharge+s.scharge;



							clrscr();
							printf("\n\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf("\t\t\t  ** SERVICE BILL  **\n");
							printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf("\nCUSTOMER NAME : %s\t\t\t\t\t%d-%d",s.cname,s.cmon,s.cyear);
							printf("\n\nCUSTOMER NO : %d\t\t\t\t\t%d",s.cno,s.billnum);
							printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf("\nSERVICE CHARGES  \t\t\t\t\t%f",s.scharge);
							printf("\n\nMISCELLANEOUS CHARGES \t\t\t\t\t%f",s.mcharge);

							printf("\n\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
                            printf("\n\nTOTAL CHARGES \t\t\t\t\t\t%f",s.tcharge);
							fwrite(&s,sizeof(s),1,fp);
							fclose(fp);
							fclose(fp1);
                            printf("\n\n\n\nPRESS 'Y' TO GO TO MAIN MENU -> ");
							flushall();
							ch=getchar();
							goto start;

/* FOR NEW CUSTOMER */
					case 2:
							printf("\nENTER CUSTOMER NAME...: ");
							flushall();
							scanf("%[^\n]", tempname);
							upper( tempname );
							printf("\nCAR NAME...: " );
							flushall();
							scanf( "%[^\n]", tempcar);
							printf("\n\nENTER SERVICE CHARGES  : ");
							scanf("%f",&tempcharge);
							printf("\nMISCELLANEOUS CHARGES  : ");
							scanf("%f",&tempmcharge);
							temptot = tempcharge + tempmcharge;
							clrscr();
                            printf("\n\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf("\t\t\t  ** SERVICE BILL  **\n");
							printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf("\nCUSTOMER NAME : %s",tempname);
							printf("\n\nCAR NAME : %s",tempcar);
							printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf("\nSERVICE CHARGES  \t\t\t\t\t%f",tempcharge);
							printf("\n\nMISCELLANEOUS CHARGES \t\t\t\t\t%f",tempmcharge);

							printf("\n\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf("\n\nTOTAL CHARGES \t\t\t\t\t\t%f",temptot);
							printf("\n\n\n\nPress <Enter> to go to main menu  -> ");
							flushall();
					take = getchar();
					if( take == '\n' )
						goto start;

					break;
					}
/* PROFIT AND SALES */
			case 7:
					clrscr();
					printf("\nPRESS 1 -> PRODUCTWISE SALES\n");
					printf("\nPRESS 2 -> MONTHLY SALES REPORT\n");
					printf("\nENTER YOUR CHOICE...: " );
					scanf("%d",&opt);
					switch(opt)
					{
/* PRODUCT WISE SALES */
						case 1:
								clrscr();
								profit=0;qty=0;
								fp=fopen("sales.dat","rb");
								rewind(fp);
								printf("\nENTER THE CAR NAME....: ");
								flushall();
								scanf("%[^\n]",sname);
								upper(sname);
								printf("\nCAR \t\t QTY \t PROFIT\n" );
								printf("\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
								while(fread(&b,sizeof(b),1,fp)==1)
								{
									if(strcmp(b.cuscname,sname)==0)
									{
										qty=qty+1;
										profit=profit+(1*b.price*0.1);
									}
								}
								printf("\n%s\t\t%d\t%f",sname,qty,profit);
								fclose(fp);
                                printf("\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
								printf("\n\n\n\n\nPress <Enter> to go to main menu  -> ");
								flushall();
								take = getchar();
								if( take == '\n' )
									goto start;

								break;
/* MONTHLY SALES */
						case 2:
								clrscr();
								fp=fopen("sales.dat","rb");
								rewind(fp);
								printf("\n\nENTER THE MONTH & YEAR : ");
								scanf("%d%d",&month,&year);
								printf("\n\n\nDATE\t CAR\t PRICE\n");
								printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
								while(fread(&b,sizeof(b),1,fp)==1)
								{
									if(b.mon==month&&b.year==year)
									{
										printf("%d\t %s\t %f\n",b.date, b.cuscname, b.total );
										tot = tot + b.total;
									}

								}
								printf("\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
								printf("\t\t\tTotal..= %f",tot);
								}
								printf("\n\n\n\nPress <Enter> to go to main menu  -> ");
								flushall();
								take = getchar();
								if( take == '\n' )
									goto start;

					break;

		case 9 :
					exit(0);

		}

	getch();
}


/* TO CONVERT STRING TO UPPER CASE */

void upper(char *str)
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		str[i]=toupper(str[i]);
	}
}

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
	int cno,cmodelno;
	char cname[50],ccolor[20];

};
struct accesories
{
	char aname[50];
	int aqty;
	float aprice;
}d;

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
	float price,profit;
	char ch,sname[20],scolor[20],cname[50],ccolor[20],aname[20];
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
		{
			case 1:
				printf("PRESS 1 -> CAR PURCHASES\nPRESS 2 -> ACCESSORIES PURCHASES\n");
				scanf("%d",&opt);
				switch(opt)
				{
					case 1:
						fp=fopen("stock12.dat","rb+");

						if ( fp  ==  NULL)
						{
							printf("CANNOT OPEN THE FILE \n");
							exit(1) ;
						}

						do
						{
							clrscr();

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

							fseek(fp,0,SEEK_END);
							fwrite(&a,-recsize,1,fp);

						/*	rewind(fp);
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
							}  */

							printf( "\n\nDO YOU WANT TO CONTINUE (Y\\N) -> " );
							flushall();
							ch=toupper(getchar());

						} while(ch=='Y');

							fclose(fp);

							goto start;

					case 2:
						do
						  {
							clrscr();
							fp=fopen("accesory12.dat","ab+");
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

			case 2:
				printf("PRESS 1 ->DISPLAY CAR STOCK\nPRESS 2 ->DISPLAY ACCESSORIES STOCK\n");
				scanf("%d",&opt);
				switch(opt)
				{

					case 1:
						fp=fopen("stock12.dat","rb");

						if ( fp  ==  NULL)
						{
							printf("CANNOT OPEN THE FILE \n");
							exit(1) ;
						}

						fseek(fp,0,SEEK_SET);

						printf( "\n\t\t\t STOCK INFORMATION\n" );
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						printf( "CAR NAME\t        MODEL\tCOLOR\t  QUANTITY\t\n" );
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ \n");

						while(fread(&a,recsize,1,fp)==1)
						{
							if(a.cno>0)
							{
								if(strlen(a.cname)<8)
								{
									printf("\n%s\t\t\t%d\t%s\t   %d\n",a.cname,a.cmodelno,a.ccolor,a.cno);
								}
								else
									printf("\n%s\t\t%d\t%s\t   %d\n",a.cname,a.cmodelno,a.ccolor,a.cno);
							}
						}

						printf( "\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ \n");

						fclose(fp);

						printf( "\nPRESS Y TO GO TO MAIN MENU -> " );
						flushall();
						ch=toupper(getchar());

						goto start;

				case 2:
						clrscr();
						fp=fopen("accesory12.dat","rb+");
						rewind(fp);
						printf("\t\t\tSTOCK DISPLAY\n");
                        printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
						printf( "ACCESSORY NAME\t\tQUANTITY\t\tPRICE\n" );
						printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						while(fread(&d,sizeof(d),1,fp)==1)
						{
							if(d.aqty>0)
							{
								if(strlen(d.aname)<8)
									printf("%s\t\t\t%d\t\t\t%f\n",d.aname,d.aqty,d.aprice);
								else
									printf("%s\t\t%d\t\t\t%f\n",d.aname,d.aqty,d.aprice);
							}
						}
						fclose(fp);
						printf( "\nPRESS Y TO GO TO MAIN MENU -> " );
						flushall();
						ch=toupper(getchar());

						goto start;
				}

			case 3:
				clrscr();
				flag=0;flag1=0;

				fp=fopen("sales112.dat","ab+");

				if ( fp  ==  NULL)
				{
					printf("CANNOT OPEN THE FILE \n");
					exit(1) ;
				}

				fp1=fopen("cusinfo112.dat","ab+");

				if ( fp1 ==  NULL)
				{
					printf("CANNOT OPEN THE FILE \n");
					exit(1) ;
				}

				fp2=fopen("stock12.dat","rb+");

				if ( fp2  ==  NULL)
				{
					printf("CANNOT OPEN THE FILE \n");
					exit(1) ;
				}

				printf("\n\t\tENTER THE DETAILS \n" );
				printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");

				printf("\nNAME OF THE CAR  : ");
				flushall();
				scanf("%[^\n]",sname);
				upper(sname);

				printf("\nCOLOR OF THE CAR : ");
				flushall();
				scanf("%[^\n]",scolor);
				upper(scolor);

				printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");

				rewind(fp2);

				brecsize=sizeof(b);
				while(fread(&a,sizeof(a),1,fp2)==1)
				{
					if(strcmp(sname,a.cname)==0&&strcmp(scolor,a.ccolor)==0&&a.cno>0)
					{
						while(fread(&b,sizeof(b),1,fp1)==1);
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



						/*printf("\n\t\t    CUSTOMER NUMBER : ");
						flushall();
						scanf("%d",&b.cusno);*/

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
					fp5=fopen("billno12.dat","ab+");

					while(fread(&b,sizeof(b),1,fp5)==1);
					b.billno=b.billno+1;

					printf("\t\t\t\tBILL NO : %d",b.billno);
					fwrite(&b,sizeof(b),1,fp5);
					fclose(fp5);
					printf("\nอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
					fp=fopen("cusinfo112.dat","rb");
					if ( fp  ==  NULL)
					{
						printf("CANNOT OPEN THE FILE \n");
						exit(1) ;
					}


					fseek(fp,-brecsize,SEEK_END);
					while(fread(&b,sizeof(b),1,fp)==1)
					{
						printf("CUSTOMER NAME : %s\t\t\t\t\tDATE : %d - %d - %d\n\n",b.cusname,b.date,b.mon,b.year);
						printf("CUSTOMER NO   : %d\n\n",b.cusno);
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						printf("CAR NAME   -> %s\n\nCAR MODEL  -> %d\n\nCOLOR      -> %s\n\nPRICE\t\t\t\t\t\t\t\t%f\n\nTAX[@ 4 per]\t\t\t\t\t\t\t%f\n",b.cuscname,b.cuscmodel,b.cuscolor,b.price,b.tax);

						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
						printf("TOTAL\t\t\t\t\t\t\t\t%f\n",b.total);
						printf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
					}
				   }

				   printf("\n\n\n\nENTER 'Y' TO GO TO ADD EXTRA ACCESSIORIES -> ");
				   flushall();
				   ch=getchar();
				   if(ch=='Y')
				   {
						clrscr();
						goto acc;
				   }

				   else
						goto start;

			case 4:
				fp=fopen("cusinfo112.dat","rb");

				if ( fp  ==  NULL)
				{
						printf("CANNOT OPEN THE FILE \n");
						exit(1) ;
				}
				rewind(fp);
				printf("\n\t\t\tCUSTOMER INFORMATION\n\n");
				printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
				printf("CUSTOMER NAME\tCUSTOMER  CAR NAME\tCOLOR\tDATE OF PURCHASE\n");
				printf("\t\t   NO\n");
				printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
				while(fread(&b,sizeof(b),1,fp)==1)
				{
					if(strlen(b.cusname)<8&&strlen(b.cuscolor)<7)
					printf( "%s\t\t   %d\t  %s\t\t%s\t%d-%d-%d\n\n",b.cusname,b.cusno,b.cuscname,b.cuscolor,b.date,b.mon,b.year);
					else
					printf( "%s\t   %d\t  %s\t%s\t%d-%d-%d\n\n",b.cusname,b.cusno,b.cuscname,b.cuscolor,b.date,b.mon,b.year);
				}
				printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
				fclose(fp);

				printf("\n\n\n\nPRESS 'Y' TO GO TO MAIN MENU -> ");
				flushall();
				ch=getchar();
				goto start;

		acc:case 5 :   drecsize=sizeof(d);
						ans=0;
						printf("\nEnter the accesory name : ");
						flushall();
						scanf("%[^\n]",aname);
						upper(aname);
					  printf("\nEnter the quantity : ");
					  flushall();
					  scanf("%d",&aqty);
					  fp=fopen("accesory1.dat","rb+");
					  rewind(fp);
					  while(fread(&d,sizeof(d),1,fp)==1)
					  {
							if(strcmp(aname,d.aname)==0&&d.aqty>=aqty)
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
							printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
							printf( "ACCESSORY NAME\t\tQUANTITY\t\tPRICE\n" );
                            printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
							printf("%s\t\t%d\t\t\t%f\n",d.aname,aqty,price);
						}
					  }
					  fclose(fp);
					  break;
			case 6 :
					flag=0;
					fp=fopen("service12.dat","ab+");
					fp1=fopen("cusinfo112.dat","rb");
                    while(fread(&s,sizeof(s),1,fp)==1);
					s.billnum=s.billnum+1;
					printf("\nENTER CUSTOMER NAME...: ");
					flushall();
					scanf("%[^\n]",s.cname);
					upper(s.cname);
					rewind(fp1);
					while(fread(&b,sizeof(b),1,fp1)==1)
					{
						if(strcmp(s.cname,b.cusname)==0)
						{
							printf("%s\t%d\t%s\t%d-%d\n",b.cusname,b.cusno,b.cuscname,b.mon,b.year);
						}
					}
					printf("\nENTER CUSTOMER NO.........:");
					scanf("%d",&s.cno);
					printf("\nENTER MONTH AND YEAR OF PURCHASE.....: ");
					scanf("%d%d",&pmon,&pyear);
					printf("ENTER CURRENT MONTH & YEAR........:");
					scanf("%d%d",&s.cmon,&s.cyear);
					period=12-pmon+s.cmon;
					if((s.cyear-pyear)>=1)
                    {
						printf("\nENETR SERVICE CHARGES");
						scanf("%f",&s.scharge);
					}
					else

					if(period<=12||pyear==s.cyear)
					{
						flag=1;
						s.scharge=0;
					}
					printf("\nMISCELLANEOUS CHARGES");
					scanf("%f",&s.mcharge);
					s.tcharge=s.mcharge+s.scharge;
					/*fwrite(&s,sizeof(s),1,fp);*/
					rewind(fp);

					clrscr();
					printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
					printf("\t\t\tABHARAN MOTORS\n\t\t\tSERVICE BILL\n");
					printf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
					printf("CUSTOMER NAME : %s\t\t\t\t\t\t%d-%d",s.cname,s.cmon,s.cyear);
					printf("\nCUSTOMER NO : %d\t\t\t\t\t\t\t%d",s.cno,s.billnum);
					printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
					printf("SERVICE CHARGES  \t\t\t\t\t\t\t%f",s.scharge);
					printf("\nMISCELLANEOUS CHARGES \t\t\t\t\t\t%f",s.mcharge);
					printf("\nTOTAL CHARGES \t\t\t\t\t\t\t%f",s.tcharge);
					printf("\nออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
					fwrite(&s,sizeof(s),1,fp);
					fclose(fp);
					break;
			case 7:
					clrscr();
					printf("PRESS 1 -> PRODUCTWISE SALES\n");
					printf("PRESS 2 -> MONTHLY SALES REPORT\n");
					scanf("%d",&opt);
					switch(opt)
					{

						case 1:
								profit=0;qty=0;
								fp=fopen("sales112.dat","rb");
								rewind(fp);
								printf("\nENTER THE CAR NAME ");
								flushall();
								scanf("%[^\n]",sname);
								upper(sname);
								while(fread(&b,sizeof(b),1,fp)==1)
								{
									if(strcmp(b.cuscname,sname)==0)
									{
										qty=qty+1;
										profit=profit+(1*b.price*0.1);
									}
								}
								printf("%s\t%d\t%f",sname,qty,profit);
								fclose(fp);
								break;
						case 2:
								clrscr();
								fp=fopen("sales112.dat","rb");
								rewind(fp);
								printf("ENTER THE MONTH & YEAR : ");
								scanf("%d%d",&month,&year);
								while(fread(&b,sizeof(b),1,fp)==1)
								{
									if(b.mon==month&&b.year==year);

								}
						}
		case 9 :
					exit(0);

		}

	getch();
}




void upper(char *str)
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		str[i]=toupper(str[i]);
	}
}

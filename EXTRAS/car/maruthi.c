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

main()
{
	struct car a,c;
	struct cus b;
	int choice,opt,flag=0,flag1=0,n,ans=0,aqty;
	long int recsize,brecsize,drecsize;
	float price;
	char ch,sname[20],scolor[20],cname[50],ccolor[20],aname[20];
	FILE *fp,*fp1,*fp2,*fp5;

	b.billno=100;

	start:  clrscr();
		recsize=sizeof(a);
		printf( "ENTER UR CHOICE :\n---------------");
		printf( "\n\t\tPRESS 1 -> PURCHASES FOR STOCK\n" );
		printf( "\n\t\tPRESS 2 -> STOCK DISPLAY\n" );
		printf( "\n\t\tPRESS 3 -> BOOKING A CAR\n" );
		printf( "\n\t\tPRESS 4 -> DISPLAY CUSTOMER INFO\n" );
		printf( "\n\t\tPRESS 5 -> ACCESSIORIES \n" );
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
								fp=fopen("stock.dat","rb+");

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
								ch=getchar();

							} while(ch=='Y');

							fclose(fp);

							goto start;

					case 2:
						do
						  {
							fp=fopen("accesory.dat","ab+");
							printf("\nenter the accesory name : ");
							flushall();
							scanf("%[^\n]",d.aname);
							printf("\nenter the quantity : ");
							flushall();
							scanf("%d",&d.aqty);
							printf("\nenter the price : ");
							flushall();
							scanf("%f",&d.aprice);
							fwrite(&d,sizeof(d),1,fp);
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
                        		fp=fopen("stock.dat","rb");

								if ( fp  ==  NULL)
								{
									printf("CANNOT OPEN THE FILE \n");
									exit(1) ;
								}

								fseek(fp,0,SEEK_SET);

								printf( "\n\t\t\t STOCK INFORMATION\n" );
								printf( "------------------------------------------------------------------------------\n");
								printf( "CAR NAME\t        MODEL\tCOLOR\t  QUANTITY\t\n" );
								printf( "------------------------------------------------------------------------------\n");

								while(fread(&a,recsize,1,fp)==1)
								{
									if(strlen(a.cname)<8)
									{
										printf("\n%s\t\t\t%d\t%s\t   %d\n",a.cname,a.cmodelno,a.ccolor,a.cno);
									}
									else
										printf("\n%s\t\t%d\t%s\t   %d\n",a.cname,a.cmodelno,a.ccolor,a.cno);
								}

								printf( "\n------------------------------------------------------------------------------\n");

								fclose(fp);

								printf( "\nPRESS Y TO GO TO MAIN MENU -> " );
								flushall();
								ch=toupper(getchar());

								goto start;

						case 2:fp=fopen("accesory.dat","rb");
								rewind(fp);
								while(fread(&d,sizeof(d),1,fp)==1)
								{
									printf("%s\t%d\t%f\n",d.aname,d.aqty,d.aprice);
								}
								fclose(fp);
                                printf( "\nPRESS Y TO GO TO MAIN MENU -> " );
								flushall();
								ch=toupper(getchar());

								goto start;
						}

			case 3:
				clrscr();

				fp=fopen("sales1.dat","ab");

				if ( fp  ==  NULL)
				{
					printf("CANNOT OPEN THE FILE \n");
					exit(1) ;
				}

				fp1=fopen("cusinfo1.dat","rb+");

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

				printf("\n\tENTER THE DETAILS \n" );
				printf("------------------------------------------------------------------------------\n");

				printf("\nNAME OF THE CAR  : ");
				flushall();
				scanf("%[^\n]",sname);
				upper(sname);

				printf("\nCOLOR OF THE CAR : ");
				flushall();
				scanf("%[^\n]",scolor);
				upper(scolor);

				printf("\n------------------------------------------------------------------------------\n");

				rewind(fp2);

				brecsize=sizeof(b);
				while(fread(&a,sizeof(a),1,fp2)==1)
				{
					if(strcmp(sname,a.cname)==0&&strcmp(scolor,a.ccolor)==0&&a.cno>0)
					{

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

						printf("\n\t\t    CUSTOMER NUMBER : ");
						flushall();
						scanf("%d",&b.cusno);

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
					fp5=fopen("billno.dat","rb+");
					while(fread(&b,sizeof(b),1,fp5)==1);
					b.billno=b.billno+1;


					printf("\t\t\t\tBILL NO : %d",b.billno);
					fwrite(&b,sizeof(b),1,fp5);
					fclose(fp5);
					printf("\n------------------------------------------------------------------------------\n");
					fp=fopen("cusinfo1.dat","rb");
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
						printf("-----------------------------------------------------------------------------\n");
						printf("CAR NAME   -> %s\n\nCAR MODEL  -> %d\n\nCOLOR      -> %s\n\nPRICE\t\t\t\t\t\t\t\t%f\n\nTAX[@ 4 per]\t\t\t\t\t\t\t%f\n",b.cuscname,b.cuscmodel,b.cuscolor,b.price,b.tax);

						printf("-----------------------------------------------------------------------------\n");
						printf("TOTAL\t\t\t\t\t\t\t\t%f\n",b.total);
						printf("------------------------------------------------------------------------------\n");
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
				fp=fopen("cusinfo1.dat","rb");

				if ( fp  ==  NULL)
				{
						printf("CANNOT OPEN THE FILE \n");
						exit(1) ;
				}
				rewind(fp);
				printf("\n\t\t\tCUSTOMER INFORMATION\n\n");
				printf("-----------------------------------------------------------------------------\n");
				printf("CUSTOMER NAME\tCUSTOMER  CAR NAME\tCOLOR\tDATE OF PURCHASE\n");
				printf("\t\t   NO\n");
				printf("-----------------------------------------------------------------------------\n\n");
				while(fread(&b,sizeof(b),1,fp)==1)
				{
					if(strlen(b.cusname)<8&&strlen(b.cuscolor)<7)
					printf( "%s\t\t   %d\t  %s\t\t%s\t%d-%d-%d\n\n",b.cusname,b.cusno,b.cuscname,b.cuscolor,b.date,b.mon,b.year);
					else
					printf( "%s\t   %d\t  %s\t%s\t%d-%d-%d\n\n",b.cusname,b.cusno,b.cuscname,b.cuscolor,b.date,b.mon,b.year);
				}
				printf("-----------------------------------------------------------------------------\n");
				fclose(fp);

				printf("\n\n\n\nPRESS 'Y' TO GO TO MAIN MENU -> ");
				flushall();
				ch=getchar();
				goto start;

		acc:case 5 :   drecsize=sizeof(d);
						ans=0;
						printf("enter the accesory name : ");
						flushall();
						scanf("%[^\n]",aname);
					  printf("enter the quantity");
					  flushall();
					  scanf("%d",&aqty);
					  fp=fopen("accesory.dat","rb+");
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
							printf("%s\t%d\t%f\n",d.aname,aqty,price);
						}
					  }
					  break;
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
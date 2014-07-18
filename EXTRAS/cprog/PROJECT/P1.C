#include<stdio.h>
#include<conio.h>

struct car
{
	int cno,cprice,cmodelno;
	char cname[50],ccolor[20];
};

struct cus
{
	char cuscname[20],cusname[20],cuscolor[20];
	int date,mon,year,cusno,price,tax,total,cuscmodel;
};

main()
{
	struct car a,c;
	struct cus b;
	int i,j,k,choice,flag=0,n,ans=0;
	long int size,recsize,brecsize;
	char ch,sname[20],scolor[20];
	FILE *fp,*fp1,*fp2;

	clrscr();

  start:clrscr();
		recsize=sizeof(a);
		printf( "ENTER UR CHOICE!!!!!!!!!\n");
		printf( "1 -> STOCK PURCHASE\n" );
		printf( "2 -> STOCK DISPLAY\n" );
		printf( "3 -> ORDER\n" );
		printf( "4 -> DISPLAY CUSTOMER INFO\n" );
		printf( "5 -> " );
		printf( "9 -> EXIT\n " );

		scanf( "%d",&choice );
		clrscr();

		switch(choice)
		{
			case 1:
					fp=fopen("stock.dat","rb+");
					do
					{
						clrscr();


						printf( "CAR NAME : " );
						flushall();
						scanf( "%[^\n]",a.cname);

						printf( "\nQTY : " );
						flushall();
						scanf( "%d",&a.cno);

						printf( "\nPRICE ; ");
						flushall();
						scanf( "%d",&a.cprice);

						printf( "\nMODEL NO. : ");
						flushall();
						scanf( "%d",&a.cmodelno);

						printf( "\nCOLOR : " );
						flushall();
						scanf( "%s",a.ccolor);

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

						printf( "Do u want to continue (Y\N)\n" );
						flushall();
						ch=toupper(getchar());
					} while(ch=='Y');

					fclose(fp);
					goto start;


		case 2:

			   fp=fopen("stock.dat","rb");
				size=sizeof(a);
				fseek(fp,0,SEEK_SET);

				printf( "\n\t\t\t STOCK INFORMATION\n" );
				printf( "\t---------------------------------------------------\n");
				printf( "CAR NAME\t        MODEL\tCOLOR\t  QUANTITY\t\n" );
				printf( "------------------------------------------------------------------------\n");
				while(fread(&a,size,1,fp)==1)
				{
					if(strlen(a.cname)<8)
					{
						printf("\n%s\t\t\t%d\t%s\t   %d",a.cname,a.cmodelno,a.ccolor,a.cno);
					}
					else
						printf("\n%s\t\t%d\t%s\t   %d",a.cname,a.cmodelno,a.ccolor,a.cno);
				}
				printf( "\n--------------------------------------------------------------------------\n");
				fclose(fp);

				printf( "\nDO U WANT TO GO TO MAIN MENU (Y\\N)\n" );
				flushall();
				ch=toupper(getchar());
				goto start;

		case 3:
			   clrscr();

			   fp=fopen("sales1.dat","ab");
			   fp1=fopen("cusinfo1.dat","ab");
			   fp2=fopen("stock.dat","rb+");

			   printf("Enter which car u want to buy ?\n" );
			   printf("Name : ");
			   flushall();
			   scanf("%[^\n]",sname);
			   printf("Color : ");
			   flushall();
			   scanf("%[^\n]", scolor);

			   rewind(fp2);
			   recsize=sizeof(a);
			   brecsize=sizeof(b);
			   while(fread(&a,sizeof(a),1,fp2)==1)
			   {
				if(strcmp(sname,a.cname)==0&&strcmp(scolor,a.ccolor)==0&&a.cno>0)
				{

					strcpy(b.cuscname,sname);
					strcpy(b.cuscolor,scolor);
					b.cuscmodel=a.cmodelno;
					printf( "\n Stock is present..\n" );
					b.price=a.cprice + (a.cprice * 0.15);
					b.tax=b.price * 0.04;
					b.total=b.price+b.tax;
					printf( "\n Custumer name..: ");
					flushall();
					scanf("%[^\n]",b.cusname);
					printf("Cutumer ID : ");
					flushall();
					scanf("%d",&b.cusno);
					printf("DATE : " );
					flushall();
					scanf("%d",&b.date);
					printf("\tMONTH : ");
					flushall();
					scanf("%d",&b.mon);
					printf("\tYEAR :");
					flushall();
					scanf("%d",&b.year);
					printf("\n");
					a.cno= a.cno-1;
					fseek(fp2,-recsize,SEEK_CUR);
					fwrite(&a,recsize,1,fp2);
					fwrite(&b,sizeof(b),1,fp1);
					fwrite(&b,sizeof(b),1,fp);
					flag=1;
				}
			   }
				fclose(fp);
				fclose(fp1);
				fclose(fp2);
				if(flag==0)
					printf(" No stock\n");
				printf( "PRESS 'Y' TO GO BILL..........\n");
				flushall();
				ch=getchar();
				if(ch=='\n')
				{       clrscr();
					printf("\t\t\t\tBILL\n------------------------------------------------------------------------------\n");
					fp=fopen("cusinfo1.dat","rb");
					fseek(fp,-brecsize,SEEK_END);
					while(fread(&b,sizeof(b),1,fp)==1)
					{
						printf("CUSTOMER NAME : %s\t\t\t\tDATE : %d - %d - %d\n\n",b.cusname,b.date,b.mon,b.year);
						printf("CUSTOMER ID : %d\n\n",b.cusno);
						printf("-----------------------------------------------------------------------------\n");
						printf("CAR NAME\tCAR MODEL\tCOLOR\tPRICE\tTAX\tTOTAL\n");
						printf("-----------------------------------------------------------------------------\n\n");
						printf("%s\t\t%d\t\t%s\t%d\t%d\t%d\n",b.cuscname,b.cuscmodel,b.cuscolor,b.price,b.tax,b.total);
						printf("\n\n\n\n\n----------------------------------------------------------------------------\n\n");
					}
				}
				printf("\n\n\n\nENTER 'Y'\n");
				ch=getchar();
				goto start;

		case 4:
				fp=fopen("cusinfo1.dat","rb");
				rewind(fp);

				while(fread(&b,sizeof(b),1,fp)==1)
				{
					printf( "  %s  %d  %s  %s  %d-%d-%d\n",b.cusname,b.cusno,b.cuscname,b.cuscolor,b.date,b.mon,b.year);
				}
				fclose(fp);

				printf("PRESS 'Y' TO GO TO MAIN MENU\n");
				flushall();
				ch=getchar();
				goto start;

	   case 5 :

		case 9:
				exit(0);

	}

	getch();
}
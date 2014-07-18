#include<stdio.h>
#include<dos.h>
struct details
{
	float amt,tax,examt;
	int prqty,pfqty,lrqty,lfqty,wlfqty,rfqty,wrqty,wkqty,wdqty,wfqty,date,mon,year,cmno;
};
main()

{
	struct details b;
	FILE *fp;
	char z;
	float c[10];
	float tax=0;
	int i=0,ch,choice,j,k=0,l;
	int totpr=0,totpf=0,totlr=0,totlf=0,totwf=0,totrf=0,totwlf=0,totwr=0,totwk=0,totwd=0;
	float pr=13,pf=12,lr=12.8,lf=11.6,lwf=13.1,wf=13.5,wr=16.5,rf=11,tottax=0,totexamt=0,totamt=0;
	b.examt=0;
	b.cmno=1274;
	clrscr();
	printf("press 1 -> ENETR THE DETAILS OF SALES\n");
	printf("press 2 -> DISPLAY OF SALES\n");
	printf("press 3 -> DISPLAY OF SALES WITH TOTAL\n");
	printf("press 9 -> EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			do
			{
				clrscr();
				fp=fopen("khbhat.dat","ab+");
				rewind(fp);

				while(fread(&b,sizeof(b),1,fp)==1)
				b.cmno=b.cmno+1;

				b.examt=0;
				b.tax=0;   tax=0;

				printf("ENTER THE DATE MONTH & YEAR : ");
				scanf("%d%d%d",&b.date,&b.mon,&b.year);


				printf("\nENETR THE QUANTITY : ");
				printf("\n\t\t\tPACKET RAVA       : ");
				scanf("%d",&b.prqty);

				c[0]=pr*b.prqty;


				printf("\n\t\t\t\PACKET FLOUR      : ");
				scanf("%d",&b.pfqty);

				c[1]=pf*b.pfqty;

				printf("\n\t\t\tLOOSE RAVA        : ");
				scanf("%d",&b.lrqty);

				c[2]=lr*b.lrqty;

				printf("\n\t\t\tLOOSE FLOUR       : ");
				scanf("%d",&b.lfqty);

				c[3]=lf*b.lfqty;

				printf("\n\t\t\tWHEAT FLOUR       : ");
				scanf("%d",&b.wfqty);

				c[6]=wf*b.wfqty;

				printf("\n\t\t\tLOOSE WHEAT FLOUR : ");
				scanf("%d",&b.wlfqty);

				c[5]=lwf*b.wlfqty;

				printf("\n\t\t\tRAGI FLOUR        : ");
				scanf("%d",&b.rfqty);

				c[4]=rf*b.rfqty;

				printf("\n\t\t\tWHEAT RAVA        : ");
				scanf("%d",&b.wrqty);

				c[7]=wr*b.wrqty;

				printf("\n\t\t\tWHEAT CUTS        : ");
				scanf("%d",&b.wkqty);

				c[8]=wr*b.wkqty;

				printf("\n\t\t\tWHEAT RAVA D      : ");
				scanf("%d",&b.wdqty);

				c[9]=wr*b.wdqty;

				for(i=0;i<5;i++)
				{
				   tax=tax+c[i];
				}

				b.tax=tax*4/100;
				for(;i<10;i++)
				b.examt=b.examt+c[i];

				b.amt=b.examt+tax+b.tax;

				fwrite(&b,sizeof(b),1,fp);

				printf("\n\ndo u want 2 continue (y/n) " );
				flushall();
				z=getchar();
			}while(z=='y');
				fclose(fp);
				break;
		case 2:
				fp=fopen("khbhat.dat","rb");
				rewind(fp);
				clrscr();
		printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				for(;kbhit()==0;)
				{

					while(fread(&b,sizeof(b),1,fp)==1)
					{
						printf("\n DATE : %d-%d-%d  CASH MEMO NO : %d\n",b.date,b.mon,b.year,b.cmno);
						printf(" PR   PF   LR   LF   WF   LWF  RF   WR   WC   WRD  TAX[4%]  TAX[0%]    AMT\n");
						printf(" %d   %d   %d   %d   %d   %d   %d   %d   %d   %d   %0.2f   %0.2f   %0.2f\n",b.prqty,b.pfqty,b.lrqty,b.lfqty,b.wfqty,b.wlfqty,b.rfqty,b.wrqty,b.wkqty,b.wdqty,b.tax,b.examt,b.amt);
						printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
						sleep(2);
					}
				}
				fclose(fp);
				break;
	case 3:
				clrscr();
				fp=fopen("khbhat.dat","rb");
				i=0; l=0;
				for(;kbhit()==0;)
				{
					while(fread(&b,sizeof(b),1,fp)==1)
					{
						i++; l++;
						totpr=totpr+b.prqty;
						totpf=totpf+b.pfqty;
						totlr=totlr+b.lrqty;
						totlf=totlf+b.lfqty;
						totwr=totwr+b.wrqty;
						totwk=totwk+b.wkqty;
						totwd=totwd+b.wdqty;
						totrf=totrf+b.rfqty;
						totwlf=totwlf+b.wlfqty;
						totwf=totwf+b.wfqty;
						totexamt=totexamt+b.examt;
						tottax=tottax+b.tax;
						totamt=totamt+b.amt;
						if(i==5)

						{

							k=l-5;j=k+5;i=0;k=k+1;
							rewind(fp);
							printf("\nÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\n");
							printf(" PR   PF   LR   LF   WF   LWF  RF   WR   WC   WRD  TAX[4%]  TAX[0%]    AMT\n");
							printf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
							clrscr();

							while(fread(&b,sizeof(b),1,fp)==1)
							{
								if(i==k)
								{
									i++;k++;
								}
								else
									i++;
								if(i==k&&i<=j)
								{
    								printf("\n DATE : %d-%d-%d    CASH MEMO NO : %d\n",b.date,b.mon,b.year,b.cmno);
    								printf(" PR   PF   LR   LF   WF   LWF  RF   WR   WC   WRD  TAX[4%]  TAX[0%]    AMT\n");
    								printf(" %d   %d   %d   %d   %d   %d   %d   %d   %d   %d   %0.2f   %0.2f   %0.2f\n",b.prqty,b.pfqty,b.lrqty,b.lfqty,b.wfqty,b.wlfqty,b.rfqty,b.wrqty,b.wkqty,b.wdqty,b.tax,b.examt,b.amt
);
									printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

									if(i==j)
									{
										i=0;break;
									}
								}
							}
							printf("\n %d  %d  %d  %d  %d  %d  %d  %d  %d  %d   %0.2f   %0.2f   %0.2f \n",totpr,totpf,totlr,totlf,totwf,totwlf,totrf,totwr,totwk,totwd,tottax,totexamt,totamt);
							printf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
							sleep(5);
						}
					}
				}
				break;

		case 9:
				exit();
	}
	getch();
}





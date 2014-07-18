#include<stdio.h>
#include<conio.h>

struct level
{
	int item_no;
	int level;
}l;

FILE *fp1,*fp2,*fp3;

void level()
{
	int ch,no,sl,f=0,search;
	fp1=fopen("item.dat","rb");
	fp2=fopen("level.dat","ab+");
	clrscr();

	do
	{
		clrscr();

                printf("\n\n\t\t ************************* \n");
       	        printf("\t\t\t Reordering Level \n");
       	        printf("\t\t ************************* \n");

		printf("\n\n\t\t\t 1... Insert ");
		printf("\n\t\t\t 2... Update ");
		printf("\n\t\t\t 3... Display ");
		printf("\n\n\t\t\t 99.. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				fp1=fopen("item.dat","rb");
				f=0;

				printf("\n Enter Item Number : ");
				scanf("%d",&no);
				printf(" Enter Stock Level: ");
				scanf("%d",&sl);

				while(fread(&i,sizeof(i),1,fp1)==1)
				{
					if(no==i.item_no)
					{
						l.item_no=no;
						l.level=sl;

						fwrite(&l,sizeof(l),1,fp2);

						printf("\n Added...");
							f=1;
							break;
					}
				}

				if(f==0)
					printf("\n Invalid Item Number");

				fclose(fp1);
				break;
			case 3:
				rewind(fp2);
				f=0;

                                printf("\n ITEM NO  LEVEL \n");

				while(fread(&l,sizeof(l),1,fp2)==1)
				{
					printf("\n %d \t  %d",l.item_no,l.level);
					f=1;
				}

				if(f==0)
				{
					printf("\n No Record Found...");
				}
				break;
			case 2:
				fp3=fopen("temp.dat","wb");
				rewind(fp2);
				f=0;

				printf("\n Enter Item Number : ");
				scanf("%d",&search);

				while(fread(&l,sizeof(l),1,fp2)==1)
				{
					if(l.item_no==search)
					{
						printf(" Enter Stock On Hand : ");
						scanf("%d",&l.level);
						f=1;
					}
					fwrite(&l,sizeof(l),1,fp3);
				}

				if(f==0)
				{
					printf("\n Invalid Item Number");
				}
				else
				{
					fclose(fp2);
					fclose(fp3);

					remove("stock.dat");
					rename("temp.dat","stock.dat");

					fp2=fopen("stock.dat","ab+");

					printf("\n Updated....");
				}
				break;

			case 99:
				fclose(fp1);
				fclose(fp2);

				//exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

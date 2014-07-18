#include<stdio.h>
#include<conio.h>

struct quantity
{
	int item_no;
	int qty;
}q;

FILE *fp1,*fp2,*fp3;

void quantity()
{
	int ch,no,rq,f=0,search;
	fp1=fopen("item.dat","rb");
	fp2=fopen("qty.dat","ab+");
	clrscr();

	do
	{
		clrscr();

                printf("\n\n\t\t ************************* \n");
        	printf("\t\t   Reordering Quantity \n");
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
				printf(" Enter Reorder Quantity: ");
				scanf("%d",&rq);

				while(fread(&i,sizeof(i),1,fp1)==1)
				{
					if(no==i.item_no)
					{
						q.item_no=no;
						q.qty=rq;

						fwrite(&q,sizeof(q),1,fp2);

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

                                printf("\n ITEM NO \t QUANTITY \n");

				while(fread(&q,sizeof(q),1,fp2)==1)
				{
					printf("\n %d \t\t %d",q.item_no,q.qty);
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

				while(fread(&q,sizeof(q),1,fp2)==1)
				{
					if(q.item_no==search)
					{
						printf(" Enter Reorder Quntity : ");
						scanf("%d",&q.qty);
						f=1;
					}
					fwrite(&q,sizeof(q),1,fp3);
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

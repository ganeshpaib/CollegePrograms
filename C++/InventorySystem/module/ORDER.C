#include<stdio.h>
#include<conio.h>

struct order
{
	int item_no;
        int qty;
}o;

FILE *fp1,*fp2;

void order()
{
	int ch,f=0;
        clrscr();
        fp1=fopen("item.dat","rb");
        fp2=fopen("order.dat","ab+");

        do
        {
        	clrscr();

                printf("\n\n\t\t ************************* \n");
                printf("\t\t\t ORDERS \n");
                printf("\t\t ************************* \n");
                printf("\n\n");

                printf("\t 1... Order ");
                printf("\n\t 2... Display ");
                printf("\n\n\t 99.. Exit ");
                printf("\n\n Enter Your Choice :");
                scanf("%d",&ch);

                switch(ch)
                {
                	case 1:
                        	f=0;
                                rewind(fp1);


                        	printf("\n Enter Item Number : ");
                                scanf("%d",&o.item_no);

                                while(fread(&i,sizeof(i),1,fp1)==1)
                                {
                                	if(i.item_no==o.item_no)
                                        {
                                        	f=1;

                                        }
                                }

                                if(f==1)
                                {
                                	printf("\n Enter Quantity : ");
                                        scanf("%d",&o.qty);

                                        fwrite(&o,sizeof(o),1,fp2);
                                        printf("\n Order Placed...");
                                }
                                else
                                {
                                	printf("\n Invalid Item Number ");
                                }
                                break;
                        case 2:
                        	rewind(fp2);

                                while(fread(&o,sizeof(o),1,fp2)==1)
                                {
                                	printf("\n %d \t %d ",o.item_no,o.qty);
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




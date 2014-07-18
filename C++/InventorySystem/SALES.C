#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct item
{
	int item_no;
	char name[' '];
	float price;
}i;
struct stock
{
	int item_no;
	int soh;
}s;

struct level
{
	int item_no;
	int level;
}l;

struct sales
{
	int item_no;
        int qty;
        float amount;
}sa;

struct quantity
{
	int item_no;
	int qty;
}q;



FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;

void main()
{
        int no,qt,f=0,ch,t1,t2;
        float am;
        clrscr();
        fp4=fopen("sales.dat","ab+");
        do
        {
          	clrscr();


        	printf("\n\n\t\t***********************\n");
        	printf("\t\t\t  SALES \n");
    	   	printf("\t\t***********************\n");

        	printf("\n\n");

                printf("\n\t\t 1... Sales ");
                printf("\n\t\t 2... Display ");
                printf("\n\n\t\t 99.. Exit ");
                printf("\n Enter Choice :");
                scanf("%d",&ch);

                switch(ch)
                {
                	case 1:
                        	fp1=fopen("item.dat","rb");
        			fp2=fopen("stock.dat","ab+");
        			fp3=fopen("level.dat","rb");
        			fp5=fopen("temp.dat","wb");

                                printf("\n Enter Item Number : ");
       			        scanf("%d",&no);

        			while(fread(&i,sizeof(i),1,fp1)==1)
       			        {
        				if(i.item_no==no)
             			        {
                				f=1;
                     			        break;
                		         }
       				 }

      				  if(f==0)
   			          {
        				printf("\n Invalid Item Number ");
      				  }
    			          else
       				  {
        				am=i.price;

        				printf("\n Enter Quantity :");
               			        scanf("%d",&qt);

          			        while(fread(&s,sizeof(s),1,fp2)==1)
             			        {
                				if(s.item_no==no)
                    			        {
                        				break;
                   			         }

          			         }
             			         while(fread(&l,sizeof(l),1,fp3)==1)
              			         {
                				if(l.item_no==no)
                     			        {
                        				break;
                 			         }
             				   }

           				     if( qt<s.soh)
              				     {
                                             	t1=s.soh-qt;
                                                t2=l.level;

                					fclose(fp2);
                       				        fp2=fopen("stock.dat","ab+");

                  			      while(fread(&s,sizeof(s),1,fp2)==1)
                    			      {
                        				if(s.item_no==no)
                       			                {
                                				s.soh=s.soh-qt;
                           			         }
                                	      	fwrite(&s,sizeof(s),1,fp5);
                     			       }

                        			fclose(fp5);
                    			        fclose(fp2);

                        			remove("stock.dat");
                        			rename("temp.dat","stock.dat");

                        			fclose(fp1);
                        			fclose(fp3);

                                                sa.item_no=no;
                                                sa.qty=qt;
                                                sa.amount=qt*am;

                                                fwrite(&sa,sizeof(sa),1,fp4);

                                                if(t1<t2)
                                                {
                                                      fp6=fopen("qty.dat","rb");

                                                        while(fread(&q,sizeof(q),1,fp6)==1)
                                                        {
                                                        	if(q.item_no==no)
                                                                {
                                                                	break;
                                                                }
                                                        }
                                                      fp2=fopen("stock.dat","ab+");
                                                      fp5=fopen("temp.dat","wb");

                                                      while(fread(&s,sizeof(s),1,fp2)==1)
                                                      {
                                                      		if(s.item_no==no)
                                                                {
                                                                	s.soh=s.soh+q.qty;
                                                                }
                                                                fwrite(&s,sizeof(s),1,fp5);
                                                      }

                                                      fclose(fp6);
                                                      fclose(fp2);
                                                      fclose(fp5);

                                                      remove("stock.dat");
                                                      rename("temp.dat","stock.dat");
                                                }

                                                printf("\n Files Updated...");
                                                }
                                                else
                                                {
                                                	printf("\n No Stock ");
                                                }

                                                break;
                        case 2:
                        	rewind(fp4);

                                while(fread(&sa,sizeof(sa),1,fp4)==1)
                                {
                                	printf("\n %d \t %d \t %f ",sa.item_no,sa.qty,sa.amount);
                                }
                                break;
                        /*case 99:
                        	fclose(fp4);
                                exit(0);
                                break; */
                }
	}
        getch();
	}while(ch!=99);
getch();

}















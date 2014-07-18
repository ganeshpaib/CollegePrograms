/* Program to enter item & quantity and produce bill */

struct bill
 {
  int itemno,unitpz,stock;
  char itemname[20];
 };

#include<stdio.h>
#include<conio.h>
main()
 {
  struct bill *item;
  int i,ino,z,n,inum,qty,total,sum=0,ch;
  clrscr();
  printf("Enter the number of items to be inserted\n");
  scanf("%d",&ino);

  item=(struct bill *)malloc(sizeof(struct bill)*ino);

  printf( "Enter the details of the stock :\n");
  for( i = 0; i < ino; i++ )
   {
    printf( "\n" );
    printf( "item[%d] Item name : \n",i );
    flushall();
    scanf("%s",item[i].itemname);

    printf( "item[%d] Item No. : \n",i);
    flushall();
    scanf("%d",&item[i].itemno);

    printf("item[%d] Unit price : \n ",i);
    flushall();
    scanf("%d",&item[i].unitpz);

    printf("item[%d] Stock in hand : \n ",i);
    flushall();
    scanf("%d",&item[i].stock);
   }
 do
 {
  printf(" ENTER YOUR CHOICE \n ");
  printf(" 1 -> Stock Information\n " );
  printf(" 2 -> Billing\n " );
  scanf( "%d",&z);
  switch(z)
   {
    case 1:
	   printf( "\t\tSTOCK INFORMATION : \n");
	   printf("\n-----------------------------------------------\n");
	   printf( "ITEM \tITEM NO. \tUNIT PRICE(Rs.) \tSTOCK(kg) \n");
	   for( i= 0; i < ino; i++)
	    {
	     printf("%s   \t%d    \t%d \t%d\n ",item[i].itemname,item[i].itemno,item[i].unitpz,item[i].stock);
	    }
	   break;
    case 2:
	   printf("Enter number of items\n ");
	   scanf("%d",&n);
	   for(i =0; i < n; i++ )
	    {
	     printf( "Enter the item number :\n ");
	     scanf("%d",&inum);

	     printf("Enter the quantity \n ");
	     scanf("%d",&qty);
	     for(i = 0; i < ino; i++ )
	      {
	       if(n==item[i].itemno)
		{
		 total=qty * item[i].unitpz ;
		 printf(" %s \t%d \t%d \n",item[i].itemname,item[i].itemno,total);
		}
	      }
	     sum=sum+total;
	    }
	    printf(" \n\n\t TOTAL AMOUNT= %d",sum);
	   break;
  }
  printf("PRESS 7 TO CONTINUE\n ");
  scanf("%d",&ch);
 }while(ch==7);
  getch();

 }
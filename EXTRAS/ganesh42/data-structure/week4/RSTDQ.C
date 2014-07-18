/*PROGRAM TO IMPLEMENT AN INPUT RESTRICTED AND OUTPUT RESTRICTED DEQUE*/

#define max 15
#include<stdio.h>

int left=0,right=0;
int deq[max];


   int removeleft(int *left,int right)
   {
      if(*left<right)
      return deq[(*left)++];
      else
      {
      printf("no element to remove\n");
      return -1;
     }
   }


   int removeright(int *right,int left)
   {
      if(*right>left)
      return deq[--(*right)];
      else
      {
      printf("no element to remove\n");
      return -1;
      }
   }


   void insertleft(int *right,int item)
   {
   int i;
   if(*right<=max-1)
   {
     for(i=*right;i>=0;i--)
     deq[i]=deq[i-1];
     deq[left]=item;
     (*right)++;
   }
   else
   printf("not possible to insert\n");
  }


   void insertright(int *right,int item)
   {
      if(*right<=max-1)
      deq[(*right)++]=item;
      else
      printf("not possible\n");
   }


   void display(int left,int right)
   {
     int i;
     if(right>left)
     {
     for(i=left;i<right;i++)
     printf("%3d",deq[i]);
     }
     else
     printf("queue is empty\n");
   }

   void main()
   {
    char x;
    int c,item;
    void input();
    void output();
    clrscr();
    do
    {
    printf("ENTER YOUR CHOICE\n");
    printf("ENTER 1-INPUT RESTRICTED \n 2-OUTPUT RESTRICTED\n");
    scanf("%d",&c);
       switch(c)
       {
	   case 1:
		   input();
		   break;
	   case 2:
		   output();
		   break;
	   default:
		   printf("Invalid");
       }
   printf("press y to continue with the menu\n");
   scanf(" %c",&x);
   }while(x=='y');
   getch();
 }



  void input()
  {
    char x;
    int choice;
    int item;
    printf("INPUT RESTRICTED QUEUE\n");
    do
    {
    printf("ENTER 1-INSERT LEFT\n 2-REMOVE LEFT \n 3-REMOVE RIGHT\n 4-DISPLAY\n5-EXIT");
    scanf("%d",&choice);
      switch(choice)
      {
      case 1:
	    printf("enter the element\n");
	    scanf("%d",&item);
	    insertleft(&right,item);
	    break;
      case 2:
	     item=removeleft(&left,right);
	     if(item!=-1)
	     printf("removed item =%d\n",item);
	     break;
      case 3:
	     item=removeright(&right,left);
		if(item!=-1)
		printf("removed item is =%d\n",item);
		break;
      case 4:
		   display(left,right);
		   break;
     case 5:
		   exit(0);
     default:
		printf("\nInvalid");
	}
  printf("\n enter y to continue input restricted queue\n");
  scanf(" %c",&x);
  }while(x=='y');
}


 void output()
{
 int choice,item;
 char x;
 printf("OUTPUT RESTRICTED QUEUE\n");
do
{
printf("ENTER 1-INSERT LEFT\n 2-INSERT RIGHT \ 3-REMOVE LEFT\n 4-DISPLAY\n5-EXIT");
    scanf("%d",&choice);

	   switch(choice)
	   {
      case 1:
	    printf("\n enter the element\n");
	    scanf("%d",&item);
	    insertleft(&right,item);
	    break;
     case 2:
		    printf("\n enter the element to be inserted\n");
		    scanf("%d",&item);
		    insertright(&right,item);
		    break;
     case 3:
		     item=removeleft(&left,right);
		      if(item!=-1)
		       printf("\n removed item =%d\n",item);
				     break;
     case 4:
		   display(left,right);
		   break;
     case 5:
		   exit(0);
    default:
		printf("\nInvalid");
	}
  printf("\n enter y to continue with the output restricted queue\n");
  scanf(" %c",&x);
 } while(x=='y');
   }


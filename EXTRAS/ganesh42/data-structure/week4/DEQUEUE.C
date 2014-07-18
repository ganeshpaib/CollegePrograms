/*PROGRAM TO IMPLEMENT THE DEQUE*/

# define max 15
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
      printf("No element to remove\n");
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
   printf("Not possible to insert\n");
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
    clrscr();
    do
    {
    printf("ENTER YOUR CHOICE\n");
    printf(" 1-TO INSERT LEFT \n 2-INSERT RIGHT \n 3-REMOVE LEFT\n 4-REMOVE RIGHT \n 5-DISPLAY\n 6-EXIT\n");
    scanf("%d",&c);
       switch(c)
       {
	   case 1:
		    printf("enter the element\n");
		    scanf("%d",&item);
		    insertleft(&right,item);
		    break;
	   case 2:
		    printf("enter the element to be inserted\n");
		    scanf("%d",&item);
		    insertright(&right,item);
		    break;
	   case 3:
		     item=removeleft(&left,right);
		      if(item!=-1)
		       printf("removed item =%d\n",item);
				     break;
	   case 4:
		   item=removeright(&right,left);
		     if(item!=-1)
		     printf("removed item is =%d\n",item);
		   break;
	   case 5:
		   display(left,right);
		   break;
	   case 6:
		   exit(0);
	}
     printf("\n enter y to continue\n");
     scanf(" %c",&x);
     } while(x=='y');
  getch();
  }


/* Dequeue */

#include<stdio.h>
#include<conio.h>
#define max 10

int left,right;
int deque[max];
int removeleft(int *left,int right)
{
   if(*left<right)
   return deque[(*left)++];
   printf("No element to remove!!\n");
   return -1;
}

int removeright(int *right,int left)
{
   if(*right>left)
   return deque[--(*right)];
   printf("NO elements to remove !!\n");
   return -1;
}

void insertleft(int *right,int item)
{
  int i;
  if(*right<=max-1)
  {
     for(i=*right;i>0;i++)
     deque[i]=deque[i-1];
     deque[left]=item;
     (*right)++;
  }
    else
    {
      printf("Not possible to insert !\n");
    }
}

void insertright(int *right,int item)
{
   if(*right<=max-1)
      deque[(*right)++]=item;
      else
      printf("Not possible to insert !\n");
}
void display(int left,int right)
{
  int i;
  if(right>left)
  {
    for(i=left;i<left;i++)
    printf("The elements are: %3d",deque[i]);
  }
  else
  printf("Queue is empty\n");
}

void main()
{
  int c,item;
  do
  {
    clrscr();
    printf("1> insert left\n 2> insert right\n");
    printf("3> Remove left\n 4> remove right\n");
    printf("5> Display\n 6> Exit\n\n");
    printf("\nEnter the choice: ");
    scanf("%d",&c);
    if(c==1||c==2)
    {
       printf("Enter the element to be inserted: ");
       scanf("%d",&item);
    }

    switch(c)
    {
      case 1: insertleft(&right,item);
	      break;
      case 2: insertright(&right,item);
	      break;
      case 3: item=removeleft(&left,right);
	      if(item!=1)
	      printf("Removed item=%d\n",item);
	      break;
      case 4: item=removeright(&right,left);
	      if(item!=-1)
	      printf("Removed item=%d",item);
	      break;
      case 5: display(left,right);
	      break;
      case 6: exit(0);
	      break;
      default: printf("invalid option\n");
   }
 }while(c!=6);
   getch();
}
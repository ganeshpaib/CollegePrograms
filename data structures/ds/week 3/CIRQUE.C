#include<stdio.h>
#include<conio.h>
#define MAX 3
struct queue
{
  int que;

}q[MAX];
int front=0,rear=0;
void addc(int *front,int *rear,int n)
{
	*rear=(*rear+1) % MAX;
  if( *rear==*front )
  {
		printf("\nthe queue is full:");
		if(*rear==0)
		{
			  *rear=MAX-1;
		}
		else
		{
			   *rear=*rear-1;
		}
  }
  else
  {
	 q[*rear].que=n;
  }
}
int delc(int *front,int *rear)
{
   if( *front== *rear)
   {
	 printf("\nthe queue is empty:");
	 return(-1);
   }
   else

    {
	 *front=(*front+1) % MAX;
	 return(q[*front].que);
   }
}
void displayc(int *front,int *rear)
{
 int i;
 if(*front<=*rear)
 {
	 for(i= (*front)+1 ; i <= *rear; i++)
	 {
		 printf("%5d",q[i].que);
	 }
 }
 else
 {

	for(i=(*front)+1 ; i <= MAX-1; i++)
	 {
		 printf("%5d",q[i].que);
	 }

	 for(i=0 ; i <=(*rear) ; i++)
	 {
		 printf("%5d",q[i].que);
	 }


 }


}

void main()

{
  int i,opt,n,m;
  do
  {
	  clrscr();
	  printf("\n 1 for add :");
	  printf("\n 2 for delete;");
	  printf("\n 3 for display:");
	  printf("\n 99 for exit:");
	  printf("\nenter the option:");
	  scanf("%d",&opt);
	  switch(opt)
	  {
		case  1:printf("\nenter the element to addeed;");
				scanf("%d",&n);
				addc(&front,&rear,n);
				printf("\nthe element is added:");
				break;
		case 2:
				 m=delc(&front,&rear);
				 if(m!=-1)
					 printf("\n the deleated element is %d",m);
				 break;
		case 3:
				printf("\nthe element of the circular queue are :");
				displayc(&front,&rear);
				break;
		case 99: exit(0);
  }
  getch();
 }while(opt!=99);
 getch();
}
#include<stdio.h>
#include<conio.h>
#define MAX 10
struct queue
{
 int q;
}s[MAX];
int front=-1,rear=-1;
void display(int *front,int *rear)
{
   int i;
	if(*rear== *front )
   {
	 printf("\n the queue is empty:");
   }
			 for(i=(*front+1);i<=*rear;i++)
			  {
					printf("%5d",s[i].q);
			  }
}
void add(int *rear ,int n)
{
	if(*rear==MAX-1)
	{
	  printf("\nthe queue is full:");
	}
	else
	{
		s[++*rear].q=n;
		printf("\nthe element is added:");
	}
}
int del(int *front ,int *rear)
{
   if(*rear== *front )
   {
	 printf("\n the queue is empty:");
	 return(-1);
   }
   else
   {
	 return(s[++*front].q);
   }
}
void main()
{
int opt,n,m;
do
{
	clrscr();
	printf("\n 1:add queue:");
	printf("\n 2:delete queue:");
	printf("\n 3 :display:");
	printf("\n 99 :exit:");
	printf("\nenter the option");
	scanf("%d",&opt);
	switch(opt)
	{
	  case 1:printf("\nenter the element to be added.");
			scanf("%d",&n);
			add(&rear,n);
			break;
	   case 2:
			  m = del( &front,&rear);
			  if(m!=-1)
			  {
			  printf("\nthe deleated element is %d",m);
			  }
			  break;
	   case 3:
			  printf("\nthe element of the queue are:");
			  display(&front,&rear);
			  break;

	}
	getch();
}while(opt!=99);
getch();
}
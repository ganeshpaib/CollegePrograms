#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

int left=0,right=MAX;
int deq[MAX];

void insert_left(int *left,int *right,int n)
{
	int i;
	if( (*left) < (*right) )
	{
	   for(i=(*left) ; i >= 0 ; i-- )
		   deq[i+1]=deq[i];

	   (*left)++;
	   deq[0]=n;
	}
	else
		printf("\nthe queue is full:");

}

void insert_right(int *left,int *right,int n)
{
	int i;
	if( (*left) < (*right))
	{
		for(i=(*right);i<=MAX-1;i++)
		{
		   deq[i-1]=deq[i];
		}

		(*right)--;
		deq[(MAX-1)]=n;
		printf("\nThe element is added:");

	}
	else
		  printf("\nqueue is full:");

}

void delete_left(int *left,int *right)
{
	int i;
   if((*left) > 0)
   {
	printf("\ndeleted data is :%d",deq[0]);
	for(i=0;i<=(*left);i++)
	   deq[i]=deq[i+1];
	   (*left)--;
   }
   else
   {
	  if( (*right) <= MAX-1 )
	  {
		printf("\nThe deleted data is %d",deq[(*right)++] );
	  }
	  else
	  printf("\nthe list is empty:");
   }

}


void delete_right(int *left,int *right)
{
	 int i;
	 if( (*right) < MAX)
	 {

	   printf("\nthe deleted element is %d",deq[MAX-1]);
	for(i=(MAX-1);i>=(*right);i--)
		deq[i]=deq[i-1];
		(*right)++;
	  }
	  else
	  {
	  if((*left) > 0)
		  printf("\nThe deleted element is %d",deq[(*left)--]);
	  else
		printf("\nThe queue is empty:");
	   }

}

void display(int *left,int *right)
{
	int i;
	  if((*left) == 0 && (*right) == MAX )
	printf("\nThe DEQ is empty:");
	  else
	  {
	printf("\nThe element in the DEQ are.........");
	for(i=0;i<(*left);i++)
		printf("\n%5d",deq[i]);
	   for(i=(*right);i<=(MAX-1);i++)
		printf("\n%5d",deq[i]);
	  }

}

void main()
{

	int opt,n;

do
{

	clrscr();
	printf("\npress 1 for insert at the left:");
	printf("\n press 2 for insert at the right:");
	printf("\npress 3 for delete at the left:");
	printf("\npress 4 for delete at the right:");
	printf("\npress 5 for display:");
	printf("\npress 99 for exit:");
	printf("\nenter the option:");
	scanf("%d",&opt);
	switch(opt)
	{
	  case 1:
		printf("\nenter the element to insert at the left:");
		scanf("%d",&n);
		insert_left(&left,&right,n);
		break;
	  case 2:
		printf("\nenter the element to insert at the right:");
		scanf("%d",&n);
		insert_right(&left,&right,n);
		break;
	  case 3:
		delete_left(&left,&right);
		break;
	  case 4:delete_right(&left,&right);
		break;
	  case 5:display(&left,&right);
		 break;
	 }
	getch();
}while(opt!=99);

getch();
}
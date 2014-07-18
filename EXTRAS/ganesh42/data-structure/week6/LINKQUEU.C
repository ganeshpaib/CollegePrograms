/*program to implement a queue using a linked list*/

#include<stdio.h>
#define NULL 0

typedef struct queue *q_ptr;
typedef struct queue
{
	int data;
	q_ptr link;
};
q_ptr front=NULL,rear=NULL;

void insert(int item)
{
	q_ptr temp;
	temp=(struct queue *)malloc (sizeof(struct queue));
	temp->data=item;
	temp->link=NULL;
	if(front==NULL)
		front=temp;
	else
		rear->link=temp;
		rear=temp;
}

int delete()
{
	 q_ptr temp;
	 int num=0;
	 if(front==NULL)
	 printf("\n Queue is empty\n");
	 else
	 {
	   temp=front;
	   num=temp->data;
	   front=front->link;
	   free(temp);
	 }
	   return(num);
}


void display()
{
	q_ptr temp;
	if(front==NULL)
		printf("\n Queue is empty\n");
	else
	{
		printf("\n Elements in the queue\n");
		for(temp=front;temp!=NULL;temp=temp->link)
		printf("%3d",temp->data);
	}
}


void main()
{
	int choice,num;
	char x;
	clrscr();
	do
	{

	   printf("\n \t1. Insert \n \t2. Delete\n \t3. Display\n \t4. Exit\n");
	   printf("\n\tEnter your choice\n\t");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	       case 1:
		      printf("\tEnter the Number\n\t");
		      scanf("%d",&num);
		      insert(num);
		      break;
	       case 2:
		      num=delete();
		      if(num!=0)
		      printf("\n \t%d is deleted",num);
		      break;
	       case 3:
		      display();
		      break;
	       case 4:
		      exit(0);
	   }
	printf("\n\t Press y to continue\n\t");
	scanf(" %c",&x);
	}while(x=='y');
getch();
}





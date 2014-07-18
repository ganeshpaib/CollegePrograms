#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list_node *list_ptr;
typedef struct list_node
{
int data;
list_ptr link;
};
list_ptr ptr=NULL;
int i=0,n,f=0;

void create(list_ptr *ptr ,int);
void display(list_ptr *ptr);

void main()
{
int ch;
clrscr();
do
{
	clrscr();
	printf("\n\n\t1... Create List");
	printf("\n\t2... Display");
	printf("\n\t99.. Exit ");
	printf("\n Enter Your Choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		printf("\n Enter Number Of Node :");
		scanf("%d",&n);
		create(&ptr,n);
		break;
	case 2:
		display(&ptr);
		break;
	case 99:
			exit(0);
			break;


	}
 getch();
}while(ch!=99);
getch();
}

void create(list_ptr *ptr ,int n)
{
	int item;
	list_ptr temp,t;

	if(n>0)
	{
	  printf("\n Enter New Node : ");
	  scanf("%d",&item);


	  temp=(list_ptr)malloc(sizeof(struct list_node));
	  temp->data=item;
	  temp->link=NULL;

	  if( (*ptr)==NULL)
	  {
		(*ptr)=temp;
	  }
	  else
	  {
	    for(t=(*ptr);t->link!=NULL;t=t->link);
	    t->link=temp;
	  }
	  n--;
	  create(&(*ptr),n);
	}
	else
	{
		printf("\n The List Is Created...");
	}


}
void display(list_ptr *ptr)
{
list_ptr t;

if(*ptr!=NULL)
{
	f=1;
	printf("%5d",(*ptr)->data);

	display(&(*ptr)->link);
}

if(f==0)
{
	printf("\n The List Is Empty...");
}

}


#include<stdio.h>
#include<conio.h>
typedef struct list_node *list_ptr;
typedef struct list_node
{
	int data;
	list_ptr link;
};
list_ptr create_list(list_ptr *,int);
void display(list_ptr *);
main()
{
	int choice,data;
	list_ptr *ptr=NULL;
	do
	{

	printf( "Enter ur choice\n" );
	printf( "1 -> CREATE NODE\n" );
	printf( "2 -> INSERT NEW NODE\n" );
	printf( "3 -> DISPLAY NODE\n" );
	printf( "4 -> DELETE NODE\n" );
	scanf( "%d",&choice );

	switch(choice)
	{
		case 1: printf( "Enter the data\n" );
				scanf( "%d",&data );

				ptr=create_list(&ptr,data);
				break;

		case 2: display(&ptr);
			break;



	}
      }while(choice!=5);
 getch();
}

list_ptr create_list(list_ptr *ptr,int data )
{
	list_ptr temp;
	temp=(list_ptr) malloc(sizeof(struct list_node));
	temp->data=data;
	if(*ptr==NULL)
	{
		temp->link=*ptr;
		*ptr=temp;
	}
	else
	{
		printf( "LIST ALREADY CREATED\n" );
	}
}


void display(list_ptr *ptr)
{
  list_ptr t;
	for(t=*ptr;t->link!=NULL;t=t->link)
		printf( "%d",t);
}
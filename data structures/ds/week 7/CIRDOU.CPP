#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct struct_node *node_ptr;
typedef struct struct_node
{
	int data;
	node_ptr llink,rlink;

}struct_node;
node_ptr ptr=NULL;
void insert_beg(node_ptr *ptr);
void insert_end(node_ptr *ptr);
void main()
{
int opt;
clrscr();
 do
 {
	clrscr();
	printf("\npress 1 for insert beg:");
	printf("\npress 2 for insert end;");
	printf("\npress 3 for delete:");
	printf("\npress 5 for display");

	printf("\npress 99 for exit:");
	printf("\nenter the  option:");
	scanf("%d",&opt);

 switch(opt)
 {
     case 1:insert_beg();

     case 10:display(&ptr);break;
 }
 getch();
 }while(opt!=99);
getch();
}
void display(node_ptr *ptr)
{
 node_ptr t;
  if((*ptr)==NULL)
  {
  printf("\nthe list is empty:");
  }
  else
	{
		for(t=(*ptr);t!=NULL;t=t->rlink)
		     printf("%5d",t->data);
	}
}
/*void i(node_ptr *ptr)
{
node_ptr temp,t;
int val;
temp=(node_ptr)malloc(sizeof(struct_node));
printf("\nenter the value to be inserted:");
scanf("%d",&val);
temp->data=val;
if((*ptr)==NULL)
{
(*ptr)=temp;
temp->llink=NULL;
temp->rlink=NULL;
}
 else
 {
	temp->rlink=(*ptr);
	(*ptr)->llink=temp;
	temp->llink=NULL;
	(*ptr)=temp;
 }

} */
void insert_beg(node_ptr *ptr)
{
	node_ptr t,temp;
	int val;
	temp=(node_ptr)malloc(sizeof(struct_node));
	printf("\nenter the value to be inserted:");
	scanf("%d",&val);
	temp->data=val;

	if(head->rlink!=head)
	{
		 head->rlink=temp;
		 temp->llink=head;
		 for(t=(*ptr);t->rlink!=head;t=t->rlink)
		 t->rlink=head;
		 head->llink=t;

	}
	else
	 {
	    head->rlink=temp;
	    temp->llink=head;
	    temp->rlink=head;
	    head->llink=temp;
	 }
}
void delete_that(node_ptr *ptr)
{
    int n,f=0;
    node_ptr t;
	printf("\nenter the data to be deleted:");
	scanf("%d",&n);
    if( (*ptr)==NULL)
	printf("\nthe list is empty:");
    else if((*ptr)->data==n)
    {      f=1;
	   (*ptr)=(*ptr)->rlink;
	   (*ptr)->llink=NULL;
	   printf("\nthe first node is deleted:");
    }
    else
    {
	for(t=(*ptr);t!=NULL;t=t->rlink)
	{   f=0;
	   if(t->data==n)
	   {   f=1;
	       t->llink->rlink=t->rlink;
	       t->rlink->llink=t->llink;
	       printf("\nThe node is deleted:");
	       break;
	   }
	}
	if(f==0)
	  printf("\nthe node not found:");

    }
}
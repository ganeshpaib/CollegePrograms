#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list_node *list_ptr;
typedef struct list_node
{
int data;
list_ptr link;
};
list_ptr ptr1=NULL,ptr2=NULL,ptr=NULL;
void insert_end(list_ptr *ptr)
{
  list_ptr temp,t;
  int val;
  printf("\nenter the value to be inserted:");
  scanf("%d",&val);

  temp=(list_ptr)malloc(sizeof(list_node));
  temp->data=val;

 if( (*ptr)==NULL)
 {
   temp->link=NULL;
   (*ptr)=temp;
 }
 else
 {
   for(t=(*ptr);t->link!=NULL;t=t->link);
   t->link=temp;
   temp->link=NULL;
 }

}
void display(list_ptr *ptr)
{
list_ptr t;
if((*ptr)==NULL)
printf("\nThe list is empty:");
else
{
 for(t=(*ptr);t!=NULL;t=t->link)
 printf("%5d",t->data);
}
}
void concatinate(list_ptr *ptr1,list_ptr *ptr2 ,list_ptr *ptr)
{
list_ptr t;
if((*ptr1)==NULL && (*ptr2)==NULL)
{
(*ptr)=(*ptr1);
printf("\nThe resultant list is empty");
}
else if((*ptr1)!=NULL && (*ptr2)==NULL)
{
(*ptr)=(*ptr1);
}
else if( (*ptr1)==NULL && (*ptr2)!=NULL )
{
(*ptr)=(*ptr2);
}
else
{
(*ptr)=(*ptr1);
for(t=(*ptr);t->link!=NULL;t=t->link);
t->link=(*ptr2);
}
printf("\nThe list is concatinate:");
}
void main()
{
 int opt;
 char ch;
 do
 {
  clrscr();
 printf("\npress 1 for First list creation:");
 printf("\npress 2 for Second list creation:");
 printf("\nPress 3 for Concatination of two list:");
 printf("\npress 4 for display:");
 printf("\npress 99 for exit:");
 printf("\nenter the option:");
 scanf("%d",&opt);
 switch(opt)
 {
	 case 1:
		do
		{
		clrscr();
		insert_end(&ptr1);
		printf("\nany more node you want to create:");
		scanf("%c",&ch);
		}while(ch=='y' || ch == 'Y');
		printf("\nThe first list is ...");
		display(&ptr1);
		break;
	 case 2:
		do
		{

		clrscr();
		insert_end(&ptr2);
		printf("\nany more node you want to create:");
		scanf("%c",&ch);
		}while(ch=='y' || ch == 'Y');
		printf("\nThe second list is ...");
		display(&ptr2);
		break;
	 case 3:
		concatinate(&ptr1,&ptr2,&ptr);
		break;
	 case 4:
		printf("\nThe concatinate list is ...");
		display(&ptr);
		break;

 }
 getch();
 }while(opt!=99);
}
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
void insert_after(node_ptr *ptr);
void insert_before(node_ptr *ptr);
void delete_beg(node_ptr *ptr);
void delete_end(node_ptr *ptr);
//void delete_after(node_ptr *ptr);
//void delete_before(node_ptr *ptr);
void delete_that(node_ptr *ptr);
//void delete_alter_odd(node_ptr *ptr);
//void delete_alter_even(node_ptr *ptr);
void sort(node_ptr *ptr);
//void insert_sort(node_ptr *ptr);
void reverse(node_ptr *ptr);
void display(node_ptr *ptr);

void main()
{
int opt;
clrscr();
 do
 {
	clrscr();
	printf("\npress 1 for insert beg:");
	printf("\npress 2 for insert end;");
	printf("\npress 3 for insert after:");
	printf("\npress 4 for insert before");
	printf("\npress 5 for delete beg:");
	printf("\npress 6 for delete end:");
  //	printf("\npress 7 for delete after:");
    //	printf("\npress 8 for delete before:");
	printf("\npress 7 for delete that:");
     //	printf("\npress 10 for delete alternate odd:");
     //	printf("\npress 11 for delete alternate even");
	printf("\npress 8 for sort the list:");
    //	printf("\npress 13 for sort in inserting order:");

	printf("\npress 9 for reverse :");
	printf("\npress 10 for display");

	printf("\npress 99 for exit:");
	printf("\nenter the  option:");
	scanf("%d",&opt);

 switch(opt)
 {
	case 1:insert_beg(&ptr);break;
	case 2:insert_end(&ptr);break;
	case 3:insert_after(&ptr);break;
	case 4:insert_before(&ptr);break;

	case 5:delete_beg(&ptr);break;
	case 6:delete_end(&ptr);break;
       //	case 7:delete_after(&ptr);break;
      //	case 8:delete_before(&ptr);break;
	case 7:delete_that(&ptr);break;
       //	case 10:delete_alter_odd;break;
      //	case 11:delete_alter_even;break;
	case 8:sort(&ptr);break;
      //	case 13:sort_insert(&ptr);break;
	case 9:reverse(&ptr);break;
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
void insert_beg(node_ptr *ptr)
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

}
void insert_end(node_ptr *ptr)
{
	node_ptr t,temp;
	int val;
	temp=(node_ptr)malloc(sizeof(struct_node));
	printf("\nenter the value to be inserted:");
	scanf("%d",&val);
	temp->data=val;
	if(*ptr==NULL)
	{
		 (*ptr)=temp;
		 temp->llink=NULL;
		 temp->rlink=NULL;

	}
	else
	 {
		for(t=(*ptr);t->rlink!=NULL;t=t->rlink);
		 t->rlink=temp;
		 temp->llink=t;
		 temp->rlink=NULL;
	 }
}
void sort(node_ptr *ptr)
{
	node_ptr  t1,t2;
	int temp;
	for(t1=(*ptr);t1!=NULL;t1=t1->rlink)
	{
		for(t2=t1->rlink;t2!=NULL;t2=t2->rlink)
		{
		     if( t1->data > t2->data)
		     {
			temp=t1->data;
			t1->data=t2->data;
			t2->data=temp;
		     }
		}
	}
}
void insert_after(node_ptr *ptr)
{
node_ptr temp,t;
int val,after,f=0;
temp=(node_ptr)malloc(sizeof(struct_node));
printf("\nenter which value u want to enter after which value:");
scanf("%d%d",&val,&after);
temp->data=val;

	if((*ptr)==NULL)
		printf("\nthe list is empty:");
	else
	{
	    for(t=(*ptr);t!=NULL;t=t->rlink)
	    {
		       if(t->data==after)
		       {
			    f=1;
			    break;

		       }
	    }
	    if(f==1)
	    {  temp->rlink=t->rlink;
		t->rlink->llink=temp;
		t->rlink=temp;
		temp->llink=t;

	    }
	    else
	    printf("\nNode not found:");
	}

}
void insert_before(node_ptr *ptr)
{
	node_ptr temp,t;
	int f=0,before,val;
	temp=(node_ptr)malloc(sizeof(struct_node));
	printf("\nenter the value to inserted after which value:");
	scanf("%d%d",&val,&before);
	temp->data=val;
	if((*ptr)==NULL)
		printf("\nThe node is empty");
	else if((*ptr)->data==before)
	{         f=1;
	    temp->rlink=(*ptr);
	    (*ptr)->llink=temp;
	    temp->llink=NULL;
	    (*ptr)=temp;
	    printf("\nthe element is added:");
	}
	else
	{
	   for(t=(*ptr);t!=NULL;t=t->rlink)
	   {
		   if(t->data==before)
		   {    f=1;
			t->llink->rlink=temp;
			temp->llink=t->llink;
			temp->rlink=t;
			t->llink=temp;
			printf("\nThe element is added:");
			break;
		   }
	   }
	   if(f!=1)
		printf("\nThe node not found:");
	}
}
void delete_beg(node_ptr *ptr)
{
	if((*ptr)==NULL)
		printf("\nThe node is empty");
	else
	{
	    (*ptr)=(*ptr)->rlink;
	     (*ptr)->llink=NULL;
	     printf("\nnode is deleted:");
	}

}
void delete_end(node_ptr *ptr)
{
     node_ptr t;
	if( (*ptr)==NULL)
		printf("\nThe node is empty:");
	 else
	 {     if((*ptr)->rlink==NULL)
			(*ptr)=NULL;
	       else
	       {
			for(t=(*ptr);t->rlink!=NULL;t=t->rlink);
			t->llink->rlink=NULL;
		}
		printf("\nThe end node is deleted:");
	 }
}
/*void delete_after(node_ptr *ptr)
{
int after,f=0;

printf("\nenter after which value u want to delete:");
scanf("%d",&after);

if( (*ptr)==NULL)
	printf("\nThe list is empty:");
else
{
	for(t=(*ptr),prev=t;t!=NULL;t=t->rlink)
	 if(prev->data==after)
	   prev->rlink=prev->

}

} */
void reverse(node_ptr *ptr)
{
	node_ptr mid,prev;
	if(*ptr==NULL)
		printf("\nThe list is empty:");
	else
	{       mid=NULL;
		while( (*ptr)!=NULL)
		{
		   prev=mid;
		   mid=(*ptr);
		   (*ptr)=(*ptr)->rlink;
		   mid->rlink=prev;
		   prev->llink=mid;
		}
		printf("\nThe node is reversed");
		(*ptr)=mid;

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
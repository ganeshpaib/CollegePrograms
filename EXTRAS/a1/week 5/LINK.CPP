#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct list_node *list_ptr;
typedef struct list_node
{
	int data;
	list_ptr link;
} ;
list_ptr ptr=NULL;
void insert_beg(list_ptr *ptr);
void insert_end(list_ptr *ptr);
void insert_after(list_ptr *ptr);
void insert_before(list_ptr *ptr);

void delete_beg(list_ptr *ptr);
void delete_end(list_ptr *ptr);
void delete_after(list_ptr *ptr);
void delete_that(list_ptr *ptr);
void delete_before(list_ptr *ptr);

void delete_alter_odd(list_ptr *ptr);
void delete_alter_even(list_ptr *ptr);
void sort(list_ptr *ptr);
void reverse(list_ptr *ptr);
void insert_sort(list_ptr *ptr);
void display(list_ptr *ptr);


void main()
{
	int opt;
	clrscr();
	do
	{
		clrscr();
		printf("\npress 1 for insert beg:");
		printf("\npress 2 for insert end:");
		printf("\npress 3 for insert after:");
		printf("\npress 4 for insert before:");

		printf("\npress 5 for delete beg:");
		printf("\npress 6 for delete end:");
		printf("\nlpress 7 for delete after :");
		printf("\npress 8 for delete before:");
		printf("\npress 9 for deleter that:");

		printf("\npress 10 for delete odd:");
		printf("\npress 11 for delete even:");

		printf("\npress 12 for sorting:");
		printf("\npress 13 for reverse:");

		printf("\npress 14 for insert in sorted order ;");
		printf("\npress 15 for display");
		printf("\nenter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:insert_beg(&ptr); break;
			case 2:insert_end(&ptr);break;
			case 3:insert_after(&ptr);break;
			case 4:insert_before(&ptr);break;

			case 5:delete_beg(&ptr); break;
			case 6:delete_end(&ptr);break;
			case 7:delete_after(&ptr);break;
			case 8:delete_before(&ptr);break;
		 /**/	case 9:delete_that(&ptr);break;

			case 10:delete_alter_odd(&ptr);break;
			case 11:delete_alter_even(&ptr);break;

			case 12:sort(&ptr);break;
			case 13:reverse(&ptr);break;
		/**/	case 14:insert_sort(&ptr);break;

			case 15:display(&ptr);break;
		}
		getch();
	}while(opt!=99);
	getch();
}
void insert_beg(list_ptr *ptr)
{
	int val;
	list_ptr temp;
	temp=(list_ptr)malloc(sizeof(list_node));
	printf("\nenter the data to be be inserted at the beg:");
	scanf("%d",&val);
	temp->data=val;
	if(*ptr==NULL)
	{	*ptr=temp;
		temp->link=NULL;
		printf("\nthe first node is created:");
	}
	else
	{
		temp->link=*ptr;
		*ptr=temp;
		printf("\none element is added at the first ;");
	}
}
void display(list_ptr *ptr)
{

     list_ptr t;
	if(*ptr!=NULL)
	{       printf("\nthe element in the list are\n");
		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
	else
	{
		printf("\nthe list is empty:");
	}

}
void insert_end(list_ptr *ptr)
{
	list_ptr t,temp;
	int val;
	printf("\nenter the value to be added at the end :");
	scanf("%d",&val);
	temp=(list_ptr)malloc(sizeof(list_node));
	temp->data=val;

	if(*ptr!=NULL)
	{
		for(t=*ptr;t->link!=NULL;t=t->link);
		 t->link=temp;
		 temp->link=NULL;
		 printf("\nthe node is added;");
	}

	else
	{
		*ptr=temp;
		temp->link=NULL;
		printf("\nfirst node is created:");
	}

}

void insert_before(list_ptr *ptr)
{
	list_ptr temp,t,prev;
	int val,before;
	int f=0;
	temp=(list_ptr)malloc(sizeof( list_node));
	printf("\nenter the data to be inserted:");
	scanf("%d",&val);
	temp->data=val;
	printf("\nenter the data to be inserted before which value:");
	scanf("%d",&before);
		if((*ptr) == NULL)
			printf("\nthe list is empty:");

		else if((*ptr)->data==before)
		{
			temp->link=*ptr;
			*ptr=temp;
		}

		else
		{

			for(t=*ptr,prev=t;t!=NULL;prev=t,t=t->link)
			{
			      if(t->data==before)
			      {
				  f=1;
				  break;
			      }

			 }

			 if(f==1)
			 {
				/*if(t==*ptr)
				{
					temp->link=*ptr;
					*ptr=temp;
				}
				else
				{*/

				temp->link=prev->link;
				prev->link=temp;
			       //	}
			 }

			 else
			   printf("\nthe node not found;%d",before);

		}
}
void insert_after(list_ptr *ptr)
{
int val,after,f=0;
list_ptr temp,t,next;
temp=(list_ptr)malloc(sizeof(list_node));
printf("\nenter the value to be added after which value");
scanf("%d%d",&val,&after);
temp->data=val;
if(*ptr==NULL)
printf("\nthe list is empty;");
 else
 {
	for(t=(*ptr);t!=NULL;t=t->link)
	{

	      if(t->data==after)
	      {
		      next=t->link;
		      t->link=temp;
		      temp->link=next;
		      printf("\none element is added:");
		      f=1;
	      }
	  }
	  if(f==0)
	     printf("\nelement not found:");

 }

}
void delete_beg(list_ptr *ptr)
{
	list_ptr t;
	if(*ptr!=NULL)
	{  t=*ptr;
	   (*ptr)=(*ptr)->link;
	   printf("\nfirst node is deleted:");
	   free(t);
	}
	else
	{
		printf("\nthe list is empty:");
	}
}
void delete_end(list_ptr *ptr)
{
	list_ptr t,prev;
	if((*ptr)->link==NULL)
	{
		(*ptr)=NULL;
		printf("\nlist become empty;");
	}
	else if(*ptr!=NULL)
	{
	  for( t=(*ptr) , prev=t ; t ->link !=NULL ; prev=t , t=t->link );
	  prev->link=NULL;
	  printf("\nlast node is deleted:");
	  free(t);
	}
	else
	{
	    printf("\nthe list is empty:");
	}
}
void delete_after(list_ptr *ptr)
{
   list_ptr prev,t;
   int after,f=0;
   printf("\nafter which value it have to be deleted:");
   scanf("%d",&after);
   if(*ptr==NULL)
   printf("\nthe list is empty:");
   else
   {
	 for(t=*ptr,prev=t;t!=NULL;prev=t,t=t->link)
		 if(t->data==after && t->link!=NULL)
		  {
			   t->link=t->link->link;
			  f=1;
			  printf("\nThe node is deleted:");
			 break;
		   }
	 if(f!=1)
		printf("\nno node after this %d",after);



   }

}

void delete_alter_odd(list_ptr *ptr)
{
  list_ptr t;
 if(*ptr==NULL)
	 printf("\nthe list is empty:");
 else
 *ptr=(*ptr)->link;
 printf("\nall odd node are deleted:");
	for(t=(*ptr); (t!=NULL && t->link!=NULL)  ;t=t->link)
	{
		t->link=t->link->link;
	}

 }
void delete_alter_even(list_ptr *ptr)
{
  list_ptr t;
  if(*ptr==NULL)
	 printf("\nthe list is empty:");

  else
	for(t=(*ptr); (t!=NULL && t->link!=NULL)  ;t=t->link)
	{
		t->link=t->link->link;
	}
   printf("\nalternate even node are deleted:");
 }
 void delete_before(list_ptr *ptr)
 {
	list_ptr t,prev=NULL,temp=NULL;
	int n,f=0;
	printf("\n Enter data :");
	scanf("%d",&n);

	if(*ptr==NULL)
	{
		printf("\n List empty ");
	}
	else
	{
		for(t=*ptr;t!=NULL;temp=prev,prev=t,t=t->link)
		{
			if(t->data==n)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			if(t==*ptr)
			{
				printf("\n No Node....");
			}
			else if(prev==*ptr)
			{
				*ptr=t;
				printf("\nrequired node is deleted:");
				free(prev);
			}
			else
			{
				temp->link=t;
				free(prev);
			}
		}
		else
		{
			printf("\n   No Data Found....");
		}
	}
 }
 void sort(list_ptr *ptr)
 {
   list_ptr  t1,t2;
   int temp;
   for(t1=*ptr;t1!=NULL;t1=t1->link)
   {
	for(t2=t1->link;t2!=NULL;t2=t2->link)
	{
		if((t1->data) >(t2->data))
		{
		  temp=t1->data;
		  t1->data=t2->data;
		  t2->data=temp;
		}
	}
   }
   printf("\nthe list is sorted:");
 }
 void insert_sort( list_ptr *ptr )
 {
	list_ptr prev,t,temp;
	int val,f=0;
	temp=(list_ptr)malloc(sizeof(list_node));
	printf("\nenter the value to be added:");
	scanf("%d",&val);
	temp->data=val;
	if(*ptr==NULL)
	{  *ptr=temp;
	   temp->link=NULL;
	 }
	else if(((*ptr)->data) >= val)
	{
		   printf("\nnew element is added at the first:");
		   temp->link=(*ptr);
		   *ptr=temp;
	}
	else
	{
		for(t=*ptr,prev=t;t!=NULL;prev=t,t=t->link)
		{
			   if( t->data > val )
			    {
				f=1;
				break;
			    }
		}

		if(f==1)
		{
			temp->link=prev->link;
			prev->link=temp;
			printf("\nelement is added:");
		}
		else
		{
			prev->link=temp;
			temp->link=NULL;
			printf("\nthe element is added at the last:");
		}
	}
 }



  void delete_that(list_ptr *ptr)
  {
	list_ptr temp,prev,t;
	int val,f=0;
	printf("\nenter the data to be deleted:");
	scanf("%d",&val);
	if((*ptr)==NULL)
		printf("\nthe list is empty:");

	 else if((*ptr)->data==val)
	 {
		t=(*ptr)->link;
		 *ptr=t;
		 printf("\nthe element is deleted:");
	   }
       //	 if((*ptr)->data!=val )
	 else
	 {

		for(t=(*ptr);t!=NULL;t=t->link)
		{
		    if(t->link->data==val)
		    {
		     //	prev=t->link;
			t->link=t->link->link;
		       //	t=prev;
			f=1;
		    }
//		     continue;
		}
		if(f!=1)
		      printf("\nthe node not found:");
	 }

       printf("\nthe element is deleted ");
  }
  void reverse(list_ptr *ptr)
  {
     list_ptr mid ,prev;
	mid=NULL;
	while((*ptr)!=NULL)
	{
	   prev=mid;
	   mid=(*ptr);
	   (*ptr)=(*ptr)->link;
	   mid->link=prev;
	}
	(*ptr)=mid;
	printf("\nthe list is reversed;");
  }
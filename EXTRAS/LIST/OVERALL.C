#include<stdio.h>
#include<conio.h>

typedef struct list_node *list_ptr;
typedef struct list_node
{
	int data;
	list_ptr link;
};
list_ptr ptr=NULL;
int flg=0;
void add_beg(list_ptr *,int);
void disp_el(list_ptr *);
void add_end(list_ptr *,int);
void add_bef(list_ptr *,int,int);
void add_aft(list_ptr *ptr,int,int);
void del_el(list_ptr *ptr,int);
void sort_el(list_ptr *);
void delal_el(list_ptr *);
void ins_sort(list_ptr *,int);
main()
{
	int choice,item,sdata;
	clrscr();
	do
	{
		clrscr();
		printf( "1-> ADD NEW NODE AT BEGINNING\n" );
		printf( "2-> END\n" );
		printf( "3-> BEFORE ANY ELEMENT\n" );
		printf( "4-> AFTER ANY ELEMNT\n" );
		printf( "5-> DELETE ANY ELEMENT\n" );
		/*printf( "6-> TRAVERSE THROUGH THE NODES\n" );*/
		printf( "7-> SORT\n" );
		printf( "8-> DELETE EVERY ALTERNATE NODE\n" );
		printf( "9-> INSERT NODE IN SORTED LIST\n" );
		printf( "10-> DISPLAY\n" );
		printf( "99->EXIT\n" );

		scanf( "%d",&choice );

		switch(choice)
		{
			case 1: printf( "Enter the data of the node to be inserted\n" );
					scanf( "%d",&item );
					add_beg(&ptr,item);
					break;

			case 2: printf( "Enter the data of the node to be inserted\n" );
					scanf( "%d",&item );
					add_end(&ptr,item);
					break;

			case 3: printf( "Enter the data of the node before which new node is to be inserted\n" );
					scanf( "%d",&sdata );
					printf( "Enter the data of the node to be inserted\n" );
					scanf( "%d",&item );
					add_bef(&ptr,sdata,item);
					break;

			case 4: printf( "Enter the data of the node after which new node is to be inserted\n" );
					scanf( "%d",&sdata );
					printf( "Enter the data of the node to be inserted\n" );
					scanf( "%d",&item );
					add_aft(&ptr,sdata,item);
					break;

			case 5: printf( "Enter the data of the node to be deleted\n" );
					scanf( "%d",&sdata);
					del_el(&ptr,sdata);
					break;

			case 7: sort_el(&ptr);
					break;

			case 8: delal_el(&ptr);
					break;

			case 9: printf( "Enter the data of the element to be inserted in sorted order\n" );
					scanf( "%d",&item);
					ins_sort(&ptr,item);
					break;

			case 10: printf( "ENTERED ELEMENTS ARE :\n" );
					 disp_el(&ptr);
					break;

			case 99: exit();

		}
		getch();
	}while(choice!=99);
getch();
}


void add_beg(list_ptr *ptr, int item )
{
	list_ptr temp=NULL;
	temp=(list_ptr)malloc(sizeof(struct list_node));
	temp->data=item;
	if(*ptr!=NULL)
	{
		temp->link=*ptr;
		*ptr=temp;
		printf( "NODE INSERTED AT THE BEGINNING\n" );
	}
	else
	{
		temp->link=NULL;
		*ptr=temp;
		printf( "THIS IS THE FIRST NODE\n" );
	}
}


void disp_el(list_ptr *ptr)
{
	list_ptr temp=NULL;
	temp=(list_ptr)malloc(sizeof(struct list_node));
	if(*ptr==NULL)
		printf( "EMPTY\n" );
	else
	{
		for(temp=*ptr;temp!=NULL;temp=temp->link)
		{
			printf( "%d\n",temp->data );
		}
	}
}

void add_end(list_ptr *ptr,int item)
{
	list_ptr temp=NULL,t;
	temp=(list_ptr)malloc(sizeof(struct list_node));

	temp->data=item;
	if(*ptr!=NULL)
	{
		for(t=*ptr;t->link!=NULL;t=t->link);
		temp->link=NULL;
		t->link=temp;


		printf( "INSERTED AT THE END\n" );
	}
	else
	{
		temp->link=NULL;
		*ptr=temp;
		printf( "THIS IS THE FIRST NODE\n" );
	}
}

void add_bef(list_ptr *ptr,int sdata,int item)
{
	list_ptr temp,t,prev;
	temp=(list_ptr)malloc(sizeof(struct list_node));
	t=(list_ptr)malloc(sizeof(struct list_node));
	prev=*ptr;
	temp->data=item;
	for(t=*ptr; t!=NULL;prev=t,t=t->link)
	{
		if(t->data==sdata)
		{
			temp->link=prev->link;
			prev->link=temp;
			flg=1;
			break;
		}
		flg=0;
	}
}

void add_aft(list_ptr *ptr,int sdata,int item)
{
	list_ptr temp,t;
	temp=(list_ptr)malloc(sizeof(struct list_node));
	t=(list_ptr)malloc(sizeof(struct list_node));
	temp->data=item;
	for(t=*ptr; t!=NULL;t=t->link)
	{
		if(t->data==sdata)
		{
			temp->link=t->link;
			t->link=temp;
			flg=1;
			printf( "INSERTED\n");
			break;
		}
		flg=0;
	}
	if(flg==0)
		printf( "NODE NOT FOUND\n" );
}

void del_el(list_ptr *ptr,int sdata)
{
	list_ptr t,prev;

	t=(list_ptr)malloc(sizeof(struct list_node));

	prev=*ptr;
	for(t=*ptr;t!=NULL;prev=t,t=t->link)
	{
		if(t->data==sdata)
		{
			prev->link=t->link;
			flg=1;
			printf( "DELETED\n" );
			break;
		}
		flg=0;
	}
	if(flg==0)
		printf( "D\NOT DELETED\n" );
}

void sort_el(list_ptr *ptr)
{
	list_ptr t1,t2,temp;
	t1=(list_ptr)malloc(sizeof(struct list_node));
	t2=(list_ptr)malloc(sizeof(struct list_node));
	temp=(list_ptr)malloc(sizeof(struct list_node));

	for(t1=*ptr;t1!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if(t1-> data>t2->data)
			{
				temp->data=t1->data;
				t1->data=t2->data;
				t2->data=temp->data;
			}
		}
	}
	printf( "ELEMENTS SORTED\n" );
}

void delal_el(list_ptr *ptr)
{
	list_ptr t,prev;

	t=(list_ptr)malloc(sizeof(struct list_node));

	prev=*ptr;
	for(t=*ptr;t!=NULL;prev=t,t=t->link)
	{


			prev->link=t->link;

	}

}


void ins_sort(list_ptr *ptr,int item)
{
	list_ptr t1,t2,temp,prev,temp1;
	t1=(list_ptr)malloc(sizeof(struct list_node));
	t2=(list_ptr)malloc(sizeof(struct list_node));
	temp=(list_ptr)malloc(sizeof(struct list_node));
	prev=(list_ptr)malloc(sizeof(struct list_node));

	for(t1=*ptr;t1!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if(t1-> data>t2->data)
			{
				temp->data=t1->data;
				t1->data=t2->data;
				t2->data=temp->data;
			}
		}
	}
	temp->data=item;
	for(t1=*ptr;t1->link!=NULL;prev=t1,t1=t1->link)
	{
		if(t1->data>item)
		{
			temp->link=t1;
			prev->link=temp;
			flg=1;
			printf( "INSERTED\n" );
			break;
		}
		flg=0;
	}
	if(flg==0)
	{
		t1->link=temp;
		temp->link=NULL;
	}

}




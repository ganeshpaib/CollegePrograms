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

void add_beg(list_ptr *);
void add_end(list_ptr *);
void add_after(list_ptr *);
void add_before(list_ptr *);
void del_beg(list_ptr *);
void del_end(list_ptr *);
void del_after(list_ptr *);
void del_that(list_ptr *);
void del_before(list_ptr *);
list_ptr rev(list_ptr );
void sort(list_ptr *);
void display(list_ptr *);
void insert(list_ptr *);
void alter(list_ptr *);


void main()
{
	int ch;

	do
	{
		clrscr();
		printf("\n\t 1... Add Beg ");
		printf("\n\t 2... Add End ");
		printf("\n\t 3... Add After ");
		printf("\n\t 4... Add Before ");
		printf("\n");
		printf("\n\t 5... Del Beg ");
		printf("\n\t 6... Del End ");
		printf("\n\t 7... Del After ");
		printf("\n\t 8... Del That ");
		printf("\n\t 9... Del Before ");
		printf("\n");
		printf("\n\t 10... Reverse ");
		printf("\n\t 11... Sort ");
		printf("\n");
		printf("\n\t 12... Insert Sorted ");
		printf("\n\t 13... Delete Alternate Node ");
		printf("\n");
		printf("\n\t 14... Display ");
		printf("\n");
		printf("\n\t 99... Exit ");
		printf("\n\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				add_beg(&ptr);
				break;
			case 2:
				add_end(&ptr);
				break;
			case 3:
				add_after(&ptr);
				break;
			case 4:
				add_before(&ptr);
				break;
			case 5:
				del_beg(&ptr);
				break;
			case 6:
				del_end(&ptr);
				break;
			case 7:
				del_after(&ptr);
				break;
			case 8:
				del_that(&ptr);
				break;
			case 9:
				del_before(&ptr);
				break;
			case 10:
				ptr=rev(ptr);
				printf("\n List Reversed...");
				break;
			case 11:
				sort(&ptr);
				break;
			case 12:
				insert(&ptr);
				break;
			case 13:
				alter(&ptr);
				break;
			case 14:
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

void add_beg(list_ptr *ptr)
{
	int n;
	list_ptr temp;
	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter Data Node :");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;
		printf("\n Node Added For The First Time ");
	}
	else
	{
		temp->link=*ptr;
		*ptr=temp;
		printf("\n Node Added... ");
	}
}

void add_end(list_ptr *ptr)
{
	list_ptr temp,t;
	int n;
	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter Data Node :");
	scanf("%d",&n);
	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;
		printf("\n Data Added For The First Time..");
	}
	else
	{
		for(t=*ptr;t->link!=NULL;t=t->link);

		temp->link=NULL;
		t->link=temp;

		printf("\n Node Added... ");
	}
}

void add_after(list_ptr *ptr)
{
	int n,search,f=0;
	list_ptr temp,t;
	temp=(list_ptr)malloc(sizeof(list_node));

	if(*ptr==NULL)
	{
		printf("\n List Is Empty ");
	}
	else
	{
		printf("\n Enter Data Node :");
		scanf("%d",&n);
		printf("\n Enter Search Data :");
		scanf("%d",&search);

		temp->data=n;

		for(t=*ptr;t!=NULL;t=t->link)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			temp->link=t->link;
			t->link=temp;

			printf("\n One Node Added....");
		}
		else
		{
			printf("\n Search Failed....");
		}
	}
}

void add_before(list_ptr *ptr)
{
	list_ptr prev,temp,t;
	int n,search,f=0;

	temp=(list_ptr)malloc(sizeof(list_node));

	if(*ptr==NULL)
	{
		printf("\n List Is Empty...");
	}
	else
	{
		printf("\n Enter Data Node :");
		scanf("%d",&n);
		printf("\n Enter Search data :");
		scanf("%d",&search);

		temp->data=n;
		prev=*ptr;

		for(t=*ptr;t!=NULL;prev=t,t=t->link)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			if(t==*ptr)
			{
				temp->link=*ptr;
				*ptr=temp;
				printf("\n One Node Added...");
			}
			else
			{
				temp->link=prev->link;
				prev->link=temp;

				printf("\n One Node Added...");
			}
		}
		else
		{
			printf("\n Search Failed...");
		}
	}
}

void del_beg(list_ptr *ptr)
{
	list_ptr temp;

	if(*ptr==NULL)
	{
		printf("\n List Empty....");
	}
	else
	{
		temp=*ptr;
		(*ptr)=(*ptr)->link;
		free(temp);
		printf("\n One Node Deleted...");
	}
}

void del_end(list_ptr *ptr)
{
	list_ptr t,prev;

	if(*ptr==NULL)
	{
		printf("\n List Is Empty...");
	}
	else
	{
		if((*ptr)->link==NULL)
		{
			free(*ptr);
			*ptr=NULL;
			printf("\n One Node Deleted...");
		}
		else
		{
			for(t=*ptr;t->link!=NULL;prev=t,t=t->link);
			prev->link=NULL;
			free(t);
			printf("\n One Node Deleted...");
		}
	}
}

void del_after(list_ptr *ptr)
{
	int search,f=0;
	list_ptr temp,t,prev;

	if(*ptr==NULL)
	{
		printf("\n List Empty...");
	}
	else
	{
		printf("\n Enter Search Data :");
		scanf("%d",&search);

		for(t=*ptr;t!=NULL;prev=t,t=t->link)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			temp=t;
			t=t->link;
			prev->link=t;
			free(temp);
			printf("\n One Node Deleted...");
		}
		else
		{
			printf("\n Search Failed...");
		}
	}
}

void del_that(list_ptr *ptr)
{
	list_ptr t,prev;
	int search,f=0;

	if(*ptr==NULL)
	{
		printf("\n List Empty...");
	}
	else
	{
		printf("\n Enter Search Data :");
		scanf("%d",&search);

		prev=*ptr;

		for(t=*ptr;t!=NULL;prev=t,t=t->link)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			if((*ptr)->data==search)
			{
				t=*ptr;
				(*ptr)=(*ptr)->link;
				free(t);
				printf("\n One Node Deleted...");
			}
			else
			{
				prev->link=t->link;
				free(t);
				printf("\n One Node Deleted...");
			}
		}
		else
		{
			printf("\n Search Failed...");
		}
	}
}

void del_before(list_ptr *ptr)
{
	list_ptr prev,t,rprev;
	int search,f=0;

	if(*ptr==NULL)
	{
		printf("\n The List Is Empty....");
	}
	else
	{
		printf("\n Enter The Number : ");
		scanf("%d",&search);

		for(t=*ptr;t!=NULL;rprev=prev,prev=t,t=t->link)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}

		}

		if(f==1)
		{
			if(t==*ptr )
			{
				printf("\n No Befor Node...");
			}
			else if(prev==*ptr)
			{
				*ptr=(*ptr)->link;
				free(prev);
				printf("\n First Node Deleted.....");
			}
			else
			{
				rprev->link=prev->link;
				free(prev);

				printf("\n Node Deleted....");
			}
		}
		else
		{
			printf("\n Search Node Not Found.....");
		}
	}
}


list_ptr rev(list_ptr ptr)
{
	list_ptr mid,prev;
	mid=NULL;

	if(ptr==NULL)
	{
		printf("\n List Empty...");
	}
	else


		while(ptr!=NULL)
		{
			prev=mid;
			mid=ptr;
			ptr=ptr->link;
			mid->link=prev;
		}
		return(mid);

}

void sort(list_ptr *ptr)
{
	list_ptr t,t1;
	int temp;

	if(*ptr==NULL)
	{
		printf("\n List Empty...");
	}
	else
	{
		for(t=*ptr;t!=NULL;t=t->link)
		{
			for(t1=t->link;t1!=NULL;t1=t1->link)
			{
				if(t->data>t1->data)
				{
					temp=t->data;
					t->data=t1->data;
					t1->data=temp;
				}
			}
		}
		printf("\n List Sorted....");
	}
}

void insert(list_ptr *ptr)
{
	list_ptr t,prev,temp;
	int n,f=0;
	temp=(list_ptr)malloc(sizeof(list_node));

	printf("\n Enter Data Node :");
	scanf("%d",&n);

	temp->data=n;

	if(*ptr==NULL)
	{
		temp->link=NULL;
		*ptr=temp;
		printf("\n One Node Inserted...");
	}
	else
	{
		for(t=*ptr;t!=NULL;prev=t,t=t->link)
		{
			if(n<=t->data)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			if(t==*ptr)
			{
				temp->link=*ptr;
				*ptr=temp;
				printf("\n One Node Inserted...");

			}
			else
			{
				temp->link=prev->link;
				prev->link=temp;
				printf("\n One Node Inserted...");

			}
		}
		else
		{
			for(t=*ptr;t->link!=NULL;t=t->link);
			temp->link=NULL;
			t->link=temp;

			printf("\n One Node Inserted...");
		}
	}
}

void alter(list_ptr *ptr)
{
	list_ptr t;
	if(*ptr==NULL)
	{
		printf("\n List Empty ");
	}
	else
	{
		for(t=*ptr;(t!=NULL && t->link!=NULL);t=t->link)
		{
			t->link=t->link->link;
		}

		printf("\n Alternate Node Deleted...");
	}

}

void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n No Node Found...");
	}
	else
	{
		for(t=*ptr;t!=NULL;t=t->link)
		{
			printf("%5d",t->data);
		}
	}
}







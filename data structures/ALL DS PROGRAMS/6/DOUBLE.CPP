#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list_node *list_ptr;

typedef struct list_node
{
	list_ptr llink;
	int data;
	list_ptr rlink;
};

list_ptr ptr=NULL;

void create(list_ptr *);
void before(list_ptr *);
void after(list_ptr *);
void display(list_ptr *);
void del(list_ptr *);
list_ptr rev(list_ptr *);

void main()
{
	int ch;
	clrscr();

	do
	{
		clrscr();

		printf("\n\t 1... Create ");
		printf("\n\t 2... Insert_before ");
		printf("\n\t 3... Insert_after ");
		printf("\n\t 4... Delete ");
		printf("\n\t 5... Display ");
		printf("\n\t 6... Reverse ");
		printf("\n\t 99.. Exit ");
		printf("\n\n Enter Your Choce :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					create(&ptr);
					break;
			case 2:
					before(&ptr);
					break;
			case 3:
					after(&ptr);
					break;
			case 4:
					del(&ptr);
					break;
			case 5:
					display(&ptr);
					break;
			case 6:
					ptr=rev(&ptr);
					printf("\n List Reversed......");
					break;
			case 99:
					 exit(0);
					 break;
		}
		getch();
	}while(ch!=99);
getch();
}

void create(list_ptr *ptr)
{
	list_ptr temp,t;
	int n;

	printf("\n Enter New Data :");
	scanf("%d",&n);

	temp=(list_ptr)malloc(sizeof(struct list_node));
	temp->data=n;

	if(*ptr==NULL)
	{
		temp->llink=NULL;
		temp->rlink=NULL;
		*ptr=temp;

		printf("\n Node Added For First Time ");
	}
	else
	{
		for(t=*ptr;t->rlink!=NULL;t=t->rlink);
		t->rlink=temp;
		temp->llink=t;
		temp->rlink=NULL;

		printf("\n Node Added.......");
	}
}

void display(list_ptr *ptr)
{
	list_ptr t;

	if(*ptr==NULL)
	{
		printf("\n List Is Empty....");
	}
	else
	{
		for(t=(*ptr);t!=NULL;t=t->rlink)
		{
			printf("%5d",t->data);
		}
	}
}

void before(list_ptr *ptr)
{
	list_ptr t,temp;
	int n,search,f=0;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	if(*ptr==NULL)
	{
		printf("\n The List Is Empty ...");
	}
	else
	{
		printf("\n Enter Inserted data :");
		scanf("%d",&n);
		printf("\n The Search data :");
		scanf("%d",&search);

		temp->data=n;

		for(t=*ptr;t!=NULL;t=t->rlink)
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
				temp->llink=NULL;
				temp->rlink=*ptr;
				(*ptr)->llink=temp;
				*ptr=temp;

				printf("\n Node Added At The Beginning....");
			}
			else
			{
				temp->llink=t->llink;
				t->llink->rlink=temp;
				t->llink=temp;
				temp->rlink=t;
				printf("\n Node Added.....");
			}
		}
		else
		{
			printf("\n No Search Node Found .... ");
		}
	}
}

void after(list_ptr *ptr)
{
	list_ptr temp,t;
	int n,search,f=0;

	temp=(list_ptr)malloc(sizeof(struct list_node));

	if(*ptr==NULL)
	{
		printf("\n The List Is Empty....");
	}
	else
	{
		printf("\n Enter New Data :");
		scanf("%d",&n);
		printf("\n Enter Search Data :");
		scanf("%d",&search);

		temp->data=n;

		for(t=*ptr;t!=NULL;t=t->rlink)
		{
			if(t->data==search)
			{
				f=1;
				break;
			}
		}

		if(f==1)
		{
			if(t->rlink==NULL)
			{
				temp->rlink=t->rlink;
				temp->llink=t;
				t->rlink=temp;

				printf("\n Node Added At The Last...");
			}
			else
			{
				temp->llink=t;
				temp->rlink=t->rlink;
				t->rlink=temp;
				t=temp;

				printf("\n Node Added....");
			}
		}
		else
		{
			printf("\n No Search Node Found...");
		}
	}
}

void del(list_ptr *ptr)
{
	list_ptr temp,t;
	int search,f=0;

	if(*ptr==NULL)
	{
		printf("\n The List Is Empty...");
	}
	else
	{
		printf("\n Enter Search Data : ");
		scanf("%d",&search);

		for(t=*ptr;t!=NULL;t=t->rlink)
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
				t->rlink->llink=NULL;
				*ptr=(*ptr)->rlink;
				free(t);
				printf("\n First Node Deleted....");
			}
			else if(t->rlink==NULL)
			{
				t->llink->rlink=NULL;
				free(t);

				printf("\n Last Node Deleted...");
			}
			else
			{
				t->llink->rlink=t->rlink;
				t->rlink->llink=t->llink;
				free(t);

				printf("\n Node Deleted...");
			}
		}
		else
		{
			printf("\n No Search Node Found....");
		}
	}
}

list_ptr rev(list_ptr *ptr)
{
	list_ptr mid,prev;
	mid=NULL;

	while(*ptr!=NULL)
	{
		prev=mid;
		mid=*ptr;
		*ptr=(*ptr)->rlink;
		mid->rlink=prev;
		mid->llink=*ptr;
	}
	return mid;
}






















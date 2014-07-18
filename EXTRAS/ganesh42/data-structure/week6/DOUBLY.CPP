/*program to implement a doubly linked list*/
#include<stdio.h>
#define NULL 0
#include<alloc.h>
#include<conio.h>

typedef struct node *node_ptr;
typedef struct node
{
	int data;
	node_ptr rlink,llink;
};

node_ptr ptr=NULL;

node_ptr create(int num)
{
	node_ptr first;
	first->data=num;
	first->llink=first->rlink=NULL;
	return first;
}


void ins_before(node_ptr *ptr,int info,int data)
{
     node_ptr temp,t;
     temp=(node_ptr)malloc(sizeof(node));
     temp->data=info;
     t=*ptr;
     if(t->data==data)
     {
	   temp->rlink=t;
	   *ptr=temp;
	   temp->llink=NULL;
	   t->llink=temp;
    }
    else
    {
	for(t=*ptr;t->data!=data && t!=NULL;t=t->rlink);
	if(t==NULL)
		printf("Data not found\n");
	else
	{
		temp->rlink=t;
		temp->llink=t->llink;
		t->llink->rlink=temp;
		t->llink=temp;
	}
   }
}

void ins_after(node_ptr *ptr,int info,int data)
{
	node_ptr temp,t;
	temp=(node_ptr)malloc(sizeof(node));
	temp->data=info;
	for(t=*ptr;t->data!=data && t!=NULL;t=t->rlink);
	if(t==NULL)
		printf("Data not found\n");
	else
	{
		temp->llink=t;
		temp->rlink=t->rlink;
		t->rlink->llink=temp;
		t->rlink=temp;
	}
}

void del(node_ptr *ptr,int value)
{
	node_ptr t;
	if(*ptr!=NULL)
	{
		for(t=*ptr;t->data!=value && t!=NULL;t=t->rlink);
		if(t==NULL)
			printf("\nData not found");
		else
		{
			if(t==*ptr)
				*ptr=t->rlink;
			else
				t->llink->rlink=t->rlink;
			t->rlink->llink=t->llink;
			free(t);
		}
	}
	else
		printf("List is empty\n");
}

void display(node_ptr *ptr)
{
	node_ptr temp;
	if(*ptr==NULL)
		printf("\nList is empty");
	else
	{
		for(temp=*ptr;temp!=NULL;temp=temp->rlink)
			printf("%4d",temp->data);
	}
}

node_ptr reverse(node_ptr ptr)
{
	node_ptr mid,prev;
	mid=NULL;
	while(ptr!=NULL)
	{
		prev=mid;
		mid=ptr;
		ptr=ptr->rlink;
		mid->rlink=prev;
		mid->llink=ptr;
	}
	return mid;
}



void main()
{
	int c,info,data;
	char x;
	clrscr();
	do
	{
		printf("\n 1-create a list\n 2-insert before\n 3-insert after\n 4-delete an element\n 5-traverse the list\n 6-reverse the list\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				  printf("enter the elements\n");
				  scanf("%d",&info);
				  ptr=create(info);
				  break;
			case 2:
				  printf("enter the new element\n");
				  scanf("%d",&info);
				  printf("enter the node before which you want to enter the element\n");
				  scanf("%d",&data);
				  ins_before(&ptr,info,data);
				  break;
			case 3:
				  printf("enter the element to be inserted\n");
				  scanf("%d",&info);
				  printf("enter the node after which you want to enter the new node\n");
				  scanf("%d",&data);
				  ins_after(&ptr,info,data);
				  break;
			case 4:
				  printf("enter the element to be deleted\n");
				  scanf("%d",&data);
				  del(&ptr,data);
				  break;
			case 5:
				  printf("the list is\n");
				  display(&ptr);
				  break;
			case 6:
				  ptr=reverse(ptr);
				  break;
		}
		printf("\n enter y to continue\n");
		scanf(" %c",&x);
	}while(x=='y');
getch();
}






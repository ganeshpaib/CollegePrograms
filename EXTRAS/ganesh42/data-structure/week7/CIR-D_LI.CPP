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

node_ptr head=NULL;



void dinsert(node_ptr pnode,node_ptr newnode)
{
	newnode->llink=pnode;
	newnode->rlink=pnode->rlink;
	pnode->rlink->llink=newnode;
	pnode->rlink=newnode;
}

void ddelete(node_ptr head,node_ptr d)
{
	if(head==d)
		printf("\nHead node cannot be deleted");
	else
	{
		d->rlink->llink=d->llink;
		d->llink->rlink=d->rlink;
		free(d);
	}
}

void display(node_ptr head)
{
	node_ptr t;
	if(head->rlink==head)
		printf("\nEmpty list");
	else
	{
		for(t=head->rlink;t!=head;t=t->rlink)
			printf("%d",t->data);
	}
}

void main()
{
	int c;
	node_ptr newnode,t;
	char x;
	clrscr();
	head=(node_ptr)malloc(sizeof(node));
	head->llink=head;
	head->rlink=head;
	do
	{
		printf("\n 1-insert \n 2-delete an element\n 3-traverse the list\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				  printf("enter the element to be inserted\n");
				  scanf("%d",&newnode->data);
				  for(t=head;t->rlink!=head;t=t->rlink);
				  dinsert(t,newnode);
				  break;
			case 2:
				  printf("enter the element to be deleted\n");
				  scanf("%d",&newnode->data);
				  ddelete(head,newnode);
				  break;
			case 3:
				  printf("the list is\n");
				  display(head);
				  break;
		}
		printf("\n enter y to continue\n");
		scanf(" %c",&x);
	}while(x=='y');
getch();
}





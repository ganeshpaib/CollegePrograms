#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>


typedef struct list_node *list_ptr;

typedef struct list_node
{
	int data;
	list_ptr link;
};
list_ptr ptr=NULL;

list_ptr creat()
{
	list_ptr first;
	int data;
	first=(list_ptr)malloc(sizeof(list_node));
	printf("\nEnter the data : ");
	scanf("%d",&data);
	first->data=data;
	first->link=NULL;
	return first;
}
void ins_bef(list_ptr *ptr, int info, int value)
{
	list_ptr temp,t,prev;
	temp=(list_ptr)malloc(sizeof(list_node));
	temp->data=info;
	if(*ptr!=NULL)
	{
		t=*ptr;
		if(t->data==value)
		{
			temp->link=t;
			*ptr=temp;
		}
		else
		{
			for(t=*ptr;t->data!=value&&t!=NULL;prev=t,t=t->link);
			if(t==NULL)
				printf("\nData not found");
			else
			{
				temp->link=t;
				prev->link=temp;
			}
		}
	}
}

void ins_aft(list_ptr *ptr,int info,int value)
{
	list_ptr temp,t;
	temp=(list_ptr)malloc(sizeof(list_node));
	temp->data=info;
	if(*ptr!=NULL)
	{
		for(t=*ptr;t->data!=value&&t!=NULL;t=t->link);
		if(t==NULL)
			printf("\nData not found");
		else
	    //	if(t->link!=NULL)
	      {
			temp->link=t->link;
			t->link=temp;
	      //	}
	      //	else
		//{
		  //	temp->link=NULL;
		    //	t->link=temp;
		}
	}
	else
	{
		temp->link=NULL;
		*ptr=temp;
	}
}

void del_list(list_ptr *ptr, int info)
{
	list_ptr temp,prev;
	if(*ptr==NULL)
	{
		printf("\nList is empty");

	}
	else
	{
		if((*ptr)->data==info)
		{
			temp=*ptr;
			*ptr=temp->link;
			free(temp);
		}
		else
		{
			for(temp=*ptr;temp->data!=info&&temp!=NULL;prev=temp,temp=temp->link);
			if(temp==NULL)
				printf("\nData not found");
			else
			{
			prev->link=temp->link;
			free(temp);
			}
		}
	}
}

void traverse(list_ptr *ptr)
{
	list_ptr temp;
	for(temp=*ptr;temp!=NULL;temp=temp->link)
		printf("%4d",temp->data);
}

list_ptr reverse_list(list_ptr ptr)
{
	list_ptr mid,prev;
	mid=NULL;

	while(ptr!=NULL)
	{
		prev=mid;
		mid=ptr;
		ptr=ptr->link;
		mid->link=prev;
	}
	return mid;
}

void sort(list_ptr *ptr)
{
	list_ptr t1,t2;
	int temp;
	for(t1=*ptr;t1->link!=NULL;t1=t1->link)
	{
		for(t2=t1->link;t2!=NULL;t2=t2->link)
		{
			if((t1->data) > (t2->data))
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
		}
	}
}

void del_alt(list_ptr *ptr)
{
	list_ptr prev,temp;
	if(*ptr==NULL)
	{
		printf("\nList is empty");

	}
	else
	{
		temp=*ptr;

		while(temp!=NULL)
		{
		prev=temp;
		temp=temp->link;
		prev->link=temp->link;
		free(temp);
		temp=prev->link;
		}
	}
}

void ins_sort(list_ptr *ptr, int info)
{
	list_ptr t,temp,prev;
	temp=(list_ptr)malloc(sizeof(list_node));
	temp->data=info;
	for(t=*ptr;t->data<info&&t!=NULL;prev=t,t=t->link);
	if(t==*ptr)
		*ptr=temp;
	else
		prev->link=temp;
	temp->link=t;
}

void main()
{
	int ch,info,data;
	char opt;
	clrscr();
	do
	{
	printf("\nMENU\n");
	printf("\n1.create a list");
	printf("\n2.insert before element");
	printf("\n3.insert after element");
	printf("\n4.delete");
	printf("\n5.Traverse");
	printf("\n6.reverse");
	printf("\n7.sort");
	printf("\n8.del_alt");
	printf("\n9.in_sort");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		ptr=creat();
		break;
	case 2:
		printf("\nEnter the element to insert");
		scanf("%d",&info);
		printf("\nEnter the reference element");
		scanf("%d",&data);
		ins_bef(&ptr,info,data);
		break;
	case 3:
		printf("\nEnter the element to insert");
		scanf("%d",&info);
		printf("\nEnter the reference element");
		scanf("%d",&data);
		ins_aft(&ptr,info,data);
		break;
	case 4:

		  printf("\nEnter the element to delete");
		  scanf("%d",&info);
		  del_list(&ptr,info);
		  break;
	case 5:
		traverse(&ptr);
		break;
	case 6:
		ptr=reverse_list(ptr);
		break;
	case 7:
		sort(&ptr);
		break;
	case 8:
		del_alt(&ptr);
		break;
	case 9:
		printf("\nEnter the element to be inserted : ");
		scanf("%d",&info);
		ins_sort(&ptr,info);
		break;
	default:
		printf("\nInvalid choice. Try again");

	}
		printf("\nPress 'y' to continue");
		flushall();
		scanf("%c",&opt);


}while(opt=='y');
getch();

}

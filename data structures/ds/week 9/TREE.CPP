#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
typedef struct node *tree_ptr;
typedef struct node
{
	char data;
	tree_ptr left_child,right_child;
};
tree_ptr root=NULL,par=NULL;
tree_ptr queue[MAX];
int front=0,rear=0,c=0,ctr=0,dir[10];
char val[10],path[10][10];

void inorder(tree_ptr root)
{
	if(root!=NULL)
	{	 inorder(root->left_child);
		 printf("%c",root->data);
		 inorder(root->right_child);
	}
}
void preorder(tree_ptr root)
{
	if(root!=NULL)
	{
		printf("%c",root->data);
		preorder(root->left_child);
		preorder(root->right_child);
	}
}
void postorder(tree_ptr root)
{
	if(root!=NULL)
	{
	  postorder(root->left_child);
	  postorder(root->right_child);
	  printf("%c",root->data);
	}
}
tree_ptr insert(char item,tree_ptr root)
{
	tree_ptr temp,prev,cur;
	int i;
	char direction[10];
	temp=(tree_ptr)malloc(sizeof(struct node));
	temp->data=item;
	temp->left_child=temp->right_child=NULL;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	printf("\nenter the direction where the node have tobe inserted...");
	flushall();
	scanf("%s",direction);
	prev=NULL;
	cur=root;
	dir[ctr]=strlen(direction);
	strcpy(path[ctr],direction);

	for(i=0;i<strlen(direction) && cur!=NULL ;i++)
	{
		prev=cur;
		val[ctr]=item;
		if(direction[i]=='l')
			cur=cur->left_child;
		else
			cur=cur->right_child;

	}
	if(cur!=NULL || i!=strlen(direction) )
	{
	  printf("\ninsertion not possible");
	  free(temp);
	  return(root);
	}
	if(direction[i-1]=='l')
		prev->left_child=temp;
	 else
		prev->right_child=temp;
	 ctr++;
	 return root;
}
void addq(int *front ,int *rear,tree_ptr temp)
{
   *rear=((*rear)+1)%MAX;

   if((*rear)==(*front))
   {
		printf("\nThe queue is full:");
		if((*rear)==0)
			(*rear)=MAX-1;
		else
			(*rear)=(*rear)-1;
   }
   else
		queue[(*rear)]=temp;

}
tree_ptr deleteq(int *front,int *rear)
{
	if((*front)==(*rear))
	{
		printf("\nThe queue is empty:");
		return NULL;
	}
	else
	{
		(*front)=((*front)+1)%MAX;
		return ( queue[(*front)]);
	}
}

/*void display(int *front,int *rear)
{
  int i;
  if((*front)<=(*rear))
  {
	for(i=(*front+1);i<=(*rear);i++)
	printf("%5x",queue[i]);
  }
  else
  {
	for(i=(*front)+1;i<=MAX-1;i++)
		printf("%5x",queue[i]);
	for(i=0;i<=(*rear);i++)
		printf("%5d",queue[i]);
  }
} */

void level_order(tree_ptr ptr)
{
int front=rear=0;
tree_ptr queue[MAX];
if(ptr == NULL)
	return;
	addq(&front,&rear,ptr);
	for( ; ; )
	{
		ptr=deleteq(&front,&rear);
		if(ptr!=NULL)
		{
		   printf("\n");
			printf("%5c",ptr->data);
			if(ptr->left_child)
				addq(&front,&rear,ptr->left_child);
			if(ptr->right_child)
					addq(&front,&rear,ptr->right_child);
		}
		else
			break;
	}
}

tree_ptr copy(tree_ptr original)
{
	tree_ptr temp;
	if(original)
	{
		temp=(tree_ptr)malloc(sizeof(struct node));
		temp->left_child=copy(original->left_child);
		temp->right_child=copy(original->right_child);
		temp->data=original->data;
		return temp;
	}
	else
	return NULL;
}

void count(tree_ptr root)
{
	if(root!=NULL)
	{
		if(!(root->left_child))
		{
			if(!(root->right_child))
			{
				c++;
			}
		}

		count(root->left_child);
		count(root->right_child);
	  }
}

void depth(int *dir,int ctr)
{
	int i,j,temp;

	for(i=0;i<ctr-1;i++)
	{
		for(j=i+1;j<ctr;j++)
		{
			if(dir[i]<dir[j])
			{
				temp=dir[i];
				dir[i]=dir[j];
				dir[j]=temp;
			}
		}
	}


	printf("\n The Depth Of The Tree Is : %d",dir[0]+1);
}

void parent(tree_ptr head)
{
	int flag=0,l,i,j;
	char search;
	printf("\n Enter Search Data ");
	flushall();
	scanf("%c",&search);

	if(head->data ==search)
	{
		printf("\n No Parent Node Found...");
	}
	else
	{
		for(i=0;i<ctr;i++)
		{
			if(val[i]==search )
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			printf("\n Search Node Not Found....");
		}
		else
		{
			l=strlen(path[i]);

			if(l==1)
			{
				printf("\n The Parent Node Is: %c",head->data);
			}
			else
			{
				for(j=0;j<(l-1);j++)
				{
					if(path[i][j]=='l')
					{
						head=head->left_child;
					}
					else
					{
						head=head->right_child;
					}
				}

				printf("\n The Parent Node Is : %c",head->data);
			}
		}
	}
}


void grand(tree_ptr head)
{
	int f=0,i,l,j;
	char search;

	printf("\n Enter Search Data :");
	flushall();
	scanf("%c",&search);

	if(head->data==search)
	{
		printf("\n No Grand Parents...");
	}
	else
	{
		for(i=0;i<ctr;i++)
		{
			if(val[i]==search)
			{
				f=1;
				break;
			}
		}

		if(f==0)
		{
			printf("\n Search Node Not Found...");
		}
		else
		{

			l=strlen(path[i]);

			if(l==1)
			{
				printf("\n %c",head->data);
			}
			else
			{

				printf("\n %c",head->data);

				for(j=0;j<(l-1);j++)
				{
					if(path[i][j]=='l')
					{
						head=head->left_child;
						printf("%c",head->data);
					}
					else
					{
						head=head->right_child;
						printf("%c",head->data);
					}
				}

			}
		}
	}
}
void main()
{
int opt,item ;
tree_ptr temp,para;
char search;
do
{
	clrscr();
	printf("\npress 1 for maketree");
	printf("\nPress 2 for inorder ");
	printf("\npress 3 for preorder");
	printf("\npress 4 for postorder");
	printf("\npress 5 for level order traversal:");
	printf("\npress 6 for copying binary tree");
	printf("\npress 7 for finding parent of given node");
	printf("\npress 8 for finding deapth of tree");
	printf("\npress 9 for find ancestr of given element");
	printf("\npress 10 for find All The leaf node of the tree");
	printf("\npress 99 for exit");
	printf("\nenter the option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:printf("\nenter the item to be inserted:");
		       flushall();
		       scanf("%c",&item);
		       root=insert(item,root) ;
		       break;
		case 2:printf("\nThe inorder expersion is ...");
				inorder(root);
				break;
		case 3:printf("\nThe preorder expersion is...");
				preorder(root);
				break;
		case 4:printf("\nthe postorder expersion is ..");
				postorder(root);
				break;
		case 5:printf("\nThe level order traversal is ..");
				level_order(root);
				break;
		case 6:printf("\nThe copied binary tree is inorder expersion is ..\n");
		       temp=copy(root);
		       inorder(temp);
		       break;
		case 7: parent(root);
			break;
		case 8:depth(dir,ctr);
		       break;
		case 9:grand(root);
		       break;
		case 10:printf("\n");
		       count(root);
		       printf("\nThe no of leaf node  are %d",c);
		       c=0;
		       break;
	}
getch();
}while(opt!=99);
}
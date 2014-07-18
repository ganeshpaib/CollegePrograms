#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node *tree_ptr;

typedef struct node
{
	tree_ptr left_child;
	int data;
	tree_ptr right_child;
};

tree_ptr root=NULL,new_root=NULL;

tree_ptr create(tree_ptr);
tree_ptr copy(tree_ptr);
void inorder(tree_ptr);
int equ(tree_ptr,tree_ptr);

void main()
{
	int ch,f;
	clrscr();

	do
	{
		clrscr();
		printf("\n\t 1... Create ");
		printf("\n\t 2... Copy ");
		printf("\n\t 3... Equivalent ");
		printf("\n\t 4... Inorder Display ");
		printf("\n\t 99.. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				root=create(root);
				printf("\n Tree Created...");
				break;
			case 2:
				new_root=copy(root);
				printf("\n Tree Copied....");
				break;
			case 3:
				f=equ(root,new_root);

				if(f!=1)
				{
					printf("\n Not Equal ");
				}
				else
				{
					printf("\n Equal ");
				}

				break;
			case 4:
				printf("\n\n\t TREE 1 \n\n");
				inorder(root);
				printf("\n\n\t TREE 2 \n\n");
				inorder(new_root);
				break;
			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

tree_ptr create(tree_ptr root)
{
	tree_ptr temp,cur,prev;
	int n,i;
	char direction[10];

	temp=(tree_ptr)malloc(sizeof(struct node));

	printf("\n Enter New Data :");
	scanf("%d",&n);

	temp->data=n;
	temp->left_child=NULL;
	temp->right_child=NULL;

	if(root==NULL)
	{
		return(temp);
	}
	else
	{
		printf("\n Enter Direction :");
		scanf("%s",direction);

		prev=NULL,cur=root;

		for(i=0;i<strlen(direction)&&cur!=NULL;i++)
		{
			prev=cur;

			if(direction[i]=='l')
			{
				cur=cur->left_child;
			}
			else
			{
				cur=cur->right_child;
			}
		}

		if(cur!=NULL || i!=strlen(direction))
		{
			printf("\n Insertion Is Not Possible...");
			free(temp);
			return(root);
		}

		if(direction[i-1]=='l')
		{
			prev->left_child=temp;
		}
		else
		{
			prev->right_child=temp;
		}
	}
	return(root);
}

void inorder(tree_ptr root)
{
	if(root!=NULL)
	{
		inorder(root->left_child);
		printf("%5d",root->data);
		inorder(root->right_child);
	}
}

tree_ptr copy(tree_ptr old)
{
	tree_ptr temp;

	if(old!=NULL)
	{
		temp=(tree_ptr)malloc(sizeof(struct node));

		temp->left_child=copy(old->left_child);
		temp->right_child=copy(old->right_child);
		temp->data=old->data;

		return(temp);
	}
	return(NULL);
}

int equ(tree_ptr root,tree_ptr new_root)
{
	if(root==NULL && new_root==NULL)
	{
		return(1);
	}
	else if(root==NULL && new_root!=NULL)
	{
		return(0);
	}
	else if(root!=NULL && new_root==NULL)
	{
		return(0);
	}
	if(root!=NULL && new_root!=NULL)
	{
		if(root->data!=new_root->data)
		{
			return(0);
		}
		else
		{
			equ(root->left_child,new_root->left_child);
			equ(root->right_child,new_root->right_child);
		}
	}
	   /*	return(1); */
}

















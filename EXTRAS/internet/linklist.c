#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

void createlist(struct node **first,int n)
{
 struct node *p;
 p=(struct node *)malloc(sizeof(struct node));
 *first=p;
 p->data=n;
 p->next=NULL;
}

void display(struct node *first)
{
 struct node *p=first;
 if(p==NULL)
   {
    printf("\nlinklist empty\n");
   }
 else
   {
    while(p!=NULL)
         {
          printf("\n%d\t%d\t%d\n",p,p->data,p->next);
          p=p->next;
         }
   }
}

void insertnode(struct node **first,int n)
{
 int d;
 struct node *q;
 struct node *p=*first;
 q=(struct node*)malloc(sizeof(struct node));
 printf("\n2a.......\n");
 printf("\nenter data for the inserted node:");
 scanf("%d",&d);
   while(p!=NULL)
         {
          if(p->data==n)
            {
             q->data=d;
             q->next=p->next;
             p->next=q;
             return;
            }
          p=p->next;
         }
}

void removenode(struct node **first,int n)
{
 struct node *q;
 struct node *p=*first;

 if(p==NULL)
   {
    printf("\nlinklist empty\n");
   }
 else
   {
     if(p->data==n)
       {
        p=p->next;
        printf("\nhello1....\n");
        *first=p;
        free(q);
        return;
       }
      else
       {
       printf("\nhello2.....\n");
       while(p!=NULL||p->next!=NULL)
            {
             q=p->next;
             if(q->data==n)
               {
                p->next=q->next;
                free(q);
                return;
               }
             p=p->next;
            }
       }
   }
}


void main()
{
 struct node *first=NULL;
 int ch,n;

 do
  {
   printf("\nenter your choice:\n1.create list\n2.display\n");
   printf("3.insert node\n4.delete node\n5.exit\n");
   scanf("%d",&ch);
   switch(ch)
     {
      case 1: if(first==NULL)
                {
                 printf("\nenter data for new node:");
                 scanf("%d",&n);
                 createlist(&first,n);
                }
              break;

      case 2: display(first);
              break;

      case 3: printf("\nenter the data of the node after which insertion is to be done:");
              scanf("%d",&n);
              printf("\n1......\n");
              insertnode(&first,n);
              printf("\n3.......\n");
              break;

      case 4: printf("\nenter the data of the node to be deleted:");
              scanf("%d",&n);
              removenode(&first,n);
              break;
     }
 }
 while(ch!=5);
}



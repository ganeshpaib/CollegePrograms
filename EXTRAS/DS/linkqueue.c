#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

void enqueue(struct node **first,int n)
{
 struct node *p=*first,*q;
 q=(struct node *)malloc(sizeof(struct node));
 if(*first==NULL)
   {
    *first=q;
    q->data=n;
    q->next=NULL;
   }
 else
   {
       while(p->next!=NULL)
            {
             p=p->next;
            }
       p->next=q;
       q->data=n;
       q->next=NULL;
   }
}

int dequeue(struct node **first)
{
 int temp;
 struct node *p=*first;
 if(*first==NULL)
   {
    printf("\nqueue is empty\n");
    return(0);
   }
 else
   {
    p=*first;
    *first=(*first)->next;
    temp=p->data;
    free(p);
    return(temp);
   }
}

void display(struct node *p)
{
 if(p==NULL)
   {
    printf("\nqueue is empty\n");
   }
 else
   {
    while(p!=NULL)
         {
          printf("\n%d",p->data);
          p=p->next;
         }
   }
}

void main()
{
 struct node *first=NULL;
 int ch,n,temp;
 do
  {
   printf("\nenter your choice:\n1.enqueue\n2.dequeue\n");
   printf("3.display\n4.exit\n");
   scanf("%d",&ch);
   switch(ch)
     {
      case 1: printf("\nenter integar:");
              scanf("%d",&n);
              enqueue(&first,n);
              break;

      case 2: temp=dequeue(&first);
              if(temp!=0)
                {
                 printf("\n%d has been dequeued\n",temp);
                }
              break;

      case 3: display(first);
              break;
     }
 }
 while(ch!=4);
}



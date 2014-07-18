#include<stdio.h>
#include<conio.h>
#define MAX 10

struct stack
{
  int stk[MAX];
  int top;
}s;

void puch(int n,int *s.top)
{
  if(*s.top==(MAX-1))
    printf("\nthe stalk is full:");
  else
  {

     *s.top+=1;
     s.stk[*s.top]=n;
  }
}

int pop(int *s.top)
{
  if(*s.top==-1)
  {
	printf("\nstack is empty:");
	return(-1);
  }
  else
  {
   return(s.stk[*(s.top)++]);
  }
}
void display(int *s.top)
{
  int i;
  for(i=0;i<=*s.top;i++)
  {
    printf("%5d",s.stk[i]);
  }
}
void main()
{
int n,m,opt;
s.top=-1;
do
{
clrscr();

printf("\n 1 PUCH:");
printf("\n 2 POP:");
printf("\n 3 DISPLAY:");
printf("\n 99 EXIT :");
printf("\nenter the option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
	printf("\nenter the element to add:");
	scanf("%d",&n);
	puch(n,&s.top);
	break;
case 2:
       m=pop(&s.top);
       if(m!=-1)
       {
       printf("\nthe deleted element is %d",m);
       }
       break;

case 3:
	printf("\nthe element in the stack are :");
	display(&s.top);
	break;
case 99:
	exit(0);

}
getch();
}while(opt!=99);
getch();
}
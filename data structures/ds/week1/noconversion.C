#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 25

int stk[MAX],top=-1;
void push(int r)
{
	if(top==MAX-1)
		printf("\nthe stalk  is full");
	else
	{
		switch(r)
		{
			case 0:stk[++top]=48;break;
			case 1:stk[++top]=49;break;
			case 2:stk[++top]=50;break;
			case 3:stk[++top]=51;break;
			case 4:stk[++top]=52;break;
			case 5:stk[++top]=53;break;
			case 6:stk[++top]=54;break;
			case 7:stk[++top]=55;break;
			case 8:stk[++top]=56;break;
			case 9:stk[++top]=57;break;
			case 10:stk[++top]=65;break;
			case 11:stk[++top]=66;break;
			case 12:stk[++top]=67;break;
			case 13:stk[++top]=68;break;
			case 14:stk[++top]=69;break;
			case 15:stk[++top]=70;break;

		}

	}

}

int pop(void )
{
	if(top==-1)
		printf("\nthe stalk is full:");
	else
		return(stk[top--]);

}
void main()
{
	int i,j,n,x,r;
	clrscr();
	printf("\nenter the number:");
	scanf("%d",&n);
	printf("\nenter to which base no u want to convert the no:");
	scanf("%d",&x);
	j=n;
	while(j!=0)
	{
		r=j%x;
		push(r);
		j=j/x;
	}
	while(top>=0)
	printf("%c",pop() );
	getch();
}
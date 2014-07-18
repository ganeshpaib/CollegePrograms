#include<stdio.h>
#include<conio.h>
#define MAX 5

int dqueue[MAX],ctr=0;
int li=-1,ri=MAX,ld=-1,rd=MAX;

void addR(int *);
void addL(int *);
int delR(int*,int*);
int delL(int*,int*);
void display(int *,int *,int *,int *);

void main()
{
	int ch,f;
	clrscr();

	do
	{
		clrscr();
		printf("\n\t 1... Add Left ");
		printf("\n\t 2... Add Right ");
		printf("\n\t 3... Delete Left ");
		printf("\n\t 4... Delete Right ");
		printf("\n\t 5... Display ");
		printf("\n\t 99.. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					addL(&li);
					break;
			case 2:
					addR(&ri);
					break;
			case 3:
					f=delL(&ld,&rd);

					if(f==-1)
					{
						printf("\n Empty....");
					}
					else
					{
						printf("\n Deleted From The Left : %d",f);
					}

					break;
			case 4:
					f=delR(&rd,&ld);
					if(f==-1)
					{
						printf("\n Empty....");
					}
					else
					{
						printf("\n Deleted From The Right : %d",f);
					}
					break;
			case 5:
					display(&li,&ri,&ld,&rd);
					break;
			case 99:
					exit(0);
					break;
		}
		getch();
}while(ch!=99);
getch();
}

void addL(int *li)
{
	int n;

	if(ctr==MAX)
	{
		printf("\n The D-Queue Is Full ");
	}
	else
	{
		printf("\n Enter Element :");
		scanf("%d",&n);

		dqueue[++(*li)]=n;
		ctr++;
		printf("\n Element Inserted At The Left ");
	}
}

void addR(int *ri)
{
	int n;

	if(ctr==MAX)
	{
		printf("\n The Dqueue is Full ");
	}
	else
	{
		printf("\n Enter Element :");
		scanf("%d",&n);
		dqueue[--(*ri)]=n;
		ctr++;
		printf("\n Element Inserted From The Right Side ");
	}
}

int delL(int *ld,int *rd)
{
	if(*ld==*rd)
	{
		return(-1);
	}
	else
	{
		return(dqueue[++(*ld)]);
	}
}

int delR(int *ld,int *rd)
{
	if(*ld==*rd)
	{
		return(-1);
	}
	else
	{
		return(dqueue[--(*rd)]);
	}
}

void display(int *li,int *ri,int *ld,int *rd)
{
	int i;

	if(*li==-1 && *ri==MAX)
	{
		printf("\n The List Empty....");
	}
	else
	{
		for(i=(*ld+1);i<=*li;i++)
		{
			printf("%5d",dqueue[i]);
		}
		for(i=*ri;i<*rd;i++)
		{
			printf("%5d",dqueue[i]);
		}
	}
}



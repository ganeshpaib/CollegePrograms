#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int **a,**c,**kay,ver;
void allpair();
void output(int,int);
void path(int,int);

void main()
{
	int i,j,ev,sv;
	char ch;
	clrscr();

	printf("\n Enter Number Of Vertex :");
	scanf("%d",&ver);
	a=(int **)malloc(sizeof(int)*ver*ver);
	c=(int **)malloc(sizeof(int)*ver*ver);
	kay=(int **)malloc(sizeof(int)*ver*ver);

	for(i=1;i<=ver;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*ver);
		c[i]=(int *)malloc(sizeof(int)*ver);
		kay[i]=(int *)malloc(sizeof(int)*ver);
	}


	for(i=1;i<=ver;i++)
	{
		for(j=1;j<=ver;j++)
		{
			printf("a[%d][%d] :",i,j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}

	printf("\n\t INPUT MATRIX \n\n");

	for(i=1;i<=ver;i++)
	{
		for(j=1;j<=ver;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}

	allpair();

	printf("\n\t FINAL MATRIX \n\n");

	for(i=1;i<=ver;i++)
	{
		for(j=1;j<=ver;j++)
		{
			printf("%5d",c[i][j]);
		}
		printf("\n");
	}

	do
	{

		printf("\n Enter Start Vertex : ");
		scanf("%d",&sv);
		printf("\n Enter End Vertex :");
		scanf("%d",&ev);
		output(sv,ev);
		printf("\n Search MorePath (Y/N) :");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
getch();
}

void allpair()
{
	int i,j,k=0;

	for(i=1;i<=ver;i++)
	{
		for(j=1;j<=ver;j++)
		{
			c[i][j]=a[i][j];
			kay[i][j]=0;
		}
	}

	for(k=1;k<=ver;k++)
	{
		for(i=1;i<=ver;i++)
		{
			for(j=1;j<=ver;j++)
			{
				if(c[i][j]>c[i][k]+c[k][j])
				{
					c[i][j]=c[i][k]+c[k][j];
					kay[i][j]=k;
				}
			}
		}
	}
}

void output(int sv,int ev)
{
	if(sv==ev)
	{
		printf("\n Self Loop");
		return;
	}
	if(c[sv][ev]==99)
	{
		printf("\n No Path ");
		return;
	}

	printf("\n Path From %5d to %5d \n",sv,ev);
	printf("%5d",sv);
	path(sv,ev);
}
void path(int sv,int ev)
{
	if(kay[sv][ev]==0)
	{
		printf("%5d",ev);
		return;
	}
	else
	{
		path(sv,kay[sv][ev]);
		path(kay[sv][ev],ev);
	}
}


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 15

int stack[size],top=-1;
void push(int);
int pop();

void main()
{
	int **a,*v,*visited,*indegree,ver,i,j,adj=0,flag=0,ctr=0,temp;
	clrscr();

	printf("\n Enter Number Of Vertex : ");
	scanf("%d",&ver);

	a=(int **)malloc(sizeof(int)*ver*ver);
	v=(int *)malloc(sizeof(int)*ver);
	visited=(int *)malloc(sizeof(int)*ver);
	indegree=(int *)malloc(sizeof(int)*ver);

	for(i=0;i<ver;i++)
	{
		*(a+i)=(int *)malloc(sizeof(int)*ver);
	}

	for(i=0;i<ver;i++)
	{
		for(j=0;j<ver;j++)
		{
			printf("a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	for(i=0;i<ver;i++)
	{
		for(j=0;j<ver;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<ver;i++)
	{
		for(j=0;j<ver;j++)
		{
				if(a[j][i]==1)
				{
					adj++;
				}
		}
		indegree[i]=adj;
		adj=0;
	}

	printf("\n\n");

		for(i=0;i<ver;i++)
		{
			visited[i]=0;
		}

		while(1)
		{
			flag=0;
			for(i=0;i<ver;i++)
			{
				if(indegree[i]==0 && !visited[i])
				{
					flag=1;
					push(i);
					visited[i]=1;
				}
			}


			if(flag==1||top!=-1)
			{
				 temp=pop();
				 for(i=0;i<ver;i++)
				 {
					if(a[temp][i]==1)
					{
						indegree[i]-=1;
					}
				 }
			 v[ctr++]=temp;
			}
			else
			{
				break;
			}


		}


		if(ctr==ver)
		{
			for(i=0;i<ctr;i++)
			{
				printf("%5d",v[i]);
			}
		}
		else
		{
			printf("\n Not A Topological Sequence");
		}

getch();
}

void push(int n)
{
	if(top==size)
		{
			printf("\n Stack Is Full");
		}
		else
		{
			stack[++top]=n;
	}
}

int pop()
{
	return(stack[top--]);
}








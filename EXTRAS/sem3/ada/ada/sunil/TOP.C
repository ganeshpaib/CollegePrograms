#include<stdio.h>
#include<conio.h>
#define   MAX  30

int top=-1;
int stack[MAX];

void push(int num)
{
  if(top>=MAX)
  printf("\n Stack is Full..\n");
  else
  stack[top++]=num;
}
int pop()
{
  int num;
  if(top==-1)
    return -1;
  else
  {
  num=stack[--top];
  return num;
  }
}
void main()
{
  int i,j,visited[MAX],indegree[MAX],num,n,a[MAX][MAX];
  clrscr();
  printf("\n Enter the No of vertices: ");
  scanf("%d",&n);
  printf("\n Enter the Adjency Matrix: \n");
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  for(j=1;j<=n;j++)
  {
    indegree[j]=0;
    visited[j]=0;
    for(i=1;i<=n;i++)
    {
      if(a[i][j]==1)
      indegree[j]++;
    }
  }
  for(i=1;i<=n;i++)
  {
    if(indegree[i]==0)
    {
      push(i);
      visited[i]=1;
    }
  }
  while(top!=-1)
  {
    num=pop();
    printf("\n %d",num);
    for(i=1;i<=n;i++)
    {
      if(a[num][i]==1)
      {
	indegree[i]--;
      }
      if(indegree[i]==0)
      {
	if(visited[i]!=1)
	{
	  push(i);
	  visited[i]=1;
	}
      }
    }
  }
  getch();
}


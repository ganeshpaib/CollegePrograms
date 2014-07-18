/*  Prim's Method to find the Minnimum Cost Spanning Tree */

#include<stdio.h>
#include<conio.h>
#define max   30

const int noedge=100;

int adj_mat[max][max],n=0;

void prim()
{
  int visited[max];
  int lowcost[max];
  int T[max][2];       // Min Cost Spanning Tree
  int i,j,k,min,w=0;
  for(i=2;i<=n;i++)
  {
    lowcost[i]=adj_mat[1][i];
    visited[i]=1;
  }

  for(i=2;i<=n;i++)
  {
    min=lowcost[2];
    k=2;
    for(j=3;j<=n;j++)
      if(lowcost[j]<min)
      {
	min=lowcost[j];
	k=j;
      }
    T[i-1][1]=visited[k];
    T[i-1][2]=k;
    w=w+min;	//to accumulate weights

    // update all data structures
    lowcost[k]=noedge;
    for(j=2;j<=n;j++)
    if(adj_mat[k][j]<lowcost[j] && lowcost[j]!=noedge)
    {
      lowcost[j]=adj_mat[k][j];
      visited[j]=k;
    }
  }
  for(i=1;i<=n-1;i++)
   {
    printf("\n<< %d , %d >>\n",T[i][1],T[i][2]);
   }
    printf("\n");
    printf("\n Total Weight= %d",w);
}

void main()
{
  int i,j;
  clrscr();
  printf("\n Enter the No. of vertices: ");
  scanf("%d",&n);
  printf("\n Enter the Elements of (%d X %d): \n",n,n);
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&adj_mat[i][j]);
   prim();
   getch();
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct graph
{
        int u;
        int v;
        int cost;
}*g,temp;

int parent[15],t[10][2];

void unions(int,int);
int find(int);

void main()
{
        int edg,ver,i,j,k,a,b,ctr=0;
        clrscr();
        printf("\n Enter Number Of Vertex :");
        scanf("%d",&ver);
        printf("\n Enter Number Of Edges : ");
        scanf("%d",&edg);
        g=(struct graph *)malloc(sizeof(struct graph)*ver);
        for(i=0;i<edg;i++)
        {
        	parent[i]=0;
        	printf("\n Enter Vertex 1:");
                scanf("%d",&g[i].u);
                printf("\n Enter Vertex 2:");
                scanf("%d",&g[i].v);
                printf("\n Enter Cost:");
                scanf("%d",&g[i].cost);
                printf("\n");
        }
        //clrscr();

        for(i=0;i<edg-1;i++)
        {
        	for(j=i+1;j<edg;j++)
                {
                	if(g[i].cost>g[j].cost)
                        {
                        	temp=g[i];
                                g[i]=g[j];
                                g[j]=temp;
                        }
                }
        }


        for(k=0;k<edg;k++)
        {
        	i=g[k].u;
                j=g[k].v;
                a=find(i);
                b=find(j);

                if(a!=b)
                {
                	t[ctr][0]=i;
                        t[ctr][1]=j;

                        if(ctr==ver-1)
                        {
                        	break;
                        }
                        ctr++;
                        unions(i,j);
                }
        }

        for(i=0;i<ctr;i++)
        {
        	printf("\n %d -> %d",t[i][0],t[i][1]);
        }
getch();
}

int find(int e)
{
	while(parent[e])
        {
        	e=parent[e];
        }
        return(e);
}

void unions(int i,int j)
{
	parent[j]=i;
}








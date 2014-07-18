#include<stdio.h>
#include<conio.h>
#include<alloc.h>


struct graph
{
	int u;
	int v;
	int cost;
};


void main()
{
	int ctr=0,edge,i,n,k,flag=0;
	int *tv,*visited;
	clrscr();
	graph *e,*t;
	printf("\nEnter the no. of vertices : ");
	scanf("%d",&n);
	tv=(int *)malloc((sizeof(int))*n);
	visited=(int *)malloc((sizeof(int))*(n+1));
	for(i=0;i<=n;i++)
		visited[i]=0;

	printf("\nEnter the no. of edges : ");
	scanf("%d",&edge);
	e=(graph *)malloc((sizeof(graph))*edge);
	t=(graph *)malloc((sizeof(graph))*n);
	printf("\n\nEnter the edges & corresponding cost associated with each edge\n");
	for(i=0;i<edge;i++)
	{
		printf("\nedge %d",i+1);
		printf("\nu = ");
		scanf("%d",&e[i].u);
		printf("\nv = ");
		scanf("%d",&e[i].v);
		printf("\ncost = ");
		scanf("%d",&e[i].cost);
	}

	visited[1]=1;
	i=0;
	tv[i]=0;
	while(ctr!=n-1)
	{
		t[ctr].cost=0;
		flag=0;
		i++;
		for(k=0;k<edge;k++)
		{
			if((visited[e[k].u]==1&&visited[e[k].v]==0)||(visited[e[k].v]==1&&visited[e[k].u]==0))
				if(t[ctr].cost>e[k].cost||t[ctr].cost==0)
				{
					t[ctr]=e[k];
					if(visited[e[k].u]==0)
						tv[i]=e[k].u;
					else
						tv[i]=e[k].v;
					flag=1;

				}

		}
		if(flag==0)
			break;

		visited[tv[i]]=1;
		ctr++;

	}


	if(ctr==n-1)
	{
		printf("\nspanning tree is : \n");
		for(i=0;i<n-1;i++)
		{
			printf("( %d, %d )",t[i].u,t[i].v);
		}
	}
	else
		printf("\n\nthe network is not connected & hence no spanning tree");
	getch();

}










#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define size 10

typedef struct node *node_ptr;
typedef struct node
{
	int vertex;
	node_ptr link;
};
int a[size][size],ver,visited[size],ctr=0,c,stack[size],top=-1,f=0,adj[size],temp[size];
node_ptr graph[size],ptr=NULL;

void create(int);
void display(int);
void insert(int,int);
void dfs(int);
void bfs(int);
void addq(node_ptr *,int);
int delq(node_ptr *);
void path(int,int);
void path_bfs(int,int,int&);
void push(int);
int pop();
void conn_dfs(int,int &);
void conn_bfs(int,int &);

void main()
{
	int ch,i,v,sv,ev;
	clrscr();

	do
	{
		clrscr();
		printf("\n\t 1... Create");
		printf("\n\n\t 2... Display");
		printf("\n\t 3... DFS");
		printf("\n\t 4... BFS");
		printf("\n\n\t 5... Path(DFS)");
		printf("\n\t 6... Path(BFS)");
		printf("\n\n\t 7... Connected_Graph(DFS)");
		printf("\n\t 8... Connected_Graph(BFS)");
		printf("\n\n\t 9... Spanning_Tree(DFS)");
		printf("\n\t 10.. Spanning_Tree(BFS)");
		printf("\n\n\t 99.. Exit");
		printf("\n\n Enter Your Choice : ");
		scanf("%d",&ch);

		for(i=0;i<size;i++)
		{
			visited[i]=FALSE;
		}
		top=-1;

		switch(ch)
		{
			case 1:
					printf("\n Enter Number Of Vertex: ");
					scanf("%d",&ver);

					for(i=0;i<ver;i++)
					{
						graph[i]=NULL;
					}

					create(ver);

					break;
			case 2:
					display(ver);
					break;
			case 3:
					printf("\n Enter Vertex : ");
					scanf("%d",&v);
					dfs(v);
					break;
			case 4:
					printf("\n Enter Vertex :");
					scanf("%d",&v);
					bfs(v);
					break;
			case 7:
					ctr=0;
					printf("\n Enter Vertex :");
					scanf("%d",&v);
					conn_dfs(v,ctr);

					if(ctr==(ver-1))
					{
						printf("\n Connected...");
					}
					else
					{
						printf("\n Not Connected...");
					}
					break;
			case 8:
					ctr=0;
					printf("\n Enter Vertex :");
					scanf("%d",&v);
					conn_bfs(v,ctr);

					if(ctr==(ver-1))
					{
						printf("\n Connected...");
					}
					else
					{
						printf("\n Not Connected...");
					}
					break;
			case 5:
					top=-1;
					f=0;
					for(i=0;i<size;i++)
					{
						stack[i]=0;
					}
					printf("\n Enter Strating Vertex : ");
					scanf("%d",&sv);
					printf("\n Enter End Vertex :");
					scanf("%d",&ev);
					path(sv,ev);

					if(sv==ev)
					{
						printf("\n Self Loop");
					}
					if(stack[top]==ev)
					{
						for(i=0;i<=top;i++)
						{
							printf("%5d",stack[i]);
						}
					}
					else
					{
					  printf("\n No Path...");
					}
					break;
			case 6:
					ctr=0;
					printf("\n Enter Starting Vertex :");
					scanf("%d",&sv);
					printf("\n Enter End Vertex : ");
					scanf("%d",&ev);

					if(sv==ev)
					{
						printf("\n Self Loop");

					}
					else
					{
						   path_bfs(sv,ev,ctr);
							c=1;
							temp[0]=ev;

							while(ev!=0)
							{
								temp[c++]=adj[ev];
								ev=adj[ev];
							}

							for(i=c-1;i>=0;i--)
							{
								printf("%5d",temp[i]);
							}
					}

					break;
			case 9:
						ctr=0;
						printf("\n Enter Vertex : ");
						scanf("%d",&v);

						conn_dfs(v,ctr);
						if(ctr==(ver-1))
						{
                                                        printf("\n Spanning Tree");

						}
						else
						{
							printf("\n Not A Spanning Tree");
						}
						break;
                        case 10:

                                	ctr=0;
					printf("\n Enter Vertex :");
					scanf("%d",&v);
					conn_bfs(v,ctr);

					if(ctr==(ver-1))
					{
						printf("\n Spanning Tree...");
					}
					else
					{
						printf("\n Not A Spanning Tree...");
					}
					break;

			case 99:
					exit(0);
					break;
		}
		getch();
	}while(ch!=99);
getch();
}

void create(int v)
{
	int i,j;

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(a[i][j]==1)
			{
				insert(i,j);
			}
		}
	}
}

void insert(int i,int j)
{
	node_ptr temp,t;
	temp=(node_ptr)malloc(sizeof(node));
	temp->link=NULL;
	temp->vertex=j;

	if(graph[i]==NULL)
	{
		graph[i]=temp;
		printf("\n Add");
	}
	else
	{
		for(t=graph[i];t->link!=NULL;t=t->link);
		t->link=temp;
		printf("\n Added...");
	}

}

void display(int v)
{
	int i,j,f=0;
	node_ptr t;
	printf("\n\t\t MATRIX \n\n");

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\t LIST \n\n");

	for(i=0;i<v;i++)
	{
		printf("%5d->",i);
		f=0;

		for(t=graph[i];t!=NULL;t=t->link)
		{
			printf("%5d",t->vertex);
			f=1;
		}

		if(f==0)
		{
			printf("NULL");
		}
		printf("\n");
	}
}

void dfs(int v)
{
	node_ptr w;

	visited[v]=TRUE;
	printf("%5d",v);

	for(w=graph[v];w!=NULL;w=w->link)
	{
			if(!visited[w->vertex])
			{
				dfs(w->vertex);
			}
	}
}

void bfs(int v)
{
	node_ptr w;
	visited[v]=TRUE;
	printf("%5d",v);
	addq(&ptr,v);

	while(ptr!=NULL)
	{
		v=delq(&ptr);

		for(w=graph[v];w!=NULL;w=w->link)
		{
			if(!visited[w->vertex])
			{
				visited[w->vertex]=TRUE;
				printf("%5d",w->vertex);
				addq(&ptr,w->vertex);
			}
		}

	}
}

void addq(node_ptr *ptr,int v)
{
	node_ptr temp,t;
	temp=(node_ptr)malloc(sizeof(node));
	temp->vertex=v;
	temp->link=NULL;

	if((*ptr)==NULL)
	{
		(*ptr)=temp;
	}
	else
	{
		for(t=(*ptr);t->link!=NULL;t=t->link);
		t->link=temp;
	}
}

int delq(node_ptr *ptr)
{
	node_ptr temp;
	temp=(*ptr);
	(*ptr)=(*ptr)->link;
	return(temp->vertex);
}

void path(int sv,int ev)
{
	node_ptr w;
	int flag;

	if(sv==ev)
	{
		push(sv);
		f=1;
		return;
	}
		flag=0;

	visited[sv]=TRUE;
	push(sv);

	for(w=graph[sv];w!=NULL;w=w->link)
	{
		if(!visited[w->vertex])
		{
					while(pop()!=sv)
					{
							flag=1;
							push(sv);
					}
					if(flag==0)
					{
						push(sv);
					}

			path(w->vertex,ev);

			if(f)
				break;
		}

	}
}

void push(int n)
{
	if((top)==size)
	{
	   printf("\n Stack Is Full");
	}
	else
	{
		stack[++(top)]=n;
	}
}

int pop()
{
	if((top)==-1)
	{
		printf("\n Stack Is Empty...");
		return(-1);
	}
	else
	{
		return(stack[(top)--]);
	}
}


void conn_dfs(int v,int &ctr)
{
	node_ptr w;

	visited[v]=TRUE;

	for(w=graph[v];w!=NULL;w=w->link)
	{

		if(!visited[w->vertex])
		{
                	printf("\n %5d->%5d",v,w->vertex);
			ctr++;
			conn_dfs(w->vertex,ctr);
		}
	}
}

void conn_bfs(int v,int &ctr)
{
	node_ptr w;
	visited[v]=TRUE;
	addq(&ptr,v);

	while(ptr!=NULL)
	{
		v=delq(&ptr);

		for(w=graph[v];w!=NULL;w=w->link)
		{
			if(!visited[w->vertex])
			{
				ctr++;
				visited[w->vertex]=TRUE;
				printf("\n %5d->%5d",v,w->vertex);
				addq(&ptr,w->vertex);
			}
		}

	}
}

void path_bfs(int sv,int ev,int &ctr)
{
	node_ptr w;
	visited[sv]=TRUE;

	addq(&ptr,sv);

	while(ptr!=NULL)
	{
		sv=delq(&ptr);

		for(w=graph[sv];w!=NULL;w=w->link)
		{
			if(!visited[w->vertex])
			{
				visited[w->vertex]=TRUE;
				adj[w->vertex]=sv;
				ctr++;
				addq(&ptr,w->vertex);
			}
			if(w->vertex==ev)
			{
				break;
			}

		}

	}
}



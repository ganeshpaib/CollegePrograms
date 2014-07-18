/*
	GRAPH IMPLEMENTATION
*/


#define VERTICES 10
#define MAX 10

#include<stdio.h>
#include<conio.h>

typedef struct node *node_ptr;
typedef struct node
{
	int vertex;
	node_ptr link;
};

struct queue
{
  int que;

}q[MAX];

int z=0,a[10];
node_ptr graph[VERTICES];
int front=0,rear=0;
int visited[10],val,n;
void insert_el(node_ptr [],int , int );
void dfs(int );
void bfs(int );
void new_bfs(int );
void addq(int *,int *,int);
int deleteq(int *,int *);
void  path_dfs(int ,int );
void del_arr(int );
void add_arr(int , int );
void disp_path();

void main()
{
	int  i, j, a[10][10];
	char cha;
	int stvertex, endvertex;
	node_ptr t;
	clrscr();

	printf( "Enter the value of n(order) : " );
	scanf( "%d",&n );

	printf( "\nEnter the elements for input matrix: " );
	for( i = 1; i <= n; i++ )
	{
		for( j = 1; j <= n; j++ )
		{
			printf( "a[%d][%d]= ",i,j );
			scanf( "%d",&a[i][j] );
		}
	}

	printf( "INPUT: \n" );
	for( i = 1; i <= n; i++ )
	{
		for( j = 1; j <= n; j++ )
		{
			printf( "%d\t ",a[i][j] );
		}
		printf( "\n" );
	}

	for(i = 1; i <= n; i++ )
		graph[i]=NULL;

	for( i =1; i<= n; i++ )
	{
		for( j = 1; j <= n; j++ )
		{
			if(a[i][j]==1)
				insert_el(graph,i,j);
		}
	}

	printf( "\n\nOUTPUT:\n" );

	for(i=1;i<=n;i++ )
	{
		for(t=graph[i];t!=NULL;t=t->link)
		{
			printf( "%d\t",t->vertex );
		}
		printf( "\n" );
	}

	getch();
	clrscr();
	printf( "\n\n\nDFS OUTPUT\n" );
	dfs(1);

	getch();
	clrscr();
	for(i = 1; i<=n; i++ )
		visited[i]=0;
	printf( "\n\n BFS OUTPUT\n" );
	bfs(1);

	getch();
	clrscr();
	printf( "\nEnter the value of the node : " );
	scanf( "%d",&val );
		for(i = 1; i<=n; i++ )
		visited[i]=0;
	new_bfs(val);

	for(i = 1; i<=n; i++ )
		visited[i]=0;

		getch();
		clrscr();

	printf( "\nEnter the starting node : " );
	scanf( "%d",&stvertex );

	printf( "\nEnter the end vertex : " );
	scanf( "%d",&endvertex );

	path_dfs(stvertex,endvertex);


	getch();
}


void insert_el(node_ptr graph[],int i, int j)
{
	node_ptr temp,t;
	temp=(node_ptr) malloc(sizeof(struct node));

	temp->vertex=j;
	temp->link=NULL;

	if(graph[i]==NULL)
		graph[i]=temp;
	else
		for( t = graph[i]; t->link!=NULL; t=t->link);
			t->link=temp;



}


void  dfs(int v)
{
	node_ptr w;

	visited[v]=1;
	printf( "%d\t",v);

	for(w=graph[v];w!=NULL;w=w->link)
	{
		if(!visited[w->vertex])
			dfs(w->vertex);
	}
}

void bfs(int v)

{
	node_ptr w;
	 front=rear=NULL;
	printf( "%d\t",v );

	visited[v]=1;
	addq(&rear,&front,v);

	while(front!=rear)
	{
		v=deleteq(&front,&rear);

		for(w=graph[v];w!=NULL;w=w->link)
		{
			if(!visited[w->vertex])
			{
				visited[w->vertex]=1;
				printf( "%d\t",w->vertex );
				addq(&rear,&front,w->vertex);
			}
		}
	}
}
int num,flg=0,count=0,i;

void new_bfs(int v)

{
	node_ptr w;
	 front=rear=NULL;


	visited[v]=1;
	addq(&rear,&front,v);

	while(front!=rear)
	{
		v=deleteq(&front,&rear);
		num=v;
		for(w=graph[v];w!=NULL;w=w->link)
		{

			if(!visited[w->vertex])
			{
				visited[w->vertex]=1;
				printf( "%d,%d\n",num,w->vertex );
				addq(&rear,&front,w->vertex);
				count++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i]!=1)
		{
			flg=1;
			break;
		}

	}

	if((count==n-1)&&flg==0)
		printf( "The given graph is a spanning tree \n" );
	else
		printf( "NOT SPANNING TREE\n" );
}



void addq(int *rear,int *front,int n)
{
	*rear=(*rear+1) % MAX;
  if( *rear==*front )
  {
		printf("\nthe queue is full:");
		if(*rear==0)
		{
			  *rear=MAX-1;
		}
		else
		{
			   *rear=*rear-1;
		}
  }
  else
  {
	 q[*rear].que=n;
  }
}
int deleteq(int *front,int *rear)
{
   if( *front== *rear)
   {
	 printf("\nthe queue is empty:");
	 return(-1);
   }
   else

	{
	 *front=(*front+1) % MAX;
	 return(q[*front].que);
   }
}

int flag=0;
void  path_dfs(int v,int endnode)
{
	node_ptr w;

	visited[v]=1;
	if(flag==0)
	{
		a[0]=v;
		flag=1;
		z++;
	}

	for(w=graph[v];w!=NULL;w=w->link)
	{
		if(!visited[w->vertex])
		{
			if(w->vertex==endnode)
			{
				a[z]=endnode;
				z++;
				disp_path();
			}

			else
			{
				a[z]=w->vertex;
				z++;
				flg=0;
				path_dfs(w->vertex,endnode);
			}
		}
		else
			flg=1;
	}
	if(flg==1&&w==NULL)
		z--;



}

void add_arr(int vertex, int z)
{
	a[z]=vertex;
}

void del_arr(int z)
{
	z--;
}

int j;

void disp_path()
{
printf( "\nresult\n\n" );
	 for( j=0;j<z;j++)
		printf("%d\t",a[j]);
getch();
exit(0);
}
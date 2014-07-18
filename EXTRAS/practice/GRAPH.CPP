#include "header.cpp"

typedef struct node *ptr_node;

typedef struct node
{
	int vertex;
	ptr_node link;
};
void disp_mat();
void input_mat();
void insert_el(int,int);
void dfs(int);
void add_q(int *,int *,int);
int del_q(int *,int *);
void bfs(int);

int order, i, j, mat[10][10],visited[10],q[10];
ptr_node graph[10];

void main()
{
	int ch;
	ptr_node t;
	clrscr();
	do
	{

		printf( "\n\n 1 -> CREATE GRAPH\n" );
		printf( " 2 -> DFS\n" );
		printf( " 3 -> BFS\n" );
		printf( " 99 -> EXIT\n" );

		printf( " Enter ur choice.... : " );
		scanf( "%d",&ch );

		switch(ch)
		{
			case 1:	printf( " \n\nENTER THE INPUT MATRIX...:\n " );
					printf( " \n\nEnter the order of matrix...:\n " );
					scanf( "%d",&order );

					input_mat();
					disp_mat();

					for( i = 1; i <= order; i++ )
					{
						for( j = 1; j <= order; j++ )
						{
							if(mat[i][j]==1)
							{
								insert_el(i,j);
							}
						}
					}
					printf( "\n\nOUTPUT :\n" );

					for(i = 1; i <= order; i++ )
					{
						for(t=graph[i];t!=NULL;t=t->link)
							printf( "%d\t",t->vertex);
						printf( "\n" );
					}
					break;

			case 2: printf( " \n\nDFS :" );
					dfs(1);
					break;

			case 3: printf( "\n\nBFS : " );
					bfs(1);
					for( i = 1; i <= order; i++ )
						visited[i]=0;
					break;

			case 99:exit(0);

		}
		getch();
		clrscr();
	}while(ch!=99);

	getch();
}

void input_mat()
{
	for( i = 1; i <= order; i++ )
	{
		for( j = 1; j <= order; j++ )
		{
			printf( "mat[%d][%d] = ",i,j );
			scanf( "%d",&mat[i][j]);
		}
	}
	for(i = 1; i <= order; i++ )
		graph[i]=NULL;
}

void disp_mat()
{
	printf( "\n\nINPUT MATRIX :\n\n" );

	for( i = 1; i <= order; i++ )
	{
		for( j = 1; j <= order; j++ )
		{
			printf( "%d\t",mat[i][j] );
		}
		printf( "\n" );
	}
}

void insert_el(int i, int j)
{
	ptr_node temp,t;

	temp=(ptr_node)malloc(sizeof(struct node));

	temp->vertex=j;
	temp->link=NULL;

	if(graph[i]==NULL)
	{
		graph[i]=temp;
	}
	else
	{
		for(t=graph[i];t->link!=NULL;t=t->link);
		t->link=temp;
	}
}

void dfs(int v)
{
	ptr_node w;
	printf( "%d\t",v);

	visited[v]=1;
	for(w=graph[v];w!=NULL;w=w->link)
	{
		if(!visited[w->vertex])
			dfs(w->vertex);
	}
}

void bfs(int v)
{

	ptr_node w;
	int rear=NULL,front=NULL;

	visited[v]=1;
	printf( "%d\t",v );
	add_q(&front,&rear,v);

	while(front!=rear)
	{
		v=del_q(&front,&rear);
		for(w=graph[v];w!=NULL;w=w->link)
		{
			if(!visited[w->vertex])
			{
				printf( "%d\t",w->vertex);
				visited[w->vertex]=1;
				add_q(&front,&rear,v);
			}
		}
	}
}


void add_q(int *front,int *rear,int v)
{
	(*rear)=((*rear)+1)%10;
	if((*rear)==(*front))
	{
 		printf( "QUEUE FULL\n" );
		if((*rear)==0)
		{
			*rear=10-1;
		}
		else
			*rear=(*rear)-1;
	}
	q[*rear]=v;
}

int del_q(int *front,int *rear)
{

	if((*front)==(*rear))
	{
		printf( "QUEUE EMPTY\n" );
		return -1;
	}
	else
	{
		*front=((*front)+1)%10;
		return (q[*front]);
	}
}
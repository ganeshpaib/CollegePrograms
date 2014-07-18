#include "header.cpp"
struct kruscle
{
	int u,v;
}s;
int b[10],t,a[10][10],z,x,y,k,i,j,n,m,flg,cnt,p[10],c[10][10];
int find(int);
void input()
{
	printf("\nENTER THE SIZE : ");
	scanf("%d",&n);
	printf("\nENTER THE ELEMENTS");
	k=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("a[%d][%d] = ",i,j);

				scanf("%d",&a[i][j]);
				if(a[i][j]==1)
				{
					if(i<j)
					{
						printf("\n  ENTER THE COST : ");
						scanf("%d",&c[i][j]);
						b[k]=c[i][j];k++;
					}
					else
					c[i][j]=-1;

				}
				else
				{
					if(i==j)
						c[i][j]=0;
					else
						c[i][j]=-1;
				}
			}

		clrscr();
	}
}
void main()
{
	clrscr();
	input();
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}

	for(z=1;z<k;z++)
	{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(c[i][j]==b[z])
			{
				x=find(i);
				y=find(j);
				if(x!=y)
				{
					p[j]=i;
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	}
	getch();
}
int find(int e)
{
	while(p[e]!=0)
		e=p[e];
	return e;
}
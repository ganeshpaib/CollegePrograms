#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int **a,*d,*p,*l,top=0,*visited;
int mins(int,int);
int least(int *);
void path(int);

void main()
{
		int ver,i,j,s,k,minval,p1[10],sv,ev,ctr;
		clrscr();

		printf("\n Enter Number Of Vertex :");
		scanf("%d",&ver);

		a=(int **)malloc(sizeof(int)*ver*ver);
		d=(int *)malloc(sizeof(int)*ver);
		p=(int *)malloc(sizeof(int)*ver);
		l=(int *)malloc(sizeof(int)*ver);
		visited=(int *)malloc(sizeof(int)*ver);

		for(i=1;i<=ver;i++)
		{
			*(a+i)=(int *)malloc(sizeof(int)*ver);
				visited[i]=0;
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

		printf("\n Enter Source :");
		scanf("%d",&s);


		for(i=1;i<=ver;i++)
		{
			d[i]=a[s][i];
		}


		for(i=1;i<=ver;i++)
		{
			if(d[i]==0 || d[i]==99)
				{
					p[i]=0;
				}
				else
				{
					p[i]=s;
				}
		}

		for(i=1;i<=ver;i++)
		{
			if(p[i]!=0)
			{
				l[++top]=i;
			}
		}

		while(top!=0)
		{
			i=least(l);
			visited[i]=1;
			j=0;

				for(k=(j+1);k<=ver;k++)
				{
					if(a[i][k]!=0 && a[i][k]!=99)
					 {
						j=k;
						minval=mins(d[j],(d[i]+a[i][j]));
						if(d[j]!=minval)
						{
							d[j]=minval;
							p[j]=i;
						}
						if(visited[j]!=1)
							l[++top]=j;
					 }


				}
		}

		for(i=1;i<=ver;i++)
		{
			printf("\n Distance From 1 to %5d : %5d" ,i,d[i]);
		}
		printf("\n\n");

		for(i=1;i<=ver;i++)
		{
			printf("\n\n Path From 1 to %5d \n\n",i);
			path(i);
		}

getch();
}

void path(int e)
{
	int temp[10],ctr=1,i;
	temp[1]=e;

	while(e!=0)
	{
		temp[++ctr]=p[e];
		e=p[e];
	}

	for(i=ctr-1;i>=1;i--)
	{
		printf("%5d",temp[i]);
	}
}

int mins(int x,int y)
{
	if(x<y)
			return(x);
		else
			return(y);
}

int least(int *l)
{
	int temp[10],ctr=0,i,j,t,l1[10],f=0;

		for(i=1;i<=top;i++)
		{
			temp[i]=d[l[i]];

		}

		for(i=1;i<top;i++)
		{
			for(j=i+1;j<=top;j++)
			{
				if(temp[i]>temp[j])
				{
					t=temp[i];
					temp[i]=temp[j];
					temp[j]=t;
				}
			}
		}
		ctr=0;

		for(i=1;i<=top;i++)
		{
			if(temp[1]!=d[l[i]])
			{
				l1[++ctr]=l[i];
			}
			else
				f=l[i];
		}
		top=ctr;

		for(i=1;i<=ctr;i++)
		{
			l[i]=l1[i];
		}

		printf("\n");

		return(f);
}



















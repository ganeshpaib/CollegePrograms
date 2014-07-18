#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int **a,*d,*p,*l,top=0,*visited;
int min(int,int);
int least(int *);

void main()
{
	int ver,i,j,s,k,minval;
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

                for(k=1;k<=ver;k++)
                {
                	if(a[i][k]!=0 && a[i][k]!=99)
                        {
                        	j=k;
                                minval=min(d[j],(d[i]+a[i][j]));

                                if(d[j]!=minval)
                                {
                                	d[j]=minval;
                                        p[j]=i;
                                }

                        }

                        if(visited[j]!=1)
                        {
                        	l[++top]=j;
                        }


                }
        }


        for(i=1;i<=ver;i++)
        {
        	printf("\n %5d...%5d",d[i],p[i]);
        }
getch();
}

int min(int x,int y)
{
	if(x<y)
        	return(x);
        else
        	return(y);
}

int least(int *l)
{
	int temp[10];

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
                                t=temp[j];
                        }
                }
        }

        top--;
        return(tenmp[0]);
}


















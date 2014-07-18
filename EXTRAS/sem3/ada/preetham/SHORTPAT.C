#include<stdio.h>
#include<conio.h>
#define size 10

int d[size],a[size][size],p[size],l[size],temp[size],temp1[size],tp[size],n;
int top=-1;
int least(int *,int);
int min(int,int);
int count(int *);
void push(int);
int pop();


void main()
{
	int i,j[size],j1,s,ctr=0,c=0,k,small,min1,k1,sv,dv;
        clrscr();

        printf("\n Enter Number Of Vertex : ");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
        	for(j1=0;j1<n;j1++)
                {
                	printf("a[%d][%d]:",i,j1);
                        scanf("%d",&a[i][j1]);
                }
                printf("\n");
        }

        clrscr();
        printf("\n Enter  Source : ");
        scanf("%d",&s);

        for(i=0;i<n;i++)
        {
        	d[i]=a[s-1][i];
        }

        for(i=0;i<n;i++)
        {
        	if(d[i]!=0 && d[i]!=99)
                {
                	p[i]=s;
                }
                else
                {
                	p[i]=0;
                }
        }

        for(i=0;i<n;i++)
        {
        	if(p[i]==s)
                {
                	push(i);
                }
        }

      while(top!=-1)
        {
        	small=least(l,top);
                c=0;

                for(i=0;i<=top;i++)
                {
                	if(small!=l[i])
                        {
                        	temp1[c++]=pop();
                        }
                }
                for(i=0;i<c;i++)
                {
                	//l[i]=temp1[i];
                        push(temp1[i]);
                }
                i=small;
                ctr=c;
                c=0;
                printf("\n");

                for(i=0;i<=top;i++)
                {
                	printf("%5d",l[i]);
                }

                printf("\n %5d....%5d",i,ctr);
        }

                /*for(k=0;k<n;k++)
                {
                	if(a[i][k]!=0 && a[i][k]!=101)
                        {
                        	j[c++]=k;
                        }
                }

                for(k=0;k<c;k++)
                {
                	min1=min(d[j[k]],d[i]+a[i][j[k]]);

                        if(d[j[k]]!=min1)
                        {
                        	d[j[k]]=min1;
                                p[j[k]]=i;
                        }
                }

        	for(k=0;k<n;k++)
        	{
        		if(p[k]!=0 && p[k]!=101 && k!=small)
                	{
                		l[ctr++]=k;
                	}
        	}
        }

        printf("\n Enter Source Vertex :");
        scanf("%d",sv);
        printf("\n Enter Destination Vertex :");
        scanf("%d",&dv);

        while(p[sv]!=0)
        {
        	tp[ctr++]=p[sv];
                sv=p[sv];
        }
        printf("\n");

        for(i=ctr-1;i>=0;i--)
        {
        	printf("%5d",tp[i]);
        }*/
getch();
}

int min(int a,int b)
{
	if(a<b) return a;
        else return b;
}

int least(int *l,int ctr)
{
	int temp[size],t,i,j;

        for(i=0;i<ctr;i++)
        {
        	temp[i]=d[l[i]];
        }

        for(i=0;i<ctr-1;i++)
        {
        	for(j=i+1;j<ctr;j++)
                {
                	if(temp[i]>temp[j])
                        {
                        	t=temp[i];
                                temp[i]=temp[j];
                                temp[j]=t;
                        }
                }
        }

        for(i=0;i<n;i++)
        {
        	if(d[i]==temp[0])
                {
                	break;
                }
        }
        return(i);
}

void push(int n)
{
	l[++top]=n;
}
int pop()
{
	return(l[top--]);
}















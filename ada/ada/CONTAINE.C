#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int *w,*ind,*temp,*sol,n,c,i,j,t,ctr=0,sum=0;
        clrscr();

        printf("\n Enter Number Of Containers : ");
        scanf("%d",&n);
        printf("\n Enter Max Weigth :");
        scanf("%d",&c);

       	w=(int *)malloc(sizeof(int)*n);
        ind=(int *)malloc(sizeof(int)*n);
        temp=(int *)malloc(sizeof(int)*n);
        sol=(int *)malloc(sizeof(int)*n);


        for(i=0;i<n;i++)
        {
        	printf("w[%d] :",i);
                scanf("%d",&w[i]);
                temp[i]=w[i];
        }

        for(i=0;i<n-1;i++)
        {
        	for(j=i+1;j<n;j++)
                {
                	if(w[i]>w[j])
                        {
                        	t=w[i];
                                w[i]=w[j];
                                w[j]=t;
                        }
                }
        }

        for(i=0;i<n;i++)
        {
        	for(j=0;j<n;j++)
                {
                	if(w[i]==temp[j])
                        {
                        	temp[j]=-1;
                        	ind[ctr++]=j;
                        }

                }
        }


        printf("\n");

        for(i=0;i<n;i++)
        {
        	sum=sum+w[i];
		if(sum<=c)
                {
                	sol[ind[i]]=1;
                }
                else
                {
                	sol[ind[i]]=0;
                }
        }

        printf("\n");

        for(i=0;i<n;i++)
        {
                printf("%5d",sol[i]);
        }
getch();
}



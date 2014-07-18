#include<stdio.h>
#include<conio.h>
#define size 10

void main()
{
	int  p[size],w[size],ind[size],sol[size],i,j,n,c,ctr=0,tp=0,total=0;
		 float r[size],temp[size],t;
		clrscr();

		printf("\n Enter Number Of Items : ");
		scanf("%d",&n);
		printf("\n Enter Total Capacity : ");
		scanf("%d",&c);

		printf("\n\n");

		for(i=0;i<n;i++)
		{
				printf("\n Weigth [%d] : ",i);
				scanf("%d",&w[i]);
				printf("\n Profit [%d] : ",i);
				scanf("%d",&p[i]);
				r[i]=(float)p[i]/(float)w[i];
				temp[i]=r[i];
				printf("\n");
		}

		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(r[i]<r[j])
				{
					t=r[i];
					r[i]=r[j];
					r[j]=t;
				}
			}
		}

	   for(i=0;i<n;i++)
	   {
			for(j=0;j<n;j++)
				{
					if(r[i]==temp[j])
						{
							ind[ctr++]=j;
							temp[j]=-1;
								break;
						}
				}
		}

	   for(i=0;i<n;i++)
	   {
			total=total+w[ind[i]];

				if(total<=c)
				{
						tp=tp+p[ind[i]];
						sol[ind[i]]=1;
				}
				else
				{
					sol[ind[i]]=0;
				}
		}

		printf("\n\n\n");

		printf("\n Total Profit : %5d",tp);

		for(i=0;i<n;i++)
		{
			printf("%5d",sol[i]);
		}

		printf("\n\n");

getch();
}




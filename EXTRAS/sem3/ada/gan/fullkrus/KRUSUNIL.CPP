#include<stdio.h>
#include<conio.h>
#include<iostream.h>

int find(int);
int p[10];



void main()
{
   int n,i,j,a[10][10],b[10],t,k=1,c[10][10],z,x,y;
   clrscr();
   printf("\nEnter the size of the matrix:");
   scanf("%d",&n);
   printf("\nEnter the elements:\n");
   for(i=1;i<=n;i++)
   {
	  for(j=1;j<=n;j++)
	  {
		  printf("a[%d][%d]==",i,j);
		  scanf("%d",&a[i][j]);
	  }
   }
   printf("\n");
   for(i=1;i<=n;i++)
   {
	  for(j=1;j<=n;j++)
	  {
		  printf("%5d",a[i][j]);
	  }
	  printf("\n");
   }
   printf("Enter the cost:");
   for(i=1;i<=n;i++)
   {
	  for(j=1;j<=n;j++)
	  {
		  if(a[i][j]==1&&i<j)
		  {
			 printf("\na[%d][%d]==",i,j);
			 scanf("%d",&c[i][j]);
			 b[k]=c[i][j];
			 k++;
		  }
	  }
   }

  for(i=1;i<=k-1;i++)
   {
	  for(j=i+1;j<=k;j++)
	  {
		 if(b[i]>b[j])
		 {
			t=b[i];
			b[i]=b[j];
			b[j]=t;
		 }
	  }
   }

   for(i=1;i<k;i++)
   {
	  printf("%5d",b[i]);
   }
   printf("\n");
   for(z=1;z<=k;z++)
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
					printf( "%d\t%d\n",i,j);
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
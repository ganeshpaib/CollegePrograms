#include<stdio.h>
#include<conio.h>
#include<iostream.h>

void main()
{
   int n,i,j,a[10][10],b[10],t,k=0,c[10][10],z;
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

  for(i=0;i<n-1;i++)
   {
	  for(j=i+1;j<n;j++)
	  {
		 if(b[i]>b[j])
		 {
			t=b[i];
			b[i]=b[j];
			b[j]=t;
		 }
	  }
   }

   for(i=0;i<n;i++)
   {
	  printf("%5d",b[i]);
   }
   printf("\n");
   for(z=0;z<n;z++)
   {
	  for(i=1;i<=n;i++)
	  {
		 for(j=1;j<=n;j++)
		 {
			if(c[i][j]==b[z])
			{
			   printf("%d , %d\n",i,j);
			}
		 }
	  }
   }


   getch();
}

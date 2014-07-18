/*Program to perform sum of non diagonal elements*/
#include<stdio.h>
#include<conio.h>
main()
 {
  int n,i,j,a[5][5],z,sum=0;
  clrscr();

  printf("Enter the value of n: \n");
  scanf("%d",&n);

  printf("Enter the elements\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("a[%d][%d]= ",i,j);
      scanf("%d",&a[i][j]);

     }
   }

 printf("Entered elements are \n");
 for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
     printf("%5d",a[i][j]);
    }
   printf("\n");
  }

 for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
     if(i!=j)
      {
       z=sec_dig(i,j,n);
       if(z==0)
	sum=sum+a[i][j];
      }
    }
  }
  printf("Sum of non diagonal elements= %d\n",sum);
  getch();
 }


 int sec_dig(int i,int j,int n)
  {
   int l,k,z=0;
   l=n-1;
   for(k=0;k<n;k++)
    {
     if(i==k&&j==l)
      {
       z=1;
       break;
      }
     l--;
    }
   return z;
  }
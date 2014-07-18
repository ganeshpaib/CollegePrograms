#include<stdio.h>
#include<conio.h>
main()
 {
  int ***a,i,j,k,m,n,z;
  printf("Enter the number of the matrix\n");
  scanf("%d",&z);
  printf("Enter the rows\n");
  scanf("%d",&m);
  printf("enter the columns\n");
  scanf("%d",&n);
  a=(int ***)malloc(sizeof(int)*m*n*z);

  for(i=0;i<z;i++)
   {
   **(a+i)=(int **)malloc(sizeof(int)*m*n);
   }
  for(j=0;j<m;j++)
   {
   *(a+j)=(int *)malloc(sizeof(int)*m);
   }

  printf("enter the elements\n");
  for(i=0;i<z;i++)
   {
   for(j=0;j<m;j++)
    {
     for(k=0;k<n;k++)
      {
       printf("a[%d][%d][%d] = ",i,j,k);
       scanf("%d",&a[i][j][k]);
      }
    }
   }

  printf("entered elements are: \n");
  for(i=0;i<z;i++)
   {
    for(j=0;j<m;j++)
     {
     for(k=0;k<n;k++)
      {
      printf("%d\t",a[i][j][k]);
      }
     printf("\n");
    }
   printf("\n\n");
  }
  getch();
 }
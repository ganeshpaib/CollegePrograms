/*
  PROGRAM TO ROTATE MATRIX
*/

#include<stdio.h>
#include<conio.h>
main()
 {
  int n,i,j,k,a[10][10],b[10][10],temp;
  clrscr();

  printf("enter the value of n " );
  scanf("%d",&n);

  printf("Enter the elements\n ");
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
      scanf("%d",&a[i][j]);
      b[i][j]=a[i][j];
     }
   }

  printf("ENTERED ELEMENTS ARE: \n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("%d\t",a[i][j]);
     }
    printf("\n");
   }

  for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
      {
      a[i][j+1]=b[i][j] ;
     }
    j=j-1;
    for(k=0;k<n;k++)
     {

      a[k+1][j]=b[k][j];
     }
    k=k-1;
    for(j=n-1;j>=0;j--)
     {
      a[k][j-1]=b[k][j];
     }
     j=0;
    for(k=n-1;k>=0;k--)
     {
      a[k-1][j]=b[k][j];
     }
    break;
   }


  printf("\n\nRESULTANT MATRIX \n");

   for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
     {
      printf("%d\t",a[i][j]);
     }
    printf("\n");
    }
   getch();
  }
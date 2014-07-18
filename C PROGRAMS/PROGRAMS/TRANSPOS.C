/*PROGRAM TO FIND TRANSPOSE OF THE GIVEN MATRIX*/

#include<stdio.h>
#include<conio.h>
main()
 {
  int m,n,i,j,a[10][10],flg=0;
  clrscr();
  printf("Enter the dimensions of matrix: \n");
  scanf("%d%d",&m,&n);

  printf("Enter the elements\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
     {
      printf("a[%d][%d]= ",i,j);
      scanf("%d",&a[i][j]);
     }
   }

  printf("\nENTERED MATRIX\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    {
     printf("%d\t",a[i][j]);
    }
    printf("\n");
   }

  printf("\n\nTRANSPOSE OF MATRIX: \n");

  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("%d\t",a[j][i]);
     }
    printf("\n");
   }

  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
      if(a[i][j]!=a[j][i])
       {
	 flg=1;
	 break;
       }
     }
   }
   if(flg==1)
    printf("Transpose of the matrix is not symmetric\n");
   else
    printf("Transpose of the matrix is symmetric\n");




 getch();
}
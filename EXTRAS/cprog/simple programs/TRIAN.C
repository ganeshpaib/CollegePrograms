/* Program to find whether the entered matrix is an upper triangular matrix
   or not using dynamic memory allocation */

#include<stdio.h>
#include<conio.h>
main()
 {
  int **a,n,m,i,j,flg=0;
  clrscr();
  printf("Enter value of n for the square matrix\n");
  scanf("%d%d",&m,&n);

  a=(int **) malloc(sizeof(int) *n*m);

  for(i=0;i<m;i++)
   *(a+i)=(int *)malloc(sizeof(int) * n);
  printf("Enter the elements\n");
  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("a[%d][%d]= ",i,j);
      scanf("%d",&a[i][j]);
     }
   }


  printf("Entered elements\n");
  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("%5d",a[i][j]);
     }
    printf("\n");
   }


  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      if(i>j)
       {
	if(a[i][j]!=0)
	 {
	  flg=1;
	  break;
	 }
       }
     }
   }
  if(flg==1)
   printf("Entered matrix is not an upper triangular matrix\n");
  else
   printf("Entered matrix is an upper triangular matrix\n");

  getch();
 }

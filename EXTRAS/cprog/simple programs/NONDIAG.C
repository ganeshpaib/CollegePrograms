/*Program to find the sum of non diagonal elements of the matrix */

#include<stdio.h>
#include<conio.h>
main()
 {
  int n,**a,i,j,sum=0;
  clrscr();

  printf("Enter the value of n for the square matrix\n");
  scanf("%d",&n);

  a=(int **) malloc(sizeof(int) *n*n);
  for(i=0;i<n;i++)
   *(a+i)=(int *)malloc(sizeof(int) *n);
  printf("Enter the elements\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("a[%d][%d]= ",i,j);
      scanf("%d",(*(a+i)+j));
     }
   }

  printf("Entered elements\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("%5d",*(*(a+i)+j));
     }
    printf("\n");
   }

  sum=0;
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
      if(i!=j)
       {
	sum=sum+*(*(a+i)+j);
       }
     }
   }

  printf("Sum of non diagonal elements = %d\n",sum);
  getch();
 }
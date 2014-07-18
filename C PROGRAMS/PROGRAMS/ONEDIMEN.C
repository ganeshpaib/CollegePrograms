#include<stdio.h>
#include<conio.h>
main()
 {
  int m,n,i,j,k,a[10][10],b[10];
  clrscr();
  printf("ENTER THE DIMENSIONS OF THE MATRIX :\n");
  scanf("%d%d",&m,&n);

  printf("ENTER THE ELEMENTS\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
     {
      printf("\na[%d][%d]= ",i,j);
      scanf("%d",&a[i][j]);
     }
   }

  printf("\nELEMENTS IN SINGLE DIMENSION IS AS FOLLOWS: \n");
  k=0;
  for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
     {
      b[k]=a[i][j];
      printf("\n\tb[%d]=%d",k,b[k]);
      k++;
     }
   }
  getch();
 }
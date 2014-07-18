#include<stdio.h>
#include<conio.h>
int rev(int *);
main()
 {
  int m,n,**a,i,j,z,num,palin=0;
  clrscr();
  printf("Enter the dimensions of the matrix\n");
  scanf("%d%d",&m,&n);

  a=(int **) malloc(sizeof(int) *m*n);
  for(i=0;i<m;i++)
   *(a+i)=(int *) malloc(sizeof(int) * n);

  printf("Enter the elements\n");
  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("a[%d][%d]= ",i,j);
      scanf("%d",(*(a+i)+j));
     }
   }

  printf("Entered elements\n");
  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("%5d",*(*(a+i)+j));
     }
    printf("\n");
   }

  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      num=*(*(a+i)+j);
      z=rev(*(a+i)+j);
      if(z==num)
       palin++;
      *(*(a+i)+j)=z;
     }
   }
  printf("After revesing the elements\n");
  for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
     {
      printf("%5d",a[i][j]);
     }
    printf("\n");
   }
   printf("Number of palindromes=%d\n",palin);
  getch();
 }


 int rev(int *a)
  {
   int p,rev=0;
   while(*(a)>0)
    {
     p=*(a) % 10;
     rev=rev * 10+p;
     *(a)=*(a)/10;
    }
   return rev;
  }

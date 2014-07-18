#include<stdio.h>
#include<conio.h>
main()
 {
  int n,i,j,a[10][10],s,t,c,p;
  clrscr();
  printf( "Enter the dimensions\n" );
  scanf( "%d",&n);

  printf("Enter the elements\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     {
       scanf("%d",&a[i][j]);
     }
   }

  printf("Entered elements\n");
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
    s=a[i][j];
    c=0;p=1;
    for(j=i+1;j<n;j++)
     {
      if(s>a[i][j])
       {
	c=j;
	t=a[i][j];
	a[i][j]=s;
	s=t;
       }
     }


 for(t=0;t<n;t++)
  {
  if(a[i][c]>a[t][c])
    p=0;
  }

  if(p)
   printf("row %d =%d",i+1,a[i][0]);
  else
  {
   printf("row %d=no saddle",i+1);
  }
  p=1;
}
}
/*Program to perform sum of non diagonal elements in the given square matrix*/
#include<stdio.h>
#include<conio.h>
main()
 {
  int n,i,num,j,a[5][5],b[5][5],x,z=0,sum=0;
  clrscr();
  printf( " Enter the value of n for the square matrix\n " );
  scanf( "%d",&n);

  printf( " Enter the elements\n " );
  for( i = 0; i < n; i++ )
   {
    for( j = 0; j < n; j++ )
     {
      printf("a[%d][%d] = ",i,j);
      scanf( "%d",&a[i][j]);
      b[i][j]=a[i][j];
     }
   }

  printf( " Entered elements are \n " );
  for(i = 0; i < n; i++ )
   {
    for( j = 0; j < n; j++ )
     {
      printf("%5d",a[i][j] );
     }
    printf("\n" );
   }


  for( i = 0; i < n; i++ )
   {
    for( j =0; j< n; j++)
     {
      num=a[i][j];
      z = prim_dig(num,b,n);

      x = sec_dig(num,b,n);

      if(z==0&&x==0)
       sum=sum+a[i][j];
     }
   }
  printf( " Sum of non diagonal elements= %d\n ",sum );
 getch();
 }


 int prim_dig(int num,int b[][5],int n)
  {
   int i,z=0;
   for( i = 0; i < n; i++ )
    {
     if(num==b[i][i])
      {
       z = 1;
       break;

      }
    }
   return z;
  }

 int sec_dig(int num,int b[][5],int n)
  {
   int k,l,z=0;
   l=n-1;
   for(k=0;k < n;k++ )
    {
     if(l>=0)
      {
       if(num==b[k][l])
	{
	 z=1;
	 break;
	}

       l--;
      }
    }
   return z;
  }
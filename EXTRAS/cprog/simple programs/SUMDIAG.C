/*PROGRAM TO FIN THE SUM OF THE ROWS, COLUMNS & DIGONAL ELEMENTS*/

#include<stdio.h>
#include<conio.h>
main()
 {
  int m,n,i,j,k,a[10][10],sum=0,z;
  clrscr();

  printf("ENTER THE DIMENSIONS OF THE MATRIX: \n");
  scanf("%d%d",&m,&n);

  printf("ENTER THE ELEMENTS\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    {
     printf("a[%d][%d]= ",i,j);
     scanf("%d",&a[i][j]);
    }
   }

  printf("\nWHAT DO U WANT TO PERFORM?!!!!!!!!\n");
  printf("\n1 -> Sum of each row\n");
  printf("2 -> Sum of each column\n");
  printf("3 -> Sum of diagonal elements\n");
  scanf("%d",&z);

  printf("ENTERED MATRIX\n");
  for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
     {
      printf("%d\t",a[i][j]);
     }
    printf("\n");
   }

  switch(z)
   {
    case 1:
	    for(i=0;i<n;i++)
	     {
	      sum=0;
	      for(j=0;j<m;j++)
	       {
		sum = sum + a[i][j];
	       }
	      printf(" \nSum of row %d = %d",i,sum);
	     }
	     break;
    case 2:
	    for(i=0;i<n;i++)
	     {
	      sum=0;
	      for(j=0;j<m;j++)
	       {
		sum=sum+a[j][i];
	       }
	      printf("\nSum of column %d = %d",i,sum);
	     }
	    break;
    case 3:
	    if(m==n)
	     {
	      sum=0;
	      for(i=0;i<n;i++)
	       {
		for(j=0;j<m;j++)
		 {
		  if(i==j)
		   {
		    sum=sum+a[i][j];
		   }
		  }
		}
	       printf("Sum of primary diagonal elments = %d\n",sum);
		k=m-1;
		sum=0;
		for(j=0;j<n;j++)
		 {
		  sum=sum+a[j][k];
		  k--;
		 }
		printf("Sum of secondary diagonal elements = %d\n",sum);


	     }
	    else
	     printf("Can't find the sum\n");
	     break;


   }
  getch();
 }



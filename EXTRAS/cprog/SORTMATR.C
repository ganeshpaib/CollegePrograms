/*Program to sort rows and columns of a matrix*/

#include<stdio.h>
#include<conio.h>
main()
 {
   int m,n,a[10][10],i,j,k,z,temp;
   clrscr();
   printf("Enter the dimensions of matrix\n");
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

   printf("Entered elements\n");
   for(i=0;i<n;i++)
    {
     for(j=0;j<m;j++)
      {
       printf("%5d",a[i][j]);
      }
      printf("\n");
    }

   printf("ENTER YOUR CHOICE: \n");
   printf("1 -> Row sorting\n");
   printf("2 -> Column sorting\n");
   scanf("%d",&z);
   switch(z)
    {
     case 1:
	    for(i=0;i<n;i++)
	     {
	      for(j=0;j<m-1;j++)
	       {
		for(k=j+1;k<m;k++)
		 {
		  if(a[i][j]>a[i][k])
		   {
		    temp=a[i][j];
		    a[i][j]=a[i][k];
		    a[i][k]=temp;
		   }
		  }
		}
	      }
	     break;

      case 2: for(i=0;i<m;i++)
		{
		 for(j=0;j<m-1;j++)
		  {
		   for(k=j+1;j<m;j++)
		    {
		     if(a[i][j]>a[i][k])
		      {
		       temp=a[i][j];
		       a[i][j]=a[i][k];
		       a[i][k]=temp;
		      }
		    }
		  }
		}

	      break;

     }
	     printf("After sorting rows\n");
	     for(i=0;i<n;i++)
	      {
	       for(j=0;j<m;j++)
		{
		 printf("%5d",a[i][j]);
		}
	       printf("\n");
	      }



     getch();
    }
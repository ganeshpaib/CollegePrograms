#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
   void  main()
   {
	 int *a,t,i,j,n;
	 clrscr();
	 printf("\nenter the size of array;");
	 scanf("%d",&n);

	 a=(int*)malloc(sizeof(int)*n);
	 printf("\nenter the element of array:");
	 for(i=0;i<n;i++)
	 {printf("\na[%d]",i);
	   scanf("%d",&a[i]);
	 }

	 for(i=0;i<n-1;i++)
	 {  for(j=i+1;j<n;j++)
		{
		   if(a[i]>a[j])
		   {  t=a[i];
			   a[i]=a[j];
			   a[j]=t;
		  }
	   }
	}

	printf("\nthe elment of array after sort is :");
	for(i=0;i<n;i++)
	{ printf("%5d",a[i]);
	}
	getch();
	}
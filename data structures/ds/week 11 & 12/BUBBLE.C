#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
  int *a,n,i,j,t;
  clrscr();
  printf("\nenter the size of array :");
  scanf("%d",&n);
  a=(int*)malloc(sizeof(int)*n);
  printf("\nenter the element of array:");
  for(i=0;i<n;i++)
  {  printf("\na[%d]",i);
	 scanf("%d",&a[i]);
  }
  for(i=0;i<(n-1);i++)
  {
	 for(j=0;j<(n-i);j++)
	 {
	   if(a[j]>a[j+1])
	   {
		  t=a[j];
		  a[j]=a[j+1];
		  a[j+1]=t;
	   }
	 }
  }

  printf("\n.the elment of the array after  sorting is : ");
  for(i=0;i<n;i++)
  {
	printf("%5d",a[i]);
  }
  getch();
  }
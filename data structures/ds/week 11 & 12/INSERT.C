#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
 int *a,i,j,n,t,k;
 clrscr();
 printf("\nenter the size of array:");
 scanf("%d",&n);
 a=(int *)malloc(sizeof(int)*n);

 printf("\nenter the element of array:");
 for(i=0;i<n;i++)
 {
   printf("\na[%d]",i);
   scanf("%d",&a[i]);
 }

 for(i=1;i<n;i++)
 {
	 for(j=0;j<i;j++)
	 {
	   if(a[i]<a[j])
	   {
		  t=a[i];
		  for(k=i;k>j;k--)
		  {
			a[k]=a[k-1];
		  }
		 a[j]=t;
	   }
	 }
 }
 printf("\nthe element after sort is :");
 for(i=0;i<n;i++)
 {
   printf("\n%d",a[i]);
 }
 getch();

}
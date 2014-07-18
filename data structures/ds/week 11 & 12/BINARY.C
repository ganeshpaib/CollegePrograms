#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
 int *a,i,j,n,t,search,beg,end,mid,f=0;
 clrscr();
 printf("\nenter the size of array:");
 scanf("%d",&n);
 a=(int*)malloc(sizeof(int)*n);
 for(i=0;i<n;i++)
 {
   printf("\na[%d]",i);
   scanf("%d",&a[i]);
 }
 printf("\nenter the element to search:");
 scanf("%d",&search);
 for(i=0;i<n-1;i++)
 {
	for(j=i+1;j<n;j++)
	{
	  if(a[i]>a[j])
	  {  t=a[i];
		 a[i]=a[j];
		 a[j]=t;

	  }
	}
 }

 beg=0;
 end=n-1;

 while(beg<=end)
 {
	mid=(beg+end)/2;
	 if(a[mid]==search)
	 {
		   f=1;
		   break;
	 }
	 else if(a[mid]>search)
	 {
	   end=mid-1;
	 }
	 else
	 {
	   beg=mid+1;
	 }
 }
	 if(f==1)
	 {
		   printf("\nthe search element is found:");
	 }
	 else
		 printf("\nthe search element is not found:");

 getch();
}
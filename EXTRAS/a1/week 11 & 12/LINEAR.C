#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
 int *a,i,j,n,search,f=0,c;
 clrscr();
 printf("\nenter the element of array:");
 scanf("%d",&n);
 a=(int*)malloc(sizeof(int)*n);
 printf("\nenter the element of array:");
 for(i=0;i<n;i++)
 {
  printf("a[%d]",i);
  scanf("%d",&a[i]);
 }
 printf("\nenter the element to search:");
 scanf("%d",&search);
 for(i=0;i<n;i++)
 {
	if(a[i]==search)
	{
	  f=1;
	  break;
	}
 }
 if(f==1)
 {
   printf("\nthe element is found :");
 }
 else
 printf("\nthe element is not found:");
 getch();
 }
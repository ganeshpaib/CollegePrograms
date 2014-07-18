#include<stdio.h>
#include<conio.h>

int linear(int a[],int n,int search)
{
	if(n>=0)
	{
   if(search==a[n])
   {
	  return(n);

   }
   else
	{
		n=n-1;
	   return(linear(a,n ,search));
	}
   }
   return(-1);

}
void main()
{
   int a[11],i,j,n,search,m;
   clrscr();
   printf("\nenter the size of array :");
   scanf("%d",&n);
   printf("\nenter the element of array :");
   for(i=0;i<n;i++)
   {   printf("a[%d]",i);
	   scanf("%d",&a[i]);
   }
   printf("\nenter the element to be searched :");
   scanf("%d",&search);

	m=linear(a,n-1,search);
	if(m!=-1)
	 printf("\nthe element is found in the position : %d",m+1);
		else
	 printf("\nthe element is not found ");
	 getch();
	}

#include<stdio.h>
#include<conio.h>

int bin(int a[11], int beg ,int end , int search)
{
	 int mid;


   if(beg<=end)
   {
	 mid=(end+beg)/2;

	if(a[mid]==search)
	{
	  return(0);
	}
	 else if(a[mid]>search)
	 {
	   return(bin(a,beg,mid-1,search));
	 }
	else
	{
	  return(bin(a,mid+1,end,search ));
	}
  }
  return(-1);
}

void main()
{
	int a[11], i, j, n,m,c, t,beg,end,search ;
	clrscr();
	printf("\nenter the size of array :");
	scanf("%d",&n);
	flushall();
	printf("\nenter the element of array :");
	for(i=0;i<n;i++)
	{
	   printf("\na[%d]",i);
	   scanf("%d" ,&a[i]);
	}

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
		  if(a[i]>a[j])
		  {
			  t=a[i];
			  a[i]=a[j];
			  a[j]=t;
		  }
		}
	}


	printf("\enter the element to search:");
	scanf("%d",&search);

   m=bin(a,0,n,search);
   if(m==0)
	  printf("\nthe element is found:");
   else
	  printf("\nthe element is not found :");
	getch();

}




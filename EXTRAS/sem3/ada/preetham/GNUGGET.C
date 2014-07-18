
/* C program to implement GOLD NUGGET's problem */

 #include <stdio.h>
 #include <conio.h>

 int w[10],n,min,max;

 int MinMax()
 {
  int i,s;
  if(n<1)
   return 0;
  if(n==1)
  {
   min=max=0;
   return 1;
  }
  if(n%2)
  {
   min=max=0;
   s=1;
  }
  else
  {
   if(w[0]>w[1])
   {
	min=1;
	max=0;
   }
   else
   {
	min=0;
	max=1;
   }
   s=2;
  }
  for(i=s;i<n-1;i++)
  {
   if(w[i]>w[i+1])
   {
	if(w[i]>w[max])
	 max=i;
	if(w[i+1]<w[min])
	 min=i+1;
   }
   else
   {
	if(w[i+1]>w[max])
	 max=i+1;
	if(w[i]<w[min])
	 min=i;
   }
  }
  return 1;
 }

 void main()
 {
  int i;
  clrscr();
  printf("\n Enter the no. of gold nuggets to compare : ");
  scanf("%d",&n);
  printf("\n Enter the wt. of each nugget sequentially(1 to n)\n");
  for(i=0;i<n;i++)
   scanf("%d",&w[i]);
  if(MinMax())
  {
   printf("\n Minimum wt. nugget,no. = %d,%d",w[min],min);
   printf("\n Maximum wt. nugget,no. = %d,%d",w[max],max);
  }
  else
   printf("\n Can't compare !");
  getch();
 }



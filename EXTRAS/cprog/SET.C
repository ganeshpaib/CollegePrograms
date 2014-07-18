#include<stdio.h>
#include<conio.h>
main()
{
   int n,andmask,j,pos,k=~0;
   clrscr();
   printf("Enter the value of n:");
   scanf("%d",&n);
   printf("Bit pattern of %d is  ",n);
   for(j=15;j>=0;j--)
   {
      andmask=1;
      andmask<<=j;
      if(n&andmask)
      {
	 printf("1");
      }
      else
      {
	printf("0");
      }
   }
   printf("\n\nEnter the position to be set:");
   scanf("%d",&pos);
   andmask=1;
   andmask<<=pos;
   k=k^andmask;
   n=n&k;
   printf("Bit pattern after setting the position is \n");
   for(j=15;j>=0;j--)
   {
      andmask=1;
      andmask<<=j;
      if(n&andmask)
	 printf("1");
      else
	printf("0");
   }


   getch();
}

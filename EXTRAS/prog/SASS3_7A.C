#include<stdio.h>
#include<conio.h>

 main()
 {
   float a[10],s;
   int i,c=0;
   clrscr();

   printf("\n Enter Floating point numbers in A[]\n ");
   for(i=0;i<10;i++)
   {
     printf("\n A[%d] = ",i);
     scanf("%f",&a[i]);
   }
   printf("\n Enter number for search :- ");
   scanf("%f",&s);

   for(i=0;i<10;i++)
     if(s == a[i])
       c++;

   printf("\n %f is found in A[], %d times",s,c);
   getch();
 }


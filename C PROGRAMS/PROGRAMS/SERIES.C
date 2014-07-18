#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
   int i=1,x;
   float sum=0,error,t;
   clrscr();
   printf("Enter the value of x:");
   scanf("%d",&x);
   printf("Enter the value for error:");
   flushall();
   scanf("%f",&error);
   t=x;
   while(t>error)
   {
      if(i%2==1)
	 sum=sum+t;
      else
	 sum=sum-t;
      t=(t*pow(x,2))/((2*i+1)*(2*i));
      printf("The value of term:%f\n",t);
      i++;
   }
   printf("The sum of sine series is %f",sum);
   printf("The inbuilt value of sine series is %f",sin(x));
   printf("The no. of iterations:%d",i-1);
   getch();
}
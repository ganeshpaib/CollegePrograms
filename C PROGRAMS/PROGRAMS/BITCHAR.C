/* Program to accept a string from the keyboard and using the user defind
   function display the bit pattern of all the charecters in the string */

#include<stdio.h>
#include<conio.h>
void bit(char *,int);
main()
 {
  char str1[20];
  int n;
  clrscr();
  printf("Enter the string\n");
  scanf("%[^\n]",str1);
  n=strlen(str1);
  bit(str1,n);
  getch();
 }

 void bit(char *str1,int n)
  {
   int i,j, andmask,m,num;
   for(i=0;i<n;i++)
    {
     m=str1[i];
     printf("%c= ",str1[i]);
     printf("%d\n",m);
     for(j=15;j>=0;j--)
      {
       andmask=1;
       andmask=andmask<<j;
       num=m&andmask;
       (num==0)?printf("0"):printf("1");
      }
     printf("\n");
    }
  }

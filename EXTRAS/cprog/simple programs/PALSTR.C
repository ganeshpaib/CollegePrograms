 /*PROGRAM TO CHECK WHETHER ENTERED STRING IS PALINDROME OR NOT*/

#include<stdio.h>
#include<conio.h>
int pal(char *);
main()
 {
  int z;
  char str[50];
  clrscr();
  printf("ENTER A STRING: \n");
  scanf("%s",str);
  z=pal(str);
  if(z)
   printf("ENTERED STRING IS A PALINDROME\n");
  else
   printf("ENTERED STRING IS NOT A PALINDROME\n");
  getch();
 }

int pal(char *str)
 {
  int i,j=0,l1,z=1;
  l1=strlen(str);
  l1=l1-1;
  for(i=l1;i>=0;i--,j++)
    {
     if(str[i]!=str[j])
      {
       z=0;
       break;
      }
     else
      z=1;
    }
  return z;
 }
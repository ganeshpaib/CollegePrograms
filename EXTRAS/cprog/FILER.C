/*
   PROGRAM TO READ THE CONTENTS FROM THE FILE
*/

#include<stdio.h>
#include<conio.h>
main()
 {
  FILE *fptr;
  char c;
  clrscr();

  fptr=fopen("test.dat","r");

  if(fptr==NULL)
   {
    printf( "\n FILE NOT OPENED \n" );
    exit(0);
   }
  else
   {
    while((c=fgetc(fptr))!=EOF)
     {
      putchar(c);
     }
   }
  fclose(fptr);
  getch();
 }


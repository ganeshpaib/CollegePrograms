/*
  PROGRAM TO WRITE THE DATA INTO THE FILE
*/

#include<stdio.h>
#include<conio.h>
main()
{
 FILE *fptr;
 char c;
 clrscr();

 fptr=fopen("test.dat","w");

 if(fptr==NULL)
  {
   printf( "FILE UNABLE TO OPEN \n" );
   exit(0);
  }
 else
  {
   printf( "ENTER THE DATA INTO THE FILE\n" );
   while((c=getchar())!=EOF)
    {
     fputc(c,fptr);
    }
  }
 fclose(fptr);
 getch();
}

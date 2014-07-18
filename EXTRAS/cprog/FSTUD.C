/*
  PROGRAM TO CREATE FILE FOR STUDENT INFORMATION SYSTEM
*/
#include<stdio.h>
#include<conio.h>
struct student
 {
  int regno;
  char name[20];
  char addr[20];
 };

main()
 {
  struct student *stud;
  FILE *fptr;
  int sno,n,i;
  clrscr();

  printf( "\n HOW MANY STUDENT INFORMATION DO U WANT TO ENTER \n" );
  flushall();
  scanf( "%d",&sno );

  stud=(struct student *)malloc(sizeof(struct student) * sno);

  fptr=fopen("student.dat","w");
  printf(" \nEnter Student Information\n" );

  for( i = 0; i < sno; i++ )
   {
    printf( "\n" );

    printf( "\nNAME : " );
    flushall();
    scanf( "%[^\n]",stud[i].name);

    printf( "\nREGNO. : " );
    flushall();
    scanf( "%d",&stud[i].regno );

    printf( "\nADDRESS : " );
    flushall();
    scanf( "%[^\n]",stud[i].addr );
   }

  for( i = 0; i < sno; i++ )
   {

    fprintf(fptr,"\n %s\t %d\t %s\t",stud[i].name,stud[i].regno,stud[i].addr);
   }

  fclose(fptr);
  getch();
 }
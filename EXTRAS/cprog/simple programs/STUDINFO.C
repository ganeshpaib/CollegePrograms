/* Program to display student information alphabetically using structures */

struct student
 {
  int rollno,yoj;
  char name[20],branch[20],dob[10];
 }*stud,temp;

void sort_name(struct student stud[],int sno)
 {
  int i,j;

  for( i = 0; i < sno-1; i++ )
   {
    for( j = i + 1; j < sno; j++ )
     {
      if(strcmp(stud[i].name , stud[j].name) > 1)
       {
	temp = stud[i];
	stud[i] = stud[j];
	stud[j] = temp;
       }
     }
   }
 }


#include<stdio.h>
#include<conio.h>

main()
 {
  int sno,i;
  clrscr();

  printf("Enter the number of student's information to be inserted\n");
  scanf("%d",&sno);

  stud=(struct student *) malloc(sizeof(struct student) * sno);

  printf( " Enter the student information\n " );
  for(i = 0; i < sno; i++)
   {
    printf( " stud[%d] Name : ",i);
    flushall();
    scanf( "%[^\n]",stud[i].name);

    printf( " \nstud[%d] Roll No. : ",i);
    flushall();
    scanf( "%d",&stud[i].rollno);

    printf( "\n stud[%d] Branch : ",i);
    flushall();
    scanf( "%[^\n]",stud[i].branch);

    printf( "\n stud[%d] Year of join : ",i );
    flushall();
    scanf("%d",&stud[i].yoj);

    printf( "\nstud[%d] Date of birth :  ",i);
    flushall();
    scanf("%[^\n]",stud[i].dob);

   }
  sort_name(stud,sno);

  printf( "\n\t\t Student Information : \n" );
  printf( "\--------------------------------------------------\n");
  printf( " NAME\t  ROLL NO.\t BRANCH \tYOJ   \tDOB  \n ");
  printf( "\--------------------------------------------------\n");
  for( i = 0; i < sno; i++ )
   {
    printf( "\n%s\t   %d\t       %s\t     %d\t     %s",stud[i].name,stud[i].rollno,stud[i].branch,stud[i].yoj,stud[i].dob);
   }
  getch();
 }
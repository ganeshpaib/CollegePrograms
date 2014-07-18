/* Program to display student information based on
			  1. Roll number
			  2. Branch
			  3. Year of join */

struct student
 {
  int rollno,yoj;
  char name[20],branch[20];
 };

void disp_roll(struct student stud[],int sno)
 {
  int i,roll;
  printf( "Enter the roll number of the student : " );
  flushall();
  scanf( "%d",&roll);

  for( i = 0; i < sno; i++ )
   {
    if(roll==stud[i].rollno)
     {
      printf( " %s \t%d \t%s \t%d\n ",stud[i].name,stud[i].rollno,stud[i].branch,stud[i].yoj);
     }
   }
 }

void disp_branch(struct student stud[],int sno)
 {
  int i;
  char branch[20];
  printf( " Enter the Branch : \n " );
  flushall();
  scanf( "%[^\n]",branch);

  for( i = 0; i < sno; i++ )
   {
    if(strcmp(branch,stud[i].branch)==0)
     {
      printf( " %s \t%d \t%s \t%d\n ",stud[i].name,stud[i].rollno,stud[i].branch,stud[i].yoj);
     }
   }
 }



void disp_yoj(struct student stud[],int sno)
 {
  int i,yoj;
  printf( " Enter the year: \n " );
  flushall();
  scanf( "%d",&yoj);

  for(i = 0; i < sno; i++ )
   {
    if(yoj==stud[i].yoj)
     {
      printf( "%s \t%d \t%s \t%d\n",stud[i].name,stud[i].rollno,stud[i].branch,stud[i].yoj);
     }
   }

 }
#include<stdio.h>
#include<conio.h>
main()
 {
  struct student *stud;
  int sno,i,z,ch;
  clrscr();
  printf( "How many student information do you want to insert \n " );
  scanf( "%d",&sno);

  stud =(struct student *) malloc(sizeof(struct student) * sno);

  printf( "Enter student details :\n " );
  for( i = 0; i < sno; i++ )
   {
    printf( "\n");
    printf( "stud[%d] NAME : ",i);
    flushall();
    scanf( "%[^\n]",stud[i].name);

    printf( "stud[%d] ROLL NO. : ",i);
    flushall();
    scanf( "%d",&stud[i].rollno);

    printf( "stud[%d] Branch : ",i);
    flushall();
    scanf( "%[^\n]",stud[i].branch);

    printf( "stud[%d] YOJ : ",i);
    flushall();
    scanf( "%d",&stud[i].yoj);
   }

  printf( " \t\tSTUDENT DETAILS :\n " );

  printf( " -----------------------------------------------\n " );
  printf( " NAME \tROLL NO.\t BRANCH \t YOJ \n " );
  printf( " -----------------------------------------------\n " );
  for( i = 0; i < sno; i++)
   {
    printf( " %s    \t%d   \t %s   \t %d \n ",stud[i].name,stud[i].rollno,stud[i].branch,stud[i].yoj );
   }

 do
  {
   printf( " \nENTER YOUR CHOICE \n " );
   printf( "1 -> Based on roll number\n " );
   printf( "2 -> Based on branch \n " );
   printf( "3 -> Based on yoj \n " );
   flushall();
   scanf("%d",&z);

   switch(z)
    {
     case 1: disp_roll(stud,sno);
	    break;

     case 2: disp_branch(stud,sno);
	    break;

     case 3: disp_yoj(stud,sno);
	    break;
    }
   printf( "\nPRESS 7 TO CONTINUE \n " );
   flushall();
   scanf("%d",&ch);
  }while(ch==7);
  getch();
 }
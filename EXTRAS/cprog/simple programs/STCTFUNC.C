#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display(struct student *,int);
void dispreg(struct student *,int *,int);
void sort(struct student * ,int);
struct student
 {
	int regno;
	char name[20];
 }*stud;

main()
 {
	struct student temp;
	int sno,count1,reg,count2;
	clrscr();

	printf( " How many student information do u want to insert?\n " );
	scanf( "%d",&sno);

	stud=(struct student *)malloc(sizeof(struct student) * sno);

	printf( " Enter the student information \n " );
	for( count1 = 0; count1 < sno; count1++ )
	 {
		printf( "stud[%d] regno = ",count1 );
		flushall();
		scanf( "%d",&stud[count1].regno);

		printf( "stud[%d] name = ",count1 );
		flushall();
		scanf( "%[^\n]",stud[count1].name);
	 }
	printf( " \t\tSTUDENT INFORMATION \n " );
	printf( " \t-------------------------------\n " );
	printf( " \t\tReg.No.\tName\n " );
	display(stud,sno);
	/*sort(stud,sno);*/
	printf( "\n" );
/*display(stud,sno);*/

	printf( " Enter the roll number of student \n " );
	scanf("%d",&reg);
	dispreg(stud,&reg,sno);






	/*int count1,count2;*/
	for( count1 = 0; count1 < sno - 1; count1++ )
	 {
		for(count2 = count1+1; count2 < sno; count2++ )
		 {
			if(stud[count1].regno > stud[count2].regno)
			 {
				temp= stud[count1];
				stud[count1] = stud[count2];
				stud[count2] = temp;
			 }
		 }
	 }
	 display(stud,sno);
	 getch();
}

void display(struct student *stud,int sno)
 {
	int count1;
	for( count1 = 0; count1 < sno; count1++ )
	 {
		printf( "\t\t%d\t%s\n",stud[count1].regno,stud[count1].name);
	 }
 }

 void dispreg(struct student *stud,int *reg, int sno)
  {
   int count1;
   for(count1 =0;count1 < sno; count1++)
    {
     if(*(reg) == stud[count1].regno)
      printf( "\t\t%d\t%s\n",stud[count1].regno,stud[count1].name);
    }
  }
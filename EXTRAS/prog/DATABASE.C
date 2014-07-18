/* A menu Driven program for Elementry Database Management :
   To Add,Update,Delete,Display Records   */

#include<stdio.h>
#include<conio.h>

main()
{
FILE *fp,*ft;
char another,choice;

struct emp
{
 char name[20];
 int age;
 float sal;
};

  struct emp e;
  char empname[20];
  long int recsize;
  clrscr();
  fp=fopen("emp","wb+");
/*  if(fp==NULL)
  {
  fp=fopen("emp","wb+");
  }*/
  recsize=sizeof(e);

  while(1)
  {
  clrscr();
  gotoxy(10,30);
  printf("\n1. ADD RECORDS");
  gotoxy(12,30);
  printf("\n2. LIST RECORDS");
  gotoxy(14,30);
  printf("\n3. MODIFY RECORDS");
  gotoxy(16,30);
  printf("\n4. DELETE RECORDS");
  gotoxy(18,30);
  printf("\n5. EXIT");
  gotoxy(20,30);
  printf("\n\nYOUR CHOICE\n");
  fflush(stdin);
  choice=getche();

  switch(choice)
  {
    case '1':
	fseek(fp,0L,2);
	another='y';
	while(another=='y')
	{
	printf("\nEnter the records ie. name,age,salary\n");
	scanf("%s%d%f",e.name,&e.age,&e.sal);
	fwrite(&e,recsize,1,fp);
	printf("\n Add another record (Y/N)");
	fflush(stdin);
	another=getche();
	}
	break;
  case '2':
	rewind(fp);
	while(fread(&e,recsize,1,fp)==1)
	{
		printf("\n%s\t%d\t%f\n",e.name,e.age,e.sal);
	}
	getch();
	break;
  case '3':
	another='y';
	while(another=='y')
	{
	printf("\nEnter the record name which you want to Modify\n");
	scanf("%s",&empname);
	rewind(fp);
	while(fread(&e,recsize,1,fp)==1)
	{
	if(strcmp(e.name,empname)==0)
	{
	printf("\nEnter the update info(ename,age,sal)\n");
	scanf("%s%d%f",e.name,&e.age,&e.sal);
	fseek(fp,-recsize,1);
	fwrite(&e,recsize,1,fp);
	}
	}
	printf("\n Modify another record (Y/N)");
	fflush(stdin);
	another=getche();
	}
       break;
case '4':
       another='y';
       while(another=='y')
       {
       printf("\nEnter the name of employe to delete: ");
       scanf("%s",empname);
       ft=fopen("temp.dat","wb");
       rewind(fp);
       while(fread(&e,recsize,1,fp)==1)
       {
       if(strcmp(e.name,empname)!=0)
       {
       fwrite(&e,recsize,1,ft);
       }
       }
       fclose(fp);
       fclose(ft);
       remove("emp.dat");
       rename("temp.dat","emp.dat");
       fp=fopen("emp.dat","rb+");
       printf("\nDelete Another record (Y/N):");
       fflush(stdin);
       another=getche();
       }
       break;
case '5':
       fclose(fp);
       exit();
 }
 }
getch();
}



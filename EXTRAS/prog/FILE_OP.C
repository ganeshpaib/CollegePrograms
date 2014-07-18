#include<stdio.h>
#include<conio.h>
struct database
{
 int item_no;
 char it_nm[10];
 int qoh;
};

struct database item;
FILE *fp1,*fp2;
long int recsize=sizeof(item);

void main()
{
 char c;
 int opt;
 clrscr();
 printf("Enter following details of item :\n");
 printf(" It. no :");
 scanf("%d",&item.item_no);
 printf("It. nm :");
 scanf("%s",item.it_nm);
 printf("QOH : ");
 scanf("%d",&item.qoh);
 fp1=fopen("file1.dat","wb");
 fwrite(&item,recsize,1,fp1);
 fclose(fp1);
 do
 {
   clrscr();
   printf(" 1> Append\n 2> Update\n 3> Delete\n 4> Didplay\n\t->>");
   scanf("%d",&opt);
   switch(opt)
   {
    case 1: append(); break;
    case 2: update(); break;
    case 3: remov(); break;
    case 4: disp(); break;
    default: printf("\n ERROR");
   }
   clrscr();
   printf("\n Do u want to continue(y/n)?  ");
   flushall();
   c=getche();
  }while(c!='n');
 }

 append()
 {
  clrscr();
 printf("Enter following details of item :\n");
 printf(" It. no :");
 scanf("%d",&item.item_no);
 printf("It. nm :");
 scanf("%s",item.it_nm);
 printf("QOH : ");
 scanf("%d",&item.qoh);
 fp1=fopen("file1.dat","ab");
 fseek(fp1,-recsize,1);
 fwrite(&item,recsize,1,fp1);
 fclose(fp1);
 return 0;
 }

 update()
 {
  int itno,qoh;
  clrscr();
  printf(" Enter it no u want to update : ");
  scanf("%d",&itno);
  fp1=fopen("file1.dat","rb+");
  while(!feof(fp1))
  {
   fread(&item,recsize,1,fp1);
   if(item.item_no==itno)
   {
    printf("\n Enter new value for QOH :");
    scanf("%d",&qoh);
    item.qoh=qoh;
    fseek(fp1,-recsize,1);
    fwrite(&item,recsize,1,fp1);
    break;
   }
  }
  fclose(fp1);
  printf("\n File updated successfully");
  return 0;
 }

  remov()
  {
   int itno;
   printf("Enter item no u want to remove : ");
   scanf("%d",&itno);
   fp1=fopen("file1.dat","rb");
   fp2=fopen("file2.dat","wb");
   while(!feof(fp1))
   {
    fread(&item,recsize,1,fp1);
    if(item.item_no!=itno)
     fwrite(&item,recsize,1,fp2);
   }
   fclose(fp1);
   fclose(fp2);
   return 0;
  }

  disp()
  {
   clrscr();
   fp1=fopen("file1.dat","rb");
   while(!feof(fp1))
   {
    fread(&item,recsize,1,fp1);
    printf("\nItem no :%d\n It nm : %s\n QOH :%d\n",item.item_no,item.it_nm,item.qoh);
   }
   fclose(fp1);
  getch();
  return 0;
  }


/*
  PROGRAM TO SEARCH A STRING AND REPLACE THE STRING
*/

#include<stdio.h>
#include<conio.h>
main()
{
 int i,j,l1,l2,l3,z,flg=0,k;
 char str1[50],str2[50],str3[50];
 clrscr();

 printf( "ENTER A STRING\n" );
 scanf( "%[^\n]",str1);

 printf("Enter the string to be searched\n " );
 flushall();
 scanf( "%[^\n]",str2);


 l1=strlen(str1);
 l2=strlen(str2);

 do
 {
  printf( "Enter the string to be replaced \n" );
  flushall();
  scanf( "%[^\n]",str3);
  l3=strlen(str3);
 }while(l2!=l3);

 i=0;
 j=0;
 next : while(str1[i]!=str2[j])
	 {
	  i++;
	 }
  for(k=i;k<l1&&j<l2;k++)
   {
    if(str1[k]==str2[j])
     {
      flg=1;
      j++;
     }
    else
     {
      flg=0;
      j=0;
      i=k;
      goto next;
     }
   }

 if(flg==1)
  {
   z=k-l2;
   printf( "Search string found and position is %d\n",z );
   for(i=z,j=0;j<l3;i++,j++)
    {
     str1[i]=str3[j];
    }
   printf( "Resultant string is %s ",str1);
  }

 else
  printf( "Search string not found\n" );


 getch();
}


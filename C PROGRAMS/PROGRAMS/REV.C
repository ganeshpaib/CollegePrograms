#include<stdio.h>
#include<conio.h>
void rev_str(char *,int);
main()
{
 char str1[100],str2[100];
 int d,i,j;
 clrscr();
 printf( "Enter a string \n " );
 scanf( "%[^\n]",str1);
 for(d=0;str1[d]!='\0';d++);
 rev_str(str1,d);
 getch();
}
 void rev_str(char *str1,int d)
 {
 int i,j;
 char str2[100];
 j=0;
 for(i = d-1; i >= 0; i-- )
  {
    str2[j]=str1[i];
    j++;
  }
 str2[j]='\0';

 printf( "Resultant string is %s",str2);

}
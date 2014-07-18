/*Program to find the number of alphabets,digits,spaces,words and special
  charecters in the entered string*/

#include<stdio.h>
#include<conio.h>
void count(char *);
main()
 {
  char str[20];
  clrscr();
  printf("Enter a string\n");
  scanf("%[^\n]",str);
  count(str);
  getch();
 }

void count(char *str1)
 {
 int i=0,cap=0,dig=0,wspace=0,ot=0,word=1;
  while(str1[i]== ' '&&str1[i++]==' ')
   {
    wspace++;
   }
  while(str1[i]!='\0')
   {
    str1[i]=toupper(str1[i]);

    if(str1[i]>=65 && str1[i]<=90)
     cap++;
    else if(str1[i]>='0' && str1[i]<='9')
      dig++;
     else if(str1[i]==' ')
      {
      word++;
       wspace++;
       while(str1[i+1]==' '||str1[i+1]=='\t')
	{
	 wspace++;
	 i++;
	}
      }
    else
	ot++;
    i++;
   }
  printf("Number of alphabets = %d\n",cap);
  printf("Number of digits\n = %d\n",dig);
  printf("Number of spaces = %d\n",wspace);
  printf("Number of other charecters = %d\n",ot);
  printf("Number of words = %d\n",word);
  getch();
 }
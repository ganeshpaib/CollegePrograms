#include<stdio.h>
#include<conio.h>
void sort(char *[],int);
main()
 {
  char **str;
  int i,n;
  clrscr();

  printf( "Enter how many names\n " );
  scanf( "%d",&n);

  str=(char **) malloc(sizeof(char) * n * n);

  for( i = 0; i < n; i++ )
   {
    *(str + i)=(char *)malloc(sizeof(char) * n);
   }

  printf("Enter names : \n");
  for(i=0;i<n;i++)
   {
    printf("name[%d]",i);
    scanf("%s",str[i]);
   }

  sort(str,n);

  for(i=0;i<n;i++)
   {
    printf("%s\n",str[i]);
   }
  getch();
 }

void sort(char *str[],int n)
 {
  int i,j;
  char temp[10];
  for(i=0;i<n-1;i++)
   {
    for(j=i+1;j<n;j++)
     {
     if((strcmp(str[i],str[j]))>1)
      {
       strcpy(temp,str[i]);
       strcpy(str[i],str[j]);
       strcpy(str[j],temp);
      }
     }
   }
 }
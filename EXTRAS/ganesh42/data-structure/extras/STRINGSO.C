/*program to accept 10 strings and sort them*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#define NUM 10

void sort_alpha(char *name)
{
	int i,j,len;
	char temp;
	len=strlen(name);
	for(i=0;i<len-1;i++)
		for(j=i+1;j<len;j++)
			if((*(name+i)) > (*(name+j)))
			{
				temp=*(name+i);
			       (*(name+i))=(*(name+j));
			       (*(name+j))=temp;
			}
}

void sort(char **name)
{
	int i,j;
	char *temp;
	temp=(char *) malloc(sizeof(char)*20);
	for(i=0;i<NUM-1;i++)
		for(j=i+1;j<NUM;j++)
			if((strcmp(*(name+i),*(name+j)))>0)
			{
				strcpy(temp,*(name+i));
				strcpy(*(name+i),*(name+j));
				strcpy(*(name+j),temp);
			}
}
void display(char **name)
{
	int i;
	for(i=0;i<NUM;i++)
		printf("\n%s",*(name+i));
}

void main()
{
	   int i,j,x;
	   char **name;
	   clrscr();
	   name=(char **) malloc(sizeof(char)*NUM*20);
	   for(i=0;i<NUM;i++)
		*(name+i)=(char *) malloc(sizeof(char)*20);

	   printf("Enter %d strings\n",NUM);
	   for(i=0;i<NUM;i++)
	   {
		flushall();
		scanf("%s",*(name+i));
	   }
	   printf("Step 1\n");
	   sort(name);
	   display(name);
	   printf("\n\nStep 2\n");
	   for(i=0;i<NUM;i++)
		sort_alpha(*(name+i));
	   display(name);
	   printf("\n\nStep3\n");
	   sort(name);
	   display(name);
	getch();
}


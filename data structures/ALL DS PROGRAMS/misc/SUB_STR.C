#include<stdio.h>
#include<conio.h>

void main()
{
	char str[30],str1[20],str2[15],str3[35];
	int i,l,a,b,ctr=0;
	clrscr();

	printf("\n Enter String :");
	flushall();
	gets(str);

	printf("\n Enter The Starting Position :");
	scanf("%d",&a);
	printf("\n Enter Number Of Character :");
	scanf("%d",&b);

	for(l=0;str[l]!='\0';l++);

	if((a+b)>(l+1))
	{
		printf("\n Invalid ");
	}
	else
	{
		for(i=a-1;i<(a+b-1);i++)
		{
			str1[ctr++]=str[i];
		}
		str1[ctr]='\0';
	}
	printf("\n The Sub_String Is : %s",str1);

	printf("\n Enter New Sub String :");
	flushall();
	gets(str2);
	ctr=0;

	for(i=0;i<(a-1);i++)
	{
		str3[ctr++]=str[i];
	}
	for(i=0;str2[i]!='\0';i++)
	{
		str3[ctr++]=str2[i];
	}
	for(i=(a+b-1);str[i]!='\0';i++)
	{
		str3[ctr++]=str[i];
	}
	str3[ctr]='\0';

	printf("\n The New String Is : %s",str3);
getch();
}





#include<stdio.h>
#include<conio.h>

void main()
{
	char str[30],str1[30];
	int ctr=0,l,i,f=0;
	clrscr();

	printf("\n Enter The String :");
	flushall();
	gets(str);

	for(l=0;str[l]!='\0';l++);

	for(i=l-1;i>=0;i--)
	{
		str1[ctr++]=str[i];
	}
	str1[ctr]='\0';

	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=str1[i])
		{
			f=1;
			break;
		}
	}


	if(f==0)
	{
		printf("\n The String Is A Pallandrom ");
	}
	else
	{
		printf("\n The String Is Not A Pallandrom");
		printf("\n The Reverse String Is : %s",str1);
	}
getch();
}





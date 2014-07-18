#include<stdio.h>
#include<conio.h>

int str_len(char*);
void str_cpy(char[],char[]);
int str_cmp(char*,char*);
void str_cat(char *,char*);


void main()
{
	char str[30],str1[30];
	int ch,l,k;

	do
	{
		clrscr();
		printf("\n\t 1. Length Of The String ");
		printf("\n\t 2. Copy The String ");
		printf("\n\t 3. Compare Two String ");
		printf("\n\t 4. Concatenate Two String ");
		printf("\n\t 99.Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					printf("\n Enter The String :");
					flushall();
					gets(str);

					l=str_len(str);

					printf("\n The Length Of The String Is : %d",l);
					break;
			case 2:
					printf("\n Enter First String :");
					flushall();
					gets(str);
					printf("\n Enter Second String :");
					flushall();
					gets(str1);
					str_cpy(str,str1);
					break;
			case 3:
					printf("\n Enter First String :");
					flushall();
					gets(str);
					printf("\n Enter Second String :");
					flushall();
					gets(str1);
					k=str_cmp(str,str1);

					if(k==0)
					{
						printf("\n Both The Strings Are Equal ");
					}
					else if(k==1)
					{
						printf("\n The First String Is Greater Than Second String ");
					}
					else
					{
						printf("\n The Second String Is Greater Than The First String ");
					}
					break;

			case 4:
					printf("\n Enter First String :");
					flushall();
					gets(str);
					printf("\n Enter Second String :");
					flushall();
					gets(str1);

					str_cat(str,str1);
					break;
			case 99:
					exit(0);

		}
		getch();
	}while(ch!=99);
getch();
}

int str_len(char *str)
{
	int l;

	for(l=0;str[l]!='\0';l++);
	return(l);
}

int str_cmp(char *str,char *str1)
{
	int l,l1,c,f,i,j;
	l=str_len(str);
	l1=str_len(str1);

	if(l>l1)
	{
		c=l;
	}
	else
	{
		c=l1;
	}

	for(i=0;i<c;i++)
	{
		if(str[i]==str1[i])
		{
			f=0;
		}
		else if(str[i]>str[j] && str[i]!='\0')
		{
			f=1;
			break;
		}
		else
		{
			f=-1;
			break;
		}
	}

	return(f);
}

void str_cpy(char *str,char *str1)
{
	int l,l1,ctr=0,i;
	l=str_len(str);
	l1=str_len(str1);

	if(str_cmp(str,str1)<0)
	{
		printf("\n The Copied String Is : %s",str1);
	}
	else if(str_cmp(str,str1)==0)
	{
		printf("\n The Copied String Is : %s",str1);
	}
	else
	{
		for(i=0;i<l1;i++)
		{
			str[ctr++]=str1[i];
		}
		printf("\n The Copied String Is : %s",str);
	}
}

void str_cat(char *str,char *str1)
{
	int l,l1,ctr=0;
	char str2[30];


	for(i=0;str[i]!='\0';i++)
	{
		str2[ctr++]=str[i];
	}
	str2[ctr++]=" ";
	for(i=0;str1[i]!='\0';i++)
	{
		str2[ctr++]=str1[i];
	}
	str2[ctr]='\0';

	printf("\n The Combined String Is : %s",str2);
}











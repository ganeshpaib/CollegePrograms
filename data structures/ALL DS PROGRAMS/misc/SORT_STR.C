#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	char **str,*t,x;
	int m,n,i,j,ch,k,l;
	clrscr();

	printf("\n Character Size :");
	scanf("%d",&m);
	printf("\n Number Of String :");
	scanf("%d",&n);

	str=(char **)malloc(sizeof(char)*n);

	for(i=0;i<m;i++)
	{
		*(str+i)=(char *)malloc(sizeof(char)*n);
	}

	for(i=0;i<n;i++)
	{
		printf("string [%d] :",i+1);
		flushall();
		gets(*(str+i));
	}
	printf("\n");

	do
	{
		clrscr();
		printf("\n\n\t 1. Sort String ");
		printf("\n\n\t 2. Sort Character ");
		printf("\n\n\t 99. Exit");
		printf("\n Enter Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:

					for(i=0;i<n-1;i++)
					{
						for(j=i+1;j<n;j++)
						{
							if(strcmp(*(str+i),*(str+j))>0)
							{
								t=*(str+i);
								*(str+i)=*(str+j);
								*(str+j)=t;
							}
						}
					}


					printf("\n");

					for(i=0;i<n;i++)
					{
						printf("\n %s",*(str+i));
					}
					break;

			case 2:
					for(k=0;k<n;k++)
					{
						l=strlen(*(str+k));

						for(i=0;i<l-1;i++)
						{
							for(j=i+1;j<l;j++)
							{
								if(*(*(str+k)+i)>*(*(str+k)+j))
								{
									x=*(*(str+k)+i);
									*(*(str+k)+i)=*(*(str+k)+j);
									*(*(str+k)+j)=x;
								}
							}
						}
						printf("\n %s",*(str+k));
					}
					break;

		 }
		getch();
	}while(ch!=99);
getch();
}






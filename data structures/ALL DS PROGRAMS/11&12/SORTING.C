#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int *a,n,i,ch,j,t;
	clrscr();

	printf("\n Enter The Size Of The Array :");
	scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		printf("a[%d] :",i);
		scanf("%d",&a[i]);
	}
	do
	{
		clrscr();
		printf("\n\t 1. Selection Sorting ");
		printf("\n\t 2. Bubble Sorting ");
		printf("\n\t 3. Insertion Sorting ");
		printf("\n\t 99. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:

				for(i=0;i<n-1;i++)
				{
					for(j=0;j<n;j++)
					{
						if(a[i]>a[j])
						{
							t=a[i];
							a[i]=a[j];
							a[j]=t;
						}
					}
				}

				printf("\n");
				for(i=0;i<n;i++)
				{
					printf("%5d",a[i]);
				}
				break;

			case 99:
					exit(0);
		}
	getch();
	}while(ch!=99);
getch();
}




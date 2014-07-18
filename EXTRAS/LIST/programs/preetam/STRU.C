#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct student
{
		int roll;
		char name[20];
		int yoj;
}s[10];

 void roll(struct student *,int,int);
 void yoj(struct student *,int,int);

 void main()
 {
		int n,i,ch,search;
		clrscr();
		printf("\n Enter Number Of Student :");
		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
			printf("\n Enter Roll [%d]: ",i+1);
			scanf("%d",&s[i].roll);
			printf("\n Enter Name [%d] :",i+1);
			flushall();
			gets(s[i].name);
			printf("\n Enter Yoj [%d] : ",i+1);
			scanf("%d",&s[i].yoj);
			printf("\n");
		}



		do
		{
			clrscr();
			printf("\n\n\t 1.Roll Search ");
			printf("\n\n\t 2.Yoj Search ");
			printf("\n\n\t 99. Exit");
			printf("\n Enter Your Choice :");
			scanf("%d",&ch);

			switch(ch)
			{
				case 1:

						printf("\n Enter Roll Number To Be Searched :");
						scanf("%d",&search);
						roll(s,n,search);
						break;
				case 2:

						printf("\n Enter Yoj To Be Searched :");
						scanf("%d",&search);
						yoj(s,n,search);
						break;
				case 99:
						exit(0);
			}
			getch();
	}while(ch!=99);
 getch();
 }


 void roll(struct student *s,int n,int search)
 {
	int i,f=0;

	for(i=0;i<n;i++)
	{
		if(search==s[i].roll)
		{
			printf("\n %d \t %s \t %d ",s[i].roll,s[i].name,s[i].yoj);
			f=1;
		}
	}

	if(f==0)
	{
		printf("\n No Record Found ");
	}
 }

 void yoj(struct student *s,int n,int search)
 {
	int i,f=0;

	for(i=0;i<n;i++)
	{
		if(s[i].yoj==search)
		{
			printf("\n %d \t %s \t %d ",s[i].roll,s[i].name,s[i].yoj);
			f=1;
		}
	}

	if(f==0)
	{
		printf("\n No Record Found ");
	}
 }





#include<stdio.h>
#include<string.h>
 struct teacher
 {
	int tno;
	char tname[20];
	char tsubject[20];
 }t;

main()
{
 FILE *fp,*fp1;
 long int recsize;
 int choice,flag=0,num;
 clrscr();


 do
 {
	printf( "1 -> ADD NEW\n 2->DISPLAY\n 3->UPDATE\n");
	scanf("%d",&choice);

	switch(choice)
	{
	case 1:fp=fopen("teach1.dat","ab");
	       fseek(fp,0,SEEK_END);
		printf(" ENTER NO.,NAME, SUBJECT\n");
		scanf("%d%s%s",&t.tno,t.tname,t.tsubject);
		fwrite(&t,sizeof(t),1,fp);
		fclose(fp);
		break;


	case 2: fp=fopen("teach1.dat","rb");
		fseek(fp,0,SEEK_SET);
		while(fread(&t,sizeof(t),1,fp)==1)
		{
			printf("%d%s%s",t.tno,t.tname,t.tsubject);
		}
		fclose(fp);
		break;

	case 3:  fp=fopen("teach1.dat","rb+");
		printf("Enter the no. to be updated\n");
		scanf("%d",&num);
		rewind(fp);
		recsize=sizeof(t);
		while(fread(&t,sizeof(t),1,fp)==1)
		{

			if(t.tno==num)
			{
				printf("Enter the subject\n");
				scanf("%s",t.tsubject);
				fseek(fp,-recsize,SEEK_CUR);
				fwrite(&t,recsize,1,fp);
				flag=1;
			}

			if(flag==0)
				printf("Record not found\n");
		}
		fclose(fp);
		break;
	}
    }while(choice!=5);

	getch();
 }
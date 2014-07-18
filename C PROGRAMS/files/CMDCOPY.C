#include<stdio.h>
#include<conio.h>
main(int argc,char *argv[])
{
	FILE *fp,*fp1;
	char ch;
	fp=fopen(argv[1],"w");

	while((ch=getchar())!=EOF)
	{
		fputc(ch,fp);
	}
	fclose(fp);

	fp=fopen(argv[1],"r");
	fp1=fopen(argv[2],"w");

	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp1);
	}
	fclose(fp);
	fclose(fp1);

	fp= fopen(argv[2],"r");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp);

	getch();
}



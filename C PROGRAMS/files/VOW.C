#include<stdio.h>
#include<conio.h>
main()
{
	FILE *fp;
	int wd=0,ln=0,vowel=0,sp=0;
	char ch;
	clrscr();

	fp=fopen("data.dat","w");

	printf("Enter the contents\n" );
	while((ch=toupper(getchar()))!=EOF)
	{
		fputc(ch,fp);

		if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
		{
			vowel++;
		}

		else if(ch==' '||ch=='\t')
			  {
				sp++;
				while(((ch=getchar())!=EOF)&&ch==' ')
				{
					sp++;
				}


				wd++;
			  }
		else if(ch=='\n')
			  {
				ln++;
				wd++;
				sp++;
			  }


	}
	fclose(fp);
	printf(" WORD=%d\tLINES=%d\tVOWELS=%d\tSPACE=%d\t",wd,ln,vowel,sp);
	getch();
}
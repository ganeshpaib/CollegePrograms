#include <stdio.h>
#include <conio.h>
struct stores
{
	char iname[50],compname[50];
	int ino,mfgmon,mfgyear,emon,eyear;
	float iamt,iqty;
}s,s1;

void main()
{
	FILE *fp;
	fp=fopen("stock.dat","rb+");
	
	while(fread(&s,sizeof(s),1,fp)==1)
	{

			if(s.iqty>0)
				printf( "\n%s\t\t%d-%d\t\t%d-%d\t\t%f\t%f",s.compname,s.mfgmon,s.mfgyear,s.emon,s.eyear,s.iqty,s.iamt);

	}
	fclose(fp);
	getch();
}
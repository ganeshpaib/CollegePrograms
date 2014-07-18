#include<stdio.h>
#include<conio.h>
main()
{
	int ans;
	char st[50],pat[50];
	printf( "Enter the string\n" );
	flushall();
	scanf( "%[^\n]",st );

	printf( "Enter the string to check whether it is present or not\n" );
	flushall();
	scanf( "%[^\n]",pat );

	ans=nfind(st,pat);

	if(ans>0)
		printf( "SEARCH STRING IS PRESENT & POSITION IS %d\n",ans);
	else
		printf( "SEARCH STRING IS NOT FOUND\n" );

	getch();
}


int nfind(char *st, char *pat)
{
	int i,j,start=0;
	int lasts,lastp,endmatch;
	lasts=strlen(st)-1;
	lastp=strlen(pat)-1;
	endmatch=lastp;

	for(endmatch=lastp;endmatch<=lasts;endmatch++,start++)
	{
		if(st[endmatch]==pat[lastp])
		{
			for(j = 0,i = start;j < lastp&&st[i]==pat[j];i++,j++);
			if(j==lastp)
				return start;
		}
	}
	return -1;
}



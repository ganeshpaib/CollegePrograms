#include<graphics.h>
main()
{
	int gd= DETECT,gm,maxx,maxy,x=40,y=40,fst;
	char str[40];
	char *pattern[]={
						"EMPTY_FILL", "SOLID_FILL","LINE_FILL","LTSLASH_FILL",
						"SLASH_FILL","BKSLASH_FILL","LTBKXSLASH_FILL",
						"HATCH_FILL","XHATCH_FILL","INTERLEAVE_FILL",
						"WIDE_DOT_FILL","CLOSE_DOT_FILL","USER_FILL"
					};

	initgraph(&gd,&gm,"c:\\tc\\bgi");
	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,10,maxx,maxy);
	setfillstyle(5,BLUE);
	bar(x,y,maxx-68,maxy-60);
	setcolor(WHITE);
	outtextxy(175,0,"PRE-DEFINED FILL STYLES");

	for(fst=0; fst<12;fst++)
	{
		setfillstyle(fst,MAGENTA);
		bar(x,y,x+80,y+80);
		rectangle(x,y,x+80,y+80);

		itoa(fst,str,10);
		outtextxy(x,y+100,str);
		outtextxy(x,y+110,pattern[fst]);

		x=x+150;
		if(x>490)
		{
			y=y+150;
			x=40;
		}


	}
	getch();
}
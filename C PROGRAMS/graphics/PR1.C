#include<graphics.h>
main()
{
	int gd=DETECT,gm,x,y;

	initgraph(&gd,&gm,"c:\\tc\\bgi");
	outtextxy(100,10,"DEMONSTRATION OF MOVETO, MOVEREL, LINETO, LINEREL");

	x=getmaxx();
	y=getmaxy();
	rectangle(10,25,x-20,y-20);

	moveto(100,50);
	lineto(100,300);

	moverel(200,-250);
	linerel(0,250);
	getch();
}
#include<graphics.h>
main()
{
	int gd=DETECT,gm,x,y,z;
	int array[]={540,220,590,270,320,510,320,490,270,540,220};
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	x=getmaxx();
	y=getmaxy();

	/*printf("%d\n%d",x,y);*/

	setcolor(WHITE);
	rectangle(x/30,y/20,x/5,y/4);
	outtextxy(x/30+15,y/8+5,"RECTANGLE");

	circle(x/2,y/6,75);
	putpixel(x/2,y/6,WHITE);



	outtextxy(x/2-textwidth( "CIRCLE" )/2,y/6+10,"CIRCLE");
	arc(x/1.2,y/6,300,90,80);
	outtextxy(x/1.2,y/6,"ARC");

	line(x/30,10*y/15,x/6,10*y/15);
	outtextxy(x/30+10,10*y/15+10,"LINE");

	ellipse(x/2,10*y/17,0,360,100,50);
	drawpoly(6,array);
	outtextxy(515,270,"POLYGON");

	getch();
	closegraph();
	restorecrtmode();
}
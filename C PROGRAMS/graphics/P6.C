#include<graphics.h>
main()
{
	int gd= DETECT,gm,maxx,maxy,x=600,y=450;
	int array[]={ 350, 180, 400, 80, 450, 180, 350, 180 };

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,20,maxx,maxy);
	setcolor(WHITE);

	outtextxy(150,10,"FILL FIGURES USING DIFFERENT FUNCTIONS" );
	ellipse(x/4,10 * y/35,0,360,100,50);

	setfillstyle(SOLID_FILL,RED);
	fillellipse(x/4,10*y/35,100,50);

	circle(280,320,70);
	line(190,350,370,350);
	moveto(190,350);
	linerel(100,-120);
	linerel(80,120);
	floodfill(280,320,WHITE);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(192,349,WHITE);
	floodfill(368,349,WHITE);
	floodfill(290,231,WHITE);

	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(240,289,WHITE);
	floodfill(330,289,WHITE);
	floodfill(280,351,WHITE);


	getch();
}
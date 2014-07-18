#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

#include<graphics.h>
main()
{
	int gd=DETECT,gm;
	char msg[80];

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	outtextxy(100,0,"DEMONSTRATION OF MOVETO, LINETO, MOVEREL, LINEREL" );

	rectangle(0,10,639,479);   /* draws the boundary*/

	moveto(300,50);             /* moves cp */
	lineto(300,350);            /* draws line upto the point*/

	moverel(200,-300);
	linerel(0,300);

	outtextxy(104,50,"(100,50)");
	outtextxy(104,350,"(100,350)");
	outtextxy(90,375,"LINE");

	outtextxy(304,50,"(300,50)");
	outtextxy(304,350,"(300,350)");
	outtextxy(280,375,"MOVETO,LINETO");

	outtextxy(504,50,"(500,50)");
	outtextxy(504,350,"(500,350)");
	outtextxy(480,375,"MOVEREL,LINEREL");



	getch();
	closegraph();
	restorecrtmode();

}

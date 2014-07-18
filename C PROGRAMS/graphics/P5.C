#include<graphics.h>
main()
{
	int gd=DETECT,gm, maxx, maxy, x = 40, y = 40, fst;
	char str[40];
	char pattern[][8]= {
						  { 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55 },
						  { 0x33, 0x33, 0xCC, 0xCC, 0x33, 0x33, 0xCC, 0xCC },
						  { 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0 },
						  { 0x00, 0x10, 0x28, 0x44, 0x28, 0x10, 0x00, 0x00 }
					   };

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	maxx = getmaxx();
	maxy = getmaxy();
	rectangle(0,10,890,490);

	setcolor(WHITE);
	outtextxy( 175, 0, "USER DEFINED FILL STYLES" );

	for( fst = 0; fst < 4; fst++ )
	{
		setfillpattern( &pattern[fst][0],MAGENTA);
		bar( x, y, x + 80, y + 80 );
		rectangle( x, y, x + 80, y + 80 );

		itoa( fst, str, 10 );
		outtextxy(x, y + 100, str );

		x = x + 150;
		if( x > 490 )
		{
			y = y + 150;
			x=40;
		}
	}

	getch();
	closegraph();
	restorecrtmode();
}
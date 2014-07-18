#include<graphics.h>
main()
{
	int gd=DETECT, gm, x=10,y,i,j;
	char str[]="FONTS";
	char *demo[]={
					"DEFAULT FONT DEMO",
					"TRIPLEX FONT DEMO",
					"SMALL FONT DEMONSTRATION",
					"SANSSERIF FONT DEMO",
					"SCRIPT FONT DEMO"
				 };
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setcolor(WHITE);

	for(i=0;i<=5;i++)
	{
		rectangle(0,20,639,479);
		settextstyle(0,0,1);
		outtextxy(150,10,demo[i]);
		y=30;
		for(j=1;j<=4;j++)
		{
			settextstyle(i,HORIZ_DIR,j);
			outtextxy(10,y,str);
			y+=(textheight(str)+10);
		}
		settextstyle(i,VERT_DIR,0);
		setusercharsize(2,1,3,2);
		outtextxy(10,y,str);
		getch();
		clearviewport();
	}
	getch();
}
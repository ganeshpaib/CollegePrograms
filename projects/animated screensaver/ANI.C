#include<graphics.h>
#include<alloc.h>
void main()
{
	int gd=DETECT,gm,area,x=25,y=25,ch,xdirn=1,ydirn=1;
	int maxx,maxy;
	char *buff;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	circle(50,50,25);
	floodfill(50,50,WHITE);

	area=imagesize(25,25,75,75);
	buff=malloc(area);
	getimage(25,25,75,75,buff);

	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,20,maxx,maxy);
	outtextxy(250,10,"ANIMATION");

	while(1)
	{
		if(kbhit())
		{
			ch=getch();

			if(ch=='\r')
			{
				xdirn=xdirn*(-1);
				ydirn=ydirn*(-1);
			}
			else
			{
				if(ch==27)
					break;
			}
		}


	putimage(x,y,buff,XOR_PUT);
	delay(0);
	x=x+(xdirn*1);
	y=y+(ydirn*1);
	putimage(x,y,buff,XOR_PUT);

	if(x>maxx-50||x<0)
	{
		sound(50);
		delay(10);
		nosound();
		xdirn*=-1;
	}
	if(y>maxy-50||y<20)
	{
		sound(50);
		delay(10);
		nosound();
		ydirn*=-1;
	}
  }
	getch();
}

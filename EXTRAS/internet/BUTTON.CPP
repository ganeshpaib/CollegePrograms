/**************************************************************************\
** You can use this Sample Of making Button in any of your projects,in    **
** anyform you like, modify it according to your needs, but give credit   **
** where credit is due.                                                   **
** This code was written to provide template code for programmers         **
** interested in developing GUI Applications In C/C++.                    **
**									  **
** If you have any questions or comments regarding any of my programs     **
** please contact me at my email address                                  **
**                                                                        **
**			     -Author:  Ankit Nitin                        **
**				       ฿฿฿฿฿฿฿฿฿฿฿		          **
**				       <ankit_nitin@rediffmail.com>       **
**				       http://www.anitin.co.nr/           **
**									  **
** ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ **
**			       SPECIFICATIONS				  **
**			       ฿฿฿฿฿฿฿฿฿฿฿฿฿฿                             **
** For running this sample either copy file "EGAVGA.BGI" located in your  **
** /Lib directory to the  current working directory where this sample is  **
** kept or change the path in initgraph().                                **
**             This sample is made and tested on Turbo C++ 3.0            **
/**************************************************************************/

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ   Mouse Handling Routines   ออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */

int m_status;
int m_x;
int m_y;

/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ        Mouse  Reset        อออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */

int m_reset(void)
{
   _AX=0;
   geninterrupt(0x33);
   return(_AX);
}
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ        Mouse  Enable       อออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */

void m_enable(void)
{
   _AX=1;
   geninterrupt(0x33);
}
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ        Mouse  Disable      อออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */


void m_disable(void)
{
   _AX=2;
   geninterrupt(0x33);
}

/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ    Mouse  Read Position    อออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */

void m_read(void)
{
   _AX=3;
   geninterrupt(0x33);
   m_status=_BX;
   m_x=_CX;
   m_y=_DX;

}

/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ     Set Horizontal Range   อออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */

void m_HRange(int xmin, int xmax)
{
   _AX=7;
   _CX=xmin;
   _DX=xmax;
   geninterrupt(0x33);
}
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ      Set Vertical Range    อออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */

void m_VRange(int ymin, int ymax)
{
   _AX=8;
   _CX=ymin;
   _DX=ymax;
   geninterrupt(0x33);
}

/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
/* อออออออออออออออออออออ         Main Function      อออออออออออออออออออออ */
/* ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */


int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   clrscr();
   printf("\n\n\n This is a program that shows you how to make a Button in C/C++.\n Great Sample for starters to learn about GUI application developemnt in C/C++.\n\n\n This Sample is made by ANKIT NITIN. \n\n This Sample is  available at http://www.anitin.co.nr/.\n\n\n\n Press Any Key To Continue . . . ");
   getch();
   initgraph(&gdriver, &gmode, "");    //change path here and put path where EGAVGA.BGI is

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   int l=100,t=100,r=170,b=120;
   setfillstyle(1,3);
   bar(70,70,200,150);
   outtextxy(220,400,"Press any key to continue ");
   char ch;
   outtextxy(120,430,"This Sample is Download From http://www.anitin.co.nr");
   m_HRange(0,620); // set range
   m_VRange(0,500); // set range
   m_enable();
   int k=1;

   while(!kbhit()) //while no key is pressed
   {
    m_read();       // Read Position
    if(m_status==1) // Left click
     {
	    m_disable();
	    setfillstyle(1,7);

	    bar(l,t,r+1,b+2);   // shift right and bottom border
	    setcolor(12);
	    outtextxy(l+11,t+6,"Button");

	    setcolor(9);
	    rectangle(l,t,r+2,b+2); // Display Message
	    outtextxy(500,50,"Click Made");
	    m_enable();
	    delay(100);
	     k=1;
     }

   if(k==1 && m_status!=1)     // Refresh If a click was made
   {
	   m_disable();
	   setfillstyle(1,7);
	   bar(l,t,r,b);
	   setcolor(12);
	   outtextxy(l+10,t+5,"Button");
	   setcolor(9);
	   line(l,b+1,r+1,b+1); // Draw Border
	   line(l,b+2,r+1,b+2); // Draw Border
	   line(r+1,t,r+1,b+1); // Draw Border
	   line(r+2,t,r+2,b+1); // Draw Border
	   setfillstyle(1,0);
	   bar(500,5,600,75);
	   outtextxy(120,430,"This Sample is Download From http://www.anitin.co.nr");
	   m_enable();
	   k=0;
    }
   }
   outtextxy(120,430,"This Sample is Download From http://www.anitin.co.nr");
   getch(); // Clear stdin
   closegraph();
  printf ("\n\n\nThis Demo program was provided by, Ankit Nitin.");
  printf ("\nIf you wish to contact me to ask how something works,");
  printf ("\nor to report this doesn't work on a certain compiler,");
  printf ("\nthen you can reach me at: http://www.anitin.co.nr");

  getch();

   return 0;
}

#include<stdio.h>
#include<conio.h>
#include "p2.c"
void display();
void main()
{
 extern x;
 clrscr();
 display();
 printf( "We are in file %d" ,x);

 getch();
}
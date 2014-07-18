#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdarg.h>

int add(int argc,...)
{
	int result=0;
	va_list args;

	va_start(args,argc);
	for(int i=0;i<argc;i++)
		result+=va_arg(args,int);
	va_end(args);
	return result;
}

void main()
{
	cout << "\nRESULT : "<<add(2,10,20);
	cout << "\nRESULT : "<<add(4,2,3,4,5);
}

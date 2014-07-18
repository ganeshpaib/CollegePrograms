#include<iostream.h>
#include<conio.h>
#include<stdarg.h>

int sum(int argc,...)
{
	va_list va;
        int result=0;

        va_start(va,argc);

        for(int i=0;i<argc;i++)
        {
        	result+=va_arg(va,int);
        }
        va_end(va);
        return(result);
}


void main()
{
	clrscr();

        cout<<"\n"<<sum(3,10,30,40)<<endl;
getch();
}
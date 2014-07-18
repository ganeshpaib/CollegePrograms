#include<iostream.h>
#include<conio.h>
#include<stdarg.h>
int add(int argc,...)
{
	int total=0;

        va_list args;
        va_start(args,argc);

        for(int i=0;i<argc;i++)
        {
        	total+=va_arg(args,int);
        }
        va_end(args);
        return(total);

}
template <class T>
void swap(T &a,T &b)
{
	T t;
        t=a;
        a=b;
        b=t;
        cout<<a<<endl<<b;
}
void main()
{
struct std
{
int i;
}a,b;
	clrscr();
        cin>>a.i;
        cin>>b.i;
        swap(a.i,b.i);
        cout<<a.i<<endl;
    	cout<<b.i;
        cout<<add(2,a.i,b.i);

getch();
}





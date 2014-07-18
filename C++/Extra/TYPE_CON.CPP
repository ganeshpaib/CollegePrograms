#include<iostream.h>
#include<conio.h>
#include<string.h>

class String
{
	char str[20];
        public:
        	String(){str[0]='\0';}
                String(char *s){strcpy(str,s);}
                operator char*(){return(str);}

};

void main()
{
	clrscr();

        String s("HELLO");
        cout<<s;
getch();
}
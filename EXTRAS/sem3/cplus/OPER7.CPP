#include "header.cpp"

class String
{
	char str[20];
	public:
		String()
		{
			str[0]='\0';
		}
		String(char *msg)
		{
			strcpy(str,msg);
		}

		 operator char*()
		{
			return str;
		}
		void disp()
		{
			cout<<str;
		}
};

void main()
{
	clrscr();
	String str1;
	char *stri="hi my name is ganesh";
	str1=stri;

	str1.disp();
	String str2="i love my india";

	stri=str2;
	cout<<stri;
	getch();
}
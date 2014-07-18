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

		void get()
		{
			cout << " \nEnter String : ";
			cin >> str;
		}
		String operator + (String s2)
		{
			return String (strcat(str,s2.str));
		}
		void disp()
		{
			cout<<str;
		}
};

void main()
{
	String s1,s2,s3;

	s1.get();
	s2.get();

	s1.disp();
	s2.disp();

	s3=s1+s2;
	s1.disp();
	getch();
}


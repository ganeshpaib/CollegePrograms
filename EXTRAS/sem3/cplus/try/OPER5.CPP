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
			cout << "\nEnter the string : " ;
			cin >> str;
		}

		char* disp()
		{
			return str;
		}

		int operator < (String s2)
		{
			if((strcmp(str,s2.str)<0))
				return 1;
			else
				return 0;
		}
		int operator > (String s2)
		{
			if((strcmp(str,s2.str)>0))
				return 1;
			else
				return 0;
		}

};

void main()
{
	String s1, s2;
	s1.get();
	s2.get();
	if(s1>s2)
		cout<<s1.disp()<<" > " <<s2.disp();
	if(s1<s2)
		cout<<s1.disp()<<" < " <<s2.disp();
	else
		cout<<s1.disp()<<" = " <<s2.disp();
	getch();
}
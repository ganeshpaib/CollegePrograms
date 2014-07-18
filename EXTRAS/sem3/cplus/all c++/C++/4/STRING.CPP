#include<iostream.h>
#include<conio.h>
#include<string.h>

class String
{
	char str[20];
	public:
		String(){strcpy(str,"NULL");}
		String(char *s){strcpy(str,s);}
		int operator >(String);
		int operator <(String);
		int operator ==(String);
		void read();
		void display();
};

void String::read()
{
	cin>>str;
}

void String::display()
{
	cout<<"\n"<<str;
}

int String::operator >(String s)
{
	if(strcmp(str,s.str)>0)
		return(1);
	else
		return(0);
}

int String::operator <(String s)
{
	if(strcmp(str,s.str)<0)
		return(1);
	else
		return(0);
}

int String::operator ==(String s)
{
	if(strcmp(str,s.str)==0)
		return(1);
	else
		return(0);
}


void main()
{
	String s1,s2;
	clrscr();
	cout<<"\n Enter First String :";
	s1.read();
	cout<<"\n Enter Second String :";
	s2.read();

	if(s1>s2)
	{
		cout<<"\n First String Is Larger"<<endl;
	}
	else if(s1<s2)
	{
		cout<<"\n Second String Is Larger"<<endl;
	}
	else if(s1==s2)
	{
		cout<<"\n Both The String Is Equal"<<endl;
	}
getch();
}





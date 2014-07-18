#include<iostream.h>
#include<conio.h>
#include<string.h>

class String
{
	char str[30];
        public:
        	String(){strcpy(str,"NULL");}
                String(char *s){strcpy(str,s);}
                void read();
                void display();
                String operator +(String s);
};

void String::read()
{
	cout<<"\n Enter String : ";
        cin>>str;
}
void String::display()
{
	cout<<"\n The String Is : "<<str<<endl;
}

String String::operator +(String s)
{
	int i,j;
        String temp;

        for(i=0;str[i]!='\0';i++)
        {
        	temp.str[i]=str[i];
        }
        for(j=0;s.str[j]!='\0';j++)
        {
        	temp.str[i+j]=s.str[j];
        }
        temp.str[i+j]='\0';

        return(temp);
}

void main()
{
	String s1,s2,s3;
        clrscr();
        s1.read();
        s2.read();
        s3=s1+s2;
        s3.display();
getch();
}


#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>

void main()
{
	int d=0,l=0,s=0;
	char str[' '];
	clrscr();
	ofstream out("c:\\test.dat");
	if(!out)
	{
		cout<<"\n Error";
		exit(0);
	}
	cout<<"\n Enter String :";
	cin.getline(str,30,'\n');
	out<<str;
	out.close();

	ifstream in("c:\\test.dat");
	if(!in)
	{
		cout<<"\n Error";
		exit(0);
	}
	in.getline(str,30,'\n');

	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]>=48 && str[i]<=56)
		{
			d++;
		}
		else if((str[i]>=65 && str[i]<=90)||(str[i]>=97 && str[i]<=122))
		{
			l++;
		}
		else
		{
			s++;
		}
	}
	in.close();

	cout<<d<<"\t"<<l<<"\t"<<s<<endl;
getch();
}
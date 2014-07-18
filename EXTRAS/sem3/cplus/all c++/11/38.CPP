#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>

void main()
{
	clrscr();
	char str[100],ch;
	int di,li,sp,al;
	di=al=sp=li=0;


	ofstream out("c:\\test.txt");
	if(!out)
	{
		cout<<"\n Error in Opening File";
		getch();
		exit(0);
	}

	do
	{
		cin.getline(str,100,'\n');
		out<<str;
		cout<<"\n Do U Want To Continue (Y/N): ";
		cin>>ch;
		cin.ignore();
	}while(ch=='Y'||ch=='y');

	out.close();

	ifstream in("c:\\test.txt");

	while(1)
	{
		in.getline(str,100,'\n');

		for(int i=0;str[i]!='\0';i++)
		{
			if((str[i]>=65 && str[i]<=90)||(str[i]>=97 && str[i]<=122))
			{
				al++;
			}
			else if(str[i]>=48 && str[i]<=56)
			{
				di++;
			}
			else if(str[i]==' ')
			{
				sp++;
			}
		}
		li++;

		if(in.eof())
			break;
	}
	in.close();

	cout<<"\n Total Number Of Alphabet " <<al;
	cout<<"\n Total Number Of Digits "<<di;
	cout<<"\n Total Number Of Lines "<<li;
	cout<<"\n Total Number Of Spaces "<<sp;
getch();
}



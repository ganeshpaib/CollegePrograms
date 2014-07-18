#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<ctype.h>

void main()
{
	ofstream out;
	ifstream in;
	clrscr();
	int ch,ctr=0;
	char str[100],c;

	do
	{
		clrscr();
		cout<<"\n\t 1... Create File ";
		cout<<"\n\t 2... Display (No Character) ";
		cout<<"\n\t 3... Display (Upper Case) ";
		cout<<"\n\t 4... Total Word & Space ";
		cout<<"\n\t 5... Total Palindromes ";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				out.open("c:\\test.txt");

				do
				{
					cin.getline(str,100,'\n');
					out<<str<<endl;
					cout<<"\n Do U Want To Continue (y/n)";
					cin>>c;
					cin.ignore();
				}while(c=='y'||c=='Y');
				out.close();
				break;
			case 2:
				int f=0;
				in.open("c:\\test.txt");

				while(1)
				{
					f=0;
					in.getline(str,100,'\n');

					for(int i=0;str[i]!='\0';i++)
					{
						f=1;
						if(str[i]!=' ')
							ctr++;
					}

					if(f==1)
					{
						cout<<endl<<str<<"\t"<<ctr;
					}
					ctr=0;
					if(in.eof())
						break;
				}
				in.close();
				break;
			case 3:
				in.open("c:\\test.txt");

				while(1)
				{
					in.getline(str,100,'\n');

					if(islower(str[0]))
					{
						str[0]=str[0]-32;
					}
					cout<<endl<<str;

					if(in.eof())
						break;
				}
				in.close();
				break;
			case 4:
				int wd=0;
				int sp=0;
				in.open("c:\\test.txt");
				ifstream in1("c:\\test.txt");

				while(1)
				{
					in>>str;
					wd++;

					in1.getline(str,100,'\n');

					for(int i=0;str[i]!='\0';i++)
					{
						if(str[i]==' ')
						{
							sp++;
						}
					}

					if(in.eof())
						break;
				}
				in1.close();
				in.close();
				cout<<"\n Word : "<<wd;
				cout<<"\n Spaces : "<<sp;

				break;


			case 5:
				in.open("c:\\test.txt");
				int pal=0;
				char temp[' '];

				while(1)
				{
					in>>str;
					strcpy(temp,str);

					if(strcmp(str,strrev(temp))==0)
					{
						cout<<endl<<str;
						pal++;
					}

					if(in.eof())
						break;
				}
				in.close();
				cout<<"\n Total Palindromes Are : "<<pal;
				break;

			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

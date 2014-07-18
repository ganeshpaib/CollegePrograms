#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>

void main()
{
	clrscr();
	ofstream out1,out2;
	ifstream in;
	char str[100],c;
	int ch,i;

	do
	{
		clrscr();
		cout<<"\n\t 1... Copy (Suppressing Space)";
		cout<<"\n\t 2... Encryption to Decryption ";
		cout<<"\n\t 3... Display (Suppressing Special Character)";
		cout<<"\n\t 99.. Exit ";
		cout<<"\n Enter Your Choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				out1.open("c:\\test1.txt");
				out2.open("c:\\test2.txt");

				do
				{
					cin.getline(str,100,'\n');
					out1<<str;
					cout<<"\n Do U Want To Continue (y/n) :";
					cin>>c;
					cin.ignore();
				}while(c=='y'||c=='Y');
				out1.close();
				in.open("c:\\test1.txt");

				while(1)
				{
					in.getline(str,100,'\n');

					for(i=0;str[i]!='\0';i++)
					{
						if(str[i]!=' ')
						{
							out2<<str[i];
						}
					}
					if(in.eof())
						break;
				}
				out2.close();
				in.close();
				break;
			case 3:
				in.open("c:\\test1.txt");

				while(1)
				{
					in.getline(str,100,'\n');

					for(i=0;str[i]!='\0';i++)
					{
						if((str[i]>=48 && str[i]<=56)||(str[i]>=65 && str[i]<=90)||(str[i]>=97 && str[i]<=122)||str[i]==' ')
						{
							cout<<str[i];
						}
					}

					if(in.eof())
					{
						break;
					}
				}
				in.close();
				break;


			case 99:
				exit(0);
		}
		getch();
	}while(ch!=99);
	getch();
}


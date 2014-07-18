#include "header.cpp"

void main()
{
	char ch[100], opt;
	int i;

	ofstream outf("c:\\tc\\sem3\\filetry\\test\\f1.dat" );
	while(1)
	{
		cout << "Enter data... : ";
		cin.getline(ch,50,'\n');
		i=0;

			outf<<ch;
		cin.ignore();
		cout<< "Do u wanna enter some more data???(Y/N)\n" ;
		cin.get(opt);
		if(opt=='n'||opt=='N')
			break;
	}
	outf.close();

	ifstream inf("c:\\tc\\sem3\\filetry\\test\\f1.dat" );
	if(!inf)
		cout<< "error...\n";
	while(!inf.eof())
	{
		inf.getline(ch,50,'\n');
		i=0;
		while(ch[i]!='\0')
		{
			cout<<ch[i];
			i++;
		}
	}
	inf.close();
	getch();
}

#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>

int count[26];

void count_alpha()
{
   ifstream file;
   file.open("text.txt");
   char c;
   while(file)
   {
     file.get(c);
     if(c>='a'&&c<='z')
     count[c-'a']++;
     else
     if(c>='A'&&c<='Z')
     count[c-'A']++;
   }
   file.close();
   cout<<"\n Frequency of Alphabets are: ";
   for(int i=0;i<26;i++)
   printf("\n %c | %c = %d",i+65,i+97,count[i]);
}

void low_upp()
{
  ifstream file;
  file.open("text.txt");
  char c;

  while(file)
  {
	file.get(c);

    if(c>='a'&&c<='z')
    c=c-' ';
    else
    if(c>='A'&&c<='Z')
    c=c+' ';
    cout<<c;
  }
  file.close();
}

void disp_10ch()
{
  ifstream file;
  file.open("text.txt");
  char c;
  int cnt=0;
  while(file)
  {
    file.get(c);
    if(cnt==10)
    {
      cout<<"\n";
      cnt=0;
    }
    cout<<c;
    cnt++;
  }
  file.close();
}

void char_freq()
{
  ifstream file;
  file.open("text.txt");
  char c,ch;
  int flag=0,cnt=0;
  cout<<"\n Enter the Character to get the Frequency: ";
  cin>>ch;
  while(file)
  {
    file.get(c);
    if(c==ch)
    {
      flag=1;
      cnt++;
    }
  }
  file.close();
  if(flag==1)
  {
    cout<<"\n Frequency of character"<<ch<<"is: "<<cnt;
  }
  else
  cout<<"\n Invalid Character";
}

void main()
{
  clrscr();
  ofstream file;
  file.open("text.txt");
  char buffer[80];
  int c;
  cout<<"\n Enter the Single Line Text in the File: \n";
  cin.getline(buffer,80,'\n');
  file<<buffer;
  file.close();
  do
  {
    cout<<"\n\n ....SELECT THE OPTION BELOW.... \n\n"
	<<"\t 1> Count the each Alphabet present in File\n"
	<<"\t 2> Convert Lower to Upper case\n"
	<<"\t 3> Display 10 Character per Line\n"
	<<"\t 4> Count the Frequency of the Particular character\n"
	<<"\t 5> Exit\n";
    cout<<"\n\t--->";
    cin>>c;
    switch(c)
    {
      case 1:  count_alpha();
	       break;
      case 2:  low_upp();
	       break;
      case 3:  disp_10ch();
	       break;
      case 4:  char_freq();
	       break;
      case 5:  exit(0);
	       break;
    }
    getch();
    clrscr();
  }while(c!=5);
 getch();
}

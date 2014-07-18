
#include<fstream.h>
#include<conio.h>

char buffer[80];

void count_opt()
{
   ifstream file;
   file.open("count.txt");
   int c=0,a=0,d=0,l=0,s=0;
   while(file)
   {
     file.getline(buffer,80,'\n');
     for(int i=0;buffer[i]!='\0';i++)
     {
      c++;
      if((buffer[i]>='a'&&buffer[i]<='z') || (buffer[i]>='A'&&buffer[i]<='Z'))
      a++;
      else
      if(buffer[i]>='0' && buffer[i]<='9')
      d++;
      else
      if(buffer[i]==' ')
      s++;
     }
     l++;
     c++;
   }
   l--;
   c--;
   file.close();
   cout<<"\n No of Characters: "<<c
       <<"\n No of Alphabets : "<<a
       <<"\n No of Digits    : "<<d
       <<"\n No of Lines     : "<<l
       <<"\n No of Spaces    : "<<s;
}

void main()
{
  clrscr();
  ofstream file;
  file.open("count.txt");
  char ch=' ';
  cout<<"\n Enter the Multiline Text Into the File: \n";
  cout<<"\n To Close the File  (Press Esc)..\n";
  while(ch!=27)
  {
    cin.getline(buffer,80,'\n');
    file<<buffer<<"\n";
    ch=getch();
  }
  file.close();
  count_opt();
  getch();
}


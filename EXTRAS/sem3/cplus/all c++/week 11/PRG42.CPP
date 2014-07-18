/* Program 42 */

#include<fstream.h>
#include<conio.h>
#include<stdio.h>

char buffer[80];

void copy_text()
{
  ifstream file("text1.txt");
  ofstream file1("text2.txt");
  while(file)
  {
    file.getline(buffer,80,'\n');
    for(int i=0;buffer[i]!='\0';i++)
    if(buffer[i]!=' ')
    file1.put(buffer[i]);
    file1<<"\n";
  }
  file.close();
  file1.close();
  cout<<"\n The Content of the New file After suppressing the spaces are: \n";
  file.open("text2.txt");
  while(file)
  {
    file.getline(buffer,80,'\n');
    cout<<buffer<<"\n";
  }
  file.close();
}

void main()
{
  ofstream file;
  file.open("text1.txt");
  char ch=' ';
  cout<<"\n Enter the Multi-Line Text into the File (Press Esc after Writing): \n";
  while(ch!=27)
  {
    cin.getline(buffer,80,'\n');
    file<<buffer<<"\n";
    ch=getch();
  }
  file.close();
  copy_text();
  getch();
}

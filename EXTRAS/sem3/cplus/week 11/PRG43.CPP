// Program No. 43

 #include <fstream.h>
 #include <conio.h>

 char buffer[80];

 void encrypt()
 {
  ifstream infile("cipher.txt");
  cout<<"\n After encrypting, the text file is : \n";
  while(infile)
  {
   infile.getline(buffer,80,'\n');
   cout<<buffer<<"\n";
  }
  infile.close();
 }

 void decrypt()
 {
  ifstream infile("cipher.txt");
  cout<<"\n After decrypting, the text file is : \n";
  while(infile)
  {
   infile.getline(buffer,80,'\n');
   for(int i=0;buffer[i];i++)
    buffer[i]=buffer[i]-50;
   cout<<buffer<<"\n";
  }
  infile.close();
 }

 void main()
 {
  ofstream outfile;
  outfile.open("cipher.txt");
  char ch=' ';
  clrscr();
  cout<<"\n Enter a multi-line text below\n";
  cout<<"( Note : to terminate reading after any line press ESC )\n\n";
  while(ch!=27)
  {
   cin.getline(buffer,80,'\n');
   for(int i=0;buffer[i];i++)
    buffer[i]=buffer[i]+50;
   outfile<<buffer<<"\n";
   ch=getch();
  }
  outfile.close();
  encrypt();
  decrypt();
  getch();
 }


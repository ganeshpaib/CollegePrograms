#include<iostream.h>
#include<conio.h>
#include<process.h>

class String
{
	public:
        	char st[20];
        public:
        	String()
                {
                	st[0]='\0';
                }
                String(char s[])
                {

                    for(int i=0;s[i]!='\0';i++)
                    {
                    	st[i]=s[i];
                    }
                        st[i]='\0';
                }
                void display();
                void input();
                int strlength();
                void cat(String);
};

void String::display()
{
	cout<<"\n The String Is  : "<<st<<endl;
}

void String::input()
{
	cout<<"\n Enter String : ";
        cin>>st;
}

int String::strlength()
{
	for(int l=0;st[l]!='\0';l++);
        return(l);
}

void String::cat(String s)
{
	for(int i=0;st[i]!='\0';i++);
        for(int j=0;s.st[j]!='\0';j++)
        {
        	st[i+j]=s.st[j];
        }
        st[i+j]='\0';
}

void String::cpy(String s)
{
	int l1,l2;

        for(l1=0;st[l1]!='\0';l1++);
        for(l2=0;s.st[l2]!='\0';l2++);

       	for(int i=0;i<l2;i++)
        {
               	st[i]=s.st[i];
        }
        }
        else
        {
        	for(i=0;i<l2;i++)
                {
                	st[i]=


void main()
{
clrscr();
	String s[2];
        int n,ch;
        //cout<<"\n Enter Number Of String : ";
        //cin>>n;

        //s=new String*[n];

        do
        {
        	clrscr();
                cout<<"\n\t 1... Input String ";
                cout<<"\n\t 2... Display ";
                cout<<"\n\t 3... Length";
                cout<<"\n\t 4... Copy";
                cout<<"\n\t 5... Cat";
                cout<<"\n\t 99.. Exit";
                cout<<"\n Enter Your Choice : ";
                cin>>ch;

                switch(ch)
                {
                	case 1:
                                for(int i=0;i<2;i++)
                                {
                                	cout<<"\n Enter String :";
                                        cin>>s[i].st;

                                }
                                break;
                        case 2:
                        	cout<<endl;
                        	for(i=0;i<2;i++)
                                {
                                	cout<<"\t "<<s[i].st;
                                }
                                break;
                        case 3:
                        	cout<<endl;

                                for(i=0;i<2;i++)
                                {
                                	cout<<"\n Length : "<<s[i].strlength();
                                }
                                break;
                        case 5:
                        	s[0].cat(s[1]);
                                break;
                        case 4:
                        	s[0].cpy(s[1]);
                                break;

                        case 99:
                        	exit(0);
                                break;
                }
                getch();
        }while(ch!=99);
getch();
}






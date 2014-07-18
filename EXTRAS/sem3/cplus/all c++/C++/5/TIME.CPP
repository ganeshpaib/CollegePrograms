#include<iostream.h>
#include<conio.h>
#include<process.h>

int flag=0,x,flag1=0;

class Time12
{
	int t12;
        public:
        	Time12(){t12=0;}
                Time12(int a){t12=a;}
                void read(){cin>>t12;}
                void display()
		{
                	if(t12==0)
                        	cout<<"\n Invalid Time";
                        else if(flag1==1)
                        	cout<<t12<<" AM"<<endl;
                        else if(flag1==0)
                        	cout<<t12<<" PM"<<endl;

                }
                getdata(){return(t12);}
};

class Time24
{
	int t24;
        public:
        	Time24(){t24=0;}
                Time24(int a){t24=a;}
                void read(){cin>>t24;}
                void display(){cout<<t24<<endl;}

                operator Time12()
                {
                	if(t24>=1 && t24<=12)
                        {
                        	flag1=1;
                        	return Time12(t24);
                        }
                        else if(t24>=13 && t24<=24)
                        {
                        	return Time12(t24-12);
                        }
                        else
                        {
                        	return Time12(0);
                        }
                }
                Time24(Time12 ti12)
                {
                	x=ti12.getdata();

                        if(x>=1 && x<12 && flag==1)
                        {
                        	t24=x;
                        }
                        else if(x>=1 && x<=12 && flag==0)
                        {
                        	t24=x+12;
                        }
                        else
                        {
                        	cout<<"\n Invalid Time";
                        }

                }
};

void main()
{
	int ch;
        Time12 ti12;
        Time24 ti24;
        clrscr();

        do
        {
        	clrscr();
                flag=0;
                cout<<"\n\t 1... 24 Hrs To 12 Hrs ";
                cout<<"\n\t 2... 12 Hrs To 24 Hrs(AM) ";
                cout<<"\n\t 3... 12 Hrs To 24 Hrs(PM) ";
                cout<<"\n\t 99.. Exit";
                cout<<"\n Enter Your Choice :";
                cin>>ch;

                switch(ch)
                {
                	case 1:
                        	cout<<"\n Enter Time In 24 Hour :";
                                ti24.read();
                                ti12=ti24;
                                ti12.display();
                                break;
                        case 2:
                        	flag=1;
                        	cout<<"\n Enter Time In 12 Hours (AM) :";
                                ti12.read();
                                ti24=ti12;
                                ti24.display();
                                break;
                        case 3:
                        	cout<<"\n Enter Time In 12 Hours (PM) :";
                                ti12.read();
                                ti24=ti12;
                                ti24.display();
                                break;
                	case 99:
                        	exit(0);
                                break;
                }
                getch();
        }while(ch!=99);
getch();
}






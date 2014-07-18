#include<iostream.h>
#include<conio.h>
#include<process.h>

class Date
{
	int h,m,s;
        public:
        	Date(){h=0;m=0;s=0;}
                Date(int h,int m,int s){this->h=h;this->m=m;this->s=s;}
                void read();
                void display();
                Date operator+(Date);
                Date operator++();
                Date operator++(int);
                void operator +=(Date);
                Date operator -(Date);
                Date operator --();
                Date operator --(int);
                void operator -=(Date d);

};

void Date::read()
{
	cout<<"\n Enter Hour : ";
        cin>>h;
        cout<<"\n Enter Min : ";
        cin>>m;
        cout<<"\n Enter Sec :";
        cin>>s;
}

void Date::display()
{
	cout<<"\n"<<h<<":"<<m<<":"<<s<<endl;
}

Date Date::operator +(Date d)
{
	Date temp;
        temp.h=h+d.h;
        temp.m=m+d.m;
        temp.s=s+d.s;

        if(temp.s>=60)
        {
        	temp.m+=temp.s/60;
                temp.s=temp.s%60;
        }
        if(temp.m>=60)
        {
        	temp.h+=temp.m/60;
                temp.m=temp.m%60;
        }
        return temp;
}

Date Date::operator ++()
{
	Date temp;
        h=h+1;
        m=m+1;
        s=s+1;

        if(s>=60)
        {
        	m+=s/60;
                s=s%60;
        }
        if(m>=60)
        {
        	h+=m/60;
                m=m%60;
        }
        temp.h=h;
        temp.m=m;
        temp.s=s;

        return(temp);
}

Date Date::operator ++(int)
{
	Date temp;
        temp.h=h;
        temp.m=m;
        temp.s=s;

        h=h+1;
        m=m+1;
        s=s+1;

        if(s>=60)
        {
        	m+=s/60;
                s=s%60;
        }
        if(m>=60)
        {
        	h+=m/60;
                m=m%60;
        }
        return(temp);
}

void Date:: operator +=(Date d)
{
        h=h+d.h;
        m=m+d.m;
        s=s+d.s;

        if(s>=60)
        {
        	m+=s/60;
                s=s%60;
        }
        if(m>=60)
        {
        	h+=m/60;
                m=m%60;
        }
}

Date Date::operator -(Date d)
{
	Date temp;
        temp.h=h-d.h;
        temp.m=m-d.m;
        temp.s=s-d.s;

        if(temp.s>=60)
        {
        	temp.m+=temp.s/60;
                temp.s=temp.s%60;
        }
        if(temp.m>=60)
        {
        	temp.h+=temp.m/60;
                temp.m=temp.m%60;
        }
        return temp;
}

Date Date::operator --()
{
	Date temp;
        h=h-1;
        m-=1;
        s-=1;
        if(s>=60)
        {
        	m+=s/60;
                s=s%60;
        }
        if(m>=60)
        {
        	h+=m/60;
                m=m%60;
        }
        temp.h=h;
        temp.m=m;
        temp.s=s;

        return(temp);
}

Date Date::operator --(int)
{
	Date temp;
        temp.h=h;
        temp.m=m;
        temp.s=s;

        h=h-1;
        m=m-1;
        s=s-1;

        if(s>=60)
        {
        	m+=s/60;
                s=s%60;
        }
        if(m>=60)
        {
        	h+=m/60;
                m=m%60;
        }
        return(temp);
}

void Date:: operator -=(Date d)
{
        h=h-d.h;
        m=m-d.m;
        s=s-d.s;

        if(s>=60)
        {
        	m+=s/60;
                s=s%60;
        }
        if(m>=60)
        {
        	h+=m/60;
                m=m%60;
        }
}


void main()
{
	Date d1,d2,d3;
        int ch;
        clrscr();
        do
        {
        	clrscr();
                cout<<"\n\t 1...'+' ";
                cout<<"\n\t 2...'-' ";
                cout<<"\n\t 3...'++(prefix)' ";
                cout<<"\n\t 4...'++(postfix)' ";
                cout<<"\n\t 5...'--(prefix)' ";
                cout<<"\n\t 6...'--(postfix)' ";
                cout<<"\n\t 7...'+=' ";
                cout<<"\n\t 8...'-=' ";
                cout<<"\n\t 99.. Exit";
                cout<<"\n Enter Your Choice : ";
                cin>>ch;

                switch(ch)
                {
                	case 1:
                        	cout<<"\n Enter First Date \n";
       				d1.read();
      			        cout<<"\n Enter Second Date \n";
     			        d2.read();
    			        d3=d1+d2;
      			        d3.display();
                                break;
                        case 2:
                        	cout<<"\n Enter First Date \n";
                                d1.read();
                                cout<<"\n Enter Second Date \n";
                                d2.read();
                                d3=d1-d2;
                                d3.display();
                                break;
                        case 3:
                        	cout<<"\n Enter Date\n";
                                d1.read();
                                d2=++d1;
                                d2.display();
                        	break;
                        case 4:
                        	cout<<"\n Enter Date \n";
                                d1.read();
                                d2=d1++;
                                cout<<"\n First Date \n";
				d1.display();
                                cout<<"\n Second Date \n";
				d2.display();
                                break;
                        case 5:
                        	cout<<"\n Enter Date \n";
                                d1.read();
                                d2=--d1;
                                d2.display();
                                break;
                        case 6:
                        	cout<<"\n Enter Date \n";
                                d1.read();
                                d2=d1--;
                                cout<<"\n First Date \n";
                                d1.display();
                                cout<<"\n Second Date \n";
                                d2.display();
                                break;

                        case 7:
                        	cout<<"\n Enter First Date \n";
                                d1.read();
                                cout<<"\n Enter Second Date \n";
                                d2.read();
                                d1+=d2;
                                d1.display();
                                break;
                        case 8:
                        	cout<<"\n Enter First Date \n";
                                d1.read();
                                cout<<"\n Enter Second Date \n";
                                d2.read();
                                d1-=d2;
                                d1.display();
                                break;

                        case 99:
                        	exit(0);
                                break;
                }
                getch();
        }while(ch!=99);
getch();
}




#include<iostream.h>
#include<conio.h>

class Time
{
	private:
        	int hour;
                int min;
                int sec;
        public:
        	Time()
                {
                	hour=min=sec=0;
                }
                Time(int h,int m,int s)
                {
                	hour=h;
                        min=m;
                        sec=s;
                }
                void add(Time,Time);
                void display();
};

void Time::display()
{
	cout<<endl<<"\n\t"<<hour<<":"<<min<<":"<<sec<<endl;
}

void Time::add(Time t1,Time t2)
{
	hour=t1.hour+t2.hour;
        min=t1.min+t2.min;
        sec=t1.sec+t2.sec;

        if(min>=60)
        {
        	hour+=(min/60);
                min%=60;
        }
        if(sec>=60)
        {
        	min+=(sec/60);
                sec%=60;
        }
}

void main()
{
clrscr();
	int h[2],m[2],sec[2];
        Time t3;

        for(int i=0;i<2;i++)
        {
		cout<<"\n Enter Hour :";
    	        cin>>h[i];
       	        cout<<"\n Enter Min : ";
      	        cin>>m[i];
      	        cout<<"\n Enter Sec : ";
        	cin>>sec[i];
                cout<<endl;

        }
        Time t1(h[0],m[0],sec[0]);
        Time t2(h[1],m[1],sec[1]);

        t3.add(t1,t2);
        t3.display();
getch();
}



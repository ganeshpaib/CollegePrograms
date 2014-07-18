#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
class Time_24
{
 private:
	int hor;
	int min;
 public:
		Time_24(){hor = 24 ;min =30;}
		Time_24(int hor,int min){this->hor = hor;this->min = min;}
		int get_hor(){ return hor;}
		int get_min(){return min;}
		void display(){cout<<"Time in 24_hour format is : "<< hor<<" :: "<<min; }
};
class Time_12
{
private:
	int h;
	int m;
	char str[' '];
public:
		Time_12(){h = 12;m = 0;strcpy(str,"am");}
		Time_12(int h,int m,char s[]){this->h = h;this->m = m;strcpy(str,s);}
		Time_12(Time_24 t){
					if(t.get_hor() > 12)
					{   h=t.get_hor()-12 ;
					    m=t.get_min();
					    strcpy(str,"pm");
					}
					else
					{
						h=t.get_hor();
						m=t.get_min();
						strcpy(str,"am");
					}
				}
		operator Time_24() { if(strcmp(str,"am")==0)
						return (Time_24(h,m));
				      else
					return(Time_24( h+12 , m ) );
				   }
		void display(){cout<<"Time in 12_hour format is : "<< h <<" :: "<< m ;cout<<"->"<<str;}
};
void main()
{
     int h,m,opt;
     char str[' '];
	do
	{

		clrscr();
		cout<<"\n\nEnter 1 for Convert input time into 12_hour format: ";
		cout<<"\nEnter 2 for Convert input time into 24_hour Format ; ";
		cout<<"\nEnter 99 for exit;";
		cout<<"\nEnter the option: ";
		cin>>opt;
		switch( opt )
		{
		 case 1:cout<<endl<<"Enter the data in 24 Time format: ";
			cout<<endl<<"Hour :";
			cin>>h;
			cout<<endl<<"Min: ";
			cin>>m;
			Time_24 t1(h,m);
			Time_12 t2=t1;
			cout<<"\n24 format time is...";
			t1.display();
			cout<<"\n12 format time is ...";
			t2.display();
			break;
		 case 2:cout<<"Enter  the time in 12 hour format ;";
			cout<<endl<<"Hor :";
			cin>>h;
			cout<<endl<<"Min: ";
			cin>>m;
			cout<<endl<<"Enter pm / am : ";
			cin>>str;
			Time_12 t3(h,m,str);
			Time_24 t4=t3;
			cout<<endl<<"12 format time is .." ;
			t3.display();
			cout<<endl<<"24 format time is...";
			t4.display();
			break;
	       }
	       getch();
	}while(opt!=99);
getch();
}
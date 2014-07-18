#include<iostream.h>
#include<conio.h>

class Count
{
	private:
        	 static int ctr,c;
        public:
        	Count()
                {
                	ctr++;
                }
                ~Count()
                {
                	c++;
                }
                void display()
                {
                	cout<<"\n\n Total Instances : "<<ctr<<endl;
                        cout<<"\n Destructor : "<<c<<endl;
                        cout<<"\n Total Active Objects : "<<ctr-c<<endl;

                }
};

int Count::ctr=0;
int Count::c;

void main()
{

clrscr();
	int n,m;
        cout<<"\n Enter Number Of Objects :";
        cin>>n;
        Count **c1;

        c1=new Count*[n];

	for(int i=0;i<n;i++)
        {
        	c1[i]=new Count();
        }

        cout<<"\n Enter Number Of Objects You Want To Delete :";
        cin>>m;

        if(m>n)
        {
        	cout<<"\n Error"<<endl;
        }
        else
        {

        	for(i=0;i<m;i++)
       	        {
        		delete(c1[i]);
       		 }
                c1[0]->display();
        }


getch();
}
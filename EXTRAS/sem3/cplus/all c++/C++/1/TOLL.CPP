#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>

class Tollbooth
{
	private:
        	unsigned int pcar;
                double totalamount;
                unsigned int npcar;
                unsigned int total;
        public:
        	void payingcar(int n);
                void display();

                Tollbooth()
                {
                	pcar=0;
                        npcar=0;
                        total=0;
                        totalamount=0;
                }
};

void Tollbooth::payingcar(int n)
{
	total++;

	if(n==1)
        {
		pcar++;
      	  	totalamount+=0.50;
       	        cout<<"\n Car Paid...";
                sleep(1);
        }
        else if(n==2)
        {
        	npcar++;
                cout<<"\n Car Not Paid";
                sleep(1);
        }
}

void Tollbooth::display()
{
	cout<<"\n\n Total Number Of Cars : "<<total<<endl;
        cout<<"\n Total Paid Cars : "<<pcar<<endl;
        cout<<"\n Total Unpaid Cars : "<<npcar<<endl;
	cout<<"\n Total Amount :"<<totalamount<<endl;
}

void main()
{
	clrscr();
        Tollbooth t;
        char ch;

        while(1)
        {
        	clrscr();
                cout<<"\n\t1... Paying Car (Y) ";
                cout<<"\n\t2... Not Paying Car (N) ";
        	cout<<"\n\t3... Exit (Esc)";
                cout<<"\n\n Enter Choice : ";
                ch=getche();

                if(ch=='Y'||ch=='y')
                {
                	t.payingcar(1);
                }
                else if(ch=='N'||ch=='n')
                {
                	t.payingcar(2);
                }
                else if(ch==27)
                {
                	t.display();
                        break;
                }
        }
getch();
}




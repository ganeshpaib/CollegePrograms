#include<iostream.h>
#include<conio.h>

class Sample
{
	int i;
        public:
        	Sample(){i=0;}
                Sample(int i){this->i=i;}
                Sample operator +(Sample s){return Sample(i+s.i);}
                Sample operator -(Sample s){return Sample(i-s.i);}
                Sample operator *(Sample s){return Sample(i*s.i);}
                void read();
                void display();
};

void Sample::read()
{
	cout<<"\n Enter Value : ";
        cin>>i;
}
void Sample::display()
{
	cout<<"\n"<<i;
}

void main()
{
	Sample s1,s2,s3;
        clrscr();
        cout<<"\n Add"<<endl;
        s1.read();
        s2.read();
        s3=s1+s2;
        s3.display();
        cout<<"\n Sub"<<endl;
        s1.read();
        s2.read();
        s3=s1-s2;
        s3.display();
        cout<<"\n Mul"<<endl;
        s1.read();
        s2.read();
        s3=s1*s2;
        s3.display();
getch();
}


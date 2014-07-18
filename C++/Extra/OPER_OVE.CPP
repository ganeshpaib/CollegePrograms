#include<iostream.h>
#include<conio.h>

class Sample
{
	private:
        	int i;
        public:
        	Sample(){i=0;}
                Sample(int i){this->i=i;}
                Sample operator ++(){return Sample(++i);}
                Sample operator ++(int){return Sample(i++);}
                void display(){ cout<<endl<<i<<endl;}
};

void main()
{
clrscr();
	Sample s1,s2,s3;
        s1.display();
        cout<<"\n";
        s3=++s1;
        s1.display();
        s3.display();
        s3=s1++;
        s3.display();
        s1.display();
getch();
}

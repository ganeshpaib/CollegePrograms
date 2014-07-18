#include<iostream.h>
#include<conio.h>
#include<process.h>

class Complex
{
	int r,i;
        public:
        	Complex(){r=0,i=0;}
                Complex(int r,int i){this->r=r,this->i=i;}
                void read();
                void display();
                Complex operator+(Complex);
                Complex operator-(Complex);
                Complex operator*(Complex);
                Complex operator/(Complex);
};

Complex Complex::operator+(Complex c)
{
	return Complex(r+c.r,i+c.i);
}
Complex Complex::operator-(Complex c)
{
	return Complex(r-c.r,i-c.i);
}
Complex Complex::operator*(Complex c)
{
	Complex temp;
	temp.r=(r*c.r)-(i*c.i);
        temp.i=(r*c.i)+(i*c.r);
        return temp;
}
Complex Complex::operator /(Complex c)
{
	Complex temp;
        float qt;
        qt=c.r*c.r+c.i*c.i;
        temp.r=(r*c.r+i*c.i)/qt;
        temp.i=(i*c.r-r*c.i)/qt;
        return(temp);
}

void Complex::read()
{
	cout<<"\n Enter Real Part : ";
        cin>>r;
        cout<<"\n Enter Imaginary Part : ";
        cin>>i;
}
void Complex::display()
{
	cout<<r<< " i"<<i<<endl;
}

void main()
{
	int ch;
        Complex c1,c2,c3;
        clrscr();
        cout<<"\n Enter First Complex Number \n";
        c1.read();
        cout<<"\n Enter Second Complex Number \n";
        c2.read();

        do
        {
        	clrscr();
                cout<<"\n\t 1... Add";
                cout<<"\n\t 2... Sub ";
                cout<<"\n\t 3... Mul";
                cout<<"\n\t 4... Div";
                cout<<"\n\t 99.. Exit";
                cout<<"\n Enter Your Choice :";
                cin>>ch;

                switch(ch)
                {
                	case 1:
                        	c3=c1+c2;
                                c3.display();
                                break;
                        case 2:
                        	c3=c1-c2;
                                c3.display();
                                break;
                        case 3:
                        	c3=c1*c2;
                                c3.display();
                                break;
                        case 4:
                        	c3=c1/c2;
                                c3.display();
                                break;
                        case 99:
                        	exit(0);
                                break;
                }
                getch();
        }while(ch!=99);
getch();
}




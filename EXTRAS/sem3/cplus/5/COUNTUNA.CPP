#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class Count
{
  private:
	  int i;
  public:
	Count(){i=0;}
	Count(int i){this->i=i;}
	Count operator++();
	Count operator--();
	void display();

};
void main()
{
	int opt,n;
	do
	{
		clrscr();
	    cout<<endl<<"Enter 1 for enter the value: ";
	    cout<<endl<<"Enter 2 for upward counting: ";
	    cout<<endl<<"Enter 3 for downward counting: ";
	    cout<<endl<<"Enter 99 for exit: ";
	    cout<<endl<<"Enter the option: ";
	    cin>>opt;
	    switch(opt)
	    {
		case 1:cout<<"Enter the one value: ";
			cin>>n;
			Count c(n);
			break;
		case 2:Count c2=++c;
			c2.display();
			break;
		case 3:Count c3=--c;
			c3.display();
			break;
	    }
	    getch();
	}while(opt!=99);
	getch();
}
Count Count ::  operator++()
{
Count temp;
    temp.i=i+1;
    return temp;
}
Count Count :: operator--()
{
	Count temp;
	temp.i=i-1;
	return temp;
}
void Count :: display()
{
	cout<<"The value of i is : "<<i;

}
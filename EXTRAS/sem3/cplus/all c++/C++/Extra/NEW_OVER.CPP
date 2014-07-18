#include<iostream.h>
#include<conio.h>

class Array
{
	int *a;
        public:
        	void *operator new(size_t size)
                {
                	Array *aa;
                        aa=::new Array();
                        aa->a=new int[2];
                        cout<<size<<endl;
                        return aa;
                }

                void operator delete(void *ar)
                {
                	Array *ptr;
                        ptr=(Array *)ar;
                        //delete (int *)ptr->a;
                        ::delete ptr;

                        cout<<"\n Object Deleted.."<<endl;
                }
                void readdata();
                void display();
};

void Array::readdata()
{
	cout<<"\n Enter First Data :";
        cin>>a[0];
        cout<<"\n Enter Second Data :";
        cin>>a[1];
}

void Array::display()
{
	cout<<"\n"<<a[0]<<a[1]<<endl;
}

void main()
{
	clrscr();
        Array *arr=new Array;
        arr->readdata();
        arr->display();
        delete arr;
getch();
}






#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#define MAX 20

class Array
{
	private:
		int *a;
		int n;
	public:
		void inputarray();
		void display();
		int largest();
		float average();
		void sort();
		Array()
		{
			n=2;
			a=(int *)malloc(sizeof(int)*n);
		}

		Array(int x)
		{
			n=x;
			a=(int *)malloc(sizeof(int)*n);
		}

};

void Array::inputarray()
{

	for(int i=0;i<n;i++)
	{
        	cout<<"\n a["<<i+1<<"] :";
                cin>>a[i];
        }
        cout<<"\n Added...";

}

void Array::display()
{
	for(int i=0;i<n;i++)
        {
        	cout<<"\t"<<a[i];
        }
}

int Array::largest()
{
	int temp[MAX],t;

        for(int i=0;i<n;i++)
        {
        	temp[i]=a[i];
        }

        for(i=0;i<n-1;i++)
        {
        	for(int j=i+1;j<n;j++)
                {
                	if(temp[i]>temp[j])
                        {
                        	t=temp[i];
                                temp[i]=temp[j];
                                temp[j]=t;
                        }
                }
        }

        return(temp[n-1]);
}

float Array::average()
{
	float sum;

        for(int i=0;i<n;i++)
        {
        	sum+=a[i];
        }

        return(sum/n);
}

void Array::sort()
{
	int temp;

	for(int i=0;i<n-1;i++)
        {
        	for(int j=i+1;j<n;j++)
                {
                	if(a[i]>a[j])
                        {
                        	temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                }
        }
}

void main()
{
clrscr();

        int ch,n;
        cout<<"\n Enter Number Of Element : ";
        cin>>n;
        Array ar(n);

        do
        {
        	clrscr();
                cout<<"\n\t 1... Input";
                cout<<"\n\t 2... Display ";
                cout<<"\n\t 3... Largest ";
                cout<<"\n\t 4... Average ";
                cout<<"\n\t 5... Sort";
                cout<<"\n\t 99.. Exit";
                cout<<"\n Enter Your Choice : ";
                cin>>ch;

                switch(ch)
                {
                	case 1:
                                ar.inputarray();
                                break;
                        case 2:
                        	ar.display();
                                break;
                        case 3:
                        	cout<<"\n Largest Number Is :"<<ar.largest()<<endl;
                                break;
                        case 4:
                        	cout<<"\n Average : "<<ar.average()<<endl;
                                break;
                        case 5:
                        	ar.sort();
                                ar.display();
                                break;
                        case 99:
                        	exit(0);
                                break;
                }
                getch();
        }while(ch!=99);
getch();
}



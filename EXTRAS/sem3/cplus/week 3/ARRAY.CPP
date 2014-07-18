#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
#include<process.h>

int i,j,largest;
class Array
{
	int n;
	int *arr;

	public:
		Array()
		{
			arr=(int *)malloc(sizeof(int)*1);
		}

		Array(int m)
		{
			n=m;
			arr=(int *)malloc(sizeof(int)*n);
		}

		void get_data()
		{
			for( i = 0; i < n; i++ )
			{
				cout << "arr["<<i<<"]= ";
				cin >> arr[i];
			}
		}
		void disp_data()
		{
			for( i = 0; i < n; i++ )
			{
				printf( "%d\t",arr[i] );
			}
		}

		int greatest()
		{
			largest=arr[0];
			for(i = 1; i < n; i++ )
			{
				if(largest<arr[i])
				{
					largest=arr[i];
				}
			}
			return largest;
		}

		void sort()
		{
			int temp;
			for( i = 0; i < n-1; i++ )
			{
				for( j = i+1; j < n; j++ )
				{
					if( arr[i] > arr[j] )
					{
						temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
					}
				}
			}
		}

		float avg()
		{
			int tot=0;
			float avg=0;

			for( i = 0; i < n; i++ )
			{
				tot=tot + arr[i];
			}
			avg=tot/n;
			return avg;
		}

};

void main()
{
	int m, ch;
	float avg;
	clrscr();

	do
	{
		cout << "\n1 -> Create Array \n" ;
		cout << "\n2 -> Display Array\n" ;
		cout << "\n3 -> Largest Value\n" ;
		cout << "\n4 -> Sort Array\n " ;
		cout << "\n5 -> AVERAGE\n" ;
		cout << "\n99 -> Exit\n" ;
		cout << "\nEnter ur choice..... : ";
		cin >> ch;

		switch(ch)
		{
			case 1: clrscr();
					cout << "\nEnter the size of the array : ";
					cin >>m;

					Array array(m);

					array.get_data();
					getch();
					break;

			case 2: clrscr();
					cout << "Contents of the array : ";
					array.disp_data();
					getch();
					break;

			case 3: clrscr();
					largest=array.greatest();
					cout << "\n\nLARGEST VALUE IS :"<< largest;
					getch();
					break;

			case 4: clrscr();
					cout << "Elements in sorted order : ";
					array.sort();
					array.disp_data();
					getch();
					break;

			case 5: clrscr();
					avg=array.avg();
					cout << "AVERAGE : "<<avg;
					getch();
					break;

			case 99: exit(0);
		}

	}while(ch!=99);

	getch();
}
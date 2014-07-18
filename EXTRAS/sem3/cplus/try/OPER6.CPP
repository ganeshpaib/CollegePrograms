#include "header.cpp"

class Sample
{
	int *arr;
	public:
		void get()
		{
			for(int i = 0; i < 5; i++ )
			{
				cout<<"\nvalue[<<i<<"<<"] = ";
				cin>>arr[i];
			}
		}
		void disp()
		{
			for(int i = 0; i < 5; i++ )
				cout<<"\n"<<arr[i];
		}

		void* operator new(size_t size)
		{
			Sample *ptr;
			ptr=::new Sample;
			ptr->arr=new int[5];
			return ptr;
		}

		void operator delete(void *a)
		{
			Sample *ptr;
			ptr=(Sample *)a;
			delete (int *)ptr->arr;
			::delete a;
		}


};

void main()
{
	Sample *a;
	a=new Sample();
	cout<<"Enter the values : ";
	a->get();
	a->disp();
	delete a;
	getch();
}
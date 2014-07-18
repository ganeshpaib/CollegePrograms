#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct student
{
	int rollno;
	char name[' '];
}*s;

void swap(int &,int &);
void swap(float &,float &);
void swap(char *,char *);
void swap(struct student *);

void main()
{
	int ch,n1,n2,i;
	float f1,f2;
	char str1[10],str2[10];
	clrscr();

	s=(struct student*)malloc(sizeof(struct student)*2);

	do
	{
		clrscr();
		cout<<"\n\t 1... Swap Integer ";
		cout<<"\n\t 2... Swap Float ";
		cout<<"\n\t 3... Swap Structure ";
		cout<<"\n\t 4... Swap String ";
		cout<<"\n\t 99.. Exit";
		cout<<"\n Enter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\n Enter First Number : ";
				cin>>n1;
				cout<<"Enter Second Number : ";
				cin>>n2;

				swap(n1,n2);

				cout<<"\n NEW VALUES "<<endl;
				cout<<"\n First Number : "<<n1;
				cout<<"\n Second Number : "<<n2;

				break;
			case 2:
				cout<<"\n Enter First Number : ";
				cin>>f1;
				cout<<"Enter Second Number : ";
				cin>>f2;

				swap(f1,f2);

				cout<<"\n NEW VALUES "<<endl;
				cout<<"\n First Number : "<<f1;
				cout<<"\n Second Number : "<<f2;
				break;
			case 4:
				cout<<"\n Enter First String : ";
				cin>>str1;
				cout<<"\n Enter Second String : ";
				cin>>str2;

				swap(str1,str2);

				/*cout<<"\n NEW VALUES "<<endl;
				cout<<"\n First String : "<<str1;
				cout<<"\n Second String : "<<str2;*/
				break;
			case 3:
				for(i=0;i<2;i++)
				{
					cout<<"\n Enter Roll_No : ";
					cin>>s[i].rollno;
					cout<<"\n Enter Name : ";
					cin>>s[i].name;
				}

				swap(s);

				for(i=0;i<2;i++)
				{
					cout<<"\n"<<s[i].rollno<<"\t"<<s[i].name<<endl;
				}
				break;

			case 99:
				exit(0);
				break;
		}
		getch();
	}while(ch!=99);
getch();
}

void swap(int &n1,int &n2)
{
	int temp;
	temp=n1;
	n1=n2;
	n2=temp;
}

void swap(float &n1,float &n2)
{
	float temp;
	temp=n1;
	n1=n2;
	n2=temp;
}

void swap(char *str1,char *str2)
{
	char *temp;
	//long int t;
	//t=&str1;
	cout << "\nstr1 = " << &str1 << "  str2 = " << &str2;
	temp=str1;
	str1=str2;
	str2=temp;
	cout << "\nstr1 = " << &str1 << "  str2 = " << &str2;
	cout<<"\n NEW VALUES "<<endl;
	cout<<"\n First String : "<<str1;
	cout<<"\n Second String : "<<str2;

}

void swap(struct student *s)
{
	struct student temp;

	temp=s[0];
	s[0]=s[1];
	s[1]=temp;
}











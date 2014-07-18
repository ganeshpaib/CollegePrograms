#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>

class Matrix
{
	int row,col,**mat;
	public:
	Matrix(){}
	Matrix(int ,int );
	int operator ==(Matrix );
	friend ostream& operator <<(ostream& ,Matrix );
	friend istream& operator >>(istream& ,Matrix & );
	Matrix operator +(Matrix);
};
int Matrix:: operator ==(Matrix m1)
{
	if(row!=m1.row||col!=m1.col)
	{
		clrscr();
		cout<<"\nADDITION IS NOT POSSIBLE ";
		return 0;
	}
	else return 1;
}
Matrix Matrix:: operator +(Matrix m1)
{

		Matrix temp(row,col);
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				temp.mat[i][j]=mat[i][j]+m1.mat[i][j];
			}
		}
		return temp;


}
Matrix::Matrix(int a,int b)
{

	row=a;
	col=b;
	mat=new int* [row];
	for(int i=0;i<row;i++)
		mat[i]=new int[col];
}
ostream& operator<<(ostream& out,Matrix m)
{
	clrscr();
	for(int i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
		{
			cout<<"\t"<<m.mat[i][j];
		}
		cout<<endl;

	}
		return out;
}

istream& operator>>(istream& in,Matrix &m)
{
	clrscr();
	for(int i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
		{
			cout<<"mat["<<i<<"]["<<j<<"] = ";
			cin>>m.mat[i][j];
		}
	}
		return in;
}

int a,b;
void read()
{
	clrscr();
	cout<<"ENTER THE SIZE -> ";
	cin>>a>>b;
}
void main()
{

	read();
	Matrix m(a,b);
	cin>>m;
	cout<<m;
	getch();
	read();
	Matrix m1(a,b),m3;
	cin>>m1;
	cout<<m1;
	getch();
	if(m==m1)
	{
		m3=m+m1;
		cout<<m3;
	}
	getch();
}



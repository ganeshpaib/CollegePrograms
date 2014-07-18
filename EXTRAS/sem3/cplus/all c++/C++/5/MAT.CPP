#include<iostream.h>
#include<conio.h>

class Matrix
{
	int **mat,row,col;
	public:
		Matrix();
		Matrix(int,int);
		Matrix operator +(Matrix );
		Matrix operator *(Matrix );
		int operator ==(Matrix );
		friend ostream& operator <<(ostream &,Matrix);
		friend istream& operator >>(istream &,Matrix &);
};

istream& operator >>(istream&in,Matrix &m)
{

	for(int i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
		{
			cout<<"mat["<<i<<"]["<<j<<"] :";
			in>>m.mat[i][j];
		}
		cout<<endl;
	}
	return(in);
}

ostream& operator <<(ostream&out,Matrix m)
{
	for(int i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
		{
			out<<"\t"<<m.mat[i][j];
		}
		cout<<endl;
	}
	return out;
}

int Matrix::operator ==(Matrix m)
{
	if(row==m.row && col==m.col)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


Matrix::Matrix()
{
	row=col=2;
	mat=new int*[row];

	for(int i=0;i<row;i++)
	{
		mat[i]=new int[col];
	}
}

Matrix::Matrix(int r,int c)
{
	row=r;
	col=c;
	mat=new int*[row];
	for(int i=0;i<row;i++)
	{
		mat[i]=new int[col];
	}
}

Matrix Matrix::operator +(Matrix m)
{
	Matrix temp(row,col);

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			temp.mat[i][j]=mat[i][j]+m.mat[i][j];
		}
	}
	return(temp);
}

Matrix Matrix::operator *(Matrix m)
{
	Matrix temp(row,col);

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			temp.mat[i][j]=0;
			for(int k=0;k<col;k++)
			{
				temp.mat[i][j]+=mat[i][k]*m.mat[k][j];
			}
		}
	}

	return(temp);
}

void main()
{
	clrscr();
	int row,col;
	cout<<"\n Enter Row :";
	cin>>row;
	cout<<"\n Enter Col :";
	cin>>col;

	Matrix m1(row,col),m2(row,col),m3(row,col);

	if(m1==m2)
	{
		cout<<"\n ADDITION \n";
		cout<<"\n First Matrix \n";
		cin>>m1;
		cout<<"\n Second Matrix \n\n";
		cin>>m2;
		m3=m1+m2;
		cout<<endl<<endl;
		cout<<m3;
		cout<<endl<<endl;
		cout<<"\n MULTIPLICATION \n";
		cout<<"\n First Matrix \n";
		cin>>m1;
		cout<<"\n Second Matrix \n\n";
		cin>>m2;
		m3=m1*m2;
		cout<<endl;
		cout<<m3;
	}
	else
	{
		cout<<"\n ERROR"<<endl;
	}
getch();
}




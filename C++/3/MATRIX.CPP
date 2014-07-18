#include<iostream.h>
#include<conio.h>

class Matrix
{
	int row,col,**mat;
	public:
		Matrix();
		Matrix(int,int);
		void read();
		//void display();
		int operator ==(Matrix);
		Matrix operator +(Matrix);
		Matrix operator -(Matrix);
		void operator <<(Matrix);
};

Matrix::Matrix()
{
	row=col=2;
	mat=new int *[row];
	for(int i=0;i<row;i++)
	{
		mat[i]=new int[col];
	}
}

Matrix::Matrix(int row,int col)
{
	this->row=row;
	this->col=col;
	mat=new int *[row];
	for(int i=0;i<row;i++)
	{
		mat[i]=new int[col];
	}
}

void Matrix::read()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"mat["<<i<<"][ "<<j<<"] : ";
			cin>>mat[i][j];
		}
		cout<<endl;
	}
}

void Matrix::operator <<(Matrix m)
{
	cout<<"\n ADD \n";

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<mat[i][j]<<"\t";

		}
		cout<<endl;
	}

	cout<<"\n SUB \n";

	for(i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
		{
			cout<<m.mat[i][j]<<"\t";

		}
		cout<<endl;
	}
}

int Matrix::operator ==(Matrix m)
{
	int f=0;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(mat[i][j]!=m.mat[i][j])
			{
				f=1;
				break;
			}
		}
	}

	if(f==1)
	{
		return(0);
	}
	else
	{
		return(1);
	}
}

Matrix Matrix::operator +(Matrix m)
{
	Matrix temp;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			temp.mat[i][j]=mat[i][j]+m.mat[i][j];
		}
	}
	return(temp);
}

Matrix Matrix::operator -(Matrix m)
{
	Matrix temp;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			temp.mat[i][j]=mat[i][j]-m.mat[i][j];
		}
	}
	return(temp);
}


void main()
{
	//int r,c,n,temp;
	Matrix m1,m2,m3,m4;
	clrscr();

	cout<<"\n Read First Matrix \n";
	m1.read();
	cout<<"\n Read Second Matrix \n";
	m2.read();

	if(m1==m2)
	{
		m3=m1+m2;
		m4=m1-m2;
		//cout<<"\n ADD \n";
		//m3.display();
		 m3<<m4;
		//cout<<"\n SUB \n";
		//m4.display();
	}
	else
	{
		cout<<"\n Not Possible \n";
	}
getch();
}




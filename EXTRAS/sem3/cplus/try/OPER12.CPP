#include "header.cpp"
int i,j,k;

class Matrix
{
	int row, col;
	int **mat;
	public:
		Matrix()
		{
			row=2;
			col=2;
			mat=new int *[row];
			for( i = 0; i < col; i++ )
				mat[i]=new int[col];
		}

		Matrix(int r, int c)
		{
			row=r;
			col=c;
			mat=new int *[row];
			for( i = 0; i < col; i++ )
				row[i]=new int[col];
		}

		void get()
		{
			for( i = 0; i < row; i++ )
			{
				for( j = 0 ; j  < col; j++ )
				{

					cout<< "mat["<<i<<"]["<<j<<"] = ";
					cin>>mat[i][j];
				}
			}
		}
		Matrix operator +(Matrix m2)
		{
			Matrix temp;
			for( i = 0;i < row; i++)
			{
				for( j = 0; j < col; j++ )
				{
					temp.mat[i][j]=mat[i][j]+m2.mat[i][j];
				}
			}
			return temp;
		}

		Matrix operator *(Matrix m2)
		{
			Matrix temp;
			for( i = 0;i < row; i++)
			{
				for( j = 0; j < col; j++ )
				{
					temp.mat[i][j]=0;
					for( k = 0; k < col; k++ )
					{

						temp.mat[i][j]=temp.mat[i][j]+mat[i][k]*m2.mat[k][j];
					}
				}
			}
			return temp;
		}
		void disp()
		{
			for( i = 0 ; i < row; i++)
			{
				for( j = 0; j < col; j++ )
				{
					cout<<mat[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
};

void main()
{
	clrscr();
	Matrix m1,m2,m3;
	cout<< "\nMATRIX 1 :\n" ;
	m1.get();
	cout<< "\nMATRIX 2 :\n" ;
	m2.get();
	cout<< "\nMATRIX 1 :\n" ;
	m1.disp();
	cout<< "\nMATRIX 2 :\n" ;
	m2.disp();
	m3=m1+m2;
	cout<< "\nMATRIX 3 :\n" ;
	m3.disp();
	m3=m1*m2;
	m3.disp();
	getch();
}

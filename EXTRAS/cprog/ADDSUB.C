#include<stdio.h>
#include<conio.h>
#include <matrix.h>
int counter_1,counter_2;
void input_mat(int [][3],int,int);
void disp_mat(int [][3],int,int );
void add_mat(int [][3],int [][3],int [][3],int,int);
void sub_mat(int [][3],int [][3],int [][3],int,int);

int
main()
{
	int row, col, z, a[3][3], b[3][3], c[3][3];


	printf( " Enter the dimensions of matrix1 & matrix2: \n " );
	scanf("%d%d",&row,&col );

	printf( " Enter the elements of the matrix1: \n " );
	input_mat(a,row,col);

	printf( " Enter the elements of the matrix2: \n " );
	input_mat(b,row,col);

	printf( " What do you wanna perform!!! " );
	printf( " 1 -> ADDITION OF MATRIX \n " );
	printf( " 2 -> SUBTRACTION OF MATRIX \n " );
	scanf("%d",&z );

	printf( " Entered elments are\n " );
	display(a,row,col);
	display(b,row,col);

	switch(z)
	 {
		case 1: add_mat(a,b,c,row,col);
				display_mat(c,row,col);
				break;

		case 2: sub_mat(a,b,c,row,col);
				display_mat(c,row,col);
				break;
	 }
	getch();
	return 0;
}



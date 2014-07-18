#include<stdio.h>
#include<conio.h>
void input(int a[6][6],int,int);
void display(int b[6][6],int,int);
void main()
{
	int i,j,k,m,n,t;
	int a[6][6];
	clrscr();
	printf("Enter value for Matrix A[][]\n");
	printf("\n Enter no. of rows :- ");
	scanf("%d",&m);
	printf("\n Enter no. of coloumns :- ");
	scanf("%d",&n);

	input(a,m,n);
	display(a,m,n);
	printf("\n");

	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	    for (k=j+1;k<n;k++)
	      if(a[i][j] > a[i][k])
	      {
		t=a[i][j];
		a[i][j]=a[i][k];
		a[i][k]=t;
	      }

	printf("After Sorting Row Wise \n");
	printf("---------------------- ");
	display(a,m,n);
	getch();

  }




  void input(int a[6][6],int m,int n)
  {
    int i,j;

    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
      {
	printf("a[%d][%d]=",i,j);
	scanf("%d",&a[i][j]);
      }
  }
  void display(int a[6][6],int m,int n)
  {
    int i,j;
    for(i=0;i<m;i++)
    {
      printf("\n");
      for(j=0;j<n;j++)
	printf("\t%d",a[i][j]);
    }
  }


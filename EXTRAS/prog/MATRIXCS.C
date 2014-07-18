#include<stdio.h>
#include<conio.h>

void input(int a[6][6],int,int);
void display(int a[6][6],int,int);
void main()
{
	int i,j,k,m,n,t;
	int a[6][6];
	clrscr();
	printf("Enter value for Matrix A[][] \n");
	printf("\n Enter no. of rows :- ");
	scanf("%d",&m);
	printf("\n Enter no. of coloumns :- ");
	scanf("%d",&n);

	input(a,m,n);
	display(a,m,n);
	printf("\n");

	for(j=0;j<n;j++)
	  for(i=0;i<m;i++)
	    for(k=i+1;k<m;k++)
	      if(a[i][j]>a[k][j])
	      {
		t=a[i][j];
		a[i][j]=a[k][j];
		a[k][j]=t;
	      }

	 printf("\n After sorting coloumn wise");
	 printf("\n --------------------------");
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
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int **a,**b,**c,**a1,**a2,**a3,**a4,**b1,**b2,**b3,**b4,**c1,**c2,**c3,**c4;
int **d,**e,**f,**g,**h,**ii,**jj,**temp,**temp1;

void main()
{
	int n,i,j,ctri=0,ctrj=0,k;
	clrscr();
	printf("\n Enter Size Of The Matrix :");
	scanf("%d",&n);

	a=(int **)malloc(sizeof(int)*n*n);
	b=(int **)malloc(sizeof(int)*n*n);
	c=(int **)malloc(sizeof(int)*n*n);

	a1=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	a2=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	a3=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	a4=(int **)malloc(sizeof(int)*(n/2)*(n/2));

	b1=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	b2=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	b3=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	b4=(int **)malloc(sizeof(int)*(n/2)*(n/2));

	c1=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	c2=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	c3=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	c4=(int **)malloc(sizeof(int)*(n/2)*(n/2));

	d=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	e=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	f=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	g=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	h=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	ii=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	jj=(int **)malloc(sizeof(int)*(n/2)*(n/2));

	temp=(int **)malloc(sizeof(int)*(n/2)*(n/2));
	temp1=(int **)malloc(sizeof(int)*(n/2)*(n/2));

	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*n);
		b[i]=(int *)malloc(sizeof(int)*n);
		c[i]=(int *)malloc(sizeof(int)*n);
	}

	for(i=0;i<(n/2);i++)
	{
		a1[i]=(int *)malloc(sizeof(int)*(n/2));
		a2[i]=(int *)malloc(sizeof(int)*(n/2));
		a3[i]=(int *)malloc(sizeof(int)*(n/2));
		a4[i]=(int *)malloc(sizeof(int)*(n/2));

		b1[i]=(int *)malloc(sizeof(int)*(n/2));
		b2[i]=(int *)malloc(sizeof(int)*(n/2));
		b3[i]=(int *)malloc(sizeof(int)*(n/2));
		b4[i]=(int *)malloc(sizeof(int)*(n/2));

		c1[i]=(int *)malloc(sizeof(int)*(n/2));
		c2[i]=(int *)malloc(sizeof(int)*(n/2));
		c3[i]=(int *)malloc(sizeof(int)*(n/2));
		c4[i]=(int *)malloc(sizeof(int)*(n/2));

		d[i]=(int *)malloc(sizeof(int)*(n/2));
		e[i]=(int *)malloc(sizeof(int)*(n/2));
		f[i]=(int *)malloc(sizeof(int)*(n/2));
		g[i]=(int *)malloc(sizeof(int)*(n/2));
		h[i]=(int *)malloc(sizeof(int)*(n/2));
		ii[i]=(int *)malloc(sizeof(int)*(n/2));
		jj[i]=(int *)malloc(sizeof(int)*(n/2));

		temp[i]=(int *)malloc(sizeof(int)*(n/2));
		temp1[i]=(int *)malloc(sizeof(int)*(n/2));
	}

	printf("\n\n\t MATRIX A \n\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d] :",i,j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\t MATRIX B \n\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("b[%d][%d] :",i,j);
			scanf("%d",&b[i][j]);
		}
		printf("\n");
	}

	// SUB MATRIX A & B

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			a1[i][j]=a[i][j];
			b1[i][j]=b[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		ctrj=0;
		for(j=(n/2);j<n;j++)
		{
			a2[i][ctrj]=a[i][j];
			b2[i][ctrj++]=b[i][j];
		}
	}
	ctri=ctrj=0;

	for(i=(n/2);i<n;i++)
	{
		for(j=0;j<(n/2);j++)
		{
			a3[ctri][j]=a[i][j];
			b3[ctri][j]=b[i][j];
		}
		ctri++;
	}
	ctri=ctrj=0;

	for(i=(n/2);i<n;i++)
	{
		for(j=(n/2);j<n;j++)
		{
			a4[ctri][ctrj]=a[i][j];
			b4[ctri][ctrj++]=b[i][j];
		}
		ctrj=0;
		ctri++;
	}

	// D MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp[i][j]=b2[i][j]-b4[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			d[i][j]=0;
			for(k=0;k<(n/2);k++)
			{
				d[i][j]+=a1[i][k]*temp[k][j];
			}
		}
	}

	// E MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp[i][j]=b3[i][j]-b1[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			e[i][j]=0;
			for(k=0;k<(n/2);k++)
			{
				e[i][j]+=a4[i][k]*temp[k][j];
			}
		}
	}

	// F MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp[i][j]=a3[i][j]+a4[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			f[i][j]=0;
			for(k=0;k<(n/2);k++)
			{
				f[i][j]+=b1[i][k]*temp[k][j];
			}
		}
	}

	// G MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp[i][j]=a1[i][j]+a2[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			g[i][j]=0;
			for(k=0;k<(n/2);k++)
			{
				g[i][j]+=b4[i][k]*temp[k][j];
			}
		}
	}

	// H MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp[i][j]=a3[i][j]-a1[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp1[i][j]=b1[i][j]+b2[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			h[i][j]=0;
			for(k=0;k<(n/2);k++)
			{
				h[i][j]+=temp[i][k]*temp1[k][j];
			}
		}
	}

	// I MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp[i][j]=a2[i][j]-a4[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp1[i][j]=b3[i][j]+b4[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			ii[i][j]=0;
			for(k=0;k<(n/2);k++)
			{
				ii[i][j]+=temp[i][k]*temp1[k][j];
			}
		}
	}

	// J MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp[i][j]=a1[i][j]+a4[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			temp1[i][j]=b1[i][j]+b4[i][j];
		}
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			jj[i][j]=0;
			for(k=0;k<(n/2);k++)
			{
				jj[i][j]+=temp[i][k]*temp1[k][j];
			}
		}
	}

	// C1,C2,C3,C4 MATRIX

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			c1[i][j]=e[i][j]+ii[i][j]+jj[i][j]-g[i][i];
			c2[i][j]=d[i][j]+g[i][j];
			c3[i][j]=e[i][j]+f[i][j];
			c4[i][j]=d[i][j]+h[i][j]+jj[i][j]-f[i][j];
		}
	}


	printf("\n\n");

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			printf("%5d",c1[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			printf("%5d",c2[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			printf("%5d",c3[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			printf("%5d",c4[i][j]);
		}
		printf("\n");
	}
getch();
}










main()
{
   int i,j,temp,temp1,mat[3][3];
   void display(int[][3],int,int);
   clrscr();
   for(i=0;i<3;i++)
   {
	for(j=0;j<3;j++)
	{
		printf("\n Enter number  : ");
		scanf("%d",&mat[i][j]);
	}
   }
   for(;kbhit()==0;)
   {
   for(i=0;i<1;i++)
   {
	for(j=0;j<1;j++)
	{
		temp = mat[i][j+2];
		mat[i][j+2] = mat[i][j+1];
		temp1 = mat[i][j+1];
		mat[i][j+1] = mat[i][j];
	}
   }
   for(i=0;i<1;i++)
   {
	temp1 = mat[i+2][2];
	mat[i+2][2] = mat[i+1][2];
	mat[i+1][2] = temp;
   }
   i = 2;
   for(j=0;j<1;j++)
   {
	temp = mat[i][j];
	mat[i][j] = mat[i][j+1];
	mat[i][j+1] = temp1;
   }
   j = 0;
   for(i=0;i<1;i++)
   {
	temp1 = mat[i+1][j];
	mat[i+1][j] = temp;
	mat[i][j] = temp1;
   }
   /*i = 2;
	temp = mat[2][i-2];
	mat[2][i-2] = mat[2][i-1];
	mat[2][i-1] = temp1;*/
   clrscr();
   display(mat,3,3);
   sleep(1);
   }
}
void display(int a[][3],int m,int n)
{
   int i,j;
   for(i=0;i<m;i++)
   {
	for(j=0;j<3;j++)
	{
		printf("%d\t",a[i][j]);
	}
	printf("\n");
   }
}
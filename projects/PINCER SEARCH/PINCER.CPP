#include<stdio.h>
#include<conio.h>
#include<dos.h>

int l0[20],l1[20],c1[20],s1[20],mfs1[20], mfcs1[20], new_mfcs1[20];
int l2[20][20], c2[20][20], s2[20][20], mfs2[20][20],mfcs2[20][20],temp[20][20], newtemp[20][20], temparr[20], c3[20][20], tempc3[20][20],pr[20][20],prfinal[20][20], l3[20][20];
int support,l1index=0, s1index=0,i,j,z,count=0, k=0, mfcs_cnt=0, mfcsrow, newmfcscnt,tempcnt, ktempval, newmfcsrow;
int ctr1=0, temprowcnt=1, tp, c3row, c3temprow,rowcnt=1,l3cnt=1;

void calc_new_mfcs();
void 	calc_c2();
int x,y,inc,s;
void calc_support();
void mfcs_gen();
void check_subset();
void check_reverse_subset();
void calc_c3();
void prune();
void c3_support();
						//INPUT MATRIX
int array[15][9]={{1,0,0,0,1,1,0,1,0},
		   {0,1,0,1,0,0,0,1,0},
		   {0,0,0,1,1,0,1,0,0},
		   {0,1,1,0,0,0,0,0,0},
		   {0,0,0,0,1,1,1,0,0},
		   {0,1,1,1,0,0,0,0,0},
		   {0,1,0,0,0,1,1,0,1},
		   {0,0,0,0,1,0,0,0,0},
		   {0,0,0,0,0,0,0,1,0},
		   {0,0,1,0,1,0,1,0,0},
		   {0,0,1,0,1,0,1,0,0},
		   {0,0,0,0,1,1,0,1,0},
		   {0,1,0,1,0,1,1,0,0},
		   {1,0,1,0,1,0,1,0,0},
		   {0,1,1,0,0,0,0,0,1}
		   };

void main()
{
	clrscr();
	printf("\n\n\n\n\n\n\n\t\t\t Pincer Search Algorithm \n\n");
	sleep(1);
	printf("\n\t\t *************************************** \n\n");
	sleep(1);
	printf("\n\n\n\n\t\t\t    Implemented By  \n\n");
	sleep(1);
	printf("\n\n\t\t 1. Sangeeta Pai ");
	printf(" \n\n\t\t 2. Shilpa Shanubag");
	printf("\n\n\t\t 3. Maya p.");
	printf("\n\n\t\t 4. Deepshikha Khawas");
	printf("\n\n\t\t 5. Pooja gupta");
	printf("\n\n\t\t 6. Ganesh Pai");
	printf("\n\n\t\t 7. Guru Prasad ");
	printf("\n\n\t\t 8. Yogesh Rao ");
	printf("\n\n\t\t 9. Sameer Pradhan ");
	printf("\n\n\t\t 10. Jitendra kumar ");
	getch();
	clrscr();

	printf(" \n Enter Support::");
	scanf("%d",&support);

	support= (15 * support)/100;                          //CALCULATING SUPPORT



	for(  i=0;i< 9;i++)
	{
		ctr1 = 0;

		c1[count] = i+1;                             // CALCULATING C1
		mfcs1[count++]= i+1;                         //MFCS 1 ITEM SET

		for(  j=0;j< 15; j++)
		{
			if(array[j][i]==1)                    //FINDING WHETHER INPUT MATRIX IS HAVING SUPPORT
			{
				ctr1 ++;
			}
		}
		if( ctr1 >= support )
		{
			l1[ l1index++] =  i+1;			//IF IT IS HAVING SUPPORT PUT IT INTO FREQUENT SET L1
		}
		else
		{
			s1[ s1index++] =i+1;			//ELSE PUT IT INTO S1 (INFREQUENT SET)
		}
	}

	printf("\n\n\n\n Candidate Item set C1[] : \n\n");
	for(j=0; j < count ; j++)                              // PRINTING C1
		printf("\t %d",c1[j]);

	printf("\n\n\n\n MFCS Item set..\n\n");
	for(j=0; j < count ; j++)
	printf("\t %d",mfcs1[j]);                              // PRINTING MFCS1


	printf("\n\n\n\n Frequent Item Set L1[] : \n\n");

	for( i = 0; i < l1index; i++ )
	{
		printf( "\t%d", l1[i] );                      // PRINTING L1
	}
		printf("\n\n\n\n Infrequent Item Set S1[] : \n\n");

	for( i = 0; i < s1index; i++ )                       //S1INDEX CONTAINS NUMBER OF ELEMENTS IN S1
	{
		printf( "\t%d", s1[i] );                     // PRINTING S1
	}


	printf("\n\n\n\n MFCS for S1...");
	j=0;

	while(j<s1index)
	{
		printf( "\n\n" );
		calc_new_mfcs();
		j++;
	}

	calc_c2();

	getch();
	clrscr();

	printf("\n\n\n\nCandidate 2 Item set c2[][]= ");
	for(i=1;i<=count;i++)
	{
		printf("\n");
		for(j=1;j<=count;j++)
		{
			if(mfcs2[i][j]>0)
			{
				c2[i][j]=mfcs2[i][j];
				printf("%d,%d\t",i,mfcs2[i][j]);
			}
		}

	}
	calc_support();

	printf( "\n\n\n\nFrequent 2 Item Set l2[][]= \n" );
	for(i=1;i<=count;i++)
	{
		for(j=1;j<=count;j++)
		{
			if(l2[i][j]>0)
				printf("%d,%d\t",i,l2[i][j]);
		}

	}


	printf( "\n\n\n\nInfrequent 2 Item Set s2[][]= \n" );
	for(i=1;i<=count;i++)
	{
		for(j=1;j<=count;j++)
		{
			if(s2[i][j]>0)
				printf("%d,%d\t",i,s2[i][j]);

		}

	}

	printf( "\n\n\n\n NEW MFCS : \n" );
	for(i=0;i<count; i++)
		printf( "%d\t",mfcs1[i]);


					//COPYING CONTENTS OF MFCS1[] TO MFCS2[][]
	k=1;
	mfcsrow=1;
	for(j=0;j<count;j++)
	{
		mfcs2[mfcsrow][k++]=mfcs1[j];

	}



	for(int l=1;l<=count;l++)
	{
		  for(int m=1;m<=count;m++)
		  {
		   if(s2[l][m]>0)
		   {
			x=l;
			y=s2[l][m];

			mfcs_gen();
			}
		  }
	}

	getch();
	clrscr();

	calc_c3();
	prune();

	c3_support();

	printf( "\n\n\n**********************************\n\n");
	printf( "\n\n\n\n\n L = \n\n\n{ " );
	for( i = 0; i < l1index; i++ )
	{
		printf( "{%d},", l1[i] );                      // PRINTING L1
	}
	for(i=1;i<=count;i++)
	{
		for(j=1;j<=count;j++)
		{
			if(l2[i][j]>0)
				printf("{%d,%d}",i,l2[i][j]);
		}

	}
	for(i=1;i<=l3cnt-1;i++)
	{
		printf("{");
		for(j=1;j<=k;j++)
		{
			printf( "%d,",l3[i][j]);
		}
		printf( "} ");
		printf( "}");
	}




	getch();
}


void calc_new_mfcs()
{
		mfcs_cnt=0;
		for(i=0;i<count;i++)
		{
			if(mfcs1[i]!=s1[j])                       // PUTTING ALL ELMENTS IN NEW MFCS EXCEPT THE ELEMENTS IN S1
			{
				new_mfcs1[mfcs_cnt++]=mfcs1[i];
			}
		}
		count=mfcs_cnt;

		for(i=0;i<mfcs_cnt;i++)
		{
			printf("%d\t",new_mfcs1[i]);
			mfcs1[i]=new_mfcs1[i];			// COPYING CONTENTS OF NEW_MFCS1[] INTO MFCS1[]
		}
}

void calc_c2()
{
	j=1, k=1;

	while(j<=count)
	{
		for(i=0;i<count;i++)
		{
			if(mfcs1[i]==j)
			{
				for(z=0;z<count;z++)
				{
					if(mfcs1[z]>j)
					{
						mfcs2[j][k]=mfcs1[z];              //COPYING ALL THE ELEMENTS OF MFCS1[](1 DEMENSION) TO MFCS2[][] (2 DIMENSION)
						k++;
					}
				}
			}
		}
		j++;
		k=1;
	}
}

void calc_support()
{
	s=1;
	z=1;

	for(i=1; i<=count; i++)
	{
		for(j=1; j<=count; j++)
		{
			if(mfcs2[i][j]>0)
			{
				x=i-1;
				y=mfcs2[i][j]-1;
				inc=0;
				for(k=0;k<15;k++)
				{
					if((array[k][x]&array[k][y]))
					{
						inc++;
					}
				}
				if(inc>=support)
					l2[x+1][z++]=y+1;
				else
					s2[x+1][s++]=y+1;

			}
		}
		z=1;
		s=1;
	}
}

void mfcs_gen()

{
	temprowcnt=1;

	getch();
	clrscr();
	printf( "\n\n\n**********************************\n\n");
	printf( "\t\t(%d,%d)\t",x,y);
	printf( "\n\n**********************************\n\n");

	for(k=1;k<=mfcsrow;k++)
	{
		int flg=0;
		for(j=1;j<=count;j++)
		{
			if(mfcs2[k][j]==x)
				flg++;
			else if(mfcs2[k][j]==y)
				flg++;
		}
		if(flg==2)
		{

		  newmfcscnt=1;

			for(j=1;j<=count;j++)
			{
				if(mfcs2[k][j]!=x)
				{
				   //	temparr[tp++]=mfcs2[k][j];
					temp[temprowcnt][newmfcscnt++]=mfcs2[k][j];
				}
			}

			if(newmfcscnt<count)
			{
				for(z=newmfcscnt;z<=count;z++)
				{
				   //	temparr[tp++]=0;
					temp[temprowcnt][z]=0;
				}
			}

			temprowcnt++;

			tempcnt=newmfcscnt;
			newmfcscnt=1;
			for(j=1;j<=count;j++)
			{
				if(mfcs2[k][j]!=y)
				{
					temp[temprowcnt][newmfcscnt++]=mfcs2[k][j];
				}
			}
			if(newmfcscnt<count)
			{
				for(z=newmfcscnt;z<=count;z++)
				{
					temp[temprowcnt][z]=0;
				}
			}

			temprowcnt++;

		}

		else
		{
			int setf=0;

			for(int f=1; f<=count;f++)
			{
				if(mfcs2[k][f]!=0)
				{
					setf=1;
					break;
				}
			}
			if(setf==1)
			{

				for(int f=1;f<=count;f++)
				{
					temp[temprowcnt][f]=mfcs2[k][f];
				}
				temprowcnt++;
			}
		}
	}
	ktempval=temprowcnt;
	mfcsrow=ktempval;

	check_subset();

	for(int f=1; f<=temprowcnt;f++)
	{
		for(z=1;z<=count;z++)
		{

				mfcs2[f][z]=temp[f][z];

		}
	}


	printf( "\n\n    NEW MFCS : \n\n" );
	for( f=1; f<=temprowcnt;f++)
	{
		printf("\n\t");
		for(z=1;z<=count;z++)
		{
			if(mfcs2[f][z]>0)
				printf( "%d\t",mfcs2[f][z]);
		}
	}
   //	getch();
   //	clrscr();

}


void check_subset()
{
	int tempp;
	for(int ii=1;ii<=temprowcnt-1;ii++)
	{
			for(int jj=ii+1;jj<=temprowcnt;jj++)
			{
				int  incc=0,   flgg=0;
					for(int zz=1;zz<=count;zz++)
					{
						if(temp[jj][zz]>0)
							incc++;
					}
				for(int ll=1; ll<=count;ll++)
				{
					tempp=temp[jj][ll];

						if(tempp > 0)
						{
							for(int kk=1; kk<= count; kk++)
							{
								if(temp[ii][kk]==tempp)
								{
									flgg++;
									break;
								}
							}
						}

				}
				if(flgg==incc)
				{
				   //	printf("%d,%d is subsets\n",ii,jj );
					for(int hh=1; hh<=count;hh++)
						temp[jj][hh]=0;
				}
				else
				{
				   //	printf("%d,%d is not subsets\n",ii,jj );
				}
			}
		}
		check_reverse_subset();

}

void check_reverse_subset()
{
	int tempp;
	for(int ii=temprowcnt;ii>=1;ii--)
	{
			for(int jj=ii-1;jj>=0;jj--)
			{
				int  incc=0,   flgg=0;
					for(int zz=1;zz<=count;zz++)
					{
						if(temp[jj][zz]>0)
							incc++;
					}
				for(int ll=1; ll<=count;ll++)
				{


					tempp=temp[jj][ll];


						if(tempp > 0)
						{
							for(int kk=1; kk<= count; kk++)
							{
								if(temp[ii][kk]==tempp)
								{
									flgg++;
									break;
								}
							}
						}

				}
				if(flgg==incc)
				{
				   //	printf("%d,%d is subsets\n",ii,jj );
					for(int hh=1; hh<=count;hh++)
						temp[jj][hh]=0;
				}
				else
				{
				   //	printf("%d,%d is not subsets\n",ii,jj );
				}
			}
		}

}

void calc_c3()
{
	int incr,setf=0;
	c3row=1;
	c3temprow=1;


	for(i=1;i<=mfcsrow;i++)
	{
		incr=0;
		for(j=1;j<=count;j++)
		{
			if(mfcs2[i][j]>0)
			{
				incr++;
			}
		}
		if(incr==3)
		{
			for(k=1;k<=count;k++)
				c3[c3row][k]=mfcs2[i][k];
			c3row++;
		}
		if(incr==2)
		{
			for(k=1;k<=2;k++)
				tempc3[c3temprow][k]=mfcs2[i][k];
			c3temprow++;
		}

	}

	for(i=1; i<c3temprow-1;i++)
	{
		setf=0;
		for(j=i+1;j<c3temprow;j++)
		{
			for(k=1;k<=2;k++)
			{
				if((tempc3[i][k]>0)||(temp[j][k]>0))
				{
					if(tempc3[i][k]==tempc3[j][k])
					{
						setf=1;
						break;
					}
				}
			}
			if(setf==1)
			{
				z=1;
				c3[c3row][z++]=tempc3[i][k];
				c3[c3row][z++]=tempc3[i][2];
				c3[c3row][z++]=tempc3[j][2];
				c3row++;
			}
		}
	}

	printf("\n\n\nC3[][] \n\n" );

	for(i=1;i<=c3row-1;i++)
	{
		printf("\n");

		for(j=1;j<=count;j++)
		{
			if(c3[i][j]>0)
				printf("%d\t",c3[i][j]);
		}
	}
}

void prune()
{
	int tmpval,flg,cnt;
	rowcnt=1;

	for(int f=1; f<=c3row-1;f++)
	{
		cnt=0;
		for(z=1;z<=count;z++)
		{
			if(c3[f][z]>0)
			{
				x=c3[f][z];
				y=c3[f][z+1];
				flg=0;
				if(c3[f][z+1]>0)
				{

						for(j=1;j<=count;j++)
						{
							if(y==l2[x][j])
								flg=1;
						}

					if(flg==1)
						cnt++;
				}
			}
		}
		if(cnt==2)
		{
			for(i=1;i<=count; i++)
			{
				prfinal[rowcnt][i]=c3[f][i];
			}
			rowcnt++;
		}
	}

	printf( "\n\n\n**********************************\n\n");
	printf( "\n\n\n\nAFTER PRUNING...\n" );
	for(i=1;i<=rowcnt-1;i++)
	{
		printf( "\n");
		for(j=1;j<=count;j++)
		{
			if(prfinal[i][j]>0)
				printf( "%d\t",prfinal[i][j]);
		}
	}


}



void c3_support()
{
	int flg;
	for(i=1;i<=rowcnt-1;i++)
	{
		flg=0;
		k=1;

		x=prfinal[i][1]-1;
		y=prfinal[i][2]-1;
		z=prfinal[i][3]-1;



		for(j=0;j<15;j++)
		{
			if((array[j][x])&(array[j][y])&(array[j][z]))
				flg++;
		}
		if(flg>=support)
		{
			l3[l3cnt][k++]=x+1;
			l3[l3cnt][k++]=y+1;
			l3[l3cnt++][k]=z+1;
		}
	}

	printf( "\n\n\n**********************************\n\n");
	printf( "\n\n\n\nL3[][] == \n");
	for(i=1;i<=l3cnt-1;i++)
	{
		printf("\n");
		for(j=1;j<=k;j++)
		{
			printf( "%d\t",l3[i][j]);
		}
	}
}

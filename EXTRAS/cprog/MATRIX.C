int counter_1,counter_2;

void input_mat(int a[][3],int row,int col)
 {
  for(counter_1 = 0; counter_1 < row; counter_1++ )
   {
		for(counter_2 = 0; counter_2 < col; counter_2++ )
		 {
			 printf( "a[%d][%d]",counter_1,counter_2);
			 scanf("%d",&a[counter_1][counter_2]);
		 }
   }
 }

void display_mat(int a[][3],int row,int col)
 {
  for(counter_1 = 0; counter_1 < row; counter_1++ )
   {
	  for(counter_2 = 0; counter_2 < col; counter_2++ )
	   {
		 printf( "%d",a[counter_1][counter_2]);
	   }
	  printf( "\n" );
   }
 }

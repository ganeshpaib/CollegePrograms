main( int argc, char *argv[] )
 {
  int counter_1;
  clrscr();
  printf( " \nNumber of command line arguments = %d ",argc );
  printf( " \n The parameters are\n " );

  for( counter_1=0; counter_1 < argc; counter_1++)
   {
    printf( "%s",argv[counter_1] );
   }
 }


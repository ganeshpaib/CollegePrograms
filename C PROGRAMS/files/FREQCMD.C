/*
    PROGRAM TO PRINT THE FREQUENCY OF EACH CHARECTER IN A FILE USING COMMAND
    LINE ARGUMENTS
*/

#include<stdio.h>
#include<conio.h>
main(int argc,char *argv[])
{
  FILE *fptr;
  int temp,line=0,i,j;
  static int b[10][30];
  char c,w;

  fptr=fopen(argv[1],"w");

  printf( "Enter the string\n" );
  do
  {
	c=getchar();
	c=toupper(c);
	putc(c,fptr);
  }while(c!=EOF);

  fclose(fptr);

  fptr=fopen(argv[1],"r");

  while((c=getc(fptr))!=EOF)
  {
	 temp=c-65;
	 b[line][temp]+=1;
	 if(c=='\n')
		line++;
  }

  for(i = 0; i < 26; i++ )
  {
	w=i+65;
	printf( "%c",w);
  }


  printf("\n");
  for(i = 0; i < line; i++ )
  {
	for(j = 0; j < 26; j++ )
	{
		printf("%d",b[i][j]);
	}
	printf("\n");
  }

  fclose(fptr);
  getch();
}

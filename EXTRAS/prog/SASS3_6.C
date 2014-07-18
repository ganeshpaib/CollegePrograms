#include<stdio.h>
#include<conio.h>
int gcd(int ,int );
  main()
  {
    int n1,n2,g,l;
    clrscr();

    printf("Enter value for N1 :- ");
    scanf("%d",&n1);
    printf("\n Enter value for N2 :- ");
    scanf("%d",&n2);

    g = gcd(n2,n1);
    printf("\n G.C.D of %d and %d is %d",n1,n2,g);
    l = (n1*n2)/g;

    printf("\n L.C.M of %d and %d is %d",n1,n2,l);

    getch();
  }

  int gcd(int n1,int n2)
  {
    if((n1%n2) == 0)
      return n2;
    else
      return(gcd(n2,n1%n2));
  }


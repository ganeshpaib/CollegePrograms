			/* Program No.: 06(c) */


  /* C program to sort 10 integers using INSERTION SORT */

  #include<stdio.h>
  #include<conio.h>

  void main()
  {
   int a[10];
   void ins_sort(int *),disp(int *);
   clrscr();
   printf("Enter 10 integers to the array\n");
   ins_sort(a);
   printf("\n After sorting the array elements are\n");
   disp(a);
   getch();
  }

  void ins_sort(int *a)
  {
   int i,j,k,temp;
   for(i=0;i<10;i++)
   {
    scanf("%d",&a[i]);
    if(i>0)
    {
     if(a[i]<a[i-1])
     {
      k=i;
      for(j=i-1;j>=0;j--)
       if(a[k]<a[j])
       {
	temp=a[j];
	a[j]=a[k];
	a[k]=temp;
	k--;
       }
     }
    }
   }
  }

  void disp(int *a)
  {
   int i;
   for(i=0;i<10;i++)
    printf("\n a[%d]= %d",i,*(a+i));
  }
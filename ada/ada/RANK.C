#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int *a,*b,n,i,c=0,j;
        clrscr();
        printf("\n Enter Number Of Element : ");
        scanf("%d",&n);

        a=(int*)malloc(sizeof(int)*n);
        b=(int*)malloc(sizeof(int)*n);

        printf("\n");

        for(i=0;i<n;i++)
        {
        	printf("a[%d] :",i);
                scanf("%d",&a[i]);
        }
        printf("\n");

        for(i=0;i<n;i++)
        {
        	for(j=0;j<n;j++)
                {
                	if(a[j]<a[i])
                        {
                        	c++;
                        }
                }
                for(j=0;j<i;j++)
                {
                	if(a[j]==a[i])
                        {
                        	c++;
                        }
                }
                b[c]=a[i];
                c=0;
        }

        for(i=0;i<n;i++)
        {
        	printf("%5d",b[i]);
        }
getch();
}





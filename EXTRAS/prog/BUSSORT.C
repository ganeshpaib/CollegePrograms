#include<stdio.h>
#include<conio.h>

void bubble(float [],int );
void selects(float [],int );


main()
{
float i,a[10];
int n,ch;
clrscr();
printf("Enter the array size\n");
scanf("%d",&n);
printf("Enter 10 elements\n");
for(i=0;i<n;i++)
scanf("%f",&a[i]);
do
{
printf("Press 1-Bubble sort\n");
printf("Press 2-Selection sort\n");
printf("Press 3-Quit\n");
scanf("%d",&ch);

switch(ch)
{
case 1:bubble(a,n);
break;
case 2:selects(a,n);
break;
}
}while(ch<3);
getch();
}
void bubble(float a[9],int n)
{
int l,i,j;
float temp;
l=n-1;
for(i=0;i<n;i++)
{
for(j=0;j<l-i;j++)
   {
	if(a[j]>a[j+1])
	{
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
	}
   }
}
printf("Bubble sort\n");
for(i=0;i<n;i++)
printf("%f\n",a[i]);

}

void selects(float a[9],int n)
{
int i,j;
float temp;

	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	}
printf("Sorted list\n");
	for(i=0;i<10;i++)
	printf("%f\n",a[i]);

}





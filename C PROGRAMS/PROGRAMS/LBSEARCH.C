#include<stdio.h>
#include<conio.h>
void linear(float [],float ,int );
void binary(float [],float ,int );

main()
{
float a[10],x;
int i,f=0,n,k,ch;
clrscr();
printf("Enter the size\n");
scanf("%d",&n);
printf("Enter the 10 elments\n");
for(i=0;i<n;i++)
scanf("%f",&a[i]);
printf("Enter the numbers to be searched\n");
scanf("%f",&x);
do
{
printf("\nPress 1- Linear search\n");
printf("Press 2- Binary search\n");
printf("Press 3- Exit\n");
scanf("%d",&ch);

switch(ch)
{
case 1:linear(a,x,n);
break;
case 2:binary(a,x,n);
break;
}
}while(ch<=2);
getch();
}

void linear(float ar[9],float x,int n)
{
int i,f=0;
for(i=0;i<n;i++)
if(x==ar[i])
{
f=1;
break;
}
if(f==1)
printf("%f number found at %d position",x,i+1);
else
printf("Number %f not found\n",x);
}

void binary(float a[9],float x,int n)
{
int i,j,low,high,mid,f=0;
float temp;
for(i=0;i<n;i++)
 for(j=i+1;j<n;j++)

 if(a[i]>a[j])
 {
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
 }

 printf("Ascending order of entered elments\n");
 for(i=0;i<n;i++)
 printf("%f\n",a[i]);

	low=0;
	high=n-1;
	while(low<=high)
	{
	mid=(low+high)/2;
	if(x>a[mid])
	low=mid+1;
	else if(x<a[mid])
	high=mid-1;
	else if(x==a[mid])
	{
	f=1;
	break;
	}
	}
	if(f==1)
	printf("Number found at %d postion \n",mid+1);
	else
	printf("Number not found\n");

	}
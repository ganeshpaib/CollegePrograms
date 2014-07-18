#include<stdio.h>
#include<conio.h>

void main()
{
	int **a,*temp,v,i,j,*d,t,s=1,ctr=1,*tv,min;
        clrscr();
        printf("\n Enter Number Of Vertex :");
        scanf("%d",&v);

        a=(int **)malloc(sizeof(int)*v*v);
        temp=(int *)malloc(sizeof(int)*v);
        d=(int *)malloc(sizeof(int)*v);
        tv=(int *)malloc(sizeof(int)*v);
        for(i=1;i<=v;i++)
        {
        	*(a+i)=(int *)malloc(sizeof(int)*v);
        }
        tv[s]=1;

        for(i=1;i<=v;i++)
        {
        	for(j=1;j<=v;j++)
                {
                	printf("a[%d][%d] :",i,j);
                	scanf("%d",&a[i][j]);
                }
                printf("\n");
                d[i]=99;
                tv[i+1]=0;
        }

        while(1)
        {

        	for(i=1;i<=v;i++)
       		{
                	if(a[s][i]!=0)
                        {
                        	d[i]=a[s][i];
                                temp[i]=d[i];
                        }
      	        }

      	        for(i=1;i<v;i++)
        	{
        		for(j=i+1;j<=v;j++)
                	{
                		if(d[i]>d[j])
                        	{
                        		t=d[i];
                                	d[i]=d[j];
                                	d[j]=t;
                       		 }
                	}
        	}

                for(i=1;i<v;i++)
        	{
        		for(j=i+1;j<=v;j++)
                	{
                		if(temp[i]>temp[j])
                        	{
                        		t=temp[i];
                                	temp[i]=temp[j];
                                	temp[j]=t;
                       		 }
                	}
        	}
                if(d[1]<temp[1])
                {
                	min=d[1];
                }
                else
                {
                	min=temp[1];
                }


     	        for(i=1;i<=v;i++)
    	        {
        		if(min==a[s][i])
               	       	{
                		break;
               	 	}
    	      	 }
                 tv[ctr++]=i;
                 for(j=1;j<=v;j++)
                 {
                     	a[j][i]=99;
                 }
                 a[i][s]=99;
                 s=i;
                 	if(ctr==v)
                  	   break;
            }

            printf("\n 1");
            for(i=1;i<v;i++)
            {
            	printf("%5d",tv[i]);
            }

getch();
}






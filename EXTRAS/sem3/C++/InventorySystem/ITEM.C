#include<stdio.h>
#include<conio.h>

struct item
{
	int item_no;
	char name[' '];
	float price;
}i;

FILE *fp,*fp1;
int ctr=0;

void main()
{

	int ch,j,search,f,no,it[10],t,k;
        char name[' '];
	float temp;
	clrscr();
	fp=fopen("item.dat","ab+");

	if(fp==NULL)
	{
		printf("\n Error In Opening File");
		fclose(fp);
		exit(0);
	}

      	do
	{
		clrscr();

                printf("\n\n\t\t ************************* \n");
        	printf("\t\t\t ITEM \n");
       	        printf("\t\t ************************* \n");

		printf("\n\n\t\t\t 1... Insert");
		printf("\n\t\t\t 2... Delete");
		printf("\n\t\t\t 3... Update");
		printf("\n\t\t\t 4... Display");
		printf("\n\n\t\t\t 99.. Exit ");
		printf("\n Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
                        		f=0;
					printf("\n Item_No : ",j+1);
					scanf("%d",&no);
                                        printf(" Item_Name : ",j+1);
					flushall();
					gets(name);
					printf(" Item_Price : ",j+1);
					scanf("%f",&temp);

					rewind(fp);

                                        while(fread(&i,sizeof(i),1,fp)==1)
                                        {
                                        	if(i.item_no==no)
                                                {
                                                	f=1;
                                                }
                                        }
                                        fclose(fp);
                                        fp=fopen("item.dat","ab+");


                                        if(f==1)
                                        {
                                        	printf("\n Item_No Already Exists");
                                        }
                                        else
                                        {
                                        	strcpy(i.name,name);
                                        	i.price=temp;
                                        	i.item_no=no;
                                                fwrite(&i,sizeof(i),1,fp);
						printf("\n");
						printf("\n One Record Saved...");
                                        }

				break;
			case 2:
				rewind(fp);
				fp1=fopen("temp.dat","ab");
				f=0;

				if(fp1==NULL)
				{
					printf("\n Error In Opening File");
					fclose(fp1);
				}
				printf("\n Enter Item_No : ");
				scanf("%d",&search);

				while(fread(&i,sizeof(i),1,fp)==1)
				{
					if(search==i.item_no)
					{
						f=1;
					}
					else
					{
						fwrite(&i,sizeof(i),1,fp1);
					}
				}

				if(f==1)
				{
					fclose(fp);
					fclose(fp1);

					remove("item.dat");
					rename("temp.dat","item.dat");

					printf("\n Record Deleted......");
					fp=fopen("item.dat","ab+");

				}
				else
				{
					printf("\n Record Not Found....");
				}
				break;

			case 4:
				rewind(fp);
                                ctr=0;
                                fp1=fopen("temp.dat","wb+");

				f=0;

                                while(fread(&i,sizeof(i),1,fp)==1)
                                {
                                	it[ctr++]=i.item_no;
                                }
                                printf("\n ITEM_NO NAME    PRICE \n");

                                for(k=0;k<ctr-1;k++)
                                {
                                	for(j=k+1;j<ctr;j++)
                                        {
                                        	if(it[k]>it[j])
                                                {
                                                	t=it[k];
                                                        it[k]=it[j];
                                                        it[j]=t;
                                                }
                                        }
                                }
                                		rewind(fp);
                                                k=0;
                                                while(k<ctr)
                                                {
                                                	while(fread(&i,sizeof(i),1,fp)==1)
							{
                                                		if(it[k]==i.item_no)
                                                        	{
                                                        		fwrite(&i,sizeof(i),1,fp1);
                                                              	 	f=1;
                                                		}
                                              		  }
                                                          k++;
                                                          rewind(fp);
                                                }

				    if(f==0)
				    {
					printf("\n No Record....");
				     }
                                     else
                                     {
                                     	fclose(fp);
                                        fclose(fp1);

                                        remove("item.dat");
                                        rename("temp.dat","item.dat");

                                        fp=fopen("item.dat","ab+");

                                        rewind(fp);

                                        while(fread(&i,sizeof(i),1,fp)==1)
                                        {
                                        	printf("\n %d \t %s \t %f",i.item_no,i.name,i.price);
                                        }
                                     }


				     break;

			case 3:
				rewind(fp);
				fp1=fopen("temp.dat","wb");
				f=0;

				if(fp1==NULL)
				{
					printf("\n Error In Opening File");
					fclose(fp1);
				}

				printf("\n Enter Item_No : ");
				scanf("%d",&search);

				while(fread(&i,sizeof(i),1,fp)==1)
				{
					if(i.item_no==search)
					{
						printf("\n Enter Item Name: ");
						flushall();
						gets(i.name);
						printf("\n Enter Item Price :");
						scanf("%f",&temp);
						i.price=temp;

						f=1;
					}
					fwrite(&i,sizeof(i),1,fp1);
				}

				if(f==0)
				{
					printf("\n No Record Found");
				}
				else
				{
					fclose(fp);
					fclose(fp1);
					remove("item.dat");
					rename("temp.dat","item.dat");

					fp=fopen("item.dat","ab+");

					printf("\n Record Updated....");
				}
				break;

			/*case 99:
				fclose(fp);
				exit(0);*/
		}
		getch();
	}while(ch!=99);
getch();
}












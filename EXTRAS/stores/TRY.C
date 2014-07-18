/*
	PROJECT ON DEPARTMENTAL STORES MANAGEMENT SYSTEM
*/



struct stores
{
	char iname[50],compname[50];
	int ino,mfgmon,mfgyear,emon,eyear;
	float iamt,iqty;
}s,s1;


struct bill
{
	int ino,mon,year,date;
	char iname[50],compname[50];
	float totprice,iqty,profit;
};



#include<stdio.h>
#include<conio.h>
void upper(char *);

main()
{
	FILE *fp,*fp1,*fp3;

	struct bill b;

	int choice,ch,i,n,flg=0,ans=0,val=0,a[50],j=0,m,k,temp,month,year,num;
	long int recsize,recsize1;
	char iname[50],cname[50],opt,option;
	float total=0,qty=0,totprofit=0,grandtot = 0;

		clrscr();


	/* MAIN MENU */
	menu:printf( "\n\t\t\tMAIN MENU" );
		 printf("\n\tอออออออออออออออออออ   อออออออออออออออออออออ");

		 printf( "\n\t\t\t1 -> STOCK INFO\n" );
		 printf( "\n\t\t\t2 -> BILL\n" );
		 printf( "\n\t\t\t3 -> SALES & PROFIT\n" );
		 printf( "\n\t\t\t4 -> EXIT!!!\n" );
		  printf("\tออออออออออออออออออออ   ออออออออออออออออออออ\n");
		 printf( "\n\t\tENTER YOUR CHOICE............" );
		 scanf("%d",&choice);
		 s1.ino=1;

	switch(choice)
	{
		case 1:
					clrscr();

			   start:printf( "\n\t\t\tSTOCK MENU");
					 printf( "\n\tอออออออออออออออออออ   อออออออออออออออออออออ");
					 printf( " \n\t\t\t1 -> ADD STOCK\n" );
					 printf( " \n\t\t\t2 -> DISPLAY STOCK\n" );
					 printf( " \n\t\t\t3 -> UPDATE STOCK\n" );
					 printf( " \n\t\t\t4 -> EXIT\n" );
					 printf( " \n\t\t\t5 -> MAIN MENU\n" );
                     printf("\n\tอออออออออออออออออออ   อออออออออออออออออออออ");
					 printf( " \n\t ENTER UR CHOICE......" );

					 flushall();
					 scanf( "%d",&ch);

					 switch(ch)
					{
						case 1: clrscr();                    /* ADD STOCK */
								fp=fopen("stok.dat","rb+");
								if(fp==NULL)
									printf("UNABLE TO OPEN THE FILE\n");
								s1.ino=1;
								printf( "\n\t\t\tADD STOCK\n" );
                                printf("\tอออออออออออออออออออ   อออออออออออออออออออออ");
								printf( "\nEnter the Item name : ");
								flushall();
								scanf( "%[^\n]",s1.iname);

								upper(s1.iname);
								printf( "\nEnter the Company name : " );
								flushall();
								scanf( "%[^\n]",s1.compname);
								upper(s1.compname);


								printf( "\nEnter quantity : ");
								flushall();
								scanf( "%f",&s1.iqty);

								printf( "\nEnter the mfg date\n" );
								do
								{
									printf( "\tMonth : ");
									flushall();
									scanf( "%d",&s1.mfgmon);
								}while(!(s1.mfgmon>0&&s1.mfgmon<=12));

								do
								{
									printf( "\tYear : ");
									flushall();
									scanf( "%d",&s1.mfgyear);
								}while(!(s1.mfgyear>=2000 && s1.mfgyear<=2100));

								printf( "\nEnter the Expiry date\n" );
								do
								{
									printf( "\tMonth : ");
									flushall();
									scanf( "%d",&s1.emon);
								}while(!(s1.emon>0&&s1.emon<=12));

								do
								{
									printf( "\tYear : ");
									flushall();
									scanf( "%d",&s1.eyear);
								}while(!((s1.eyear>=2000&&s1.eyear<=2100)&&(s1.eyear>s1.mfgyear)));


								printf( "\nEnter the amount : ");
								flushall();
								scanf( "%f",&s1.iamt);

								/*printf( "\nEnter the tax of item : ");
								flushall();
								scanf( "%f",&s1.taxamt);*/

								fseek(fp,0,SEEK_SET);
								recsize1=sizeof(s);

								while(fread(&s,recsize1,1,fp)==1)
								{
									ans=0;
									if(strcmp(s1.iname,s.iname)==0)
									{
									 s1.ino=s.ino;
									 ans=1;
									 break;
									}
								}

								if(ans==0)
								{
									rewind(fp);
									while(fread(&s,sizeof(s),1,fp)==1)
									{
										a[j]=s.ino;
										j++;
									}                                           /* INCREMENTING ITEM NO. */
									m=j-1;

									for(j=0;j<m;j++)
									 {
										for(k=j+1;k<=m;k++)
										{
											if(a[j]>a[k])
											{
												temp=a[j];
												a[j]=a[k];
												a[k]=temp;
											}
										}
									 }




									s1.ino=a[m]+1;

								}

								fseek(fp,0,SEEK_END);
								fwrite(&s1,sizeof(s1),1,fp);
								fclose(fp);
								printf( "PRESS <ENTER> TO GO TO MAIN MENU\n" );
								opt=getchar();
								if(opt=='\n')
								{
									clrscr();
									goto start;
								}


						case 2:     clrscr();               /* DISPLAY STOCK */
									printf( "\n\t\t\tDISPLAY STOCK MENU" );

									printf( "\n\tอออออออออออออออออออ   อออออออออออออออออออออ");
									printf( "\n\t\t\t1 -> DISPLAY ALL ITEMS\n" );
									printf( "\n\t\t\t2 -> DISPLAY STOCK OF SELECTED ITEM\n" );
									printf( "\n\t\t\t3 -> EXIT\n" );
									printf( "\n\t\t\t4 -> MAIN MENU\n" );
                                    printf("\n\tอออออออออออออออออออ   อออออออออออออออออออออ");
									printf( "\n\tENTER UR CHOICE......." );
									scanf( "%d",&n);

									switch(n)
									{
										case 1: clrscr();     /* DISPLAY ALL STOCK */
												i=1;
												fp=fopen("stok.dat","rb");

												printf("--------------------------------------------------------------");
												printf( "\n\t\tITEM NAME\tITEM NUMBER\n" );
												printf("--------------------------------------------------------------\n");

												while(fread(&s,sizeof(s),1,fp)==1)
												{
													if(s.ino==i)
													{
														printf( "\t\t%s\t\t%d\n",s.iname,s.ino);
														i++;
													}
												}

												printf("       ********************************************\n");
												fclose(fp);
												goto start;




										case 2: clrscr();     /* DISPLAY STOCK OF SELECTED ITEM */

												printf( "\nEnter the Item name : " );
												flushall();
												scanf( "%[^\n]",iname);
												upper(iname);

												fp=fopen("stok.dat","rb");
												fseek(fp,0,SEEK_SET);
												clrscr();

												printf( "\nITEM NAME : %s\n",iname);
												printf("-------------------------------------------------------------------------------\n");
												printf( "\nCOMPANY NAME\tQUANTITY\tMFG DATE\tEXP DATE\tAMT\n" );
												printf("-------------------------------------------------------------------------------\n");

												while(fread(&s,sizeof(s),1,fp)==1)
												{
													if(strcmp(s.iname,iname)==0)
													{
														if(s.iqty==0)
														{
															continue;
														}
														flg=1;
														printf("%s\t\t%f\t%d-%d\t\t%d-%d\t\t%f\n",s.compname,s.iqty,s.mfgmon,s.mfgyear,s.emon,s.eyear,s.iamt);

													}

												}

												if(flg==0)
													printf( "ITEM NOT AVAILABLE\n" );

												printf("\n-------------------------------------------------------------------------------\n");
												fclose(fp);
												goto start;


									   case 3: exit(0);

									   case 4:clrscr();
											  goto menu;

									}


						case 3: clrscr();
								fp=fopen( "stok.dat","rb+" );
								rewind(fp);
								printf("\n\t\t\tUPDATING RECORD");

								printf("\n\tอออออออออออออออออออ   อออออออออออออออออออออ");
								printf( "Enter the Item name to be updated : " );
								flushall();
								scanf( "%[^\n]",iname );
								upper(iname);

								printf( "\nCOMP NAME\tMFG DATE\tEXP DATE\tQUANTITY\tAMT\n");
								printf( "---------------------------------------------------------------------\n");
								while(fread(&s,sizeof(s),1,fp)==1)
								{
									if(strcmp(iname,s.iname)==0)
									{
										if(s.iqty>0)
											printf( "\n%s\t\t%d-%d\t\t%d-%d\t\t%f\t%f",s.compname,s.mfgmon,s.mfgyear,s.emon,s.eyear,s.iqty,s.iamt);
									}
								}
								printf( "\n---------------------------------------------------------------------\n");

								printf( "Enter the Company name : " );
								flushall();
								scanf( "%[^\n]",cname );
								upper(cname);

								rewind(fp);
								recsize=sizeof(s1);

								while(fread(&s,sizeof(s),1,fp)==1)
								{
									if(strcmp(s.compname,cname)==0)
									{
										strcpy(s1.iname,iname);
										s1.ino = s.ino;
										printf( "\nEnter Company name : " );
										flushall();
										scanf( "%[^\n]",s1.compname);
										upper(s1.compname);

										printf( "\nEnter Quantity : " );
										flushall();
										scanf( "%f",&s1.iqty );

										printf( "\nEnter the mfg date\n" );
										do
										{
											printf( "\tMonth : ");
											flushall();
											scanf( "%d",&s1.mfgmon);
										}while(!(s1.mfgmon>0&&s1.mfgmon<=12));

										do
										{
											printf( "\tYear : ");
											flushall();
											scanf( "%d",&s1.mfgyear);
										}while(!(s1.mfgyear>=2000 && s1.mfgyear<=2100));

										printf( "\nEnter the Expiry date\n" );
										do
										{
											printf( "\tMonth : ");
											flushall();
											scanf( "%d",&s1.emon);
										}while(!(s1.emon>0&&s1.emon<=12));

										do
										{
											printf( "\tYear : ");
											flushall();
											scanf( "%d",&s1.eyear);
										}while(!((s1.eyear>=2000&&s1.eyear<=2100)&&(s1.eyear>s1.mfgyear)));


										printf( "\nEnter the amount : ");
										flushall();
										scanf( "%f",&s1.iamt);

										fseek(fp,-recsize,SEEK_CUR);
										fwrite(&s1,sizeof(s1),1,fp);

									}

								}
								fclose(fp);

								printf( "\nPRESS <ENTER> TO GO TO MAIN MENU\n" );
								flushall();
								opt=getchar();

								if( opt=='\n')
								{
									clrscr();
									goto menu;
								}
								break;

					case 4: exit(0);

					case 5:clrscr();
						   goto menu;

					}
					break;


		case 2:
									  /* BILLING */

				do
				{
					clrscr();

					printf( "\n\t\t\tBILLING\n" );
					printf("\tอออออออออออออออออออ   อออออออออออออออออออออ");

					printf( "\nEnter the item name: " );
					flushall();
					scanf( "%[^\n]",b.iname);
					upper(b.iname);


					fp=fopen("stok.dat","rb+");
					fp1=fopen("bill.dat","ab");
					fp3=fopen("sale.dat","ab");
					rewind(fp);

					printf( "--------------------------------------------------------------------");
					printf( "\nCOMPANY NAME\tMFG DATE\tEXP DATE\tUNIT PRICE\n" );
					printf( "--------------------------------------------------------------------");

					while(fread(&s,sizeof(s),1,fp)==1)
					{
						if(strcmp(b.iname,s.iname)==0)
						{
							if(s.iqty==0)
								continue;

							printf( "\n%s\t\t%d-%d\t\t%d-%d\t\t%f",s.compname,s.mfgmon,s.mfgyear,s.emon,s.eyear,s.iamt);
						}
					}

					printf( "\n---------------------------------------------------------------\n");

					printf( "\nEnter the  company name : ");
					flushall();
					scanf("%[^\n]",b.compname);
					upper(b.compname);


					printf( "\nEnter the quantity : ");
					flushall();
					scanf("%f",&b.iqty);
					recsize=sizeof(s);

					printf( "\nEnter current date, month & year : " );
					flushall();
					scanf( "%d%d%d",&b.date,&b.mon,&b.year);
					rewind(fp);
					grandtot=0.0000;
					while(fread(&s,sizeof(s),1,fp)==1)
					{
						if(strcmp(b.iname,s.iname)==0&&strcmp(b.compname,s.compname)==0&&(s.iqty>=b.iqty))
						{
							b.ino=s.ino;
							b.totprice=(s.iamt*b.iqty)+(s.iamt*0.2);
							grandtot = grandtot + b.totprice;
																		/* SETTING PROFIT */
							b.profit=(s.iamt*0.2);
							fwrite(&b,sizeof(b),1,fp1);
							fwrite(&b,sizeof(b),1,fp3);

							s.iqty=s.iqty-b.iqty;
							fseek(fp,-recsize,SEEK_CUR);
							fwrite(&s,sizeof(s),1,fp);
							val=1;
						}
					}

					if(val==0)
						printf("\nSTOCK NOT PRESENT\n");

					fclose(fp);
					fclose(fp1);
					fclose(fp3);

					printf( "\nPRESS 'Y' TO CONTINUE....\n" );
					flushall();
					scanf("%c",&opt);
					opt=toupper(opt);
				}while(opt=='Y');

					clrscr();

					printf( "\n\t\t\t*** BILL ***\n" );
					printf( "\n\nITEM NAME\tCOMPANY NAME\tQUANTITY\tTOTAL\n" );
					printf( "\n-------------------------------------------------------\n");
					fp=fopen("bill.dat","rb");

					while(fread(&b,sizeof(b),1,fp)==1)
					{
						printf("\n%s\t\t%s\t\t%f\t%f\n",b.iname,b.compname,b.iqty,b.totprice);
					}
					printf("----------------------------------------------------------\n" );
					printf("\t\tGRAND TOTAL..= %f", grandtot );
					printf( "\n\n\n\t*****************VISIT AGAIN***************\n");
					fclose(fp);

					remove("bill.dat");

					printf( "\n\n\nPRESS <ENTER> TO GO TO MAIN MENU\n" );
					flushall();
					ch=getchar();
					if(ch=='\n')
					{
						clrscr();
						goto menu;
					}
			   break;

		case 3:   clrscr();
				  printf( "\n\t\t\tSALES & PROFIT MENU" );
                  printf("\n\tอออออออออออออออออออ   อออออออออออออออออออออ");
				  printf( "\n\n\t\t\t1 -> PRODUCTWISE SALES\n" );
				  printf( "\n\t\t\t2 -> ITEMWISE SALES\n" );
				  printf( "\n\t\t\t3 -> TOTAL SALES\n" );
				  printf( "\n\t\t\t4 -> MONTHLY REPORT\n" );
				  printf("\n\tอออออออออออออออออออ   อออออออออออออออออออออ");

				  printf( "\nENTER YOUR CHOICE.......: " );
				  scanf( "%d",&opt);
				  switch(opt)
				  {                                                           /* PRODUCTWISE SALES */
					case 1:
							clrscr();
							printf( "\n\nEnter the Item Name........ : ");
							flushall();
							scanf( "%[^\n]",iname);
							upper(iname);

							printf( "\nEnter Company Name : " );
							flushall();
							scanf( "%[^\n]",cname);
							upper(cname);

							clrscr();
							fp=fopen("sale.dat","rb");
							rewind(fp);

							printf( "\t\t\tSALES & PROFIT OF %s\n",iname);
							printf( "\n---------------------------------------------------------------\n" );

							printf( "\tITEM NAME\tCOMPANY NAME\tQUANTITY SOLD\tPROFIT(in Rs.)\n" );
							printf( "-----------------------------------------------------------------\n" );


							qty=0.0000;
							total=0.0000;
							while(fread(&b,sizeof(b),1,fp)==1)
							{
								if(strcmp(b.iname,iname)==0)
								{
									if(strcmp(b.compname,cname)==0)
									{
									  qty=qty+b.iqty;

									  total=total+b.profit;
									}
								}
							}
							printf( "\n\t%s\t\t%s\t%f\t%f",iname,cname,qty,total);
							printf( "\n----------------------------------------------------------------\n" );
							printf( "\n\n\t\t\t TOTAL           %f\n",total);
							printf( "\n\t\t****************************************\n" );
							fclose(fp);


							printf( "\n\n\n\n\nPRESS <ENTER> TO GO TO MAIN MENU\n" );
							flushall();
							ch=getchar();
							if(ch=='\n')
							{
								clrscr();
								goto menu;
							}

							break;

					 case 2:                                                     /* ITEMWISE SALES */
							clrscr();
							printf( "\n\nEnter the Item Name........ : ");
							flushall();
							scanf( "%[^\n]",iname);
							upper(iname);

							clrscr();
							fp=fopen("sale.dat","rb");
							rewind(fp);

							printf( "\n\t\t\tSALES & PROFIT OF %s\n",iname);
							printf( "\n------------------------------------------------------------------\n" );

							printf( "\tITEM NAME\tQUANTITY SOLD\tPROFIT(in Rs.)\n" );
							printf( "--------------------------------------------------------------------\n" );

							qty=0.0000;
							total=0.0000;
							while(fread(&b,sizeof(b),1,fp)==1)
							{
								if(strcmp(b.iname,iname)==0)
								{
									  qty=qty+b.iqty;

									  total=total+b.profit;
								}
							}

							printf( "\n\t%s\t\t%f\t%f\n",iname,qty,total);

							printf( "\n\n---------------------------------------------------------------\n" );
							printf( "\n\n\t\t\t TOTAL           %f\n",total);
							printf( "\n\t\t****************************************\n" );
							fclose(fp);

							printf( "\n\n\n\n\nPRESS <ENTER> TO GO TO MAIN MENU\n" );
							flushall();
							ch=getchar();
							if(ch=='\n')
							{
								clrscr();
								goto menu;

							}
							break;

					 case 3:   i=1;                                            /* TOTAL SALES */
                            	clrscr();
							fp=fopen("sale.dat","rb");
							rewind(fp);
							printf( " \n\t\t\t\tTOTAL SALES\n" );
							printf( "\n----------------------------------------------------------------\n" );

							printf( "\tITEM NAME\tQUANTITY SOLD(kg/pkt)\tPROFIT(in Rs.)\n" );
							printf( "------------------------------------------------------------------\n" );

							while(fread(&b,sizeof(b),1,fp)==1)
												{
													if(b.ino==i)
													{
														num=b.ino;
														i++;
													}
												}

							totprofit=0.0000;
							for( i = 1; i <= num; i++ )
							{
								flg=0;
								qty=0.0000;
								total=0.0000;
								rewind(fp);
								while(fread(&b,sizeof(b),1,fp)==1)
								{

									if(i==b.ino)
									{
										qty=qty+b.iqty;
										strcpy(iname,b.iname);
										total=total+b.profit;
										totprofit=totprofit+b.profit;

										flg=1;
									}
								}
								if(flg==1)
									printf( "\n\t%s\t\t%f\t\t%f",iname,qty,total);
							}
							printf( "\n\n----------------------------------------------------------\n" );
							printf( "\n\n\t\t\t TOTAL           %f\n",totprofit);
							printf( "\n\t\t****************************************\n" );
							fclose(fp);

							printf( "\n\n\nPRESS <ENTER> TO GO TO MAIN MENU......" );
							flushall();
							ch=getchar();
							if(ch=='\n')
							{
								clrscr();
								goto menu;
							}
							break;

					 case 4: i=1;
							clrscr();

							fp=fopen("sale.dat","rb");
							rewind(fp);

							printf( "\nEnter the month & year : " );
							flushall();
							scanf( "%d%d",&month,&year);
							clrscr();


							printf( "\n\n\t\t\tSALES REPORT OF %d - %d\n" ,month,year);
							printf( "\n\t--------------------------------------------------------------\n" );

							printf( "\tITEM NAME\tQUANTITY SOLD(kg/pkt)\tPROFIT(in Rs.)\n" );
							printf( "\t---------------------------------------------------------------\n" );

							while(fread(&b,sizeof(b),1,fp)==1)
												{
													if(b.ino==i)
													{
														num=b.ino;
														i++;
													}
												}
							totprofit=0.0000;
							for( i = 1; i <= num; i++ )
							{
								flg=0;
								qty=0.0000;
								total=0.0000;

								rewind(fp);
								while(fread(&b,sizeof(b),1,fp)==1)
								{
									if((b.mon==month)&&(b.year==year))
									{
										if(b.ino==i)
										{
											qty=qty+b.iqty;
											strcpy(iname,b.iname);
											total=total+b.profit;
											totprofit=totprofit+b.profit;
											flg=1;
										}
									}
								}
								if(flg==1)
									printf( "\n\t%s\t\t%f\t\t%f",iname,qty,total);
							}
							printf( "\n\t--------------------------------------------------------------\n" );
							printf( "\n\t\t\t TOTAL           %f\n",totprofit);
							printf( "\n\t\t****************************************\n" );
							fclose(fp);

                            printf( "\n\n\n\n\nPRESS <ENTER> TO GO TO MAIN MENU\n" );
							flushall();
							ch=getchar();
							if(ch=='\n')
							{
								clrscr();
								goto menu;

							}
							break;

				  }
				  break;

		case 4:
					exit(0);


	}

	getch();
}




void upper(char *str)                /* FUNCTION TO CONVERT INTO UPPER CASE */
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		str[i]=toupper(str[i]);


	}


}





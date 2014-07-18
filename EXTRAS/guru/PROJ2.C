#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct item
{
	int no,h;
	char name[20];
	float price;
}i,it;
struct stock
{
	int no;
	float stock;
}s;
struct level
{
	int no;
	float level;
}l;
struct qtity
{
	int no;
	float qtity;
}q;
main()
{
	int op,ch,temp,o,p,y,ino,f=0,z,g,flag=0,iprice,a,x[50],h=0,lp=0,xp=0;
	char cho[5],iname[20],s1[20]="WRONG CHOICE",inf[20]="ITEM NOt FOUND";
	char id[20]="ITEM DELETED",ia[20]="ITEM ADDED",sa[20]="STOCK ADDED",up[10]="UPDATED";

	double sizei,sizes,sizel,sizeq,sizet;
	FILE *fp,*fp1,*fp2;


	sizei=sizeof(i);
	sizes=sizeof(s);
	sizel=sizeof(l);
	sizeq=sizeof(q);

	do
	{
		clrscr();
		printf("\t\t\tMASTER\n\n");
		printf("PRESS [MI] FOR ITEM\n");
		printf("PRESS [MS] FOR STOCK\n");
		printf("PRESS [ML] FOR REORDER LEVEL\n");
		printf("PRESS [MQ] FOR REORDER QUANTITY\n");
		printf("\n\t\t\tTRANSACTION\n\n");
		printf("PRESS [TS] FOR SALES\n");
		printf("PRESS [TO] FOR ORDERING\n");
		printf("\n\t\t\tDISPLAY\n\n");
		printf("PRESS [DI] FOR ITEM\n");
		printf("PRESS [DS] FOR STOCK\n");
		printf("PRESS [DL] FOR REORDER LEVEL\n");
		printf("PRESS [DQ] FOR REORDER QUANTITY\n");
		printf("PRESS [E]  FOR EXIT\n");
		printf("\n\t\t\t\t\tENTER YOUR CHOICE : ");
		flushall();
		gets(cho);
		strupr(cho);
		if(strcmp(cho,"MI")==0)ch=1;else
		if(strcmp(cho,"MS")==0)ch=2;else
		if(strcmp(cho,"ML")==0)ch=3;else
		if(strcmp(cho,"MQ")==0)ch=4;else
		if(strcmp(cho,"TS")==0)ch=5;else
		if(strcmp(cho,"TO")==0)ch=6;else
		if(strcmp(cho,"DI")==0)ch=7;else
		if(strcmp(cho,"DS")==0)ch=8;else
		if(strcmp(cho,"DL")==0)ch=9;else
		if(strcmp(cho,"DQ")==0)ch=10;else
		if(strcmp(cho,"E")==0)ch=99;else

		{clrscr();printf("%1005s\n",s1);ch=11;}

		switch(ch)
		{
			case 1:
							do
							{
								clrscr();
								printf("PRESS 1 -> INSERTION\n");
								printf("PRESS 2 -> DELETION\n");
								printf("PRESS 3 -> UPDATION\n");
								printf("PRESS 9 -> BACK\n");
								printf("\n\t\tENTER YOUR CHOICE : ");
								scanf("%d",&op);
								switch(op)
								{
									case 1:
                  				fp=fopen("item.dat","rb");
													rewind(fp);
													while(fread(&i,sizei,1,fp)==1)
													{
														lp=1;
													}
													fclose(fp);
                  				printf("\nENTER THE ITEM NO : ");
													flushall();
													scanf("%d",&i.no);

													printf("\nENTER THE ITEM NAME : ");
													flushall();
													gets(i.name);
													strupr(i.name);

													printf("\nENTER THE PRICE : ");
													flushall();
													scanf("%f",&i.price);

													fp1=fopen("item1.dat","ab");
													rewind(fp1);

													/*if(lp==0)
													{
														fp=fopen("item.dat","ab+");
														fwrite(&i,sizei,1,fp);
													}*/
													if(lp!=0)
													{
														fp=fopen("item.dat","rb+");
														rewind(fp);

														while(fread(&it,sizeof(it),1,fp)==1)
														{
															if(it.no<=i.no)
															{
																fwrite(&it,sizeof(it),1,fp1);
																xp=1;
															}
															else
															{
																flag=1;
																break;
															}
														}

															if(flag==1)
															{
																fwrite(&i,sizei,1,fp1);
																if(i.no<it.no)
																fseek(fp,-sizei,SEEK_CUR);
																while(fread(&it,sizeof(it),1,fp)==1)
																{
																	fwrite(&it,sizeof(it),1,fp1);
																}
															}
															else
															if(xp==1)
															fwrite(&i,sizei,1,fp1);

														remove("item.dat");
														rename("item1.dat","item.dat");
													}

													if(lp==0)
													{
														fp=fopen("item.dat","ab+");
														fwrite(&i,sizei,1,fp);
													}
													fclose(fp);
													fclose(fp1);
													lp++;
													clrscr();
													printf("%1005s",ia);
													break;

									case 2:
													fp=fopen("item.dat","rb");
													fp1=fopen("item1.dat","ab+");
													f=0;
													rewind(fp);

													printf("\nENTER THE ITEM NO WHICH YOU WANT TO DELETE : ");
													flushall();
													scanf("%d",&ino);

													while(fread(&i,sizeof(i),1,fp)==1)
													{
														if(ino!=i.no)
														{

															fwrite(&i,sizeof(i),1,fp1);
														}
														else
														f=1;
													}

													if(f==0){clrscr();printf("%1005s",inf);}
													if(f==1){clrscr();printf("%1005s",id);}

													remove("item.dat");
													rename("item1.dat","item.dat");
													fclose(fp1);
													z=1;
													goto stock;

										back:	goto level;
										kcab:	goto qtity;
										 end:	break;

									case 3:
													fp=fopen("item.dat","rb+");
													rewind(fp);

													printf("\nENTER THE ITEM NO YOU WANT TO UPDATE : ");
													flushall();
													scanf("%d",&ino);

													while(fread(&i,sizeof(i),1,fp)==1)
													{
														if(i.no==ino)
														{
																fseek(fp,-sizei,SEEK_CUR);

																printf("\nENTER THE ITEM NO : ");
																flushall();
																scanf("%d",&i.no);

                                printf("\nENTER THE ITEM NAME : ");
																flushall();
																gets(i.name);
																strupr(i.name);

																printf("\nENTER THE PRICE : ");
																flushall();
																scanf("%f",&i.price);

																fwrite(&i,sizeof(i),1,fp);

																{clrscr();printf("%1005s",up);}
																break;
														}
														else
														{clrscr();printf("%1005s\n",inf);}
													}

													fclose(fp);
													break;

									case 9:
													break;
									default:
													clrscr();printf("1005s",s1);
								}
								getch();
							}while(op!=9);
							break;
			case 2:
      				do
							{
								clrscr();
								printf("PRESS 1 -> INSERTION\n");
								printf("PRESS 2 -> DELETION\n");
								printf("PRESS 3 -> UPDATION\n");
								printf("PRESS 9 -> BACK\n");
								printf("\n\t\tENTER YOUR CHOICE : ");
								scanf("%d",&op);
								switch(op)
								{
									case 1: g=0;
													fp=fopen("stock.dat","ab+");
													fp1=fopen("item.dat","rb");

													rewind(fp);
                          h=0;
													while(fread(&s,sizes,1,fp)==1)
													{
														h++;
													}
													x[h]=s.no;
													rewind(fp1);

													printf("\nENTER THE ITEM NO : " );
													flushall();
													scanf("%d",&s.no);

													while(fread(&i,sizei,1,fp1)==1)
													{
														if(s.no==i.no)
														{
															printf("\nENTER THE QUANTITY : ");
															flushall();
															scanf("%f",&s.stock);

															fwrite(&s,sizes,1,fp);
															{clrscr();printf("%1005s",sa);}

															g=0;
															break;
														}
														else
														g=1;

													}
													fclose(fp);
													fclose(fp1);
													if(g==1)
													{clrscr();printf("%1005s",inf);}

													break;

									case 2: z=0;
									stock:  fp=fopen("stock.dat","rb");
													fp1=fopen("stock1.dat","ab+");
													f=0;
													rewind(fp);

													if(z==0)
													{printf("\nENTER THE ITEM NO WHICH YOU WANT TO DELETE : ");
													flushall();
													scanf("%d",&ino);}

													while(fread(&s,sizeof(s),1,fp)==1)
													{
														if(ino!=s.no)
														{
															fwrite(&s,sizeof(s),1,fp1);
														}
														else
														f=1;
													}
													if(z==0)
													{
															if(f==0){clrscr();printf("%1005s",inf);}
															if(f==1){clrscr();printf("%1005s",id);}
													}

													remove("stock.dat");
													rename("stock1.dat","stock.dat");
													fclose(fp1);
													if(z==1)
													goto back;

													break;

									case 3:
									case 9:break;
									default:{clrscr();printf("%1005s",s1);}
								}
								getch();
							}while(op!=9);
							break;
			case 3:
      				do
							{
								clrscr();
								printf("PRESS 1 -> INSERTION\n");
								printf("PRESS 2 -> DELETION\n");
								printf("PRESS 3 -> UPDATION\n");
								printf("PRESS 9 -> BACK\n");
								printf("\n\t\tENTER YOUR CHOICE : ");
								scanf("%d",&op);
								switch(op)
								{
									case 1:
									case 2: z=0;
									 level:	fp=fopen("level.dat","rb");
													fp1=fopen("level1.dat","ab+");
													f=0;
													rewind(fp);
													if(z==0)
													{
														printf("\nENTER THE ITEM NO WHICH YOU WANT TO DELETE : ");
														flushall();
														scanf("%d",&ino);
													}

													while(fread(&l,sizel,1,fp)==1)
													{
														if(ino!=l.no)
														{
															fwrite(&l,sizeof(l),1,fp1);
														}
														else
														f=1;
													}
													if(z==0)
													{
														if(f==0){clrscr();printf("%1005s",inf);}
														if(f==1){clrscr();printf("%1005s",id);}
													}

													remove("level.dat");
													rename("level1.dat","level.dat");
													fclose(fp1);
													if(z==1)
													goto kcab;

													break;


									case 3:
									case 9:break;
									default: {clrscr();printf("1005s",s1);}
								}
								getch();
							}while(op!=9);
							break;
			case 4:
      				do
							{
								clrscr();
								printf("PRESS 1 -> INSERTION\n");
								printf("PRESS 2 -> DELETION\n");
								printf("PRESS 3 -> UPDATION\n");
								printf("PRESS 9 -> BACK\n");
								printf("\n\t\tENTER YOUR CHOICE : ");
								scanf("%d",&op);
								switch(op)
								{
									case 1:
									case 2:z=0;
									 qtity:	fp=fopen("qtity.dat","rb");
													fp1=fopen("qtity1.dat","ab+");
													f=0;
													rewind(fp);

													if(z==0)
													{
														printf("\nENTER THE ITEM NO WHICH YOU WANT TO DELETE : ");
														flushall();
														scanf("%d",&ino);
													}

													while(fread(&q,sizeq,1,fp)==1)
													{
														if(ino!=q.no)
														{
															fwrite(&q,sizeof(q),1,fp1);
														}
														else
														f=1;
													}
													if(z==0)
													{
														if(f==0){clrscr();printf("1005s",inf);}
														if(f==1){clrscr();printf("1005s",id);}
													}

													remove("qtity.dat");
													rename("qtity1.dat","qtity.dat");
													fclose(fp1);
													if(z==1)
													goto end;

													break;
									case 3:
									case 9:break;
									default:{clrscr();printf("%1005s\n",s1);}
								}
								getch();
							}while(op!=9);
							break;
			case 5:
			case 6:
			case 7:
							fp=fopen("item.dat","rb");
							clrscr();

							rewind(fp);

							while(fread(&i,sizeof(i),1,fp)==1)
							{
								printf("%d\t%s\t%f\n",i.no,i.name,i.price);
							}

							fclose(fp);
							break;
			case 8:
							fp=fopen("stock.dat","rb");
							clrscr();
							y=0;
							h=0;
							rewind(fp);
							while(fread(&s,sizes,1,fp)==1)
							h++;
							for(o=0;o<h;o++)
							{
								for(p=o+1;p<h;p++)
								{
									if(x[o]<x[p])
									{
										temp=x[o];
										x[o]=x[p];
										x[p]=temp;
									}
								}
							}
							while(y<=x[0])
							{
									rewind(fp);

									while(fread(&s,sizeof(s),1,fp)==1)
									{
											if(s.no==y)
											{
												printf("%d\t%f\n",s.no,s.stock);

											}
									}
									y++;
							}

							fclose(fp);
							break;
			case 9:
							fp=fopen("level.dat","rb");
							clrscr();
							y=0;
							h=0;
							rewind(fp);
							while(fread(&l,sizel,1,fp)==1)
							h++;
							for(o=0;o<h;o++)
							{
								for(p=o+1;p<h;p++)
								{
									if(x[o]<x[p])
									{
										temp=x[o];
										x[o]=x[p];
										x[p]=temp;
									}
								}
							}
							while(y<=x[0])
							{
									rewind(fp);

									while(fread(&l,sizeof(l),1,fp)==1)
									{
											if(l.no==y)
											{
												printf("%d\t%f\n",l.no,l.level);

											}
									}
									y++;
							}

						/*	while(fread(&l,sizeof(l),1,fp)==1)
							{
								printf("%d\t%f\n",l.no,l.level);
							}*/

							fclose(fp);
							break;
			case 10:
							fp=fopen("qtity.dat","rb");
							clrscr();

              y=0;
							rewind(fp);
							while(fread(&q,sizeq,1,fp)==1)
							h++;
							for(o=0;o<h;o++)
							{
								for(p=o+1;p<h;p++)
								{
									if(x[o]<x[p])
									{
										temp=x[o];
										x[o]=x[p];
										x[p]=temp;
									}
								}
							}
							while(y<=x[0])
							{
									rewind(fp);

									while(fread(&q,sizeof(q),1,fp)==1)
									{
											if(q.no==y)
											{
												printf("%d\t%f\n",q.no,q.qtity);

											}
									}
									y++;
							}

							/*while(fread(&q,sizeof(q),1,fp)==1)
							{
								printf("%d\t%f\n",q.no,q.qtity);
							}*/

							fclose(fp);
							break;
			case 11: break;
			case 99: exit(0);
		}
		getch();
	}while(ch!=99);
	getch();
}



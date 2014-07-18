#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<item.c>
#include<stock.c>
#include<level.c>
#include<quantity.c>
#include<order.c>
#include<sales.c>


char ch;

void menu()
{
	clrscr();
        //sleep(1);
	printf("\n\t\t ********************************* \n");
        //sleep(1);
        printf("\t\t         INVENTORY SYSTEM \n");
        //sleep(1);
        printf("\t\t ********************************* \n");
        //sleep(1);
        printf("\n\n\n");

        printf("\t\t MASTER \t TRANSACTION \t EXIT \n");
        printf("\t\t -      \t -           \t - \n");
        printf("\n\n\t\t Enter Choice : ");
        flushall();
        scanf("%c",&ch);
}


void main()
{
start:
	clrscr();
        menu();

	switch(ch)
        {
        	case 'M'|'m':
                master:
                	clrscr();
                        printf("\n\t\t ************************* \n");
                        printf("\t\t\t MASTER \n");
                        printf("\t\t ************************* \n");
                        printf("\n\n\t Item \t Stock \t Reorder Level \t Reorder Quntity \t Exit\n");
                        printf("\t - \t - \t - \t\t   - \t\t\t - \n");
                        printf("\n\n\t Enter Choice : ");
                        flushall();
                        scanf("%c",&ch);

                        switch(ch)
                        {
                        	case 'i'|'I':
                                	item();
                                        break;
                                case 's'|'S':
                                	stock();
                                        break;
                                case 'r'|'R':
                                	level();
                                        break;
                                case 'o'|'O':
                                	quantity();
                                        break;

                        	case 'e'|'E':
                                	goto start;
                                default:
                                	printf("\n Invalid Choice");
                                        sleep(1);
                                        goto master;
                        }
                        break;
                case 'e'|'E':
                	exit(0);
                        break;
                case 'T'|'t':
                	tran:
                		clrscr();
                                printf("\n\n\t\t ************************* \n");
                                printf("\t\t\t TRANSACTIONS \n");
                                printf("\t\t ************************* \n");
                                printf("\n");

                                printf("\n\t Sales \t Order \t Exit \n");
                                printf("\n\t -     \t -     \t -\n");
                                printf("\n Enter Choice :");
                                flushall();
                                scanf("%c",&ch);

                                switch(ch)
                                {
                                	case 'S'|'s':
                                        	sales();
                                                break;
                                        case 'O'|'o':
                                        	order();
                                        case 'E'|'e':
                                        	goto start;
                                        default:
                                        	printf("\n Invalid Choice");
                                                sleep(1);
                                                goto tran;
                                }
                                break;
                default:
                	printf("\n Invalid Option ");
                        sleep(1);
                        goto start;


        }
getch();
}
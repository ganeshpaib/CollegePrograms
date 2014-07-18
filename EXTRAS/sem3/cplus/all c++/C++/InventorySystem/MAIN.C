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
	printf("\n\t\t ********************************* \n");
        printf("\t\t         INVENTORY SYSTEM \n");
        printf("\t\t ********************************* \n");
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
					goto master;

				case 's'|'S':
					stock();
					goto master;
				case 'r'|'R':
					level();
					goto master;
				case 'o'|'O':
					quantity();
					goto master;
				case 'e'|'E':
					goto start;
				default:
					printf("\n Invalid Choice");
					sleep(1);
                                        goto master;
			}
			//break;
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
						goto tran;
					case 'O'|'o':
						order();
						goto tran;
					case 'E'|'e':
						goto start;
					default:
						printf("\n Invalid Choice");
						sleep(1);
						goto tran;
				}
				//break;
                default:
                	printf("\n Invalid Option ");
                        sleep(1);
                        goto start;


        }
getch();
}
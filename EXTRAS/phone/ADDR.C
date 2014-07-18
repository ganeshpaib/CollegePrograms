#include<stdio.h>
#include<conio.h>

typedef struct addr *ptr_node;

typedef struct addr
{
	char name[20], addr[50], pnum[12], email[20];
	ptr_node link;
};



main()
{
	char ch;
	FILE *fp;
	ptr_node temp, ptr=NULL,b,t;
	do
	{
		temp=(ptr_node)malloc(sizeof(struct addr));
		t=(ptr_node)malloc(sizeof(struct addr));
		printf( "\nName: " );
		flushall();
		scanf( "%[^\n]",temp -> name );

		printf( "\nADDR: ");
		flushall();
		scanf( "%[^\n]",temp -> addr );



		if(ptr==NULL)
		{
			ptr=temp;
			temp->link=NULL;
		}
		else
		{
			for(t=ptr;t->link!=NULL;t=t->link);
			t->link=temp;
			temp->link=NULL;
		}
		printf( "enter" );
		flushall();
		scanf( "%c",&ch);
	}while(ch!='n');

	/*for(temp=ptr;temp!=NULL;temp=temp->link)
		printf("%s\n",temp->name);*/

	fp=fopen("addr.dat","ab");

	 t=ptr;
	 while(t!=NULL)
	 {

		fprintf(fp,"%s\t%s\n",t->name,t->addr );
		t=t->link;
	 }
	fclose(fp);

	getch();
	fp=fopen("addr.dat","rb");

	while(fscanf(fp,"%s%s",temp->name,temp->addr)!=EOF)
		printf( "\n%s\t%s\n",temp->name,temp->addr );
	fclose(fp);
	getch();
}



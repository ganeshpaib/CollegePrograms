 /* Program to implement user defined function to obtain the substring */

#include<stdio.h>
#include<conio.h>
#include<string.h>

void str_sub(char *str,char *sub,int pos,int len)
{
	int i,j,str_len,count=0;
	for(i=0;str[i]!='\0';i++);
	str_len=i;
	if(pos+len>str_len)
		len=str_len-pos+1;
	pos=pos-1;
	while(count<len)
		sub[count++]=str[pos++];
	sub[count]='\0';

}

void replace(char *str,char *rep,int pos,int sub_len)
{
      int i,rep_len,str_len,len,diff;
      rep_len=strlen(rep);
      str_len= strlen(str);
      len=str_len+rep_len-sub_len;
      diff=len-str_len;
      if(diff>0)
      {
	for(i=str_len-1;i>pos;i--)
		str[i+diff]=str[i];
      }
      if(diff<0)
      {
	for(i=pos;i<str_len;i++)
		str[i]=str[i-diff];
      }
      pos=pos-1;
      for(i=0;i<rep_len;i++)
	str[pos++]=rep[i];
      str[len]='\0';
}




void main()
{
	char str[20],sub_str[20],rep[20];
	int len,sub_len,i,pos;
	clrscr();
	printf("\n\tEnter the string  :  ");
	scanf("%[^\n]",str);
	printf("\n\tEnter the starting position of the substring	: ");
	scanf("%d",&pos);
	printf("\n\tEnter the length of the string	:  ");
	scanf("%d",&sub_len);
	str_sub(str,sub_str,pos,sub_len);
	printf("\n\tSub String is	:  ");
		printf("%s",sub_str);
	printf("\n\tEnter the string to be replaced : ");
	flushall();
	scanf("%[^\n]",rep);
	replace(str,rep,pos,sub_len);
	printf("\n\nAfter replacing string : %s",str);
	getch();
}

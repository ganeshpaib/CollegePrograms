/*program to convert a prefix expression to an infix expression*/
  #include<string.h>
  #include<stdio.h>
  #define max 10
  char infix[max],infix1[max],prefix[max],stack[max][max];
  int top=-1;
  main()
  {
     int n,i;
     char c,temp1[max],temp2[max];
     void push(char[]);
     char * pop();
     clrscr();
    printf("enter the expression in prefix form\n");
    scanf("%s",&prefix);
    n=strlen(prefix);
    i=n-1;
     do
     {
      c=prefix[i--];
	 switch(c)
	 {
	   case '+':
	   case '-':
	   case '*':
	   case '/':
	   case '%':
		    infix[0]='(';
		    infix[1]='\0';
		    infix1[0]=c;
		    infix1[1]='\0';
		    strcpy(temp1,pop());
		    strcpy(temp2,pop());
		    strcat(infix,temp1);
		    strcat(infix,infix1);
		    strcat(infix,temp2);
		    infix1[0]=')';
		    infix1[1]='\0';
		    strcat(infix,infix1);
		    push(infix);
		    break;
	    default:
		    infix[0]=c;
		    infix[1]='\0';
		    push(infix);
		    break;
	}
	}  while(i>=0);
	strcpy(infix,pop());
	printf("the infix expression is %s",infix);
	getch();
    }

    void push(char str[])
    {
      if(top>=max-1)
      printf("stack full\n");
      else
      strcpy(stack[++top],str);
    }

    char* pop()
    {
     if(top==-1)
     printf("stack is empty\n");
     else
     return (stack[top--]);
   }
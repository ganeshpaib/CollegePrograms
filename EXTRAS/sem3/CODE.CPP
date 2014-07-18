#include <stdio.h>
#include<conio.h>
char *program = "#include <stdio.h>%cchar *program = %c%s%c";
int main()
{
printf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);
getch();
return 0;
}

/*int main()
{
printf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);
return 0;
} */

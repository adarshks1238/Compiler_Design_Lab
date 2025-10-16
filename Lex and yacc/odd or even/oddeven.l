%{
#include <stdio.h>
#include <stdlib.h>

int odd = 0;
int in;
%}

%%
[0-9]+  {
    in = atoi(yytext);
    if (in % 2 == 0)
        odd = 0;
    else
        odd = 1;
}

.        ;
\n       return 0;
%%

int main()
{
    printf("Enter the number to check: ");
    yylex();
    if (odd == 1)
        printf("It's odd\n");
    else
        printf("It's even\n");
    return 0;
}

int yywrap()
{
    return 1;
}


%{
#include <stdio.h>
#include <string.h>
%}

%%
[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}    { printf("Valid Email ID\n"); }
.|\n                                              { printf("Invalid Email ID\n"); }
%%

int main()
{
    char input[100];
    printf("Enter an email ID: ");
    scanf("%s", input);
    YY_BUFFER_STATE buffer = yy_scan_string(input);
    yylex();
    yy_delete_buffer(buffer);
    return 0;
}

int yywrap()
{
    return 1;
}


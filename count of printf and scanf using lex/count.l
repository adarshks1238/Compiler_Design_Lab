%{
#include <stdio.h>
#include <stdlib.h>

int printf_count = 0;
int scanf_count = 0;
extern FILE *yyin;
%}

%%
"printf"    { printf_count++; printf("writef"); }
"scanf"     { scanf_count++; printf("readf"); }
.|\n        { putchar(yytext[0]); }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("cannot open file");
        return 1;
    }

    yyin = file;
    yylex();
    fclose(file);

    printf("\nprintf Count: %d\nscanf Count: %d\n", printf_count, scanf_count);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

char *cursor;
char string[100];

int E();
int Edash();
int T();
int Tdash();
int F();
int N();

int main() {
    printf("Enter the string to be parsed: ");
    scanf("%s", string);

    cursor = string;

    puts("");
    puts("INPUT\t\tACTION");
    puts("-----------------------------------");

    if (E() && *cursor == '\0') {
        printf("String is successfully parsed\n");
        return 0;
    } else {
        printf("String is not successfully parsed\n");
        return 1;
    }
}

int E() {
    printf("%-16s E -> T E'\n", cursor);
    if (T()) {
        if (Edash()) return SUCCESS;
    }
    return FAILED;
}

int Edash() {
    if (*cursor == '+') {
        printf("%-16s E' -> + T E'\n", cursor);
        cursor++;
        if (T()) {
            if (Edash()) return SUCCESS;
        }
        return FAILED;
    }
    printf("%-16s E' -> ε\n", cursor);
    return SUCCESS;
}

int T() {
    printf("%-16s T -> F T'\n", cursor);
    if (F()) {
        if (Tdash()) return SUCCESS;
    }
    return FAILED;
}

int Tdash() {
    if (*cursor == '*') {
        printf("%-16s T' -> * F T'\n", cursor);
        cursor++;
        if (F()) {
            if (Tdash()) return SUCCESS;
        }
        return FAILED;
    }
    printf("%-16s T' -> ε\n", cursor);
    return SUCCESS;
}

int F() {
    if (*cursor == '(') {
        printf("%-16s F -> (E)\n", cursor);
        cursor++;
        if (E()) {
            if (*cursor == ')') {
                printf("%-16s Matched ')'\n", cursor);
                cursor++;
                return SUCCESS;
            }
        }
        return FAILED;
    } else {
        printf("%-16s F -> N\n", cursor);
        return N();
    }
}

int N() {
    if (*cursor >= 'a' && *cursor <= 'z') {
        printf("%-16s N -> %c\n", cursor, *cursor);
        cursor++;
        return SUCCESS;
    }
    return FAILED;
}

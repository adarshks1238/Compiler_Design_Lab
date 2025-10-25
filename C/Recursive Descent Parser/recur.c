#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

int len = 0, e = 0;
char inp[MAX_LEN];

void E();
void T();
void EDASH();
void F();
void TDASH();
void skipSpaces();

void skipSpaces() {
    while (isspace(inp[len])) len++;
}

int main() {
    printf("Enter expression:");
    fgets(inp, MAX_LEN, stdin);
    inp[strcspn(inp, "\n")] = '\0';

    len = 0; e = 0;
    E();
    skipSpaces();

    if (len == strlen(inp) && e == 0) {
        printf("Parsing successful\n");
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}

void E() {
    T();
    EDASH();
}

void T() {
    F();
    TDASH();
}

void EDASH() {
    skipSpaces();
    if (inp[len] == '+') {
        len++;
        T();
        EDASH();
    }
}
void TDASH() {
    skipSpaces();
    if (inp[len] == '*') {
        len++;
        F();
        TDASH();
    }
}

void F() {
    skipSpaces();
    if (isalpha(inp[len])) {
        while (isalnum(inp[len])) {
            len++;
        }
    } else if (inp[len] == '(') {
        len++;
        E();
        skipSpaces();
        if (inp[len] == ')') {
            len++;
        } else {
            e = 1;
        }
    } else {
        e = 1;
    }
}

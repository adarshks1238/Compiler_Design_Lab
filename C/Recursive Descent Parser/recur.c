#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

char inp[MAX_LEN];
int len = 0;    
int e = 0;       
char lookahead;  

// Function declarations
void E();
void T();
void EDASH();
void F();
void TDASH();
void match(char c);
void nextToken();
void skipSpaces();


void skipSpaces() {
    while (isspace(inp[len])) len++;
}


void nextToken() {
    skipSpaces();
    lookahead = inp[len];  
}

// Match and advance input
void match(char c) {
    if (lookahead == c) {
        len++;
        nextToken();
    } else {
        e = 1;
    }
}

// E → T E'
void E() {
    T();
    EDASH();
}

// E' → + T E' | ε
void EDASH() {
    if (lookahead == '+') {
        match('+');
        T();
        EDASH();
    }
}

// T → F T'
void T() {
    F();
    TDASH();
}

// T' → * F T' | ε
void TDASH() {
    if (lookahead == '*') {
        match('*');
        F();
        TDASH();
    }
}

// F → id | (E)
void F() {
    if (isalpha(lookahead)) {
        // identifier: accept sequence of letters/digits
        while (isalnum(inp[len])) len++;
        nextToken();
    } else if (lookahead == '(') {
        match('(');
        E();
        if (lookahead == ')')
            match(')');
        else
            e = 1;
    } else {
        e = 1; // invalid factor
    }
}

int main() {
    printf("Enter expression:\t");
    fgets(inp, MAX_LEN, stdin);
    inp[strcspn(inp, "\n")] = '\0'; // remove newline

    len = 0; e = 0;
    nextToken(); // initialize lookahead with first symbol

    E(); // start parsing from start symbol

    skipSpaces();
    if (lookahead == '\0' && e == 0)
        printf("Parsing successful\n");
    else
        printf("Parsing failed\n");

    return 0;
}

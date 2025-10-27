#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    char stack[100];  
    int top = -1, i = 0;

    printf("Enter expression (use i for identifier): ");
    scanf("%s", input);

    printf("\n--- SHIFT REDUCE PARSER ---\n");

    while (input[i] != '\0') {
       
        stack[++top] = input[i];
        printf("\nShift: %c", input[i]);
        i++;

 
        int reduced;
        do {
            reduced = 0;

          
            if (top >= 0 && stack[top] == 'i') {
                stack[top] = 'E';
                printf("\nReduce: E -> i");
                reduced = 1;
            }
          
            else if (top >= 2 && stack[top - 2] == '(' &&
                     stack[top - 1] == 'E' && stack[top] == ')') {
                stack[top - 2] = 'E';
                top -= 2; 
                printf("\nReduce: E -> (E)");
                reduced = 1;
            }
            
            else if (top >= 2 && stack[top - 2] == 'E' &&
                     (stack[top - 1] == '+' || stack[top - 1] == '-' || stack[top - 1] == '*') &&
                     stack[top] == 'E') {
                char op = stack[top - 1];
                stack[top - 2] = 'E';
                top -= 2; 
                printf("\nReduce: E -> E%cE", op);
                reduced = 1;
            }
        } while (reduced);

       
        printf("\tStack: ");
        for (int j = 0; j <= top; j++)
            printf("%c", stack[j]);
        printf("\n");
    }

   
    if (top == 0 && stack[top] == 'E')
        printf("\nSuccessfully parsed!\n");
    else
        printf("\nSyntax Error.\n");

    return 0;
}

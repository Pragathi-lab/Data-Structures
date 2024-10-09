#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    return 0; // Return 0 if the character is not an operator
}

char associativity(char c) {
    if (c == '^') return 'R'; // Right associative
    return 'L'; // Left associative
}

void infixToPostfix(const char *s) {
    int len = strlen(s);
    char *result = (char *)malloc(len + 1);
    char *stack = (char *)malloc(len);
    int resultIndex = 0;
    int stackIndex = -1;

    if (!result || !stack) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // If the character is an operand (letter or digit)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c; // Add operand to result
        } 
        // If the character is '('
        else if (c == '(') {
            stack[++stackIndex] = c; // Push '(' to stack
        } 
        // If the character is ')'
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--]; // Pop from stack to result
            }
            stackIndex--; // Pop '('
        } 
        // If the character is an operator
        else {
            while (stackIndex >= 0 && (prec(c) < prec(stack[stackIndex]) || 
                  (prec(c) == prec(stack[stackIndex]) && associativity(c) == 'L'))) {
                result[resultIndex++] = stack[stackIndex--]; // Pop from stack to result
            }
            stack[++stackIndex] = c; // Push current operator to stack
        }
    }

    // Pop all remaining operators from the stack
    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0'; // Null-terminate the result
    printf("Postfix Expression: %s\n", result);

    free(result);
    free(stack);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0; // Return 0 to indicate successful execution
}

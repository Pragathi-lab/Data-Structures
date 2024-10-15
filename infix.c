#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    return 0; 
}

char associativity(char c) {
    if (c == '^') return 'R';
    return 'L'; 
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

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c; 
        } 
        
        else if (c == '(') {
            stack[++stackIndex] = c; 
        } 
    
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--]; 
            }
            stackIndex--;
        } 
    
        else {
            while (stackIndex >= 0 && (prec(c) < prec(stack[stackIndex]) || 
                  (prec(c) == prec(stack[stackIndex]) && associativity(c) == 'L'))) {
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c; 
        }
    }

    
    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0'; 
    printf("Postfix Expression: %s\n", result);

    free(result);
    free(stack);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0; 
}
